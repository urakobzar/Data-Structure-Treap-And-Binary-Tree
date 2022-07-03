#pragma once
#include "TreapNode.h"
#include "Treap.h"

/// @brief Функция, выводящая Меню взаимодействия
/// с Декартовым деревом
void DisplayTreapMenuActions();

/// @brief Функция инициализации параметров Декартового Дерева
/// @param key Ключ узла
/// @param priority Приоритет узла
void InitializeParametr(int& key, int& priority);

/// @brief Функция на проверку наличия Ключа в Дереве
/// @param treap Переменная структуры Декартовое Дерево
/// @param key Ключ, введенный пользователем
/// @return Возвращает уведомление о наличие или отсутствии Ключа
bool CheckExistenceKey(Treap* treap, int key);

/// @brief Функция, говорящая о заполненности Дерева
/// @param treap Переменная структуры Декартового Дерева
/// @return Существует корень или нет (Пусто ли дерево)
bool InformAboutTreeFullness(Treap* treap);

/// @brief Функция вывода Бинарного Дерева на экран
/// @param node Переменная структуры узла Бинарного Дерева
/// @param level "Уровень" для вывода определенного элемента
///  на нужной строке
void PrintTreap(TreapNode* node, int level);