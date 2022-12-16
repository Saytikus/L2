#include "Header.h"
using namespace std;
	void TryCatch_My(const string & msg, const int & key, const bool DeleteEncMsg = false, const bool InvalidKeyDec = false, const bool HugeKeyDec = false) {
		try {
			int InvalidKey = 0;
			Header head;
			string EncryptedMsg = head.Encrypt(msg, key);
			if (DeleteEncMsg)
				EncryptedMsg = "";
			string DecryptedMsg;
			if (InvalidKeyDec)
				DecryptedMsg = head.Decrypt(EncryptedMsg, InvalidKey);
			else if (HugeKeyDec) {
				InvalidKey = 999999;
				DecryptedMsg = head.Decrypt(EncryptedMsg, InvalidKey);
			}
			else
				DecryptedMsg = head.Decrypt(EncryptedMsg, key);
			cout << msg << endl << EncryptedMsg << endl << DecryptedMsg << endl;
		}
		catch (const Mymethods_error& er) {
			cerr << "Error: " << er.what() << "\n\n";
		}
}

int main() {
	setlocale(LC_ALL, "RU");

	TryCatch_My("", 4);								// Пустая строка
	TryCatch_My("!@#$12345!6789x", 4);				// Некорректные символы в строке
	TryCatch_My("123456789x", 1);					// Слишком маленький ключ
	TryCatch_My("123", 4);							// Маленькая строка по сравнению с ключем
	TryCatch_My("123456789x", 4, true);				// Пустая строка в расшифровании
	TryCatch_My("123456789x", 4, false, true);		// Маленький ключ в расшифровании
	TryCatch_My("123", 3, false, false, true );		// Маленькая строка по сравнению с ключем в расшифровании

	return 0;
}