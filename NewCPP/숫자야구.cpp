#include <iostream>
#include <time.h>

using namespace std;

void MixNumber(int _iArray[]);
bool CompareArrays(int _iCom[], int _iUser[]);
int ConfirmBall(int _iCom[], int _iUser[]);
int ConfirmStrike(int _iCom[], int _iUser[]);

int main()
{
	int iArray[9] = {}; // 1���� 9������ ���ڸ� ���� �迭
	int iSize = sizeof(iArray) / sizeof(int); // 9

	int iCom[3] = {}; // ���� �� ���� ��ǻ���� ���ڵ��� ������ �迭

	// iArray�� 1���� 9���� ����
	for (int i = 0; i < iSize; ++i)
	{
		iArray[i] = i + 1;
	}

	MixNumber(iArray);


	cout << "��ǻ�Ͱ� ���� ���ڴ� ";
	for (int i = 0; i < 3; ++i)
	{
		iCom[i] = iArray[i]; // ���� �� ���� ���ڵ� �� 0��°���� 2��°������ ���ڸ� ���ο� �迭�� ����
		cout << iCom[i] << " ";
	}
	cout << endl;

	

	for (int i = 0; i < 9; ++i)
	{
		int iNumber1 = 0, iNumber2 = 0, iNumber3 = 0; // ����ڰ� �Է��� �� ���� ���ڸ� ������ ���� ����
		cout << "���� �� ���� �Է��ϼ��� > ";
		cin >> iNumber1 >> iNumber2 >> iNumber3;
		int iUser[3] = { iNumber1, iNumber2, iNumber3 }; // ����ڰ� �Է��� �� ���� ���ڸ� iBall �迭�� ����


		bool bIsEqual = CompareArrays(iCom, iUser); // �� �迭�� ������ ������ �ƴ��� �Ǵ�
		int iBallCount = ConfirmBall(iCom, iUser);
		int iStrikeCount = ConfirmStrike(iCom, iUser);


		switch (iBallCount)
		{
		case 1:
			cout << "1��!" << endl;
			break;
		case 2:
			cout << "2��!" << endl;
			break;
		case 3:
			cout << "3��!" << endl;
			break;
		default:
			break;
		}

		switch (iStrikeCount)
		{
		case 1:
			cout << "1��Ʈ����ũ!" << endl;
			break;
		case 2:
			cout << "2��Ʈ����ũ!" << endl;
			break;
		case 3:
			cout << "3��Ʈ����ũ! �����մϴ�, ���ӿ��� �¸��ϼ̽��ϴ�!" << endl;
			exit(0);
		default:
			break;
		}

		

	}
	cout << "�ƽ��Ե� ������ ���ϼ̽��ϴ�... �ȳ��� ������." << endl;





	return 0;
}

void MixNumber(int _iArray[])
{
	srand(unsigned(time(NULL)));
	for (int i = 0; i < 100; ++i)
	{
		int iSour = rand() % 9; // �� ���� ������ ������ ���ڸ� ������ ��
		int iDest = rand() % 9;
		int iTemp = 0;

		// swap �Լ� ������ ���´�. �ݺ��� �ȿ� �����Ƿ� 100ȸ ���´�.
		iTemp = _iArray[iSour];
		_iArray[iSour] = _iArray[iDest];
		_iArray[iDest] = iTemp;
	}
}

// �� �迭�� ���� �ε����� �ִ� ���Ұ� ������ Ȯ���ϴ� �Լ�, ������� �ʾҴ�.
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