#pragma once
#include "BinaryTreeNode.h"

struct BinaryTree
{
	BinaryTreeNode* Root;
};

/// @brief ������� ������������� ����� �������� ���� ��������� ������
/// @param node ���������� ��������� ���� ��������� ������
/// @param key ����, ��������� �������������
/// @return ���������� ����� ����
BinaryTreeNode* InitializeBinaryTree(BinaryTreeNode* node, int key);

/// @brief ������� ������ �������� � �������� ������
/// @param node ���������� ��������� ���� ��������� ������
/// @param key ������� ����, ��������� �������������
/// @return ���������� ����� �������� ��������
BinaryTreeNode* FindElement(BinaryTreeNode* node, int key);

/// @brief ������� ������ ������������� �������� � �������� ������
/// @param node ���������� ��������� ���� ��������� ������
/// @return ���������� ����� �������� ��������
BinaryTreeNode* FindMaximumElement(BinaryTreeNode* node);

/// @brief ������� ������ ������������ �������� � �������� ������
/// @param node ���������� ��������� ���� ��������� ������
/// @return ���������� ����� �������� ��������
BinaryTreeNode* FindMinimumElement(BinaryTreeNode* node);

/// @brief ������� ���������� �������� � ��������� ������
/// @param node ���������� ��������� ���� ��������� ������
/// @param tree ���������� ��������� ��������� ������
/// @param key ����������� ������� � ��������� ������
void AddElementBinaryTree(BinaryTree* tree, BinaryTreeNode* node, BinaryTreeNode*  parent, int key);

/// @brief ������� �������� �������� �� ��������� ������ 
/// @param tree ���������� ��������� ��������� ������
/// @param node ���������� ��������� ���� ��������� ������
void DeleteElementBinaryTree(BinaryTree* tree, BinaryTreeNode* node, BinaryTreeNode* parent, int key);

/// @brief ������� �������� ��������� ������
/// @param node ���������� ��������� ���� ��������� ������
void DeleteBinaryTree(BinaryTreeNode* node);
