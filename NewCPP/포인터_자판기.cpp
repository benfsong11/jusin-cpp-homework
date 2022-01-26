#include <iostream>

using namespace std;

// �Լ��� �����
int checkCurrentMoney();
int inputCoin(int* _iCurrentMoney);
void vendingMachine(int* _iCurrentMoney, int* _iCoin);

int main(void)
{
	// ���� �ܾװ� ������ �Լ� ȣ���Ͽ� ������ ��� ���Ǳ� �Լ��� �Ű� ������ �ִ´�.
	int iCurrentMoney = checkCurrentMoney();
	while (iCurrentMoney >= 0)
	{
		int iCoin = inputCoin(&iCurrentMoney);
		// iCurrentMoney�� �ּҰ��� �����Ѵ�.
		// �׷��� ���ο� iCoin ���� �Է��ϸ� iCurrentMoney�� ���� �ٲ��.
		// vendingMachine()���� inputCoin()�� ��ȣ������ �ʾƵ� �ȴ�.
		// �����͸� ������� �ʾ��� ������ �ݺ����� ���� �ٽ� inputCoin()�� ȣ��Ǿ� iCurrentMoney�� ���� ���� �Է��ص� ó�� �Է��ߴ� ������ ������ �ʾҴ�.
		// ���� ��� �����͸� ������� �ʾ��� ������ iCurrentMoney�� 1000�� �Է��ϰ� 1000��¥�� �ݶ� �������� ��, �ٷ� �������� �ܾ��� 0���� ������
		// while���� ���� inputCoin()�� ��ȣ��Ǹ� iCurrentMoney�� �ٽ� 1000�� �Ǿ� �־���.
		// �̴� iCurrentMoney�� main �Լ� ������ ����� ���� �����̱� ������ �Լ��� �Ű� ������ ����� ���̱� �����̴�.
		// �Լ� ȣ�� ���Ŀ� ���簪�� ������ �ִ� �Ű� ������ �ڵ������� �����ȴ�.
		vendingMachine(&iCurrentMoney, &iCoin);
	}




	return 0;
}

int checkCurrentMoney(void)
{
	int iCurrentMoney = 0;
	cout << "������ �־� �ּ���. > ";
	cin >> iCurrentMoney;

	if (iCurrentMoney <= 0) // ���� �ܾ��� 0���̰ų� �� �����̸�(����ڰ� ���Ƿ� ������ �Է����� ���) �ٽ� �ܾ��� ������ ��ȸ�� �ش�.
	{
		cout << "������� �� ��� �� �ִ� ���� ������ ����� �ʴ±���... �˼��մϴ�." << endl;
		checkCurrentMoney(); // ��� �Լ��� ���� �ٽ� �ܾ� �������� ���ư���.
	}
	else
		return iCurrentMoney;

}

int inputCoin(int* _iCurrentMoney)
{
	int iCoin = 0;
	cout << "���� �ܾ��� " << *_iCurrentMoney << "���Դϴ�. �ݶ�(1), ���̴�(2), ȯŸ(3), �Ž�����(������) �� �ϳ��� �����ϼ���. > ";
	cin >> iCoin;

	return iCoin;
}

void vendingMachine(int* _iCurrentMoney, int* _iCoin)
{
	int iCoke = 1000, iSprite = 800, iFanta = 700; // �ݶ�� 1000��, ���̴ٴ� 800��, ȯŸ�� 700������ �����Ѵ�.
	int iChange = 0; // �Ž������� ���� ������ �����Ѵ�.


	switch (*_iCoin)
	{
	case 1:
		if (*_iCurrentMoney >= iCoke) // ���� �ܾ��� ������� ������ ���ų� ���� ��쿡�� �����Ѵ�.
		{
			*_iCurrentMoney -= iCoke; // ���� �ܾ׿��� ������� ���� �� �� ���� �ܾ��� ���Ѵ�.
			cout << "�� ��� ��, �ݶ��Դϴ�! ���� ���� ���� " << *_iCurrentMoney << "���Դϴ�." << endl;
			break;
		}
		else
		{
			cout << "������ �ִ� ���� ���ڶ��ϴ�." << endl;
			break;
		}

	case 2:
		if (*_iCurrentMoney >= iSprite)
		{
			*_iCurrentMoney -= iSprite;
			cout << "�ÿ��� ź���� ��, ���̴��Դϴ�! ���� ���� ���� " << *_iCurrentMoney << "���Դϴ�." << endl;
			break;
		}
		else
		{
			cout << "������ �ִ� ���� ���ڶ��ϴ�." << endl;
			break;
		}
	case 3:
		if (*_iCurrentMoney >= iFanta)
		{
			*_iCurrentMoney -= iFanta;
			cout << "ȯ���� ��������, ȯŸ�Դϴ�! ���� ���� ���� " << *_iCurrentMoney << "���Դϴ�." << endl;
			break;
		}
		else
		{
			cout << "������ �ִ� ���� ���ڶ��ϴ�." << endl;
			break;
		}
	default:
		iChange = *_iCurrentMoney; // �Ž����� ������ ���� �ܾ��� ��´�.
		if (iChange == 0)
			cout << "�Ž������� " << iChange << "���Դϴ�. �ȳ��� ������." << endl;
		else
			cout << "�Ž����� " << iChange << "���� �帮�ڽ��ϴ�. �ȳ��� ������." << endl;
		exit(0); // �Ž������� �ް� �� �� ���Ǳ� ���α׷��� ����ȴ�.
	}

}