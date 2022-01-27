#include <iostream>

using namespace std;

int main()
{
	int iArray[25] = {}; // 배열 iArray 초기화
	int iSize = sizeof(iArray) / sizeof(int); // 25

	// 배열 iArray에 1부터 25까지 값을 넣는 반복문
	for (int i = 0; i < iSize; ++i)
	{
		iArray[i] = i + 1;
	}
	
	// 배열 출력 반복문
	int iIndex = 0;
	for (int i = 0; i < 5; ++i)
	{
		
		for (int j = iIndex; j < iIndex + 5; ++j)
		{
			cout << iArray[j] << "\t";
		}
		iIndex += 5;
		
		cout << endl;
	}
	



	return 0;
}