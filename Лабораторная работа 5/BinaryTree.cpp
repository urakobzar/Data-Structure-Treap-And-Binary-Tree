#include "BinaryTree.h"

BinaryTreeNode* InitializeBinaryTree(BinaryTreeNode* node, int key)
{
	node = new BinaryTreeNode;
	node->Key = key;
	node->Left = nullptr;
	node->Right = nullptr;
	return node;
}

BinaryTreeNode* FindElement(BinaryTreeNode* node, int key)
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

BinaryTreeNode* FindMaximumElement(BinaryTreeNode* node)
{
	if (node == nullptr)
	{
		return nullptr;
	}
	while (node->Right != nullptr)
	{
		node = node->Right;
	}
	return node;
}

BinaryTreeNode* FindMinimumElement(BinaryTreeNode* node)
{
	if (node == nullptr)
	{
		return nullptr;
	}
	while (node->Left != nullptr)
	{
		node = node->Left;
	}
	return node;
}

void AddElementBinaryTree(BinaryTree* tree, BinaryTreeNode* node, 
										BinaryTreeNode* parent, int key)
{
	if (node == nullptr)
	{
		node = InitializeBinaryTree(node, key);
		if (tree->Root == nullptr)
		{
			tree->Root = node;
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
	else if (key < node->Key)
	{
		return AddElementBinaryTree(tree, node->Left, node, key);
	}
	else if (key > node->Key)
	{
		return AddElementBinaryTree(tree, node->Right, node, key);
	}
}


void DeleteActionsWhenChildNodeExist(BinaryTree* tree, BinaryTreeNode* node, 
										BinaryTreeNode* oldNode, BinaryTreeNode* oldParent)
{
	if (oldParent != nullptr)
	{
		if (oldParent->Left == oldNode)
		{
			oldParent->Left = node;
		}
		else
		{
			oldParent->Right = node;
		}
	}
	else
	{
		tree->Root = node;
	}
}


void DeleteElementBinaryTree(BinaryTree* tree, BinaryTreeNode* node,
										BinaryTreeNode* parent, int key)
{
	if (key < node->Key)
	{
		return DeleteElementBinaryTree(tree, node->Left, node, key);
	}
	else if (key > node->Key)
	{
		return DeleteElementBinaryTree(tree, node->Right, node, key);
	}
	if (node->Left == nullptr && node->Right == nullptr)
	{
		if (parent != nullptr)
		{
			if (parent->Left == node)
			{
				parent->Left = nullptr;
			}
			else
			{
				parent->Right = nullptr;
			}
		}
		else
		{
			tree->Root = nullptr;
		}
		delete node;
	}
	else if (node->Left != nullptr && node->Right == nullptr)
	{
		BinaryTreeNode* oldNode = node;
		BinaryTreeNode* oldParent = parent;
		node = node->Left;
		DeleteActionsWhenChildNodeExist(tree, node, oldNode, oldParent);
		delete oldNode;
	}
	else if (node->Right != nullptr && node->Left == nullptr)
	{
		BinaryTreeNode* oldNode = node;
		BinaryTreeNode* oldParent = parent;
		node = node->Right;
		DeleteActionsWhenChildNodeExist(tree, node, oldNode, oldParent);
		delete oldNode;
	}
	else
	{
		BinaryTreeNode* oldNode = node;
		node = FindMinimumElement(oldNode->Right);
		int minimum = node->Key;
		DeleteElementBinaryTree(tree, tree->Root, nullptr, minimum);
		oldNode->Key = minimum;
	}
}


void DeleteBinaryTree(BinaryTreeNode* node)
{
	if (node == nullptr)
	{
		return;
	}
	DeleteBinaryTree(node->Left);
	DeleteBinaryTree(node->Right);
	delete node;
}

