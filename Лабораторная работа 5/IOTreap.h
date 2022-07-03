#pragma once
#include "TreapNode.h"
#include "Treap.h"

/// @brief �������, ��������� ���� ��������������
/// � ���������� �������
void DisplayTreapMenuActions();

/// @brief ������� ������������� ���������� ����������� ������
/// @param key ���� ����
/// @param priority ��������� ����
void InitializeParametr(int& key, int& priority);

/// @brief ������� �� �������� ������� ����� � ������
/// @param treap ���������� ��������� ���������� ������
/// @param key ����, ��������� �������������
/// @return ���������� ����������� � ������� ��� ���������� �����
bool CheckExistenceKey(Treap* treap, int key);

/// @brief �������, ��������� � ������������� ������
/// @param treap ���������� ��������� ����������� ������
/// @return ���������� ������ ��� ��� (����� �� ������)
bool InformAboutTreeFullness(Treap* treap);

/// @brief ������� ������ ��������� ������ �� �����
/// @param node ���������� ��������� ���� ��������� ������
/// @param level "�������" ��� ������ ������������� ��������
///  �� ������ ������
void PrintTreap(TreapNode* node, int level);