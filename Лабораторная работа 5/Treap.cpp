#include <iostream>
#include "TreapNode.h"
#include "Treap.h"

using namespace std;

TreapNode* InitializeTreapNode(TreapNode* node, int key, int priority, 
									TreapNode* left, TreapNode* right)
{
	node = new TreapNode;
	node->Key = key;
	node->Priority = priority;
	node->Left = left;
	node->Right = right;
	return node;
}


void Split(TreapNode* node, int key, TreapNode*& left, TreapNode*& right)
{
	if (node == nullptr)
	{
		left = right = nullptr;
	}
	else if (key >= node->Key)
	{
		Split(node->Right, key, node->Right, right);
		left = node;
	}
	else if (key < node->Key)
	{
		Split(node->Left, key, left, node->Left);
		right = node;
	}
}

TreapNode* Merge(TreapNode* left, TreapNode* right)
{
	if (left == nullptr)
	{
		return right;
	}
	if (right == nullptr)
	{
		return left;
	}
	if (left->Priority > right->Priority)
	{
		left->Right = Merge(left->Right, right);
		return left;
	}
	else
	{
		right->Left = Merge(left, right->Left);
		return right;
	}
}

void UnoptimizedAddElement(Treap* treap, int key, int priority)
{
	TreapNode* left = nullptr;
	TreapNode* right = nullptr;
	Split(treap->Root, key, left, right);
	TreapNode* newNode = nullptr;
	newNode = InitializeTreapNode(newNode, key, priority, nullptr, nullptr);
	left = Merge(left, newNode);
	treap->Root = Merge(left, right);
}

void OptimizedAddElement(Treap* treap, TreapNode* node, 
								TreapNode* parent, int key, int priority)
{
	if (node == nullptr)
	{
		node = InitializeTreapNode(node, key, priority, nullptr, nullptr);
		if (treap->Root == nullptr)
		{
			treap->Root = node;
		}
		else if (parent != nullptr)
		{
			if (node->Key > parent->Key)
			{
				parent->Right = node;
			}
			else
			{
				parent->Left = node;
			}
		}
		return;
	}
	else if (node->Priority < priority)
	{
		TreapNode* left = nullptr;
		TreapNode* right = nullptr;
		Split(node, key, left, right);
		TreapNode* newNode = nullptr; 
		newNode = InitializeTreapNode(newNode, key, priority, left, right);
		if (parent != nullptr)
		{
			if (parent->Left == node)
			{
				parent->Left = newNode;
			}
			else
			{
				parent->Right = newNode;
			}
		}
		else
		{
			treap->Root = newNode;
		}
		return;
	}
	else if (key < node->Key)
	{
		return OptimizedAddElement(treap, node->Left, node, key, priority);
	}
	else if (key > node->Key)
	{
		return OptimizedAddElement(treap, node->Right, node, key, priority);
	}
}

void UnoptimizedDeleteElement(Treap* treap, int key)
{
	TreapNode* left = nullptr;
	TreapNode* right = nullptr;
	Split(treap->Root, key, left, right);
	TreapNode* newLeft = nullptr;
	TreapNode* newRight = nullptr;
	Split(left, key - 1, newLeft, newRight);	
	treap->Root = Merge(newLeft, right);
	delete newRight;
}

void OptimizedDeleteElement(Treap* treap, TreapNode* node, 
									TreapNode* parent, int key)
{
	if (key < node->Key)
	{
		return OptimizedDeleteElement(treap, node->Left, node, key);
	}
	else if (key > node->Key)
	{
		return OptimizedDeleteElement(treap, node->Right, node, key);
	}
	else
	{
		TreapNode* newNode = Merge(node->Left, node->Right);		
		if (parent != nullptr)
		{
			if (parent->Left == node)
			{
				parent->Left = newNode;
			}
			else
			{
				parent->Right = newNode;
			}
		}
		else
		{
			treap->Root = newNode;
		}		
		delete node;
		return;
	}
}

TreapNode* FindElement(TreapNode* node, int key)
{
	if (node == nullptr)
	{
		return nullptr;
	}
	if (node->Key == key)
	{
		return node;
	}
	if (key < node->Key)
	{
		return FindElement(node->Left, key);
	}
	else
	{
		return FindElement(node->Right, key);
	}
}

void DeleteTreap(TreapNode* node)
{
	if (node == nullptr)
	{
		return;
	}
	DeleteTreap(node->Left);
	DeleteTreap(node->Right);
	delete node;
}