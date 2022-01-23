#include <iostream>

using namespace std;

void vendingMachine(void);

int main(void)
{
	vendingMachine();

	return 0;
}

void vendingMachine(void)
{
	int coin = 0;

	cout << "콜라(1), 사이다(2), 환타(3) > ";
	cin >> coin;

	switch (coin)
	{
	case 1:
		cout << "톡 쏘는 맛, 콜라입니다!" << endl;
		break;
	case 2:
		cout << "부드러운 탄산의 맛, 사이다입니다!" << endl;
		break;
	case 3:
		cout << "환상의 맛, 환타입니다!" << endl;
		break;
	default:
		cout << "1, 2, 3 중 하나를 입력해 주세요." << endl;
		vendingMachine();
		break;
	}
}