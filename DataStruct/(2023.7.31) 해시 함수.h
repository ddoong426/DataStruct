#pragma once
#include <iostream>

#define SIZE 10
#define SIZE2 5

int quickArray[SIZE] = { 4,1,2,3,9,7,8,6,10,5 };

//                �迭           0         9
void QuickSort(int data[], int start, int end)
{
	// ���Ұ� 1�� ���� ���
	if (start >= end)
	{
		return;
	}

	// pivot 
	// left
	// right

	int pivot = start;
	int left = start + 1;
	int right = end;

	while (left <= right)
	{
		// left�� end���� �۰ų� ���ٸ� �ݺ�
		// ���ʿ� �ִ� left������ pivot�� ���մϴ�.
		while (left <= end && quickArray[left] < quickArray[pivot])
		{
			left++;
		}

		// right�� start���� ũ�ٸ�
		// �����ʿ� �ִ� right ������ pivot�� ���մϴ�.
		while (right > start && quickArray[right] > quickArray[pivot])
		{
			right--;
		}
		// if ���ʰ� ������ �������� ��
		if (left > right)
		{
			std::swap(quickArray[pivot], quickArray[right]);
		}
		else // else right�� left�� ���� ��ȯ�մϴ�.
		{
			std::swap(quickArray[left], quickArray[right]);
		}
	}

	QuickSort(data, start, right - 1);
	QuickSort(data, right + 1, end);


}

struct Node
{
	int key;
	int value;

	Node* next;
};

struct Bucket
{
	Node* head;
	int count;
};

class HashTable
{
private:
	Bucket bucket[5];

public:
	HashTable()
	{
		for (int i = 0; i < 5; i++)
		{
			bucket[i].count = 0;
			bucket[i].head = nullptr;
		}
	}

	Node* CreateNode(int key, int value)
	{
		// 1. ���ο� ��带 �����մϴ�.
		Node* newNode = new Node;

		// 2. ���ο� ����� key���������մϴ�.
		newNode->key = key;

		// 3. ���ο� ����� value ���� �����մϴ�.
		newNode->value = value;

		// 4. ���ο� ����� next�� ���� �ʱ�ȭ�մϴ�.
		newNode->next = NULL;

		// 5. ���ο� ����� �ּ� ���� ��ȯ�մϴ�.
		return newNode;
	}

	int HashFuction(int key)
	{
		return key & 5;
	}

	void Insert(int key, int value)
	{
		// �ؽ� ���� �޴� ����
		int hashIndex = HashFuction(key);
		// ���ο� ��带 �����մϴ�.
		Node* newNode = CreateNode(key, value);
		// ��尡 1 ���� �������� ������
		if (bucket[hashIndex].count == 0)
		{
			// 1. bucket[hashIndex]�� head �����Ϳ� ���ο� ����� �ּڰ��� �����մϴ�.
			bucket[hashIndex].head = newNode;

			// 2. bucket[hashIndex]�� count ������ ���� �����մϴ�.
			bucket[hashIndex].count++;
		}
		else // ��尡 1 ���� �����ϸ�
		{
			// 1. newNode�� next�� bucket[hashIndex]�� head�� ���� �־��ݴϴ�.
			newNode->next = bucket[hashIndex].head;

			// 2. bucket[hashIndex].head�� ��� ���� ������ node�� �ּҸ� ����Ű���� �����մϴ�.
			bucket[hashIndex].head = newNode;

			// 3. bucket[hashIndex]�� count ������ ���� �����մϴ�.
			bucket[hashIndex].count++;
		}
	}

	void Remove(int key)
	{
		// �ؽ� ���� �޴� ����
		int hashIndex = HashFuction(key);
		// Node�� Ž���� �� �ִ� ��ȸ�� ������ ���� ���� <- �� bucket�� head ���� �����մϴ�.
		Node* currentNode = bucket[hashIndex].head;

		Node* traceNode = nullptr;
		// currentNode�� nullptr�̶�� �Լ��� �����մϴ�.
		if (currentNode == nullptr)
		{
			printf("���� ��尡 �������� �ʽ��ϴ�.");
			return;
		}

		// currentNode�� �̿��ؼ� ���� ã���ִ� key���� ã���� �˴ϴ�.
		while (currentNode != nullptr)
		{
			if (currentNode->key == key)
			{
				if (currentNode == bucket[hashIndex].head)
				{
					bucket[hashIndex].head = currentNode->next;
				}
				else
				{
					traceNode[hashIndex];
				}

				// �� bucket�� ī��Ʈ�� ���ҽ�ŵ�ϴ�.
				bucket[hashIndex].count--;

				// �ش��ϴ� �޸𸮸� �����մϴ�.
				delete currentNode;

				return;
			}

			traceNode = currentNode;
			currentNode = currentNode->next;
		}




	}

