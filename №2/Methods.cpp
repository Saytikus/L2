#include "Header.h"
using namespace std;

string Methods::Encrypt(const string str, const int key) {
	if (str.empty())
		throw Mymethods_error("String Error: Empty string");
	for (auto& c : str) {
		if (!isalnum(c))
			throw Mymethods_error("String error: invalid character");
	}
	for (auto& c : str) {
		if (islower(c))
			throw Mymethods_error("String Error: lowercase character");
	}
	if (key < 2)
		throw Mymethods_error("Key Error: Too small key");
	if (str.length() < key)
		throw Mymethods_error("Key Error: Too many key");
	int arraySize = str.length();
	int Cols = arraySize / key + (arraySize % key > 0 ? 1 : 0);
	int Rows = arraySize / Cols + (arraySize % Cols > 0 ? 1 : 0);
	int extraValues = abs(Cols * Rows - arraySize);
	char** array = new char* [Cols];
	for (int i = 0; i < Cols; i++)
		array[i] = new char[key];
	int number = 0;
	for (int i = 0; i < extraValues; i++) {
		array[Cols - 1][key - 1 - i] = '_';
	}
	string result;
	for (int i = 0; i < Cols; i++) {
		for (int j = 0; j < Rows; j++) {
			if (array[i][j] == '_')
				continue;
			array[i][j] = str.at(number);
			number++;
		}
	}
	for (int i = 0; i < Rows; i++) {
		for (int j = 0; j < Cols; j++) {
			if (array[j][(Rows - 1) - i] == '_')
				continue;
			result += array[j][(Rows - 1) - i];
		}
	}
	for (int i = 0; i < Cols; i++)
		delete[] array[i];
	delete[] array;
	return result;
}

string Methods::Decrypt(const string str, const int key) {
	int arraySize = str.length();
	int Cols = arraySize / key + (arraySize % key > 0 ? 1 : 0);
	int Rows = arraySize / Cols + (arraySize % Cols > 0 ? 1 : 0);
	int extraValues = abs(Cols * Rows - arraySize);
	char** array = new char* [Cols];
	for (int i = 0; i < Cols; i++)
		array[i] = new char[key];
	int number = 0;
	string result;
	for (int i = 0; i < extraValues; i++) {
		array[Cols - 1][key - 1 - i] = '_';
	}
	for (int i = 0; i < Rows; i++) {
		for (int j = 0; j < Cols; j++) {
			if (array[j][(Rows - 1) - i] == '_')
				continue;
			array[j][Rows - 1 - i] = str.at(number);
			number++;
		}
	}
	for (int i = 0; i < Cols; i++) {
		for (int j = 0; j < Rows; j++) {
			if (array[i][j] == '_')
				continue;
			result += array[i][j];
		}
	}
	for (int i = 0; i < Cols; i++)
		delete[] array[i];
	delete[] array;
	return result;
}