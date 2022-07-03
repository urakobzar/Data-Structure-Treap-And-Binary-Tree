#include "IOTreap.h"
#include <iostream>
#include "Common.h"

using namespace std;

void PrintTreap(TreapNode* node, int level)
{
	if (node != nullptr)
	{
		PrintTreap(node->Right, level + 1);
		for (int i = 0; i < level; i++)
		{
			cout << "\t";
		}
		cout << node->Key << "; " << node->Priority << "\n";
		PrintTreap(node->Left, level + 1);
	}
}

bool InformAboutTreeFullness(Treap* treap)
{
	if (treap->Root == nullptr)
	{
		cout << "\nДерево пусто\n";
		cout << "Возвращение в Меню взаимодействия\n";
		return true;
	}
	return false;
}

bool CheckExistenceKey(Treap* treap, int key)
{
	TreapNode* findNode = FindElement(treap->Root, key);
	if (findNode == nullptr)
	{
		cout << "\nЭлемент с таким ключем не присутствует в дереве\n";
		return false;
	}
	cout << "\nЭлемент с таким ключем присутствует в дереве\n";
	cout << "Возвращение в Меню взаимодействия\n";
	return true;
}

void InitializeParametr(int& key, int& priority)
{
	cout << "Введите ключ элемента: ";
	key = ReadingCorrectValue();
	priority = rand() % 100;
}

enum TreapMenuItems
{
	UnoptimizedAddTreapItem = 1,
	OptimizedAddTreapItem = 2,
	UnoptimizedDeleteTreapItem = 3,
	OptimizedDeleteTreapItem = 4,
	FindTreapItem = 5,
	ExitTreapItem = 6
};

void DisplayTreapMenuActions()
{
	Treap* treap = new Treap;
	treap->Root = nullptr;
	bool exitTreap = true;
	while (exitTreap)
	{
		if (treap->Root != nullptr)
		{
			cout << endl << endl;
			PrintTreap(treap->Root, 0);
			cout << endl << endl;
		}
		cout << "\nЧто вы хотите сделать?\n";
		cout << "1. Добавление элемента с использованием неоптимизированного алгоритма\n";
		cout << "2. Добавление элемента с использованием оптимизированного алгоритма\n";
		cout << "3. Удаление элемента с использованием неоптимизированного алгоритма\n";
		cout << "4. Удаление элемента с использованием оптимизированного алгоритма\n";
		cout << "5. Поиск элемента\n";
		cout << "6. Вернуться в Главное меню\n";
		cout << "\nВведите ваш вариант действий: ";
		int localNumber = ReadingCorrectValue();
		switch (localNumber)
		{
			case UnoptimizedAddTreapItem:
			{
				int key;
				int priority;
				InitializeParametr(key, priority);
				if (!CheckExistenceKey(treap, key))
				{
					UnoptimizedAddElement(treap, key, priority);
				}
				system("pause");			
				break;
			}
			case OptimizedAddTreapItem:
			{
				int key;
				int priority;
				InitializeParametr(key, priority);
				if (!CheckExistenceKey(treap, key))
				{
					OptimizedAddElement(treap, treap->Root, nullptr, key, priority);
				}
				system("pause");
				break;
			}
			case UnoptimizedDeleteTreapItem:
			{
				if (InformAboutTreeFullness(treap))
				{
					break;
				}
				cout << "Введите ключ элемента: ";
				int key = ReadingCorrectValue();
				TreapNode* findNode = FindElement(treap->Root, key);
				if (findNode == nullptr)
				{
					cout << "\nДанного элемента нет в дереве\n";
				}
				else
				{
					UnoptimizedDeleteElement(treap, key);
				}
				system("pause");			
				break;
			}
			case OptimizedDeleteTreapItem:
			{
				if (InformAboutTreeFullness(treap))
				{
					break;
				}
				cout << "\nВведите ключ элемента: ";
				int key = ReadingCorrectValue();
				TreapNode* findNode = FindElement(treap->Root, key);
				if (findNode == nullptr)
				{
					cout << "\nДанного элемента нет в дереве\n";
				}
				else
				{
					OptimizedDeleteElement(treap, treap->Root, nullptr, key);
				}
				system("pause");
				break;
			}
			case FindTreapItem:
			{
				if (InformAboutTreeFullness(treap))
				{
					break;
				}
				cout << "\nВведите ключ элемента: ";
				int key = ReadingCorrectValue();
				TreapNode* node = FindElement(treap->Root, key);
				if (node == nullptr)
				{
					cout << "\nЭлемент не найден\n";
				}
				else
				{
					cout << "\nЭлемент найден, ключ = " << node->Key;
					cout << ", приоритет = " << node->Priority;
					cout << endl;
				}
				system("pause");
				break;
			}
			case ExitTreapItem:
			{
				if (treap->Root != nullptr)
				{
					DeleteTreap(treap->Root);
				}
				exitTreap = false;
				system("pause");
				break;
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
	delete treap;
}