#include "search_engine.h"

int launch() {
    nlohmann::json j{};
    fstream fileConfig("config.json");
    fstream fileAnswers("answers.json", ios::out);

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
    if (!fileAnswers.is_open()) fstream answers("answers.json");
    else fileAnswers.close();;
}

class ConverterJSON {
public:
    ConverterJSON() = default;

    vector<string> GetTextDocuments() {

        nlohmann::json j{};
        vector<string> files;
        ifstream file("config.json");
        file >> j;
        int numberFiles = j["files"].size();

        for (int i = 0; i < numberFiles; i++) {
            files.push_back(j["files"][i]);
        };

        return files;
    };

    int GetResponsesLimit() {

        nlohmann::json j{};
        ifstream file("config.json");
        file >> j;
        int maxResponses = j["config"]["max_responses"];

        return maxResponses;
    };

    vector<string> GetRequests() {

        nlohmann::json j{};
        vector<string> requests;
        ifstream file("requests.json");
        file >> j;
        int numberFiles = j["requests"].size();

        for (int i = 0; i < numberFiles; i++) {
            requests.push_back(j["requests"][i]);
        };

        return requests;
    };

    //void putAnswers()
};