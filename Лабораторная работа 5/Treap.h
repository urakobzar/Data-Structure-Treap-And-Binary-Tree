#pragma once

struct Treap
{
	TreapNode* Root;
};

/// @brief ������� ������������� ���� ����������� ������
/// @param node ���������� ��������� ���� ����������� ������
/// @param key ����, ��������� �������������
/// @param priority ���������, ������� ��������� �������
/// @param left ����� ������ ���������
/// @param right ����� ������� ���������
/// @return ����� ����
TreapNode* InitializeTreapNode(TreapNode* node, int key, int priority, TreapNode* left, TreapNode* right);

/// @brief ������� ���������� ����������� ������
/// @param node 
/// @param key ����, �� �������� ���� ������
/// @param left ����� ������ ���������
/// @param right ����� ������� ���������
void Split(TreapNode* node, int key, TreapNode*& left, TreapNode*& right);

/// @brief ������� ������� ���������� ��������
/// @param left ����� ������ ���������
/// @param right ����� ������� ���������
/// @return ����� ����� ������ ����� �������
TreapNode* Merge(TreapNode* left, TreapNode* right);

/// @brief ������� ������������������� ���������� ��������
/// @param treap ���������� ��������� ����������� ������
/// @param key ����������� �������
/// @param priority ����������� ��������� ��������
void UnoptimizedAddElement(Treap* treap, int key, int priority);

/// @brief ������� ����������������� ���������� ��������
/// @param treap ���������� ��������� ����������� ������
/// @param node ���������� ��������� ���� ����������� ������
/// @param parent ����� ���� "��������"
/// @param key ����������� �������
/// @param priority ����������� ��������� ��������
void OptimizedAddElement(Treap* treap, TreapNode* node, TreapNode* parent, int key, int priority);

/// @brief ������� ������������������� �������� ��������
/// @param treap ���������� ��������� ����������� ������
/// @param key ��������� �������
void UnoptimizedDeleteElement(Treap* treap, int key);

/// @brief ������� ����������������� �������� ��������
/// @param treap ���������� ��������� ����������� ������
/// @param node ���������� ��������� ���� ����������� ������
/// @param parent ����� ���� "��������"
/// @param key ��������� �������
void OptimizedDeleteElement(Treap* treap, TreapNode* node, TreapNode* parent, int key);

/// @brief ������� ������ �������� � ���������� ������
/// @param node ���������� ��������� ���� ����������� ������
/// @param key ����, �� �������� ���� �����
/// @return ����� ����, ���������� �������
TreapNode* FindElement(TreapNode* node, int key);

/// @brief ������� �������� ����������� ������
/// @param node ���������� ��������� ���� ����������� ������
void DeleteTreap(TreapNode* node);