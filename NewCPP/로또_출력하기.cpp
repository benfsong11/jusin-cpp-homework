#include <iostream>

using namespace std;


void MixNumber(int* iLotto);
void SortNumber(int* iLotto);

int main()
{
	int iLotto[45] = {}; // 배열 iArray 초기화
	int iSize = sizeof(iLotto) / sizeof(int); // 45

	// 배열 iLotto에 1부터 45까지 값을 넣는 반복문
	for (int i = 0; i < iSize; ++i)
	{
		iLotto[i] = i + 1;
	}


	// 6개 숫자 출력하는 반복문
	for (int i = 0; i < 5; ++i)
	{
		MixNumber(iLotto);
		SortNumber(iLotto);
		for (int j = 0; j < 6; ++j)
		{
			cout << iLotto[j] << "\t";
		}
		cout << endl;
		cout << "===========================================" << endl;
	}
	



	return 0;
}


// 배열의 원소들을 무작위로 섞는 반복문, 여기선 50회 섞는다.
void MixNumber(int* iLotto)
{
	srand(time(NULL));
	for (int i = 0; i < 50; ++i)
	{
		int irandomNumber1 = rand() % 45; // 두 개의 변수에 랜덤한 숫자를 대입한 후
		int iRandomNumber2 = rand() % 45;
		int iTemp = 0;

		// swap 함수 개념대로 섞는다. 반복문 안에 있으므로 50회 섞는다.
		iTemp = iLotto[irandomNumber1];
		iLotto[irandomNumber1] = iLotto[iRandomNumber2];
		iLotto[iRandomNumber2] = iTemp;
	}
}

// 버블 정렬로 오름차순 정렬
void SortNumber(int* iLotto)
{
	for (int i = 0; i < 6; ++i)
	{
		int iTemp = 0;
		for (int j = 0; j < (6 - i) - 1; ++j)
		{
			if (iLotto[j] > iLotto[j + 1])
			{
				iTemp = iLotto[j];
				iLotto[j] = iLotto[j + 1];
				iLotto[j + 1] = iTemp;
			}
		}
	}
}