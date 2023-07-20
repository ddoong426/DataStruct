#pragma once
#include <iostream>

template <typename T>
class VECTOR
{
private:
	int capacity = 0;
	int size = 0;

	T* array;

public:
	VECTOR(int size = 1)
	{
		capacity = size;
		array = new T[capacity];
	}

	void Push_Back(T data)
	{
		if (size >= capacity)
		{
			capacity = capacity * 2;

			Resize(capacity);
		}
		array[size++] = data;
	}

	void Resize(int size)
	{
		// capacity�� ���ο� size ���� �����Ѵ�.
		capacity = size;

		// ���ο� ������ ������ �����ؼ� ���Ӱ� �������
		//
		T* tempArray = new A[size];

		// ���ο� �޸� ������ ���� �ʱ�ȭ�մϴ�.
		for (int i = 0; i < size; i++)
		{
			tempArray[i] = NULL;
		}

		for (int i = 0; i < this->size; i++)
		{
			tempArray[i] = array[i];
		}

		// array�� �޸� �ּҸ� �����մϴ�.
		delete array;

		// array�� ���� �Ҵ��� �޸��� �ּҸ� �����մϴ�.

		array = tempArray;
	}

	int Size()
	{
		return size;
	}

	void Pop_Back()
	{
		if (size <= 0)
		{
			return;
		}
		array[--size] = NULL;
	}

	// ������ �����ε� [ ]
	T& operator [ ] (const int& value)
	{
		return array[value];
	}

	~VECTOR()
	{
		delete array;
	}
};

int main()
{
	VECTOR<int> b;

	b[0];



	return 0;
}


