/*
Задание 1. Шифр Цезаря

В древности для шифрования сообщений использовался такой способ: все буквы в
 сообщении сдвигались на одно и то же число позиций в алфавите. Число позиций 
 могло быть как положительным, так и отрицательным и являлось параметром шифра 
 — его ключом. Если для сдвига на данное число позиций алфавита не хватает, то 
 он зацикливается (то есть буква с номером 27 — это снова буква a, буква с 
 номером 28 — это буква b и так далее). Например, слово abracadabra при сдвиге 
 на десять позиций превратится в klbkmknklbk. Этот простейший шифр называется 
 шифром Цезаря. Регистр букв (заглавные и строчные) менять не нужно. Напишите 
 функцию encrypt_caesar от строки и числа, которая возвращает исходную строку, 
 зашифрованную шифром Цезаря с параметром, равным данному числу. Также напишите 
 функцию decrypt_caesar, выполняющую обратное преобразование. Считаем, что 
 входные строки состоят лишь из английских букв. Если там содержатся и другие 
 символы, то их надо игнорировать.

*/
#include <iostream>
#include <string>

using namespace std;

int main()
{
    string encryptCaesar(string, int);
    string decryptCaesar(string, int);
    string encrypted1, encrypted2, encrypted3;
    string decrypted1, decrypted2, decrypted3;

    const string test1 = "Lorem ipsum dolor sit amet consectetur adipiscing elit sed do eiusmod tempor incididunt ut labore et dolore magna aliqua Ut enim ad minim veniam quis nostrud exercitation ullamco laboris nisi ut aliquip ex ea commodo consequat Duis aute irure dolor in reprehenderit in voluptate velit esse cillum dolore eu fugiat nulla pariatur Excepteur sint occaecat cupidatat non proident sunt in culpa qui officia deserunt mollit anim id est laborum";
    const int shift1 = -1;

    const string test2 = "The quick brown fox jumps over the lazy dog";
    const string test3 = "THE QUICK BROWN FOX JUMPS OVER THE LAZY DOG";
    const int shift2 = 5;

    encrypted1 = encryptCaesar(test1, shift1);
    encrypted2 = encryptCaesar(test2, shift2);
    encrypted3 = encryptCaesar(test3, shift2);
    decrypted1 = decryptCaesar(encrypted1, shift1);
    decrypted2 = decryptCaesar(encrypted2, shift2);
    decrypted3 = decryptCaesar(encrypted3, shift2);

    cout << "Test 1 (encrypted): " << encrypted1 << "\n"
         << endl;
    cout << "Test 1 (decrypted): " << decrypted1 << "\n"
         << endl;
    cout << "Test 2 (encrypted): " << encrypted2 << "\n"
         << endl;
    cout << "Test 2 (decrypted): " << decrypted2 << "\n"
         << endl;
    cout << "Test 3 (encrypted): " << encrypted3 << "\n"
         << endl;
    cout << "Test 3 (decrypted): " << decrypted3 << "\n"
         << endl;

    return 0;
}

string encryptCaesar(string inString, int shift)
{
    string result;
    int newChar;

    for (int i = 0; i < inString.size(); i++)
    {
        if (inString[i] >= 'A' && inString[i] <= 'Z')
        {
            newChar = ((int)inString[i] + shift - 65) % 26;
            newChar += newChar >= 0 ? 65 : 91;
        }
        else if (inString[i] >= 'a' && inString[i] <= 'z')
        {
            newChar = ((int)inString[i] + shift - 97) % 26;
            newChar += newChar >= 0 ? 97 : 123;
        }
        else
            newChar = (int)inString[i];
        result += (char)newChar;
    }
    return result;
}

string decryptCaesar(string inString, int shift)
{
    string encryptCaesar(string, int);
    string decrypted;
    decrypted = encryptCaesar(inString, -shift);
    return decrypted;
}
