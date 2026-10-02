#pragma once

#include <string>
#include <string_view>
#include <vector>
#include <random>
#include <functional>

using std::string;
using std::string_view;
using std::vector;
using std::function;

void PrintHeader(string_view header, char delimiter = '-');

void CallFunctionsWithHeader(string_view header, const vector<function<void()>>& functions);

void CleanInputStream();

void StringToLower(string& str);
string StringToLower(string_view str);


template <typename T>
T RandomNumber(T min, T max)
{
	// Random number generation using C++11 <random> library
	std::random_device rd;
	std::mt19937 gen(rd());
	std::uniform_int_distribution<T> dis(min, max);

	// Generate and return a random number in the range [min, max]
	return dis(gen);
}