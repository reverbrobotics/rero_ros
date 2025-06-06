//
// Created by lukas on 2021-01-26.
//

#ifndef NLUCLIENT_H
#define NLUCLIENT_H

#include <iostream>
#include <memory>
#include <string>
#include <utility>
#include <grpcpp/grpcpp.h>
#include <thread>
#include <chrono>
#include "../nlu.grpc.pb.h"

#define CHECK_OVERFLOW  (0)
#define CHECK_UNDERFLOW  (0)

using grpc::Status;
using grpc::Channel;
using grpc::ClientContext;
using grpc::ClientReader;

using rero::NLURequest;
using rero::Intent;
using rero::Slot;
using rero::NLU;

class NLUClient {
public:
    explicit NLUClient(const std::shared_ptr<Channel>& channel);

    ~NLUClient();

    Intent GetSpeechIntent(std::string& query);

private:
    std::unique_ptr<NLU::Stub> nlu_stub_;
};

#endif //NLUCLIENT_H
