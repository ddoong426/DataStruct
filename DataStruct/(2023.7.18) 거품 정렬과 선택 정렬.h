#pragma once
#include <iostream>

#define SIZE 5

int main()
{
#pragma region 시간 복잡도
	// 컴퓨터 프로그램의 입력 값과 연산 수행 시간의
	// 상관관계를 나타내는 척도입니다.

	// big-O 표기법
	// 입력값의 변화에 따라 연산을 수행할 때,
	// 연산 횟수에 비해 시간이 얼마만큼 걸리는 지 나타내는 척도입니다.

	// 최악의 경우를 고려하므로, 프로그램이 실행되는
	// 과정에서 소요되는 최악의 시간까지 고려할 수 있기 때문입니다.

	// O(1) 상수 시간 복잡도
	/*
	// 입력값이 증가하더라도 시간이 늘어나지 않는 시간 복잡도입니다.

	// ex 배열의 인덱스 접근
	// int buffer[100];
	// buffer[50] = 10;
	// std::cout << buffer[50] << std::endl;
	*/

	// O(n) 선형 시간 복잡도
	/*
		입력값이 증가함에 따라 시간 또한 같은 비율로
		증가하는 시간 복잡도입니다.

		// 입력 1
		// 시간 -> 1초

		// 입력 100
		// 시간 -> 100초

		ex) for문

		for(int i = 0; i < 입력값(N); i++)
		{

		}

	*/

	// O(log n) 로그 시간 복잡도
	/*
		입력 데이터의 크기가 커질수록 처리 시간이 로그(log) 만큼
		짧아지는 시간 복잡도
	*/

	// O(n^2) 2차 시간 복잡도
	/*
	// 입력값이 증가함에 따라 시간이 n의 제곱수의
	// 비율로 증가하는 시간 복잡도입니다.

	// ex)
	// for(int i = 0; i < n; i++)
	// {
	//		for(int j = 0; j < n; j++)
	//		{
	//
	//		}
	// }
	*/

	// O(2n) 기하 급수적 시간 복잡도
	// ex 재귀 함수 (피보나치 수열)
#pragma endregion

#pragma region 거품 정렬
	// 서로 인접한 두 원소를 검사하여 정렬하는 알고리즘입니다.

	// 시간 복잡도 O(n^2)
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

#pragma region 선택 정렬
	// 정렬 되지 않은 데이터들에 대해 가장
	// 작은 데이터를 찾아서 가장 앞에 있는 데이터와 교환하는
	// 알고리즘입니다.

	// 시간 복잡도 O(n^2)	

	int selectBuffer[SIZE] = { 6,2,12,5,8 };
	int value;
	int value1;


	// 내가 짠 코드
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

	// 선생님이 짠 코드
	for (int i = 0; i < SIZE; i++)
	{
		// 최솟값
		int min = selectBuffer[i];

		// select 변수
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


