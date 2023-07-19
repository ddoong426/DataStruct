#pragma once
#include <iostream>

template <typename T>
struct Node
{
	T data;
	Node<T>* next;
	Node<T>* prev;
};

template <typename T>
class DoubleLinkedList
{
private:
	Node<T>* head;
	Node<T>* tail;

public:
	DoubleLinkedList()
	{
		head = nullptr;
		tail = nullptr;

	}

	void Push_Front(T data)
	{
		Node<T>* newNode = new Node<T>;

		newNode->data = data;

		newNode->next = nullptr;

		newNode->prev = nullptr;

		if (head == nullptr)
		{
			head = newNode;
			tail = newNode;
		}
		else
		{
			newNode->next = head;

			head->prev = newNode;

			head = newNode;
		}
	}

	void Push_Back(T data)
	{
		Node<T>* NewNode = new Node<T>;

		NewNode->data = data;

		NewNode->next = nullptr;

		NewNode->prev = nullptr;

		if (head == nullptr)
		{
			head = NewNode;
			tail = NewNode;
		}
		else
		{
			tail->next = NewNode;
			NewNode->prev = tail;

			tail = NewNode;
		}
	}

	void Pop_Front()
	{
		if (head == nullptr)
		{
			return;
		}
		else
		{
			Node<T>* RemovePtr = head;

			head = head->next;

			head->prev = nullptr;

			delete RemovePtr;
		}
	}

	void Pop_Back()
	{
		if (head == nullptr)
		{
			return;
		}
		else
		{
			Node<T>* RemovePtr = tail;

			tail = tail->prev;

			tail->next = nullptr;

			delete RemovePtr;
		}
	}

	~DoubleLinkedList()
	{
		while (head != nullptr)
		{
			Node<T>* RemovePtr = head;

			head = head->next;

			delete RemovePtr;
		}
	}
};
int main()
{
	DoubleLinkedList<int> list;

	list.Push_Back(10);
	list.Push_Back(10);
	list.Push_Back(10);
	list.Push_Back(10);
	list.Push_Back(10);
	list.Push_Back(10);

	return 0;
}


