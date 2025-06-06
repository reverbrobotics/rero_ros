//
// Created by lukas on 2021-01-26.
//

#include "../include/SpeechRecognitionClient.h"

SpeechRecognitionClient::SpeechRecognitionClient(const std::shared_ptr<Channel> &audio_channel,
                                                 const std::shared_ptr<Channel> &sr_channel,
                                                 const std::shared_ptr<Channel> &hw_channel,
                                                 uint32_t sampleRate,
                                                 uint32_t numChannels, std::string format, uint32_t framesPerBuffer,
                                                 uint32_t bytesPerSample, uint32_t ringbufferSize) :audio_stub_(AudioStreamer::NewStub(audio_channel)),
                                                                                                    sr_stub_(SpeechRecognition::NewStub(sr_channel)),
                                                                                                    hw_stub_(HotwordDetection::NewStub(hw_channel)),
                                                                                                    sampleRate(sampleRate),
                                                                                                    numChannels(numChannels),
                                                                                                    format(std::move(format)),
                                                                                                    framesPerBuffer(framesPerBuffer),
                                                                                                    bytesPerSample(bytesPerSample) {

}

void SpeechRecognitionClient::StreamAudioAsync() {
    streamThread = std::thread(&SpeechRecognitionClient::StreamAudio, this);
}

void SpeechRecognitionClient::StopStream() {
    streaming = false;
    streamThread.join();
}

SpeechRecognitionResult SpeechRecognitionClient::StreamAudio() {
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
    ClientContext audio_context;
    ClientContext sr_context;

    Status status;

    std::unique_ptr<ClientReader<Audio> > reader(audio_stub_->GetStream(&audio_context, request));

    SpeechRecognitionResult response;

    std::unique_ptr<ClientWriter<Audio> > writer(sr_stub_->RecognizeSpeech(&sr_context, &response));

    milliseconds ms = duration_cast< milliseconds >(system_clock::now().time_since_epoch());

    while (streaming && reader->Read(&audio)&& writer->Write(audio));

    writer->Finish();

    return response;
}

SpeechRecognitionResult SpeechRecognitionClient::StreamAudioHotword(const std::string& hotword) {

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
    ClientContext audio_context;
    ClientContext sr_context;
    ClientContext hw_context;

    Status status;

    std::unique_ptr<ClientReader<Audio> > reader(audio_stub_->GetStream(&audio_context, request));

    HotwordResult hwResult;
    std::unique_ptr<ClientWriter<Audio> > hwWriter(hw_stub_->RecognizeHotword(&hw_context, &hwResult));

    SpeechRecognitionResult srResponse;

    std::unique_ptr<ClientWriter<Audio> > srWriter(sr_stub_->RecognizeSpeech(&sr_context, &srResponse));

    milliseconds ms = duration_cast< milliseconds >(system_clock::now().time_since_epoch());

    while(hwResult.hotword() != hotword) {
        while (streaming && reader->Read(&audio) && hwWriter->Write(audio)) {
        }
        hwWriter->Finish();
        std::cout << hwResult.hotword() << ": " << hwResult.confidence() << std::endl;
    }

    std::cout << "detected hotword!" << std::endl;

    while (streaming && reader->Read(&audio)&& srWriter->Write(audio)) {
    }

    srWriter->Finish();
    streaming=false;

    return srResponse;
}


