#include <iostream>
#include <time.h>

using namespace std;

int main(void)
{
	

	int i = 0;
	while (5 > i)
	{
		int iMyNum = 0;

		cout << "����(0), ����(1), ��(2) �� �ϳ��� �Է��ϼ��� > ";
		cin >> iMyNum;
		if (2 < iMyNum || 0 > iMyNum)
		{
			cout << "�߸��� ���� �Է��ϼ̽��ϴ�. �ٽ� �Է��� �ּ���." << endl;
		}

		srand(unsigned(time(NULL)));
		int iComNum = rand() % 3;

		if (iMyNum == iComNum) // ����� ��
		{
			cout << "�����: " << iMyNum << " ��ǻ��: " << iComNum << " �����ϴ�." << endl;
		}
		else if ((iMyNum == 0 && iComNum == 2) || (iMyNum == 1 && iComNum == 0) || (iMyNum == 2 && iComNum == 1)) // ����ڰ� �̰��� ��
		{
			cout << "�����: " << iMyNum << " ��ǻ��: " << iComNum << " �̰���ϴ�!" << endl;
		}
		else if ((iMyNum == 0 && iComNum == 1) || (iMyNum == 1 && iComNum == 2) || (iMyNum == 2 && iComNum == 0))
		{
			cout << "�����: " << iMyNum << " ��ǻ��: " << iComNum << " �����ϴ�..." << endl;
		}

		++i;

		iComNum = rand() % 3; // ���� ���� ���� ������� ���� �ٽ� �Է¹ް� ��ǻ���� ���� ���ʱ�ȭ�Ѵ�
	}


	return 0;
}