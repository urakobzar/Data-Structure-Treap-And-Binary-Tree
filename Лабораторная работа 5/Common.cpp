#include "Common.h"
#include <iostream>

using namespace std;

int ReadingCorrectValue()
{
    int value;
    while (true)
    {
        if (cin >> value)
        {
            break;
        }
        cout << "К сожалению, Вы ошиблись\n";
        cout << "(Вводимое значение должно быть целым числом)\n";
        cout << "Введите снова: ";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    return value;
}

