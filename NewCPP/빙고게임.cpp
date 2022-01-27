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
	const int marking = 'X'; // '*'�� �ƽ�Ű �ڵ� ��ȣ�� '42'�̱� ������ ������ 42�� ������ '*'�� ��µǹǷ� �ƽ�Ű �ڵ� ��ȣ 50 ���Ŀ� �ִ� 'X'�� �̿��ߴ�.
	const int complete = 'O';
	

	// ���� 1���� �迭�� ������ �����Ѵ�.
	for (int i = 0; i < iArrSize; ++i)
	{
		iArr[i] = rand() % 50 + 1;
		for (int j = 0; j < i; ++j)
		{
			// �ߺ����� �����ϴ� �ڵ�
			if (iArr[i] == iArr[j])
			{
				--i;
				break;
			}
		}
	}

	// 1���� �迭�� ���� 2���� �迭�� �����Ѵ�.
	int iIndex = 0;
	for (int i = 0; i < 5; ++i)
	{
		for (int j = 0; j < 5; ++j)
		{
			iArray[i][j] = iArr[iIndex];
			++iIndex;
		}
	}

	cout << "���� ���� ����!" << endl;
	cout << "===================================" << endl;



	while (true)
	{

		// 2���� �迭 ��� �ڵ�
		// �迭�� ���� '*'�̸� char������ ����ϰ�, �׷��� ������ int������ ����Ѵ�.
		for (int i = 0; i < 5; ++i)
		{
			for (int j = 0; j < 5; ++j)
			{
				if (iArray[i][j] == marking || iArray[i][j] == complete)
					cout << (char)iArray[i][j] << "\t";
				else
					cout << (int)iArray[i][j] << "\t";
			}
			cout << endl;
		}

		cout << "===================================" << endl;

		if (iBingoCount > 4)
		{
			cout << "�����մϴ�, " << iBingoCount << "���� ���߼̽��ϴ�!" << endl;
			break;
		}
		else
			iBingoCount = 0; // ���ڸ� �Է��� ������ iBingoCount�� 0���� �ʱ�ȭ�ϰ�, �ٽ� ���� ������ ���� �� ��ŭ ����Ѵ�.

		int iInput = 0;
		cout << "���ڸ� �Է��ϼ��� > ";
		cin >> iInput;

		// �Է¹��� ���� ���� ���� 0���� �ٲ۴�.
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

		
		

		// ���� ī��Ʈ�� �����Ǵ� ���ǵ�
		
		
		
		// ���� ���� ����
		for (int i = 0; i < 5; ++i)
		{
			if (iArray[i][0] == marking && iArray[i][1] == marking && iArray[i][2] == marking && iArray[i][3] == marking && iArray[i][4] == marking)
			{
				++iBingoCount;
			}
			if (iArray[0][i] == marking && iArray[1][i] == marking && iArray[2][i] == marking && iArray[3][i] == marking && iArray[4][i] == marking)
			{
				++iBingoCount;
			}

		}

		// �밢�� ����
		if (iArray[0][0] == marking && iArray[1][1] == marking && iArray[2][2] == marking && iArray[3][3] == marking && iArray[4][4] == marking)
		{
			++iBingoCount;
		}
		if (iArray[0][4] == marking && iArray[1][3] == marking && iArray[2][2] == marking && iArray[3][1] == marking && iArray[4][0] == marking)
		{
			++iBingoCount;
		}


		
		
		system("cls");

		cout << "���� " << iBingoCount << "�����Դϴ�." << endl;
		cout << "===================================" << endl;

		
	}



	return 0;
}

// �迭�� ���ҵ��� �������� ���� �ݺ���, ���⼱ 100ȸ ���´�.
void MixNumber(int _iArray[])
{
	srand(unsigned(time(NULL)));
	for (int i = 0; i < 100; ++i)
	{
		int irandomNumber1 = rand() % 25; // �� ���� ������ ������ ���ڸ� ������ ��
		int iRandomNumber2 = rand() % 25;
		int iTemp = 0;

		// swap �Լ� ������ ���´�. �ݺ��� �ȿ� �����Ƿ� 100ȸ ���´�.
		iTemp = _iArray[irandomNumber1];
		_iArray[irandomNumber1] = _iArray[iRandomNumber2];
		_iArray[iRandomNumber2] = iTemp;
	}
}