#include <iostream>
#include <time.h>

using namespace std;

int main(void)
{
	srand(unsigned(time(NULL)));
	int iRand = rand() % 10;

	int i = 0;
	while (10 > i) // i가 0부터 9가 될 때까지 10번 반복
	{
		cout << "이번 숫자는 " << iRand << "입니다." << endl;
		if (0 == iRand % 2)
		{
			cout << "이것은 짝수입니다!" << endl;
			cout << "" << endl;
		}
		else if (1 == iRand % 2)
		{
			cout << "이것은 홀수입니다!" << endl;
			cout << "" << endl;
		}
		++i;

		iRand = rand() % 10; // while문을 한 바퀴 돌고 난 후 iRand 값 재초기화
	}



	return 0;
}