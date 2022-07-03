#pragma once
#include "BinaryTree.h"
#include "BinaryTreeNode.h"

/// @brief Функция, выводящая Меню взаимодействия
/// с Бинарным Деревом
void DisplayBinaryTreeMenuAction();

/// @brief Функция, говорящая о заполненности Дерева
/// @param binaryTree Переменная структуры Декартового Дерева
/// @return Существует корень или нет (Пусто ли дерево)
bool InformAboutTreeFullness(BinaryTree* binaryTree);

/// @brief Функция вывода Бинарного Дерева на экран
/// @param node Переменная структуры узла Бинарного Дерева
/// @param level "Уровень" для вывода определенного элемента
///  на нужной строке
void PrintBinaryTree(BinaryTreeNode* node, int level);