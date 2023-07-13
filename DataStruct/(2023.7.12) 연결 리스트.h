#pragma once
#include <iostream>

typedef struct Node
{
	int data;
	struct Node* next;
}Node;

void AddNode(Node* target, int data)
{
	// 1. Node ����
	Node* NewNode = new Node;

	// 2. ���ο� ����� data ���� �����մϴ�.
	NewNode->data = data;

	// 3. ���ο� ����� next �����Ϳ� nullptr�� ������ �ִ� �����͸� �����մϴ�.
	NewNode->next = target->next;

	// 4. ���� ����� ���� �ּҿ� ���ο� ����� �ּҸ� �����մϴ�.
	target->next = NewNode;

}

void ShowNode(Node* targetPtr)
{
	Node* currentPtr = targetPtr;

	currentPtr = targetPtr;

	while (currentPtr != nullptr)
	{
		currentPtr = currentPtr->next;
		if (currentPtr != nullptr)
		{
			std::cout << currentPtr->data << std::endl;
		}
	}
}

void RemoveNode(Node* target)
{
	// 1. ������ ����� �����͸� ������ ����
	Node* deletePtr = target->next;

	// 2. target ����� next�� �����Ǵ� ����� �����ּҷ� ����Ű�� �մϴ�.
	target->next = deletePtr->next;

	// 3. �ش� ��带 �����մϴ�.
	delete deletePtr;
}

void ReleaseNode(Node* target)
{
	Node* curPtr = target;

	while (curPtr != nullptr)
	{
		Node* nextPtr = curPtr->next;

		delete curPtr;

		curPtr = nextPtr;
	}
}

int main()
{
	// ���� ���� ����Ʈ
	/*
	//          [dummy Node]
	Node* dummy = new Node;
	//          [node1 Node]
	Node* node1 = new Node;
	//          [node2 Node]
	Node* node2 = new Node;

	// 1. dummy�� next ������ <- node1�� ���� �ּ�
	dummy->next = node1;

	// 2. node1�� data ���� 10���� �ʱ�ȭ
	node1->data = 10;

	// 3. node1�� next ������ <- node2�� ���� �ּ�
	node1->next = node2;

	// 4. node2�� data ���� 20���� �ʱ�ȭ
	node2->data = 20;

	// 5. node2�� next �����ʹ� nullptr�� �����մϴ�.
	node2->next = nullptr;

	ShowNode(dummy);

	AddNode(dummy, 30);

	delete dummy;
	delete node1;
	delete node2;
	*/

	// ���� ���� ����Ʈ (�Լ�)
	Node* dummy = new Node;

	dummy->next = nullptr;

	AddNode(dummy, 10);
	AddNode(dummy, 20);
	AddNode(dummy, 30);

	// dummy->next

	// ShowNode(dummy);

	RemoveNode(dummy->next);

	ShowNode(dummy);

	ReleaseNode(dummy);


	return 0;
}