	void Search(int key)
	{
		// �ؽ� ���� �޴� ����
		int hashIndex = HashFuction(key);
		// Node�� Ž���� �� �ִ� ��ȸ�� ������ ���� ���� <- �� bucket�� head ���� �����մϴ�.
		Node* currentNode = bucket[hashIndex].head;

		// currentNode�� nullptr�̶�� �Լ��� �����մϴ�.
		if (currentNode == nullptr)
		{
			printf("���� ��尡 �������� �ʽ��ϴ�.");
			return;
		}

		// currentNode�� �̿��ؼ� ���� ã���ִ� key���� ã���� �˴ϴ�.
		while (currentNode != nullptr)
		{
			// �ش��ϴ� KEY���� �ִٸ� �Լ��� �����մϴ�.

			// �ش��ϴ� KEY���� VALUE���� ����մϴ�.
			if (currentNode->key == key)
			{
				std::cout << "KEY : " << currentNode->key << "VALUE : " << currentNode->value << std::endl;
				return;
			}

			// �ش��ϴ� KEY�� ���ٸ� ���� NODE�� �ּҸ� �����մϴ�.
			currentNode = currentNode->next;
		}
		std::cout << "ã���� �ϴ� KEY�� �������� �ʽ��ϴ�." << std::endl;
	}
};

int main()
{

#pragma region �� ����
	// �������� ȹ���� ���� �ش� �������� �������� �迭�� ������
	// �� �ʿ��� ���������� ���� �׸���� ��ġ�ϰ� �ٸ� �ʿ��� ���������� ū �׸���� ��ġ�մϴ�

	// �������� ���� �迭�� ���� ��������� �� ������ ȣ���Ͽ�,
	// ��� �迭�� �⺻ �迭(��Ұ� �ϳ����� �迭)�� �� ������ �ݺ��ϴ� �˰����Դϴ�.
	// QuickSort(quickArray, 0, SIZE - 1);
	// 
	// 
	// for (int i = 0; i < SIZE; i++)
	// {
	// 	std::cout << quickArray[i] << " ";
	// }


	// my code
	// ----------------------------------------------------
	// int array2[SIZE] = { 5,3,1,4,2,9,8,6,7 };
	// int Pivot = 0;
	// int Left = 0; // Pivot ������ ū ���� ã�´�.
	// int Right = SIZE - 1; // Pivot ������ ���� ���� ã�´�.
	// 
	// while (1)
	// {
	// 	if (array2[Right] < array2[Pivot])
	// 	{
	// 		Right--;
	// 	}
	// 
	// 	if (array2[Left] >= array2[Pivot])
	// 	{
	// 		Left++;
	// 	}
	// 
	// 	if (array2[Left] > array2[Pivot])
	// 	{
	// 		std::swap(array2[Left], array2[Right]);
	// 	}
	// 
	// 	if (Left > Right)
	// 	{
	// 		std::swap(array2[Pivot], array2[Right]);
	// 		break;
	// 	}
	// }
	// for (int i = 0; i < SIZE; i++)
	// {
	// 	std::cout << array2[i] << std::endl;
	// }
#pragma endregion

#pragma region �ؽ� ���̺�
	// (Key, Value)�� �����͸� �����ϴ� �ڷᱸ�� �� �ϳ���
	// ������ �����͸� �˻��� �� �ִ� �ڷᱸ���Դϴ�.

	// �ؽ� ���̺��� �ð����⵵�� O(1)�Դϴ�.

	// �ؽ� �浹�� �ذ��ϴ� ���

	// ü�̴� ���
	// �� �ؽ� ��Ŷ�� ���Ḯ��Ʈ�� �����ϴ� ����Դϴ�.

	// ���� �ּҹ�
	// �浹 �߻� �� �� ���Ͽ� �����͸� �����ϴ� ����Դϴ�.

	// �� ��Ŷ�� ��� ������ ���� ���� ���� ����� �޶����ϴ�.

	// ���� Ž�� : �浹 �߻� �� �տ��� ���� ���ʴ�� �� ��Ŷ��
	// ã�� ���� �����ϴ� ����Դϴ�.

	// ���� Ž�� : �浹 �߻� �� 2^, 2^3��ŭ ������ �� ��Ŷ�� ã��
	// ���� �����ϴ� ����Դϴ�.

	// ���� �ؽ� : �ؽ� ���� �ѹ� �� �ؽ� �Լ��� �־� �ٸ� �ؽð���
	// �����ϴ� ����Դϴ�.

	HashTable hashTable;

	hashTable.Insert(5, 555);
	hashTable.Insert(10, 111);

	hashTable.Search(7);
#pragma endregion


	return 0;
}