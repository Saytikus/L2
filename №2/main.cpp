#include "Header.h"
using namespace std;
	void TestTryCatch(const string & text, const int & key) {
		try {
			Methods head;
			string encrypted_text = head.Encrypt(text, key);
			string decrypted_text = head.Decrypt(encrypted_text, key);
			cout << text << endl << encrypted_text << endl << decrypted_text << "\n\n";
		}
		catch (const Mymethods_error& er) {
			cerr << "[" << er.what() << "]" << " with string: " << text << " and key: " << key << endl;
		}
}

int main() {
	TestTryCatch("123456789X", 3);					
	TestTryCatch("JOHNTRAVOLTA", 8);						// Блок с верными строками и ключами
	TestTryCatch("CANADAISACOUNTRYINNORTHAMERICA", 12);
	cout << "------------------------------" << endl;
	TestTryCatch("", 4);							// Ошибка: Пустая строка
	TestTryCatch("!@#$123456789X", 4);				// Ошибка: Некорректные символы в строке
	TestTryCatch("johntravolta", 5);				// Ошибка: Символ в нижнем регистре
	TestTryCatch("123456789X", 1);					// Ошибка: Слишком маленький ключ
	TestTryCatch("123", 4);							// Ошибка: Маленькая строка по сравнению с ключем
	return 0;
}