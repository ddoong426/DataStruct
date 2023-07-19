#pragma once
#include <iostream>


typedef struct Node
{
	int data;
	Node* next;
}Node;

class LinkedList
{
private:
	Node* head;
	Node* tail;

	int size;

public:

	LinkedList()
	{
		head = nullptr;
		tail = nullptr;

		size = 0;
	}

	void Push_Front(int data)
	{
		size++;
		// 1. 새로운 노드를 생성합니다
		Node* newNode = new Node;
		// 2. 새로운 노드의 data 값을 저장합니다. <- 매개변수로
		newNode->data = data;
		// 3. 새로운 노드의 next 값을 null로 합니다.
		newNode->next = nullptr;

		if (head == nullptr)
		{
			head = newNode;

			tail = newNode;
		}
		else
		{
			newNode->next = head;

			head = newNode;
		}

	}

	void Push_Back(int data)
	{
		size++;
		// 1. 새로운 노드를 생성합니다
		Node* newNode = new Node;
		// 2. 새로운 노드의 data 값을 저장합니다. <- 매개변수로
		newNode->data = data;
		// 3. 새로운 노드의 next 값을 null로 합니다.
		newNode->next = nullptr;

		if (head == nullptr)
		{
			head = newNode;

			tail = newNode;
		}
		else
		{
			tail->next = newNode;

			tail = newNode;
		}
	}

	int Size()
	{
		return size;
	}

	~LinkedList()
	{

	}

};

int main()
{
	LinkedList list;

	list.Push_Back(10);
	list.Push_Front(20);

	std::cout << list.Size() << std::endl;
	return 0;
}


