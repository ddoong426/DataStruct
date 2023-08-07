#include <iostream>

#pragma region 원형 연결 리스트
// 단순 연결 리스트에서 마지막 노드가
// 리스트의 첫 번째 노드를 가리키는 리스트 구조를
// 원형으로 만든 리스트입니다.

struct Node
{
	int data;
	Node* next;
};

class CircleLinkedList
{
private:
	int count;

public:
	CircleLinkedList(int m_count = 1)
	{
		count = m_count;
	};

	Node * Push_Front(Node* head,int data)
	{
		// 1. 새로운 노드를 생성합니다.
		Node* newNode = new Node;

		// 2. 새로운 노드에 데이터를 넣습니다.
		newNode->data = data;

		// 3. if(만약에 head가 nullptr이라면?)
		if (head == nullptr)
		{
			// head 포인터는 새로운 노드의 주소를 저장합니다.
			// 새로운 노드의 next가 자기 자신을 가르켜야 합니다.
			head = newNode;
			newNode->next = head;
		}
		else
		{
			// 새로운 노드의 next는 head를 가리키게 합니다.
			newNode->next = head->next;

			// head의 next는 새로운 노드를 가리키게 합니다.
			head->next = newNode;
		}

		return head;
	}

	Node* Push_Back(Node* head, int data)
	{
		Node* newNode = new Node;

		newNode->data = data;

		if (head == nullptr)
		{
			// head 포인터는 새로운 노드의 주소를 저장합니다.
			// 새로운 노드의 next가 자기 자신을 가르켜야 합니다.
			head = newNode;
			newNode->next = head;
		}
		else
		{
			// 새로운 노드의 next에 head의 next변수를 저장합니다.
			newNode->next = head->next;
			// head 노드의 next가 새로운 노드의 주소를 가리킵니다.
			head->next = newNode;

			// head 포인터에 새로운 노드의 주소를 저장합니다.
			head = newNode;
		}

		return head;
	}

	void Information(Node * head)
	{
		if (head == nullptr)
		{
			return;
		}
		Node* CurrentNode = head->next;

		while (CurrentNode != head)
		{
			std::cout << CurrentNode->data << std::endl;
			CurrentNode = CurrentNode->next;
		}
		
		std::cout << CurrentNode->data << std::endl;
	}
};
#pragma endregion

int main()
{
	CircleLinkedList circlelinkedlist;

	Node* head = nullptr;

	head = circlelinkedlist.Push_Front(head, 20);
	head = circlelinkedlist.Push_Front(head, 10);

	head = circlelinkedlist.Push_Back(head, 30);

	circlelinkedlist.Information(head);

	return 0;
}