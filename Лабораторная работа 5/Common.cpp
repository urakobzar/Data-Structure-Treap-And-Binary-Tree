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
        cout << "� ���������, �� ��������\n";
        cout << "(�������� �������� ������ ���� ����� ������)\n";
        cout << "������� �����: ";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    return value;
}

