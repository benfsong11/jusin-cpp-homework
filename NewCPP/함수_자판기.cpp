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

	cout << "�ݶ�(1), ���̴�(2), ȯŸ(3) > ";
	cin >> coin;

	switch (coin)
	{
	case 1:
		cout << "�� ��� ��, �ݶ��Դϴ�!" << endl;
		break;
	case 2:
		cout << "�ε巯�� ź���� ��, ���̴��Դϴ�!" << endl;
		break;
	case 3:
		cout << "ȯ���� ��, ȯŸ�Դϴ�!" << endl;
		break;
	default:
		cout << "1, 2, 3 �� �ϳ��� �Է��� �ּ���." << endl;
		vendingMachine();
		break;
	}
}