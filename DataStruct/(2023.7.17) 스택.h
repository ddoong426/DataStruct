#pragma once
#include <iostream>
#include <stack>

#define SIZE 5

template <typename T>
class STACK
{
private:
	int top;
	T buffer[SIZE];
public:
	STACK()
	{
		top = -1;
	}

	void Push(T data)
	{
		if (Isfull())
		{
			std::cout << "STACK에 데이터가 가득 찼습니다." << std::endl;
		}
		else
		{
			buffer[++top] = data;
		}
	}

	T Pop()
	{
		if (Empty())
		{
			std::cout << "STACK에 데이터가 비어있습니다." << std::endl;
			exit(1);
		}
		else
		{
			return buffer[top--];
		}
	}

	T Top()
	{
		if (Empty())
		{
			return 0;
		}
		else
		{
			return buffer[top];
		}
	}

	bool Empty()
	{
		// 비어있다면 true를 반환
		if (top <= -1)
		{
			return true;
		}
		else // 비어있지 않다면 false를 반환
		{
			return false;
		}
	}

	bool Isfull()
	{
		// 데이터 다 차 있으면 true 반환
		if (SIZE - 1 <= top)
		{
			return true;
		}
		else
		{
			return false;
		}
		// 데이터가 다 차 있지않다면 false를 반환

	}

	~STACK() {}
};
int main()
{
	STACK<char> intStack;

	intStack.Push('A');
	intStack.Push('B');
	intStack.Push('C');
	intStack.Push('D');

	while (intStack.Empty() == false)
	{
		std::cout << intStack.Top() << std::endl;
		intStack.Pop();
	}

	intStack.Pop();

	while (1)
	{

	}
	return 0;
}


