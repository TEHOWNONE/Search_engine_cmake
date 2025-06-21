#pragma once
#include <iostream>
#include <fstream>
#include <nlohmann/json.hpp>
#include <string>
#include <vector>
#include "gtest/gtest.h" 
#include <gtest/gtest.h>
using namespace std;

int launch();

class ConverterJSON {
public:
    ConverterJSON() = default;

    vector<string> GetTextDocuments();

    int GetResponsesLimit();

    vector<string> GetRequests();
};