//
// Created by lukas on 2021-01-26.
//

#include "../include/AudioClient.h"

AudioClient::AudioClient(const std::shared_ptr<Channel> &channel, uint32_t sampleRate, uint32_t numChannels,
                         std::string format, uint32_t framesPerBuffer, uint32_t bytesPerSample,
                         uint32_t ringbufferSize): stub_(AudioStreamer::NewStub(channel)),
                                                  sampleRate(sampleRate),
                                                  numChannels(numChannels),
                                                  format(std::move(format)),
                                                  framesPerBuffer(framesPerBuffer),
                                                  bytesPerSample(bytesPerSample),
                                                  ringbufferSize(ringbufferSize),
                                                  readPos(0),
                                                  writePos(0),
                                                  frameIndex(0) {
    numBytes = framesPerBuffer * numChannels * bytesPerSample;
    ringbufferBytes = numBytes*ringbufferSize;
    ringBuffer = new char[ringbufferBytes];
    readBuffer = new char[numBytes];
}


AudioClient::~AudioClient() {
    delete[] readBuffer;
}

void AudioClient::StreamAudioAsync() {
    streamThread = std::thread(&AudioClient::StreamAudio, this);
}

char* AudioClient::GetBuffer() {

    for(int i=0; i<numBytes; i++) {
        readBuffer[i] = ringBuffer[(readPos + i) % ringbufferBytes];
    }

    readPos += numBytes;

    return readBuffer;
}

void AudioClient::StopStream() {
    streaming = false;
    streamThread.join();
}

void AudioClient::StreamAudio() {
    // Data we are sending to the server.
    streaming = true;
    StreamRequest request;
    request.set_sample_rate(sampleRate);
    request.set_num_channels(numChannels);
    request.set_format(format);
    request.set_frames_per_buffer(framesPerBuffer);
    request.set_bytes_per_sample(bytesPerSample);

    Audio audio;

    // Context for the client. It could be used to convey extra information to
    // the server and/or tweak certain RPC behaviors.
    ClientContext context;

    Status status;

    std::unique_ptr<ClientReader<Audio> > reader(stub_->GetStream(&context, request));

    while (streaming && reader->Read(&audio)) {

        double avg=0;
        for(int j=0; j<numBytes; j++) {
            ringBuffer[writePos++] = audio.raw_data()[j];
            writePos = writePos % ringbufferBytes;
            avg += audio.raw_data()[j];
        }
        avg/=numBytes;

        frameIndex++;
    }
    streaming = false;
}

void AudioClient::PlayWav(std::string& wav_path) {
    ClientContext context;
    std::chrono::time_point<std::chrono::system_clock> deadline = std::chrono::system_clock::now() +
                          std::chrono::milliseconds(5000);
    context.set_deadline(deadline);

    FILE *wavin;
    int nread;

    std::vector<char> buf(bytesPerSample*framesPerBuffer*numChannels);

    wavin = fopen(wav_path.c_str(), "rb");


    fseek(wavin, 44, SEEK_SET);
    std::cerr << "after fseek" << std::endl;


    PlayResult result;
    std::unique_ptr<ClientWriter<Audio> > writer(stub_->PlayAudio(&context, &result));

    while(!feof(wavin)) {
        std::cout << "sending frame" << std::endl;
        nread = fread(buf.data(), 1, sizeof(buf.data()), wavin);

        Audio audio;
        audio.set_num_samples(16000);
        audio.set_num_channels(numChannels);
        audio.set_bytes_per_sample(bytesPerSample);
        audio.set_frames_per_buffer(framesPerBuffer);
        audio.set_sample_rate(sampleRate);
        audio.set_raw_data(buf.data(), nread);

        writer->Write(audio);

    }
    fclose(wavin);
}

