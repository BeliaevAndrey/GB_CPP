/*
 Задание 3. Валидация IP-адреса

 Что нужно сделать
Проверьте, задаёт ли введённая пользователем строка корректный IP-адрес
 четвёртой версии (IPv4). IP-адрес должен представлять из себя четыре числа,
  разделённые точками без пробелов, причём каждое число должно быть в диапазоне
  от 0 до 255 включительно. Числа не должны содержать ведущих нулей. Других
  символов в строке, кроме вышеописанных, быть не должно. Пользователь вводит
  строку, задающую IP-адрес через стандартный ввод. В результате программа
  должна вывести слово Valid, если адрес корректен, и слово Invalid, если это
  не так.
*/
#include <iostream>
#include <string>
using namespace std;

int main()
{
    bool checkIP(string);

    string address;
    cout << "Введите IP: " << endl;
    cin >> address;
    if (checkIP(address))
        cout << "Valid" << endl;
    else
        cout << "Invalid" << endl;
    return 0;
}

bool checkIP(string address)
{
    string octet = "";
    int count = 0;

    if (address[0] == '.' || address[address.size() - 1] == '.')
        return false;

    for (int i = 0; i < address.size(); i++)
    {
        if (i > 0 && address[i] == '.' && address[i - 1] == '.')
            return false;
        if (address[i] != '.')
            if (address[i] < '0' || address[i] > '9')
                return false;
            else
                octet += address[i];
        else
        {
            if (octet.size() > 1 && octet[0] == '0')
                return false;
            if (stoi(octet) > 255)
                return false;
            octet = "";
            count++;
            if (count > 3)
                return false;
        }
    }

    return true;
}