/*
Задание 2. Проверка корректности email-адреса

Напишите программу, которая проверяет корректность email-адреса, введённого
пользователем. Согласно международным требованиям, корректный email-адрес
должен состоять из двух частей, разделённых знаком @. Первая часть должна иметь
длину не менее одного и не более 64 символов, вторая часть — не менее одного и
не более 63 символов. Из символов допускаются только английские буквы, цифры и
знак «-» (дефис), а также точка. Точка не может быть первым или последним
символом, а кроме того, две точки не могут идти подряд. В первой части (которая
предшествует символу @), кроме вышеперечисленных, разрешены ещё следующие
символы:
!#$%&'*+-/=?^_{|}~`
*/
#include <iostream>
#include <string>
using namespace std;

int main()
{
    bool checkEmail(string);
    string address;
    cout << "Введите email-адрес: " << endl;
    cin >> address;
    if (checkEmail(address))
        cout << "Yes" << endl;
    else
        cout << "No" << endl;
    return 0;
}

bool checkEmail(string address)
{
    bool checkSymbol(char, bool);
    bool flag = false;
    int count = 0;
    if (address.size() <= 1)
        return false;
    if (address.find('@') <= 0)
        return false;
    if (address.size() > 63 + 64 + 1)
        return false;
    if (address.find_last_of('@') != address.find_first_of('@'))
        return false;
    if (address[0] == '.')
        return false;
    if (address[address.size() - 1] == '.')
        return false;

    for (int i = 0; i < address.size(); i++)
    {
        if (!checkSymbol(address[i], flag))
            return false;
        if (i > 0 && address[i] == '.' && address[i - 1] == '.')
            return false;
        if (address[i] == '@')
        {
            flag = true;
            count = -1;
        }
        count++;
        if (!flag and count > 64)
            return false;
        if (flag and count > 63)
            return false;
    }
    return true;
}

bool checkSymbol(char c, bool flag)
{
    const string special = "!#$%&'*+-/=?^_{|}~`";
    for (int i = 0; i < special.size(); i++)
        if (c == special[i])
        {
            if (!flag)
                return true;
            else
                return false;
        }

    for (int i = 0; i < 10; i++)
        if (c == i)
            return true;

    if (c < 'a' && c > 'z')
        return false;

    return true;
}