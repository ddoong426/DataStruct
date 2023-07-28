#pragma once
#include <iostream>

#define SIZE 10
#define SIZE2 5


int main()
{
#pragma region 계수 정렬
	// 데이터의 값을 직접 비교하지 않고, 단순하게 각 숫자가
	// 몇 개 있는지 갯수를 세어 저장한 다음 정렬하는 알고리즘입니다.

	// int array[SIZE] = { 1,3,3,4,5,5,5,1,2,2 };
	// int count[SIZE2] = { 0, };
	// 
	// for (int i = 0; i < SIZE; i++)
	// {
	// 	count[array[i] - 1] += 1;
	// }
	// 
	// for (int i = 0; i < SIZE2; i++)
	// {
	// 	std::cout << count[i] << " ";
	// }
#pragma endregion

	return 0;
}