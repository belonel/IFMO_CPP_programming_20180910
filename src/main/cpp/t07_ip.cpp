//В сети интернет каждому компьютеру присваивается четырехбайтовый код, 
// который принято записывать в виде четырех чисел, 
// каждое из которых может принимать значения от 0 до 255, разделенных точками.
// Вот примеры правильных IP-адресов:
//127.0.0.0
//192.168.0.1
//255.0.255.255
//Напишите программу, которая определяет, является ли заданная строка правильным IP-адресом.
//
//Входные данные
//
//Программа получает на вход строку из произвольных символов.
//
//Выходные данные
//
//Если эта строка является корректной записью IP-адреса, выведите YES, иначе выведите NO.
//
//Примечание
//
//Для перевода из строки в число удобно пользоваться функцией stoi,
// которая принимает на вход строку, а возвращает число.
//
//Sample Input:
//
//127.0.0.1
//Sample Output:
//
//YES

#include "t07_ip.h"
#include <iostream>


using namespace std;

int t07_ip() {
    bool result = true; //конечный ответ. true - YES
    string str; //исходная строка
    cin >> str;
    int count = 0; //количество точек в строке
    for (char q : str)
        if (q == '.')
            count++;
    if (count > 3) // если количество точек больше 3 возвращаем ответ NO и дальше НЕ идём
    {
        cout<<"NO";
        return 0;
    }

    //добавляем в конец точку, чтобы после прочтения этой точки, в массив ip записался последний номер
    str.push_back('.');

    int len = str.length();
    string current;
    int ip[4]; //числа ip адреса
    int j = 0;

    for (int i = 0; i < len; i++)
    {
        if ((str[i] >= '0' && str[i] <= '9') || str[i] == '-') {
            current += str[i];
        }
        else if (str[i] == '.' && !current.empty()) {
            ip[j] = stoi(current);
            j++;
            current.erase();
        }
    }

    for (int k = 0; k < 4 && result; ++k) {
        if (ip[k] > 255 || ip[k] < 0)
            result = false;
    }
    if (result)
        cout<<"YES";
    else
        cout<<"NO";
}
