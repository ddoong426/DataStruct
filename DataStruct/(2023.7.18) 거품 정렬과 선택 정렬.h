#pragma once
#include <iostream>

#define SIZE 5

int main()
{
#pragma region �ð� ���⵵
	// ��ǻ�� ���α׷��� �Է� ���� ���� ���� �ð���
	// ������踦 ��Ÿ���� ô���Դϴ�.

	// big-O ǥ���
	// �Է°��� ��ȭ�� ���� ������ ������ ��,
	// ���� Ƚ���� ���� �ð��� �󸶸�ŭ �ɸ��� �� ��Ÿ���� ô���Դϴ�.

	// �־��� ��츦 ����ϹǷ�, ���α׷��� ����Ǵ�
	// �������� �ҿ�Ǵ� �־��� �ð����� ����� �� �ֱ� �����Դϴ�.

	// O(1) ��� �ð� ���⵵
	/*
	// �Է°��� �����ϴ��� �ð��� �þ�� �ʴ� �ð� ���⵵�Դϴ�.

	// ex �迭�� �ε��� ����
	// int buffer[100];
	// buffer[50] = 10;
	// std::cout << buffer[50] << std::endl;
	*/

	// O(n) ���� �ð� ���⵵
	/*
		�Է°��� �����Կ� ���� �ð� ���� ���� ������
		�����ϴ� �ð� ���⵵�Դϴ�.

		// �Է� 1
		// �ð� -> 1��

		// �Է� 100
		// �ð� -> 100��

		ex) for��

		for(int i = 0; i < �Է°�(N); i++)
		{

		}

	*/

	// O(log n) �α� �ð� ���⵵
	/*
		�Է� �������� ũ�Ⱑ Ŀ������ ó�� �ð��� �α�(log) ��ŭ
		ª������ �ð� ���⵵
	*/

	// O(n^2) 2�� �ð� ���⵵
	/*
	// �Է°��� �����Կ� ���� �ð��� n�� ��������
	// ������ �����ϴ� �ð� ���⵵�Դϴ�.

	// ex)
	// for(int i = 0; i < n; i++)
	// {
	//		for(int j = 0; j < n; j++)
	//		{
	//
	//		}
	// }
	*/

	// O(2n) ���� �޼��� �ð� ���⵵
	// ex ��� �Լ� (�Ǻ���ġ ����)
#pragma endregion

#pragma region ��ǰ ����
	// ���� ������ �� ���Ҹ� �˻��Ͽ� �����ϴ� �˰����Դϴ�.

	// �ð� ���⵵ O(n^2)
	// int array[SIZE] = { 4,6,5,2,7 };
	// 
	// int value;
	// 
	// for (int i = 0; i < SIZE; i++)
	// {
	// 	for (int j = 0; j < SIZE - 1; j++)
	// 	{
	// 		if (array[j] > array[j + 1])
	// 		{
	// 			// case 1
	// 			// value = array[j + 1];
	// 			// array[j + 1] = array[j];
	// 			// array[j] = value;
	// 
	// 			// case 2
	// 			std::swap(array[j], array[j + 1]);
	// 		}
	// 	}
	// }
	// 
	// for (int i = 0; i < SIZE; i++)
	// {
	// 	std::cout << array[i] << " ";
	// }
#pragma endregion

#pragma region ���� ����
	// ���� ���� ���� �����͵鿡 ���� ����
	// ���� �����͸� ã�Ƽ� ���� �տ� �ִ� �����Ϳ� ��ȯ�ϴ�
	// �˰����Դϴ�.

	// �ð� ���⵵ O(n^2)	

	int selectBuffer[SIZE] = { 6,2,12,5,8 };
	int value;
	int value1;


	// ���� § �ڵ�
	// for (int i = 0; i < SIZE - 1; i++)
	// {
	// 	value1 = i;
	// 	for (int j = i; j < SIZE; j++)
	// 	{
	// 		if (selectBuffer[value1] > selectBuffer[j])
	// 		{
	// 			value = selectBuffer[j];
	// 			value1 = j;
	// 		}
	// 	}
	// 	if (selectBuffer[i] > selectBuffer[value1])
	// 	{
	// 	selectBuffer[value1] = selectBuffer[i];
	// 	selectBuffer[i] = value;
	// 	}
	// }

	// �������� § �ڵ�
	for (int i = 0; i < SIZE; i++)
	{
		// �ּڰ�
		int min = selectBuffer[i];

		// select ����
		int select = i;

		for (int j = i + 1; j < SIZE; j++)
		{
			if (min > selectBuffer[j])
			{
				min = selectBuffer[j];
				select = j;
			}
		}

		std::swap(selectBuffer[i], selectBuffer[select]);
	}

	for (int i = 0; i < SIZE; i++)
	{
		std::cout << selectBuffer[i] << " ";
	}
#pragma endregion

	return 0;
}


