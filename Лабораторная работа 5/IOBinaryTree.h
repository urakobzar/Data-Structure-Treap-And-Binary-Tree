#pragma once
#include "BinaryTree.h"
#include "BinaryTreeNode.h"

/// @brief �������, ��������� ���� ��������������
/// � �������� �������
void DisplayBinaryTreeMenuAction();

/// @brief �������, ��������� � ������������� ������
/// @param binaryTree ���������� ��������� ����������� ������
/// @return ���������� ������ ��� ��� (����� �� ������)
bool InformAboutTreeFullness(BinaryTree* binaryTree);

/// @brief ������� ������ ��������� ������ �� �����
/// @param node ���������� ��������� ���� ��������� ������
/// @param level "�������" ��� ������ ������������� ��������
///  �� ������ ������
void PrintBinaryTree(BinaryTreeNode* node, int level);