#include <iostream>

using namespace std;

int main()
{
	int iArray[25] = {}; // �迭 iArray �ʱ�ȭ
	int iSize = sizeof(iArray) / sizeof(int); // 25

	// �迭 iArray�� 1���� 25���� ���� �ִ� �ݺ���
	for (int i = 0; i < iSize; ++i)
	{
		iArray[i] = i + 1;
	}
	
	// �迭 ��� �ݺ���
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