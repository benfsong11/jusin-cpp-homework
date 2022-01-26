#include <iostream>

using namespace std;

// �Լ��� �����
int checkCurrentMoney();
int inputCoin(int _iCurrentMoney);
void vendingMachine(int _iCurrentMoney, int _iCoin);

int main(void)
{
	// ���� �ܾװ� ������ �Լ� ȣ���Ͽ� ������ ��� ���Ǳ� �Լ��� �Ű� ������ �ִ´�.
	int iCurrentMoney = checkCurrentMoney();
	int iCoin = inputCoin(iCurrentMoney);
	vendingMachine(iCurrentMoney, iCoin);
	
	
	
	return 0;
}

int checkCurrentMoney(void)
{
	int iCurrentMoney = 0;
	cout << "���� ������ �ִ� ���� ���Դϱ�? > ";
	cin >> iCurrentMoney;

	if (iCurrentMoney <= 0) // ���� �ܾ��� 0���̰ų� �� �����̸�(����ڰ� ���Ƿ� ������ �Է����� ���) �ٽ� �ܾ��� ������ ��ȸ�� �ش�.
	{
		cout << "������� �� ��� �� �ִ� ���� ������ ����� �ʴ±���... �˼��մϴ�." << endl;
		checkCurrentMoney(); // ��� �Լ��� ���� �ٽ� �ܾ� �������� ���ư���.
	}
	else
		return iCurrentMoney;

}

int inputCoin(int _iCurrentMoney)
{
	int iCoin = 0;
	cout << "���� �ܾ��� " << _iCurrentMoney << "���Դϴ�. �ݶ�(1), ���̴�(2), ȯŸ(3), �Ž�����(4) �� �ϳ��� �����ϼ���. > ";
	cin >> iCoin;

	return iCoin;
}

void vendingMachine(int _iCurrentMoney, int _iCoin)
{
	int iCoke = 1000, iSprite = 800, iFanta = 700; // �ݶ�� 1000��, ���̴ٴ� 800��, ȯŸ�� 700������ �����Ѵ�.
	int iChange = 0; // �Ž������� ���� ������ �����Ѵ�.

	while (_iCurrentMoney >= 0)
	{
		switch (_iCoin)
		{
		case 1:
			if (_iCurrentMoney >= iCoke) // ���� �ܾ��� ������� ������ ���ų� ���� ��쿡�� �����Ѵ�.
			{
				_iCurrentMoney -= iCoke; // ���� �ܾ׿��� ������� ���� �� �� ���� �ܾ��� ���Ѵ�.
				cout << "�� ��� ��, �ݶ��Դϴ�! ���� ���� ���� " << _iCurrentMoney << "���Դϴ�." << endl;
				_iCoin = inputCoin(_iCurrentMoney); // ������ ���� �ٽ� �޾ƾ� �ϹǷ� _iCoin�� ���ʱ�ȭ�Ѵ�.
				break;
			}
			else
			{
				cout << "������ �ִ� ���� ���ڶ��ϴ�." << endl;
				_iCoin = inputCoin(_iCurrentMoney); // ������ ���� �ٽ� �޾ƾ� �ϹǷ� _iCoin�� ���ʱ�ȭ�Ѵ�.
				break;
			}

		case 2:
			if (_iCurrentMoney >= iSprite)
			{
				_iCurrentMoney -= iSprite;
				cout << "�ÿ��� ź���� ��, ���̴��Դϴ�! ���� ���� ���� " << _iCurrentMoney << "���Դϴ�." << endl;
				_iCoin = inputCoin(_iCurrentMoney);
				break;
			}
			else
			{
				cout << "������ �ִ� ���� ���ڶ��ϴ�." << endl;
				_iCoin = inputCoin(_iCurrentMoney);
				break;
			}
		case 3:
			if (_iCurrentMoney >= iFanta)
			{
				_iCurrentMoney -= iFanta;
				cout << "ȯ���� ��������, ȯŸ�Դϴ�! ���� ���� ���� " << _iCurrentMoney << "���Դϴ�." << endl;
				_iCoin = inputCoin(_iCurrentMoney);
				break;
			}
			else
			{
				cout << "������ �ִ� ���� ���ڶ��ϴ�." << endl;
				_iCoin = inputCoin(_iCurrentMoney);
				break;
			}
		case 4:
			iChange = _iCurrentMoney; // �Ž����� ������ ���� �ܾ��� ��´�.
			cout << "�Ž����� " << iChange << "���� �帮�ڽ��ϴ�. �ȳ��� ������." << endl;
			return; // �Ž������� �ް� �� �� ���Ǳ� ���α׷��� ����ȴ�.
		default:
			cout << "���Ǳ⸦ �����մϴ�. �ȳ��� ������." << endl;
			return; // 1, 2, 3, 4�� �ƴ� �ٸ� ���ڸ� �Է��ϸ� ���Ǳ�� ������� �ʰ� ����ȴ�.
		}
	}
}