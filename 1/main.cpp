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

	TryCatch_My("", 4);								// ������ ������
	TryCatch_My("!@#$12345!6789x", 4);				// ������������ ������� � ������
	TryCatch_My("123456789x", 1);					// ������� ��������� ����
	TryCatch_My("123", 4);							// ��������� ������ �� ��������� � ������
	TryCatch_My("123456789x", 4, true);				// ������ ������ � �������������
	TryCatch_My("123456789x", 4, false, true);		// ��������� ���� � �������������
	TryCatch_My("123", 3, false, false, true );		// ��������� ������ �� ��������� � ������ � �������������

	return 0;
}