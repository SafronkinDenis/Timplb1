#include <iostream>
#include <locale>
#include <limits>
#include <string>
#include "modeBetaCipher.h"
using namespace std;

// проверка: строка должна содержать только заглавные русские буквы
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

    unsigned key;
    wstring text;
    unsigned op;

    wcout << L"Шифр маршрутной перестановки\n";
    wcout << L"Введите ключ (количество столбцов, >=2): ";
    wcin >> key;

    if (key < 2) {
        wcerr << L"Ошибка: ключ должен быть >= 2\n";
        return 1;
    }

    modeBetaCipher cipher(key);

    do {
        wcout << L"\nВыберите действие (0 - выход, 1 - шифрование, 2 - дешифрование): ";
        wcin >> op;
        if (op > 2) {
            wcout << L"Ошибка: недопустимая операция\n";
        } else if (op > 0) {
            // Очистка буфера после ввода числа
            wcin.ignore(numeric_limits<streamsize>::max(), L'\n');
            wcout << L"Введите текст (ЗАГЛАВНЫМИ русскими буквами без пробелов): ";
            getline(wcin, text);

            if (isValid(text)) {
                if (op == 1) {
                    wcout << L"Зашифрованный текст: " << cipher.encrypt(text) << endl;
                } else {
                    wcout << L"Расшифрованный текст: " << cipher.decrypt(text) << endl;
                }
            } else {
                wcout << L"Операция прервана: некорректный текст\n";
            }
        }
    } while (op != 0);

    return 0;
}