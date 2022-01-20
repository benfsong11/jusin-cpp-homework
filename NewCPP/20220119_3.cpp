#include <iostream>
#include <time.h>

using namespace std;

int main(void)
{
	

	int i = 0;
	while (5 > i)
	{
		int iMyNum = 0;

		cout << "가위(0), 바위(1), 보(2) 중 하나를 입력하세요 > ";
		cin >> iMyNum;
		if (2 < iMyNum || 0 > iMyNum)
		{
			cout << "잘못된 값을 입력하셨습니다. 다시 입력해 주세요." << endl;
		}

		srand(unsigned(time(NULL)));
		int iComNum = rand() % 3;

		if (iMyNum == iComNum) // 비겼을 때
		{
			cout << "사용자: " << iMyNum << " 컴퓨터: " << iComNum << " 비겼습니다." << endl;
		}
		else if ((iMyNum == 0 && iComNum == 2) || (iMyNum == 1 && iComNum == 0) || (iMyNum == 2 && iComNum == 1)) // 사용자가 이겼을 때
		{
			cout << "사용자: " << iMyNum << " 컴퓨터: " << iComNum << " 이겼습니다!" << endl;
		}
		else if ((iMyNum == 0 && iComNum == 1) || (iMyNum == 1 && iComNum == 2) || (iMyNum == 2 && iComNum == 0))
		{
			cout << "사용자: " << iMyNum << " 컴퓨터: " << iComNum << " 졌습니다..." << endl;
		}

		++i;

		iComNum = rand() % 3; // 다음 턴을 위해 사용자의 값을 다시 입력받고 컴퓨터의 값을 재초기화한다
	}


	return 0;
}