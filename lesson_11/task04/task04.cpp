/*
Задание 4. Оценка результатов игры в крестики-нолики
Что нужно сделать
Петя и Вася играли в крестики-нолики и не стёрли результаты своей игры. Теперь
 перед вами табличка 3 × 3, которая осталась после их поединка. Вы хотите
 понять, выиграл ли кто-то из них или они не доиграли. На вход программе даётся
 три строки, кодирующие верхнюю, среднюю и нижнюю строчки игрового поля.
 Крестик обозначается символом X (английская заглавная буква X), нолик —
 символом O (заглавная английская буква O), пустая клетка — точкой. Если ввод
 некорректен, то есть такая таблица не могла получиться в ходе настоящей игры,
 то надо написать в ответ слово Incorrect. Если таблица корректна и выиграли
 крестики, то нужно вывести в ответ слова Petya won, если нолики — Vanya won,
 иначе (то есть они не доиграли или сыграли вничью) надо написать Nobody.
*/
#include <iostream>
#include <string>
using namespace std;

int main()
{
    const string player1 = "Vasya";
    const string player2 = "Patya";
    string line1, line2, line3;

    cout << "Введите результат игры\n"
         << "строка 1: " << endl;
    cin >> line1;
    cout << "Строка 2: " << endl;
    cin >> line2;
    cout << "Строка 3: " << endl;
    cin >> line3;
    if (!checkLine(line1) || !checkLine(line2) || checkLine(line3))
        cout << "Incorrect!" << endl; 
}

bool checkLine(string lineIn)
{
    for (int i = 0; i < lineIn.size(); i++)
        if (lineIn[i] != 'X' || lineIn[i] != 'O' || lineIn[i] != '.')
            return false;
}
