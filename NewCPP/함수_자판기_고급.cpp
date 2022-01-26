#include <iostream>

using namespace std;

// 함수의 선언부
int checkCurrentMoney();
int inputCoin(int _iCurrentMoney);
void vendingMachine(int _iCurrentMoney, int _iCoin);

int main(void)
{
	// 현재 잔액과 코인을 함수 호출하여 변수에 담고 자판기 함수의 매개 변수로 넣는다.
	int iCurrentMoney = checkCurrentMoney();
	int iCoin = inputCoin(iCurrentMoney);
	vendingMachine(iCurrentMoney, iCoin);
	
	
	
	return 0;
}

int checkCurrentMoney(void)
{
	int iCurrentMoney = 0;
	cout << "현재 가지고 있는 돈은 얼마입니까? > ";
	cin >> iCurrentMoney;

	if (iCurrentMoney <= 0) // 현재 잔액이 0원이거나 그 이하이면(사용자가 임의로 음수를 입력했을 경우) 다시 잔액을 설정할 기회를 준다.
	{
		cout << "음료수를 사 드실 수 있는 돈을 가지고 계시지 않는군요... 죄송합니다." << endl;
		checkCurrentMoney(); // 재귀 함수를 통해 다시 잔액 설정으로 돌아간다.
	}
	else
		return iCurrentMoney;

}

int inputCoin(int _iCurrentMoney)
{
	int iCoin = 0;
	cout << "현재 잔액은 " << _iCurrentMoney << "원입니다. 콜라(1), 사이다(2), 환타(3), 거스름돈(4) 중 하나를 선택하세요. > ";
	cin >> iCoin;

	return iCoin;
}

void vendingMachine(int _iCurrentMoney, int _iCoin)
{
	int iCoke = 1000, iSprite = 800, iFanta = 700; // 콜라는 1000원, 사이다는 800원, 환타는 700원으로 설정한다.
	int iChange = 0; // 거스름돈을 담을 변수를 선언한다.

	while (_iCurrentMoney >= 0)
	{
		switch (_iCoin)
		{
		case 1:
			if (_iCurrentMoney >= iCoke) // 현재 잔액이 음료수의 값보다 많거나 같을 경우에만 실행한다.
			{
				_iCurrentMoney -= iCoke; // 현재 잔액에서 음료수의 값을 뺀 후 남은 잔액을 구한다.
				cout << "톡 쏘는 맛, 콜라입니다! 현재 남은 돈은 " << _iCurrentMoney << "원입니다." << endl;
				_iCoin = inputCoin(_iCurrentMoney); // 코인의 값을 다시 받아야 하므로 _iCoin을 재초기화한다.
				break;
			}
			else
			{
				cout << "가지고 있는 돈이 모자랍니다." << endl;
				_iCoin = inputCoin(_iCurrentMoney); // 코인의 값을 다시 받아야 하므로 _iCoin을 재초기화한다.
				break;
			}

		case 2:
			if (_iCurrentMoney >= iSprite)
			{
				_iCurrentMoney -= iSprite;
				cout << "시원한 탄산의 맛, 사이다입니다! 현재 남은 돈은 " << _iCurrentMoney << "원입니다." << endl;
				_iCoin = inputCoin(_iCurrentMoney);
				break;
			}
			else
			{
				cout << "가지고 있는 돈이 모자랍니다." << endl;
				_iCoin = inputCoin(_iCurrentMoney);
				break;
			}
		case 3:
			if (_iCurrentMoney >= iFanta)
			{
				_iCurrentMoney -= iFanta;
				cout << "환상의 오렌지맛, 환타입니다! 현재 남은 돈은 " << _iCurrentMoney << "원입니다." << endl;
				_iCoin = inputCoin(_iCurrentMoney);
				break;
			}
			else
			{
				cout << "가지고 있는 돈이 모자랍니다." << endl;
				_iCoin = inputCoin(_iCurrentMoney);
				break;
			}
		case 4:
			iChange = _iCurrentMoney; // 거스름돈 변수에 현재 잔액을 담는다.
			cout << "거스름돈 " << iChange << "원을 드리겠습니다. 안녕히 가세요." << endl;
			return; // 거스름돈을 받고 난 후 자판기 프로그램은 종료된다.
		default:
			cout << "자판기를 종료합니다. 안녕히 가세요." << endl;
			return; // 1, 2, 3, 4가 아닌 다른 숫자를 입력하면 자판기는 실행되지 않고 종료된다.
		}
	}
}