#pragma once

struct Treap
{
	TreapNode* Root;
};

/// @brief Функция инициализации узла Декартового дерева
/// @param node Переменная структуры узла Декартового дерева
/// @param key Ключ, введенный пользователем
/// @param priority Приоретет, даннный случайным образом
/// @param left Адрес левого поддерева
/// @param right Адрес правого поддерева
/// @return Адрес узла
TreapNode* InitializeTreapNode(TreapNode* node, int key, int priority, TreapNode* left, TreapNode* right);

/// @brief Функция разрезания Декартового Дерева
/// @param node 
/// @param key Ключ, по которому идет разрез
/// @param left Адрес левого поддерева
/// @param right Адрес правого поддерева
void Split(TreapNode* node, int key, TreapNode*& left, TreapNode*& right);

/// @brief Функция слияния Декартовых Деревьев
/// @param left Адрес левого поддерева
/// @param right Адрес правого поддерева
/// @return Адрес корня дерева после слияния
TreapNode* Merge(TreapNode* left, TreapNode* right);

/// @brief Функция неоптимизированного добавления элемента
/// @param treap Переменная структуры Декартового дерева
/// @param key Добавляемый элемент
/// @param priority Добавляемый приоритет элемента
void UnoptimizedAddElement(Treap* treap, int key, int priority);

/// @brief Функция оптимизированного добавления элемента
/// @param treap Переменная структуры Декартового дерева
/// @param node Переменная структуры узла Декартового дерева
/// @param parent Адрес узла "Родителя"
/// @param key Добавляемый элемент
/// @param priority Добавляемый приоритет элемента
void OptimizedAddElement(Treap* treap, TreapNode* node, TreapNode* parent, int key, int priority);

/// @brief Функция неоптимизированного удаления элемента
/// @param treap Переменная структуры Декартового дерева
/// @param key Удаляемый элемент
void UnoptimizedDeleteElement(Treap* treap, int key);

/// @brief Функция оптимизированного удаления элемента
/// @param treap Переменная структуры Декартового дерева
/// @param node Переменная структуры узла Декартового дерева
/// @param parent Адрес узла "Родителя"
/// @param key Удаляемый элемент
void OptimizedDeleteElement(Treap* treap, TreapNode* node, TreapNode* parent, int key);

/// @brief Функция поиска элемента в Декартовом дереве
/// @param node Переменная структуры узла Декартового дерева
/// @param key Ключ, по которому идет поиск
/// @return Адрес узла, содержащий элемент
TreapNode* FindElement(TreapNode* node, int key);

/// @brief Функция удаления Декартового дерева
/// @param node Переменная структуры узла Декартового дерева
void DeleteTreap(TreapNode* node);