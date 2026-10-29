#include <iostream>
#include <locale>
#include <string>
#include "modeAlphaCipher.h"
using namespace std;

// проверка: строка состоит только из русских прописных букв
bool isValid(const wstring& s) {
    for (auto c : s) {
        if (c < L'А' || c > L'Я')
            return false;
    }
    return true;
}

int main() {
    locale::global(locale("ru_RU.UTF-8"));
    wcout.imbue(locale("ru_RU.UTF-8"));
    wcin.imbue(locale("ru_RU.UTF-8"));

    wstring key;
    wstring text;
    unsigned op;

    wcout << L"Шифр готов. Введите ключ: ";
    wcin >> key;
    if (!isValid(key)) {
        wcerr << L"Ошибка: ключ недопустим\n";
        return 1;
    }
    wcout << L"Ключ принят\n";

    modAlphaCipher cipher(key);

    do {
        wcout << L"\nВыберите действие (0 - выход, 1 - зашифровать, 2 - расшифровать): ";
        wcin >> op;
        if (op > 2) {
            wcout << L"Ошибка: недопустимая операция\n";
        } else if (op > 0) {
            wcout << L"Введите текст: ";
            wcin >> text;
            if (isValid(text)) {
                if (op == 1) {
                    wcout << L"Зашифрованный текст: " << cipher.encrypt(text) << endl;
                } else {
                    wcout << L"Расшифрованный текст: " << cipher.decrypt(text) << endl;
                }
            } else {
                wcout << L"Операция прервана: введённый текст содержит недопустимые символы\n";
            }
        }
    } while (op != 0);

    return 0;
}