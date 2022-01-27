#include <iostream>
#include <time.h>

using namespace std;

void MixNumber(int _iArray[]);

int main()
{
	srand(unsigned(time(NULL)));

	int iArray[5][5] = {};
	int iArr[25] = {};
	int iArrSize = sizeof(iArr) / sizeof(int);

	int iBingoCount = 0;
	const int marking = 'X'; // '*'의 아스키 코드 번호가 '42'이기 때문에 난수로 42가 나오면 '*'이 출력되므로 아스키 코드 번호 50 이후에 있는 'X'를 이용했다.

	

	// 먼저 1차원 배열에 난수를 대입한다.
	for (int i = 0; i < iArrSize; ++i)
	{
		iArr[i] = rand() % 50 + 1;
		for (int j = 0; j < i; ++j)
		{
			// 중복값을 제거하는 코드
			if (iArr[i] == iArr[j])
			{
				--i;
				break;
			}
		}
	}

	// 1차원 배열의 값을 2차원 배열에 대입한다.
	int iIndex = 0;
	for (int i = 0; i < 5; ++i)
	{
		for (int j = 0; j < 5; ++j)
		{
			iArray[i][j] = iArr[iIndex];
			++iIndex;
		}
	}



	while (iBingoCount < 5)
	{
		system("cls");

		// 2차원 배열 출력 코드
		// 배열의 값이 '*'이면 char형으로 출력하고, 그렇지 않으면 int형으로 출력한다.
		for (int i = 0; i < 5; ++i)
		{
			for (int j = 0; j < 5; ++j)
			{
				if (iArray[i][j] == marking)
					cout << (char)iArray[i][j] << "\t";
				else
					cout << (int)iArray[i][j] << "\t";
			}
			cout << endl;
		}

		cout << "===================================" << endl;

		int iInput = 0;
		cout << "빙고 카운트: " << iBingoCount << " 숫자를 입력하세요 > ";
		cin >> iInput;

		// 입력받은 값과 같은 값을 0으로 바꾼다.
		for (int i = 0; i < 5; ++i)
		{
			for (int j = 0; j < 5; ++j)
			{
				if (iArray[i][j] == iInput)
				{
					iArray[i][j] = marking;
				}
			}
		}


		// 빙고 카운트가 증가되는 조건들
		// 가로 세로 빙고
		for (int i = 0; i < 5; ++i)
		{
			if (iArray[i][0] == marking && iArray[i][1] == marking && iArray[i][2] == marking && iArray[i][3] == marking && iArray[i][4] == marking)
			{
				++iBingoCount;
			}
			else if (iArray[0][i] == marking && iArray[1][i] == marking && iArray[2][i] == marking && iArray[3][i] == marking && iArray[4][i] == marking)
			{
				++iBingoCount;
			}

		}

		// 대각선 빙고
		if (iArray[0][0] == marking && iArray[1][1] == marking && iArray[2][2] == marking && iArray[3][3] == marking && iArray[4][4] == marking)
		{
			++iBingoCount;
		}
		else if (iArray[0][4] == marking && iArray[1][3] == marking && iArray[2][2] == marking && iArray[3][1] == marking && iArray[4][0] == marking)
		{
			++iBingoCount;
		}

		

		
		
		system("pause");
		
	}



	// 마지막에 빙고 현황을 보여 주며 게임이 종료된다.

	cout << "===================================" << endl;

	for (int i = 0; i < 5; ++i)
	{
		for (int j = 0; j < 5; ++j)
		{
			if (iArray[i][j] == marking)
				cout << (char)iArray[i][j] << "\t";
			else
				cout << (int)iArray[i][j] << "\t";
		}
		cout << endl;
	}

	cout << "===================================" << endl;

	// 5빙고가 되었을 경우 게임은 종료된다.
	cout << "빙고 카운트: " << iBingoCount << " 축하합니다, " << iBingoCount << "빙고를 맞추셨습니다!" << endl;
	

	



	return 0;
}

// 배열의 원소들을 무작위로 섞는 반복문, 여기선 100회 섞는다.
void MixNumber(int _iArray[])
{
	srand(unsigned(time(NULL)));
	for (int i = 0; i < 100; ++i)
	{
		int irandomNumber1 = rand() % 25; // 두 개의 변수에 랜덤한 숫자를 대입한 후
		int iRandomNumber2 = rand() % 25;
		int iTemp = 0;

		// swap 함수 개념대로 섞는다. 반복문 안에 있으므로 100회 섞는다.
		iTemp = _iArray[irandomNumber1];
		_iArray[irandomNumber1] = _iArray[iRandomNumber2];
		_iArray[iRandomNumber2] = iTemp;
	}
}