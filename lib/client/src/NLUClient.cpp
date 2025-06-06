#include "../include/NLUClient.h"


NLUClient::NLUClient(const std::shared_ptr<Channel> &channel): nlu_stub_(NLU::NewStub(channel)) {}

NLUClient::~NLUClient() = default;

Intent NLUClient::GetSpeechIntent(std::string &query) {
    NLURequest request;
    ClientContext nlu_context;
    Intent intent;

    request.set_request(query);

    Status status = nlu_stub_->GetSpeechIntent(&nlu_context, request, &intent);

    std::cout << "server side: " << intent.intentname() << std::endl;

    return intent;
}