//
// Created by lukas on 2021-01-26.
//

#ifndef AUDIOTEST_AUDIOCLIENT_H
#define AUDIOTEST_AUDIOCLIENT_H

#include "portaudio.h"
#include <iostream>
#include <memory>
#include <string>
#include <utility>
#include <grpcpp/grpcpp.h>
#include <thread>
#include <chrono>
#include "audio.grpc.pb.h"

#define CHECK_OVERFLOW  (0)
#define CHECK_UNDERFLOW  (0)

using grpc::Status;
using grpc::Channel;
using grpc::ClientContext;
using grpc::ClientReader;

using rero::StreamRequest;
using rero::AudioStreamer;
using rero::Audio;

using namespace std::chrono;


class AudioClient {
public:
    explicit AudioClient(
            const std::shared_ptr<Channel>& channel,
            uint32_t sampleRate = 16000,
            uint32_t numChannels = 1,
            std::string format = "paInt16",
            uint32_t framesPerBuffer = 1024,
            uint32_t bytesPerSample = 2,
            uint32_t ringbufferSize = 10
    );
    ~AudioClient();

    void StreamAudioAsync();

    char* GetBuffer();

    void StopStream();

    bool isStreaming() const { return streaming; }

    void StreamAudio();

    uint16_t getNumBytes() const { return numBytes; }

    uint16_t getNumChannels() const { return numChannels; }

    uint16_t getSampleRate() const { return sampleRate; }

    uint16_t getFramesPerBuffer() const { return framesPerBuffer; }

private:
    std::unique_ptr<AudioStreamer::Stub> stub_;
    uint32_t sampleRate;
    uint32_t numChannels;
    std::string format;
    uint32_t framesPerBuffer;
    uint32_t bytesPerSample;
    uint32_t numBytes;
    uint32_t ringbufferSize;
    uint32_t ringbufferBytes;
    std::atomic<char*> ringBuffer;
    char* readBuffer;
    uint32_t readPos;
    uint32_t writePos;
    std::thread streamThread;
    std::atomic_bool streaming;
};

#endif //AUDIOTEST_AUDIOCLIENT_H
