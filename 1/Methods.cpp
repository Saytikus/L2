#include "Header.h"
using namespace std;

string Header::Encrypt(const string str, const int key) {
	if (str.empty())
		throw Mymethods_error("Empty string(Encrypt)");
	for (auto& c : str) {
		if (!isalnum(c))
			throw Mymethods_error("Invalid string(Encrypt)");
	}
	if (key < 2)
		throw Mymethods_error("Too small key(Encrypt)");
	if (str.length() < key)
		throw Mymethods_error("Too short string compared with key(Encrypt)");
	int arraySize = str.length();
	int Cols = arraySize / key + (arraySize % key > 0 ? 1 : 0);
	int Rows = arraySize / Cols + (arraySize % Cols > 0 ? 1 : 0);
	int extraValues = abs(Cols * key - arraySize);
	char** array = new char* [Cols];
	for (int i = 0; i < Cols; i++)
		array[i] = new char[key];
	int number = 0;
	for (int i = 0; i < extraValues; i++) {
		array[Cols - 1][key - 1 - i] = ' ';
	}
	string result;
	for (int i = 0; i < Cols; i++) {
		for (int j = 0; j < Rows; j++) {
			if (array[i][j] == ' ')
				continue;
			array[i][j] = str.at(number);
			number++;
		}
	}
	for (int i = 0; i < Rows; i++) {
		for (int j = 0; j < Cols; j++) {
			if (array[j][(key - 1) - i] == ' ')
				continue;
			result += array[j][(key - 1) - i];
		}
	}
	for (int i = 0; i < Cols; i++)
		delete[] array[i];
	delete[] array;
	return result;
}


string Header::Decrypt(const string str, const int key) {
	if (str == "")
		throw Mymethods_error("Empty string(Decrypt)");
	if (key < 2)
		throw Mymethods_error("Too small key(Decrypt)");
	if (str.length() < key)
		throw Mymethods_error("Too short string compared with key(Decrypt)");
	int arraySize = str.length();
	int Cols = arraySize / key + (arraySize % key > 0 ? 1 : 0);
	int Rows = arraySize / Cols + (arraySize % Cols > 0 ? 1 : 0);
	int extraValues = abs(Cols * key - arraySize);
	char** array = new char* [Cols];
	for (int i = 0; i < Cols; i++)
		array[i] = new char[key];
	int number = 0;
	string result;
	for (int i = 0; i < extraValues; i++) {
		array[Cols - 1][key - 1 - i] = ' ';
	}
	for (int i = 0; i < Rows; i++) {
		for (int j = 0; j < Cols; j++) {
			if (array[j][(key - 1) - i] == ' ')
				continue;
			array[j][key - 1 - i] = str.at(number);
			number++;
		}
	}
	for (int i = 0; i < Cols; i++) {
		for (int j = 0; j < Rows; j++) {
			if (array[i][j] == ' ')
				continue;
			result += array[i][j];
		}
	}
	for (int i = 0; i < Cols; i++)
		delete[] array[i];
	delete[] array;
	return result;
}