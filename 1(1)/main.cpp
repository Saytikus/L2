#include "modAlphaCipher.h"
using namespace std;

void check(const wstring& Text, const wstring& key, bool destructCipherText = false) {
	wstring cipherText;
	wstring decryptedText;
	wstring TempText;
	try {
		modAlphaCipher cipher(key);
		cipherText = cipher.encrypt(Text);
		decryptedText = cipher.decrypt(cipherText);
		for (auto& z : Text) {
			if (z >= L'�' && z <= L'�')
				TempText += towupper(z);
			else
				TempText = Text;
		}
		wcout << L"key=" << key << endl;
		wcout << TempText << endl;
		wcout << cipherText << endl;
		wcout << decryptedText << endl;
		if (TempText == decryptedText)
			wcout << L"Ok\n\n";
		else
			wcout << L"Err\n\n";
	}
	catch (const cipher_error& e) {
		cerr << "Error: " << e.what() << endl;
	}
}

int main()
{
	locale loc("ru_RU.UTF-8");
	locale::global(loc);

	check(L"��������������������", L"�������");
	check(L"��������������������51372", L"�������");
	check(L"��������������������", L"626�������");
	check(L"", L"�������");
	check(L"��������������������", L"");

	return 0;
}