#include "IOBinaryTree.h"
#include <iostream>
#include "Common.h"

using namespace std;

void PrintBinaryTree(BinaryTreeNode* node, int level)
{
	if (node != nullptr)
	{
		PrintBinaryTree(node->Right, level + 1);
		for (int i = 0; i < level; i++)
		{
			cout << "\t";
		}
		cout << node->Key << "\n";
		PrintBinaryTree(node->Left, level + 1);
	}
}

bool InformAboutTreeFullness(BinaryTree* binaryTree)
{
	if (binaryTree->Root == nullptr)
	{
		cout << "\nДерево пусто\n";
		cout << "Возвращение в меню\n";
		return true;
	}
	return false;
}

enum BinaryTreeMenuItems
{
	AddBinaryTreeItem = 1,
	DeleteBinaryTreeItem = 2,
	FindBinaryTreeItem = 3,
	FindMaximumBinaryTreeItem = 4,
	FindMinimumBinaryTreeItem = 5,
	ExitBinaryTreeItem = 6
};

void DisplayBinaryTreeMenuAction()
{
	BinaryTree* binaryTree = new BinaryTree;
	binaryTree->Root = nullptr;
	bool exitBinaryTree = true;
	while (exitBinaryTree)
	{
		if (binaryTree->Root != nullptr)
		{
			cout << endl;
			PrintBinaryTree(binaryTree->Root, 0);
			cout << endl;
		}
		cout << "\nЧто вы хотите сделать?\n";
		cout << "1. Добавление элемента\n";
		cout << "2. Удаление элемента\n";
		cout << "3. Поиск элемента\n";
		cout << "4. Поиск максимума дерева\n";
		cout << "5. Поиск минимума дерева\n";
		cout << "6. Возвращение в главное меню\n";
		cout << "\nВведите ваш вариант действий: ";
		int localNumber = ReadingCorrectValue();
		switch (localNumber)
		{
			case AddBinaryTreeItem:
			{
				cout << "Введите ключ элемента: ";
				int key = ReadingCorrectValue();
				BinaryTreeNode* findNode = FindElement(binaryTree->Root, key);
				if (findNode == nullptr)
				{
					AddElementBinaryTree(binaryTree, binaryTree->Root, nullptr, key);
				}
				else
				{
					cout << "\nЭлемент с таким ключом присутствует в дереве\n";
				}
				system("pause");
				break;
			}
			case DeleteBinaryTreeItem:
			{
				if (InformAboutTreeFullness(binaryTree))
				{
					break;
				}
				cout << "Введите ключ элемента: ";
				int key = ReadingCorrectValue();
				BinaryTreeNode* findNode = FindElement(binaryTree->Root, key);
				if (findNode == nullptr)
				{
					cout << "\nДанного элемента нет в дереве\n";
				}
				else
				{
					DeleteElementBinaryTree(binaryTree, binaryTree->Root, nullptr, key);
				}
				system("pause");
				break;
			}
			case FindBinaryTreeItem:
			{
				if (InformAboutTreeFullness(binaryTree))
				{
					break;
				}
				cout << "Введите ключ элемента: ";
				int key = ReadingCorrectValue();
				BinaryTreeNode* findNode = FindElement(binaryTree->Root, key);
				if (findNode == nullptr)
				{
					cout << "\nЭлемент не найден\n";
				}
				else
				{
					cout << "\nЭлемент найден\n";
				}
				system("pause");
				break;
			}
			case FindMaximumBinaryTreeItem:
			{
				if (InformAboutTreeFullness(binaryTree))
				{
					break;
				}
				BinaryTreeNode* maximum = FindMaximumElement(binaryTree->Root);
				cout << "Максимальный элемент дерева: " << maximum->Key;
				cout << endl;
				system("pause");
				break;
			}
			case FindMinimumBinaryTreeItem:
			{
				if (InformAboutTreeFullness(binaryTree))
				{
					break;
				}
				BinaryTreeNode* minimum = FindMinimumElement(binaryTree->Root);
				cout << "Минимальный элемент дерева: " << minimum->Key;
				cout << endl;
				system("pause");
				break;
			}
			case ExitBinaryTreeItem:
			{
				if (binaryTree->Root != nullptr)
				{
					DeleteBinaryTree(binaryTree->Root);
				}
				exitBinaryTree = false;
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
}