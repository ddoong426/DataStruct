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
	if (root == nullptr) // root가 nullptr 이라면
	{
		root = new Node;
		root->data = data;
		root->left = nullptr;
		root->right = nullptr;
	}
	else if (data <= root->data)	// else if root의 data보다 작다면?
	{
		root->left = Insert(root->left, data);
	}
	else 	// else root의 data보다 크다면 ?
	{
		root->right = Insert(root->right, data);
	}

	return root;
}

int FindMax(Node* root)
{
	if (root == nullptr)
	{
		std::cout << "현재 데이터가 존재하지 않습니다." << std::endl;
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
		std::cout << "현재 데이터가 존재하지 않습니다." << std::endl;
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
		std::cout << "현재 데이터가 존재하지 않습니다." << std::endl;
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
		// 자식 노드가 두 개 있는 경우
		temp = minValueNode(root->right);

		// 삭제할 NODE의 데이터를 바꿉니다.
		root->data = temp->data;

		// 노드를 삭제합니다.
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
#pragma region 이진 탐색 트리 (BST)
// 임의의 키를 가진 원소를 삽입, 삭제, 검색하는데
// 효율적인 트리입니다.

// root 노드를 기준으로 root 노드보다
// 작은 노드들은 왼쪽 자식에 배치합니다.

// root 노드를 기준으로 root 노드보다
// 큰 노드들은 오른쪽 자식으로 배치합니다.

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