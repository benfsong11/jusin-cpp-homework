#include <iostream>
#include <time.h>

using namespace std;

int main(void)
{
	srand(unsigned(time(NULL)));
	int iRand = rand() % 10;

	int i = 0;
	while (10 > i) // i�� 0���� 9�� �� ������ 10�� �ݺ�
	{
		cout << "�̹� ���ڴ� " << iRand << "�Դϴ�." << endl;
		if (0 == iRand % 2)
		{
			cout << "�̰��� ¦���Դϴ�!" << endl;
			cout << "" << endl;
		}
		else if (1 == iRand % 2)
		{
			cout << "�̰��� Ȧ���Դϴ�!" << endl;
			cout << "" << endl;
		}
		++i;

		iRand = rand() % 10; // while���� �� ���� ���� �� �� iRand �� ���ʱ�ȭ
	}



	return 0;
}