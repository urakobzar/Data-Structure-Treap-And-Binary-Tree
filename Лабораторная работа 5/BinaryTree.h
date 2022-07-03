#pragma once
#include "BinaryTreeNode.h"

struct BinaryTree
{
	BinaryTreeNode* Root;
};

/// @brief Функция инициализации полей стуктуры узла Бинарного Дерева
/// @param node Переменная структуры узла Бинарного Дерева
/// @param key Ключ, введенный пользователем
/// @return Возвращает адрес узла
BinaryTreeNode* InitializeBinaryTree(BinaryTreeNode* node, int key);

/// @brief Функция поиска элемента в Бинарном Дереве
/// @param node Переменная структуры узла Бинарного Дерева
/// @param key Искомый ключ, введенный пользователем
/// @return Возвращает адрес искомого элемента
BinaryTreeNode* FindElement(BinaryTreeNode* node, int key);

/// @brief Функция поиска максимального элемента в Бинарном Дереве
/// @param node Переменная структуры узла Бинарного Дерева
/// @return Возвращает адрес искомого элемента
BinaryTreeNode* FindMaximumElement(BinaryTreeNode* node);

/// @brief Функция поиска минимального элемента в Бинарном Дереве
/// @param node Переменная структуры узла Бинарного Дерева
/// @return Возвращает адрес искомого элемента
BinaryTreeNode* FindMinimumElement(BinaryTreeNode* node);

/// @brief Функция добавления элемента в Бинарного Дерево
/// @param node Переменная структуры узла Бинарного Дерева
/// @param tree Переменная структуры Бинарного Дерева
/// @param key Добавляемый элемент в Бинарного дерево
void AddElementBinaryTree(BinaryTree* tree, BinaryTreeNode* node, BinaryTreeNode*  parent, int key);

/// @brief Функция удаления элемента из Бинарного Дерева 
/// @param tree Переменная структуры Бинарного Дерева
/// @param node Переменная структуры узла Бинарного Дерева
void DeleteElementBinaryTree(BinaryTree* tree, BinaryTreeNode* node, BinaryTreeNode* parent, int key);

/// @brief Функция удаления Бинарного Дерева
/// @param node Переменная структуры узла Бинарного Дерева
void DeleteBinaryTree(BinaryTreeNode* node);
