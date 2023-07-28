#pragma once
#include <iostream>

#define SIZE 5

class Componet
{
private:
	float x;
	float y;
	int* count;

public:
	// �⺻ ������
	Componet()
	{
		x = 10;
		y = 20;
		count = new int;
	}

	// ���� ������
	Componet(Componet& other)
	{
		std::cout << "���� ������ ȣ��" << std::endl;

		this->x = other.x;
		this->y = other.y;

		// ���� ����
		other.count = new int;
	}

	Componet(Componet&& other)
	{
		std::cout << "�̵� ������" << std::endl;
	}
};

int main()
{
#pragma region ���� ����
	// �� ��° �ڷ���� �����Ͽ� �� ��(����)��
	// �ڷ��� ���Ͽ� ������ ��ġ�� ������ ��
	// �ڷḦ �ڷ� �ű�� ������ �ڸ��� �ڷḦ �����Ͽ�
	// �����ϴ� �˰����Դϴ�.

	// �ð� ���⵵ O(n^2)

	// 1��° �ε����� ���� temp�� �ִ´�.

	// 0��°�ε����� 1��°�ε����� ���Ѵ�

	int array[SIZE] = { 5,8,6,1,2 };
	int temp = 0;
	int j = 0;

	for (int i = 1; i < SIZE; i++)
	{
		temp = array[i];

		for (j = i - 1; j >= 0 && array[j] > temp; j--)
		{
			array[j + 1] = array[j];
		}

		array[j + 1] = temp;
	}

	for (int i = 0; i < SIZE; i++)
	{
		std::cout << array[i] << std::endl;
	}
#pragma endregion

#pragma region �̵� ������
	// ���� ��ü�� �ּ� �� ���� ���ο� ������Ʈ��
	// �������� ������Ű�� �������Դϴ�.

	Componet componet1;

	Componet componet2 = componet1;

	Componet componet3 = { std::move(componet1) };

#pragma endregion


	return 0;
}