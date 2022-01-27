#include <iostream>
#include <time.h>

using namespace std;

void MixNumber(int _iArray[]);
bool CompareArrays(int _iCom[], int _iUser[]);
int ConfirmBall(int _iCom[], int _iUser[]);
int ConfirmStrike(int _iCom[], int _iUser[]);

int main()
{
	int iArray[9] = {}; // 1부터 9까지의 숫자를 담을 배열
	int iSize = sizeof(iArray) / sizeof(int); // 9

	int iCom[3] = {}; // 섞고 난 후의 컴퓨터의 숫자들을 대입할 배열

	// iArray에 1부터 9까지 대입
	for (int i = 0; i < iSize; ++i)
	{
		iArray[i] = i + 1;
	}

	MixNumber(iArray);


	cout << "컴퓨터가 뽑은 숫자는 ";
	for (int i = 0; i < 3; ++i)
	{
		iCom[i] = iArray[i]; // 섞고 난 후의 숫자들 중 0번째부터 2번째까지의 숫자를 새로운 배열에 대입
		cout << iCom[i] << " ";
	}
	cout << endl;

	

	for (int i = 0; i < 9; ++i)
	{
		int iNumber1 = 0, iNumber2 = 0, iNumber3 = 0; // 사용자가 입력한 세 개의 숫자를 저장할 변수 선언
		cout << "숫자 세 개를 입력하세요 > ";
		cin >> iNumber1 >> iNumber2 >> iNumber3;
		int iUser[3] = { iNumber1, iNumber2, iNumber3 }; // 사용자가 입력한 세 개의 숫자를 iBall 배열에 대입


		bool bIsEqual = CompareArrays(iCom, iUser); // 두 배열이 완전히 같은지 아닌지 판단
		int iBallCount = ConfirmBall(iCom, iUser);
		int iStrikeCount = ConfirmStrike(iCom, iUser);


		switch (iBallCount)
		{
		case 1:
			cout << "1볼!" << endl;
			break;
		case 2:
			cout << "2볼!" << endl;
			break;
		case 3:
			cout << "3볼!" << endl;
			break;
		default:
			break;
		}

		switch (iStrikeCount)
		{
		case 1:
			cout << "1스트라이크!" << endl;
			break;
		case 2:
			cout << "2스트라이크!" << endl;
			break;
		case 3:
			cout << "3스트라이크! 축하합니다, 게임에서 승리하셨습니다!" << endl;
			exit(0);
		default:
			break;
		}

		

	}
	cout << "아쉽게도 맞추지 못하셨습니다... 안녕히 가세요." << endl;





	return 0;
}

void MixNumber(int _iArray[])
{
	srand(unsigned(time(NULL)));
	for (int i = 0; i < 100; ++i)
	{
		int iSour = rand() % 9; // 두 개의 변수에 랜덤한 숫자를 대입한 후
		int iDest = rand() % 9;
		int iTemp = 0;

		// swap 함수 개념대로 섞는다. 반복문 안에 있으므로 100회 섞는다.
		iTemp = _iArray[iSour];
		_iArray[iSour] = _iArray[iDest];
		_iArray[iDest] = iTemp;
	}
}

// 두 배열의 동일 인덱스에 있는 원소가 같은지 확인하는 함수, 사용하진 않았다.
bool CompareArrays(int _iCom[], int _iUser[])
{
	for (int i = 0; i < 3; ++i)
	{
		if (_iCom[i] != _iUser[i])
		{
			return false;
		}
	}
	return true;
}

int ConfirmBall(int _iCom[], int _iUser[])
{
	int iBallCount = 0;
	for (int i = 0; i < 3; ++i)
	{
		for (int j = 0; j < 3; ++j)
		{
			if ((i != j) && (_iCom[i] == _iUser[j]))
			{
				++iBallCount;
			}
		}
	}
	return iBallCount;
}

int ConfirmStrike(int _iCom[], int _iUser[])
{
	int iStrikeCount = 0;
	for (int i = 0; i < 3; ++i)
	{
		if (_iCom[i] == _iUser[i])
		{
			++iStrikeCount;
		}
	}
	return iStrikeCount;
}