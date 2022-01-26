#include <iostream>

using namespace std;

// 함수의 선언부
int checkCurrentMoney();
int inputCoin(int* _iCurrentMoney);
void vendingMachine(int* _iCurrentMoney, int* _iCoin);

int main(void)
{
	// 현재 잔액과 코인을 함수 호출하여 변수에 담고 자판기 함수의 매개 변수로 넣는다.
	int iCurrentMoney = checkCurrentMoney();
	while (iCurrentMoney >= 0)
	{
		int iCoin = inputCoin(&iCurrentMoney);
		// iCurrentMoney의 주소값을 참조한다.
		// 그래서 새로운 iCoin 값을 입력하면 iCurrentMoney의 값이 바뀐다.
		// vendingMachine()에서 inputCoin()을 재호출하지 않아도 된다.
		// 포인터를 사용하지 않았을 때에는 반복문이 돌아 다시 inputCoin()이 호출되어 iCurrentMoney의 값을 새로 입력해도 처음 입력했던 값에서 변하지 않았다.
		// 예를 들어 포인터를 사용하지 않았을 때에는 iCurrentMoney에 1000을 입력하고 1000원짜리 콜라를 선택했을 때, 바로 다음에는 잔액이 0원이 되지만
		// while문을 통해 inputCoin()이 재호출되면 iCurrentMoney는 다시 1000이 되어 있었다.
		// 이는 iCurrentMoney가 main 함수 내에서 선언된 지역 변수이기 때문에 함수의 매개 변수로 복사된 값이기 때문이다.
		// 함수 호출 이후에 복사값을 가지고 있던 매개 변수는 자동적으로 해제된다.
		vendingMachine(&iCurrentMoney, &iCoin);
	}




	return 0;
}

int checkCurrentMoney(void)
{
	int iCurrentMoney = 0;
	cout << "현금을 넣어 주세요. > ";
	cin >> iCurrentMoney;

	if (iCurrentMoney <= 0) // 현재 잔액이 0원이거나 그 이하이면(사용자가 임의로 음수를 입력했을 경우) 다시 잔액을 설정할 기회를 준다.
	{
		cout << "음료수를 사 드실 수 있는 돈을 가지고 계시지 않는군요... 죄송합니다." << endl;
		checkCurrentMoney(); // 재귀 함수를 통해 다시 잔액 설정으로 돌아간다.
	}
	else
		return iCurrentMoney;

}

int inputCoin(int* _iCurrentMoney)
{
	int iCoin = 0;
	cout << "현재 잔액은 " << *_iCurrentMoney << "원입니다. 콜라(1), 사이다(2), 환타(3), 거스름돈(나머지) 중 하나를 선택하세요. > ";
	cin >> iCoin;

	return iCoin;
}

void vendingMachine(int* _iCurrentMoney, int* _iCoin)
{
	int iCoke = 1000, iSprite = 800, iFanta = 700; // 콜라는 1000원, 사이다는 800원, 환타는 700원으로 설정한다.
	int iChange = 0; // 거스름돈을 담을 변수를 선언한다.


	switch (*_iCoin)
	{
	case 1:
		if (*_iCurrentMoney >= iCoke) // 현재 잔액이 음료수의 값보다 많거나 같을 경우에만 실행한다.
		{
			*_iCurrentMoney -= iCoke; // 현재 잔액에서 음료수의 값을 뺀 후 남은 잔액을 구한다.
			cout << "톡 쏘는 맛, 콜라입니다! 현재 남은 돈은 " << *_iCurrentMoney << "원입니다." << endl;
			break;
		}
		else
		{
			cout << "가지고 있는 돈이 모자랍니다." << endl;
			break;
		}

	case 2:
		if (*_iCurrentMoney >= iSprite)
		{
			*_iCurrentMoney -= iSprite;
			cout << "시원한 탄산의 맛, 사이다입니다! 현재 남은 돈은 " << *_iCurrentMoney << "원입니다." << endl;
			break;
		}
		else
		{
			cout << "가지고 있는 돈이 모자랍니다." << endl;
			break;
		}
	case 3:
		if (*_iCurrentMoney >= iFanta)
		{
			*_iCurrentMoney -= iFanta;
			cout << "환상의 오렌지맛, 환타입니다! 현재 남은 돈은 " << *_iCurrentMoney << "원입니다." << endl;
			break;
		}
		else
		{
			cout << "가지고 있는 돈이 모자랍니다." << endl;
			break;
		}
	default:
		iChange = *_iCurrentMoney; // 거스름돈 변수에 현재 잔액을 담는다.
		if (iChange == 0)
			cout << "거스름돈은 " << iChange << "원입니다. 안녕히 가세요." << endl;
		else
			cout << "거스름돈 " << iChange << "원을 드리겠습니다. 안녕히 가세요." << endl;
		exit(0); // 거스름돈을 받고 난 후 자판기 프로그램은 종료된다.
	}

}