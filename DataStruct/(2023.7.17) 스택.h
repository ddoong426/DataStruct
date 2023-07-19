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
			std::cout << "STACK�� �����Ͱ� ���� á���ϴ�." << std::endl;
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
			std::cout << "STACK�� �����Ͱ� ����ֽ��ϴ�." << std::endl;
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
		// ����ִٸ� true�� ��ȯ
		if (top <= -1)
		{
			return true;
		}
		else // ������� �ʴٸ� false�� ��ȯ
		{
			return false;
		}
	}

	bool Isfull()
	{
		// ������ �� �� ������ true ��ȯ
		if (SIZE - 1 <= top)
		{
			return true;
		}
		else
		{
			return false;
		}
		// �����Ͱ� �� �� �����ʴٸ� false�� ��ȯ

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


