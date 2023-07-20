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
		// capacity에 새로운 size 값을 설정한다.
		capacity = size;

		// 새로운 포인터 변수를 생성해서 새롭게 만들어진
		//
		T* tempArray = new A[size];

		// 새로운 메모리 공간의 값을 초기화합니다.
		for (int i = 0; i < size; i++)
		{
			tempArray[i] = NULL;
		}

		for (int i = 0; i < this->size; i++)
		{
			tempArray[i] = array[i];
		}

		// array에 메모리 주소를 해제합니다.
		delete array;

		// array에 새로 할당한 메모리의 주소를 저장합니다.

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

	// 연산자 오버로딩 [ ]
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


