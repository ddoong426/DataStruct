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
		// 1. ���ο� ��带 �����մϴ�
		Node* newNode = new Node;
		// 2. ���ο� ����� data ���� �����մϴ�. <- �Ű�������
		newNode->data = data;
		// 3. ���ο� ����� next ���� null�� �մϴ�.
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
		// 1. ���ο� ��带 �����մϴ�
		Node* newNode = new Node;
		// 2. ���ο� ����� data ���� �����մϴ�. <- �Ű�������
		newNode->data = data;
		// 3. ���ο� ����� next ���� null�� �մϴ�.
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


