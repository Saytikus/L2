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
			if (z >= L'à' && z <= L'ÿ')
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

	check(L"óëóêîìîðüÿäóáçåëåíûé", L"çåëåíûé");
	check(L"ÓËÓÊÎÌÎÐÜßÄÓÁÇÅËÅÍÛÉ51372", L"ÇÅËÅÍÛÉ");
	check(L"ÓËÓÊÎÌÎÐÜßÄÓÁÇÅËÅÍÛÉ", L"626ÇÅËÅÍÛÉ");
	check(L"", L"ÇÅËÅÍÛÉ");
	check(L"ÓËÓÊÎÌÎÐÜßÄÓÁÇÅËÅÍÛÉ", L"");

	return 0;
}