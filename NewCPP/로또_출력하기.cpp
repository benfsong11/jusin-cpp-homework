#include <iostream>

using namespace std;


void MixNumber(int* iLotto);
void SortNumber(int* iLotto);

int main()
{
	int iLotto[45] = {}; // �迭 iArray �ʱ�ȭ
	int iSize = sizeof(iLotto) / sizeof(int); // 45

	// �迭 iLotto�� 1���� 45���� ���� �ִ� �ݺ���
	for (int i = 0; i < iSize; ++i)
	{
		iLotto[i] = i + 1;
	}


	// 6�� ���� ����ϴ� �ݺ���
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


// �迭�� ���ҵ��� �������� ���� �ݺ���, ���⼱ 50ȸ ���´�.
void MixNumber(int* iLotto)
{
	srand(time(NULL));
	for (int i = 0; i < 50; ++i)
	{
		int irandomNumber1 = rand() % 45; // �� ���� ������ ������ ���ڸ� ������ ��
		int iRandomNumber2 = rand() % 45;
		int iTemp = 0;

		// swap �Լ� ������ ���´�. �ݺ��� �ȿ� �����Ƿ� 50ȸ ���´�.
		iTemp = iLotto[irandomNumber1];
		iLotto[irandomNumber1] = iLotto[iRandomNumber2];
		iLotto[iRandomNumber2] = iTemp;
	}
}

// ���� ���ķ� �������� ����
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