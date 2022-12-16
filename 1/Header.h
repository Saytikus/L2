#pragma once
#include <iostream>
#include <string>
#include <ctype.h>
using namespace std;
class Methods {
public:
	string Encrypt(string str, const int key);
	string Decrypt(string str, const int key);
};
class Mymethods_error : public invalid_argument {
public:
	explicit Mymethods_error(const string& error_msg) :
		invalid_argument(error_msg) {}
};
