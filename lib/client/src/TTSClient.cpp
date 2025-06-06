#include "../include/TTSClient.h"


TTSClient::TTSClient(const std::shared_ptr<Channel> &channel): tts_stub_(TextToSpeech::NewStub(channel)) {}

TTSClient::~TTSClient() = default;

TTSResponse TTSClient::TTS(std::string &query) {
    TTSRequest request;
    ClientContext tts_context;
    TTSResponse response;

    request.set_text(query);

    Status status = tts_stub_->TTS(&tts_context, request, &response);

    std::cout << "tts response: " << response.status() << std::endl;

    return response;
}