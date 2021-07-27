//
// Created by lukas on 2021-01-26.
//

#ifndef TTSCLIENT_H
#define TTSCLIENT_H

#include <iostream>
#include <memory>
#include <string>
#include <utility>
#include <grpcpp/grpcpp.h>
#include <thread>
#include <chrono>
#include "text_to_speech.grpc.pb.h"

#define CHECK_OVERFLOW  (0)
#define CHECK_UNDERFLOW  (0)

using grpc::Status;
using grpc::Channel;
using grpc::ClientContext;
using grpc::ClientReader;

using rero::TTSRequest;
using rero::TTSResponse;
using rero::TextToSpeech;

class TTSClient {
public:
    explicit TTSClient(const std::shared_ptr<Channel>& channel);

    ~TTSClient();

    TTSResponse TTS(std::string& query);

private:
    std::unique_ptr<TextToSpeech::Stub> tts_stub_;
};

#endif //TTSCLIENT_H
