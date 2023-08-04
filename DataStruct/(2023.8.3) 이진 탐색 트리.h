#pragma once
#include <iostream>

struct Node
{
	int data;
	Node* left;
	Node* right;
};

Node* Insert(Node* root, int data)
{
	if (root == nullptr) // root�� nullptr �̶��
	{
		root = new Node;
		root->data = data;
		root->left = nullptr;
		root->right = nullptr;
	}
	else if (data <= root->data)	// else if root�� data���� �۴ٸ�?
	{
		root->left = Insert(root->left, data);
	}
	else 	// else root�� data���� ũ�ٸ� ?
	{
		root->right = Insert(root->right, data);
	}

	return root;
}

int FindMax(Node* root)
{
	if (root == nullptr)
	{
		std::cout << "���� �����Ͱ� �������� �ʽ��ϴ�." << std::endl;
		return 0xcccccccc;
	}

	if (root->right == nullptr)
	{
		return root->data;
	}
	else
	{
		return FindMax(root->right);
	}
}

int FindMin(Node* root)
{
	if (root == nullptr)
	{
		std::cout << "���� �����Ͱ� �������� �ʽ��ϴ�." << std::endl;
		return 0xcccccccc;
	}

	if (root->left == nullptr)
	{
		return root->data;
	}
	else
	{
		return FindMin(root->left);
	}
}

Node* DeleteNode(Node* root, int key)
{
	if (root == nullptr)
	{
		std::cout << "���� �����Ͱ� �������� �ʽ��ϴ�." << std::endl;
		return nullptr;
	}

	if (key < root->data)
	{
		root->left = DeleteNode(root->left, key);
	}
	else if (key > root->data)
	{
		root->right = DeleteNode(root->right, key);
	}
	else
	{
		struct Node* temp;

		if (root->left == nullptr)
		{
			temp = root->right;
			delete root;
			return temp;
		}
		else if (root->right == nullptr)
		{
			temp = root->left;
			delete root;
			return temp;
		}
		// �ڽ� ��尡 �� �� �ִ� ���
		temp = minValueNode(root->right);

		// ������ NODE�� �����͸� �ٲߴϴ�.
		root->data = temp->data;

		// ��带 �����մϴ�.
		root->right = DeleteNode(root->right, temp->data);

	}
}

struct Node* minValueNode(Node* node)
{
	Node* currentNode = node;

	while (currentNode && currentNode->left == nullptr)
	{
		currentNode = currentNode->left;
	}

	return currentNode;
}
#pragma region ���� Ž�� Ʈ�� (BST)
// ������ Ű�� ���� ���Ҹ� ����, ����, �˻��ϴµ�
// ȿ������ Ʈ���Դϴ�.

// root ��带 �������� root ��庸��
// ���� ������ ���� �ڽĿ� ��ġ�մϴ�.

// root ��带 �������� root ��庸��
// ū ������ ������ �ڽ����� ��ġ�մϴ�.

// Insert()

// FindMax()

// FindMin()

#pragma endregion


int main()
{
	Node* root = nullptr;

	root = Insert(root, 10); // 0x00000239e8bf3a10 
	root = Insert(root, 5);

	std::cout << FindMax(root) << std::endl;
	std::cout << FindMin(root) << std::endl;

	return 0;
}