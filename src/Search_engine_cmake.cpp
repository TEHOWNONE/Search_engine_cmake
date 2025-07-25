#include "Search_engine_cmake.h"

    int ConverterJSON::launch() {

    nlohmann::json j{};
    fstream fileConfig("../../../../config/config.json");
    fstream fileAnswers("../../../../config/answers.json", ios::out);

    try {
        if (!fileConfig.is_open()) throw "config file is missing";
        fileConfig >> j;
        if (j["config"] == nullptr) throw "config file is empty";
        else cout << j["config"]["name"];
    }
    catch (const char* err_mess) {
        cout << err_mess;
        return 0;
    }
    if (!fileAnswers.is_open()) fstream answers("../../../../config/answers.json");
    else fileAnswers.close();;
}

    vector<string> ConverterJSON:: GetTextDocuments() {

        nlohmann::json j{};
        vector<string> files;
        ifstream file("../../../../config/config.json");
        file >> j;
        int numberFiles = j["files"].size();

        for (int i = 0; i < numberFiles; i++) {
            files.push_back(j["files"][i]);
        };

        return files;
    };

    int ConverterJSON::GetResponsesLimit() {

        nlohmann::json j{};
        ifstream file("../../../../config/config.json");
        file >> j;
        int maxResponses = j["config"]["max_responses"];

        return maxResponses;
    };

    vector<string> ConverterJSON:: GetRequests() {

        nlohmann::json j{};
        vector<string> requests;
        ifstream file("../../../../config/requests.json");
        file >> j;
        int numberFiles = j["requests"].size();

        for (int i = 0; i < numberFiles; i++) {
            requests.push_back(j["requests"][i]);
        };

        return requests;
    };
    //void putAnswers()