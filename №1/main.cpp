#include "modAlphaCipher.h"
using namespace std;

void check(const wstring& Text, const wstring& key, bool destructCipherText = false) {
	wstring cipherText;
	wstring decryptedText;
	try {
		modAlphaCipher cipher(key);
		cipherText = cipher.encrypt(Text);
		if(destructCipherText)
			decryptedText = cipher.decrypt(L"маленькиесимволы");
		else
			decryptedText = cipher.decrypt(cipherText);
		wcout << L"key=" << key << endl;
		wcout << Text << endl;
		wcout << cipherText << endl;
		wcout << decryptedText << endl;
		wcout << endl;
	}
	catch (const cipher_error& e) {
		cerr << "[" << e.what() << "]" << " with string: ";
		wcout << Text << " and key: " << key << endl;
	}
}

int main()
{
	locale loc("ru_RU.UTF-8");
	locale::global(loc);
	check(L"УЛУКУМОРЬЯДУБЗЕЛЕНЫЙ", L"зеленый");
	check(L"КанадаэтостранавСевернойАмерике", L"УЭЛЬС"); // Блок верных строк и ключей
	check(L"смешалисьвкучуконилюди", L"ЛЕРМОНТОВ");

	check(L"УЛУКОМОРЬЯДУБЗЕЛЕНЫЙ51372", L"ЗЕЛЕНЫЙ");		// Ошибка: некорректная строка с текстком
	check(L"УЛУКОМОРЬЯДУБЗЕЛЕНЫЙ", L"123ЗЕЛЕНЫЙ");			// Ошибка: некорректный ключ
	check(L"", L"ЗЕЛЕНЫЙ");									// Ошибка: пустая строка текста
	check(L"УЛУКОМОРЬЯДУБЗЕЛЕНЫЙ", L"");					// Ошибка: пустой ключ
	check(L"УЛУКОМОРЬЯДУБЗЕЛЕНЫЙ", L"УЭЛЬС", true);			// Ошибка: испорченный зашифрованный текст
	return 0;
}