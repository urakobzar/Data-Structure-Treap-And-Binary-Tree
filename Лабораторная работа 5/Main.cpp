#include <iostream>
#include "Common.h"
#include "IOBinaryTree.h"
#include "IOTreap.h"

using namespace std;

enum MainMenuItems
{
	BinaryTreeItem = 1,
	TreapItem = 2,
	ExitItem = 3
};

int main()
{
	setlocale(LC_ALL, "Russian");
	while (true)
	{
		cout << "\nЧто вы хотите сделать?\n";
		cout << "1. Бинарное дерево поиска\n";
		cout << "2. Декартово дерево\n";
		cout << "3. Завершение программы\n";
		cout << "\nВведите ваш вариант действий: ";
		int menuNumber = ReadingCorrectValue();
		switch (menuNumber)
		{
			case BinaryTreeItem:
			{
				DisplayBinaryTreeMenuAction();
				break;
			}
			case TreapItem:
			{
				DisplayTreapMenuActions();
				break;
			}
			case ExitItem:
			{
				return 0;
			}
			default:
			{
				cout << "К сожалению, Вы ошиблись\n";
				cout << "Пожалуйста, введите заново\n\n";
				system("pause");
				break;
			}
		}
	}
}
