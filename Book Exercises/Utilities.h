#pragma once

#include <string>
#include <string_view>
#include <vector>
#include <functional>

using std::string;
using std::string_view;
using std::vector;
using std::function;

void PrintHeader(string_view header, char delimiter = '-');

void CallFunctionsWithHeader(string_view header, const vector<function<void()>>& functions);

void CleanInputStream();

void StringToLower(string& str);