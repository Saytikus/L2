#include "modAlphaCipher.h"
using namespace std;

modAlphaCipher::modAlphaCipher(const wstring& skey) {
	for (int i = 0; i < numAlpha.size(); i++) {
			alphaNum[numAlpha[i]] = i;
	}
	key = convert(getValidKey(skey));
}
wstring modAlphaCipher::encrypt(const wstring& open_text) {
	vector<int> work = convert(getValidOpenText(open_text));
	for (unsigned i = 0; i < work.size(); i++) {
		work[i] = (work[i] + key[i % key.size()]) % alphaNum.size();
	}
	return convert(work);
}
wstring modAlphaCipher::decrypt(const wstring& cipher_text) {
	vector<int> work = convert(getValidCipherText(cipher_text));
	for (unsigned i = 0; i < work.size(); i++) {
		work[i] = (work[i] + alphaNum.size() - key[i % key.size()]) % alphaNum.size();
	}
	return convert(work);
}
inline vector<int> modAlphaCipher::convert(const wstring& s) {
	vector<int> result;
	for (auto c : s) {
		result.push_back(alphaNum[c]);
	}
	return result;
}
inline wstring modAlphaCipher::convert(const vector<int>& v) {
	wstring result;
	for (auto i : v) {
		result.push_back(numAlpha[i]);
	}
	return result;
}
inline wstring modAlphaCipher::getValidKey(const wstring& s) {
	if (s.empty()) 
		throw cipher_error("Empty key");
	wstring output;
	for (wchar_t c : s) {
		if (c >= L'А' && c <= L'Я') {
			output += c;
		}
		else if (c >= L'а' && c <= L'я') {
			output += towupper(c);
		}
		else
			throw cipher_error("Invalid key");
	}
	return output;
}
inline wstring modAlphaCipher::getValidOpenText(const wstring& s) {
	if (s.empty()) 
		throw cipher_error("Empty Open Text");
	wstring output;
	for (wchar_t c : s) {
		if (c >= L'А' && c <= L'Я') {
			output += c;
		}
		else if (c >= L'а' && c <= L'я') {
			output += towupper(c);
		}
		else
			throw cipher_error("Invalid Open Text");
	}
	return output;
}
inline wstring modAlphaCipher::getValidCipherText(const wstring& s) {
	if (s.empty()) 
		throw cipher_error("Empty Cipher Text");
	wstring output;
	for (wchar_t c : s) {
		if (c >= L'А' && c <= L'Я') {
			output += c;
		}
		else
			throw cipher_error("Invalid Cipher Text");
	}
	return output;
}