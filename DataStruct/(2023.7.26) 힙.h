#pragma once
#include <iostream>

#define SIZE 8

class MAX_HEAP
{
private:
	int heapArray[SIZE];
	int index;

public:
	MAX_HEAP()
	{
		for (int i = 0; i < SIZE; i++)
		{
			heapArray[i] = NULL;
		}

		index = 0;
	}
	void Insert(int data)
	{
		if (index == SIZE - 1)
		{
			std::cout << "heapArray�� �����Ͱ� ���� á���ϴ�." << std::endl;
			return;
		}

		heapArray[++index] = data;

		int child = index;

		int parent = index / 2;


		while (child > 1)
		{
			if (heapArray[parent] < heapArray[child])
			{
				std::swap(heapArray[parent], heapArray[child]);
			}
			child = parent;
			parent = child / 2;
		}

		// my code
		// if (index == SIZE)
		// {
		// 	std::cout << "heapArray�� �����Ͱ� ���� á���ϴ�." << std::endl;
		// }
		// else
		// {
		// 	heapArray[++index] = data;
		// }
		// 
		// while (heapArray[index] <= heapArray[index * 2])
		// {
		// 	std::swap(heapArray[index], heapArray[index * 2]);
		// 
		// }
	}

	int& Delete()
	{
		// 1. �ӽ� ���� : ���� ����⿡ �ִ� ���� �����մϴ�.
		int result = heapArray[1];

		//int A = heapArray[1];

		// 2. heap�� ����ִٸ� �Լ��� ��ȯ�մϴ�.
		if (index <= 0)
		{
			std::cout << "heap�� ����ֽ��ϴ�." << std::endl;
			exit(1);
		}

		// 3. index���� ����Ű�� �迭�� ���� ù��° �迭�� ������ �־��ָ� �˴ϴ�.
		heapArray[1] = heapArray[index];
		// 4. index�� ����Ű�� �迭�� ���� �ʱ�ȭ�մϴ�. O

		// 5. index�� ���ҽ�ŵ�ϴ�. O 
		heapArray[index--] = NULL;
		// 6. �θ� ���� <- 1
		int parent = 1;
		// 7. �ݺ����� �����մϴ�. (�θ� ���� * 2 <= index)
		while (parent * 2 <= index)
		{
			int child = parent * 2;

			// ������ �ڽ� ��尡 Ŭ ��
			if (heapArray[child] < heapArray[child + 1])
			{
				child++;
			}

			// �θ��� ��� Key ���� ũ�ٸ� �ݺ����� �����մϴ�.
			if (heapArray[parent] > heapArray[child])
			{
				break;
			}

			std::swap(heapArray[child], heapArray[parent]);
			parent = child;

		}
		// ���� ��ȯ�մϴ�
		return result;
	}

	void show()
	{
		for (int element : heapArray)
		{
			std::cout << element << std::endl;
		}
	}
};

int main()
{
#pragma region ��
	// ���� ���� �߿��� �ִ� Ȥ�� �ּڰ���
	// ������ ã�Ƴ��� ���� �ڷᱸ���Դϴ�.


	// �ִ� ��
	// �θ� ����� Ű ���� �ڽ� ����� Ű ������
	// ũ�ų� ���� ���� ���� Ʈ��

	// ���� �ڽ� �ε��� : (�θ� �ε���) * 2
	// ������ �ڽ� �ε��� : (�θ� �ε���) * 2 + 1
	// �θ� �ε��� : (�ڽ� �ε���) / 2

	//

	MAX_HEAP maxHeap;

	maxHeap.Insert(10);
	maxHeap.Insert(20);
	maxHeap.Insert(30);
	// heap.Insert(30);
	// heap.Insert(40);
	// heap.Insert(50);
	std::cout << maxHeap.Delete() << std::endl;

	maxHeap.show();
#pragma endregion


	return 0;
}