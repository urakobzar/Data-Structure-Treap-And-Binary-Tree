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
		cout << "\n������ �����\n";
		cout << "����������� � ����\n";
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
		cout << "\n��� �� ������ �������?\n";
		cout << "1. ���������� ��������\n";
		cout << "2. �������� ��������\n";
		cout << "3. ����� ��������\n";
		cout << "4. ����� ��������� ������\n";
		cout << "5. ����� �������� ������\n";
		cout << "6. ����������� � ������� ����\n";
		cout << "\n������� ��� ������� ��������: ";
		int localNumber = ReadingCorrectValue();
		switch (localNumber)
		{
			case AddBinaryTreeItem:
			{
				cout << "������� ���� ��������: ";
				int key = ReadingCorrectValue();
				BinaryTreeNode* findNode = FindElement(binaryTree->Root, key);
				if (findNode == nullptr)
				{
					AddElementBinaryTree(binaryTree, binaryTree->Root, nullptr, key);
				}
				else
				{
					cout << "\n������� � ����� ������ ������������ � ������\n";
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
				cout << "������� ���� ��������: ";
				int key = ReadingCorrectValue();
				BinaryTreeNode* findNode = FindElement(binaryTree->Root, key);
				if (findNode == nullptr)
				{
					cout << "\n������� �������� ��� � ������\n";
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
				cout << "������� ���� ��������: ";
				int key = ReadingCorrectValue();
				BinaryTreeNode* findNode = FindElement(binaryTree->Root, key);
				if (findNode == nullptr)
				{
					cout << "\n������� �� ������\n";
				}
				else
				{
					cout << "\n������� ������\n";
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
				cout << "������������ ������� ������: " << maximum->Key;
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
				cout << "����������� ������� ������: " << minimum->Key;
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
				cout << "� ���������, �� ��������\n";
				cout << "����������, ������� ������\n\n";
				system("pause");
				break;
			}
		}
	}
}