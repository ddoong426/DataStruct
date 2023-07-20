#include <iostream>
#include <queue>

#define SIZE 5
template <typename T>
class LinearQueue
{
private:
	int front;
	int rear;
	int size;

	T array[SIZE];

public:

	LinearQueue()
	{
		front = 0;
		rear = 0;
		size = 0;
	}

	void Push(T data)
	{
		if (IsFull())
		{
			std::cout << "LinearQueue에 데이터가 가득 찼습니다." << std::endl;
		}
		
			array[rear++] = data;
			size++;
		
	}

	void Pop()
	{
		if (Empty() == true)
		{
			std::cout << "Queue에 비어있습니다." << std::endl;
			exit(1);
		}
		
			array[front++] = NULL;

			size--;
		
	}

	int & Size()
	{
		return size;
	}

	T & Front()
	{
		return array[front];
	}

	T & Back()
	{
		return array[rear - 1];
	}

	bool Empty()
	{
		if (front==rear)
		{
			return true;
		}
		else
		{
			return false;
		}
	}

	bool IsFull()
	{
		if (rear >= SIZE)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
};



int main()
{
#pragma region 선형 큐
	// 배열의 공간에 들어간 데이터가 고정되어
	// 데이터를 빼내더라도 초기화하지 않으면
	// 원래 데이터가 있던 배열의 자리에 더 이상
	// 다른 것이 들어갈 수 없는 형태의 Queue입니다.

	// std::queue<int> queue;
	// 
	// queue.push(10);
	// queue.push(20);
	// queue.push(30);
	// queue.push(40);
	// 
	// std::cout << queue.front() << std::endl;
	// std::cout << queue.back() << std::endl;
	// 
	// queue.pop();
	// 
	// std::cout << queue.size() << std::endl;
	// std::cout << queue.empty() << std::endl;

#pragma endregion

	LinearQueue<int> queue;

	queue.Push(10);
	queue.Push(20);
	queue.Push(30);
	queue.Push(40);
	queue.Push(50);
	
	queue.Pop();
	queue.Pop();
	queue.Pop();
	queue.Pop();
	queue.Pop();

	queue.Pop();

	queue.Push(10);

	std::cout << queue.Size() << std::endl;
	std::cout << queue.Front() << std::endl;
	std::cout << queue.Back() << std::endl;


	return 0;
}


