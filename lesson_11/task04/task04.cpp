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
    bool checkLine(string);
    string checkBoard(string[]);
    string lines[3];

    cout << "Введите результат игры\n"
         << endl;
    int i = 0;
    for (; i < 3; i++)
    {
        cout << "строка " << i + 1 << ":" << endl;
        cin >> lines[i];
        if (!checkLine(lines[i]))
        {
            break;
        }
    }
    if (i < 3)
    {
        cout << "Incorrect" << endl;
    }
    else if (checkBoard(lines) == "X")
        cout << "X won" << endl;
    else if (checkBoard(lines) == "O")
        cout << "O won" << endl;
    else
        cout << "Nobody won" << endl;
    return 0;
}

bool checkLine(string lineIn)
{
    for (int i = 0; i < lineIn.size(); i++)
        if (lineIn[i] != 'X' || lineIn[i] != 'O' || lineIn[i] != '.')
            return false;
    return true;
}

string checkBoard(string lines[3])
{
    int countX = 0;
    int countO = 0;
    int countDot = 0;
    string checkLines(string[]);
    string checkColumns(string[]);
    string checkDiagonal(string[]);
    if (checkLines(lines) == "X")
        return "X";
    else if (checkLines(lines) == "O")
        return "O";
    else if (checkColumns(lines) == "X")
        return "X";
    else if (checkColumns(lines) == "O")
        return "O";
    else if (checkDiagonal(lines) == "X")
        return "X";
    else if (checkDiagonal(lines) == "O")
        return "O";

    return ".";
}

string checkLines(string lines[3])
{
    int countX = 0;
    int countO = 0;
    for (int i = 0; i < 3; i++)
    {
        if (lines[i] == "XXX")
            return "X";
        else if (lines[i] == "OOO")
            return "O";
    }
    return ".";
}

string checkColumns(string lines[3])
{
    int countX = 0;
    int countO = 0;
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (lines[j][i] == 'X')
                countX++;
            if (lines[j][i] == 'O')
                countO++;
        }
        if (countX == 3)
            return "X";
        else if (countO == 3)
            return "O";
        countX = 0;
        countO = 0;
    }
    return ".";
}

string checkDiagonal(string lines[3])
{
    int countX = 0;
    int countO = 0;
    for (int i = 0; i < 3; i++)
    {
        if (lines[i][i] == 'X')
            countX++;
        else if (lines[i][i] == 'O')
            countO++;
    }
    if (countX == 3)
        return "X";
    else if (countO == 3)
        return "O";
    countO = 0;
    countX = 0;
    for (int i = 0, j = 2; i < 3, j >= 0; i++, j--)
    {
        if (lines[i][j] == 'X')
            countX++;
        else if (lines[i][j] == 'O')
            countO++;
    }
    if (countX == 3)
        return "X";
    else if (countO == 3)
        return "O";
    return ".";
}
