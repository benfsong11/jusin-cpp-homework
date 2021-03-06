#include <iostream>

using namespace std;

typedef struct tagStatus
{
	char szJob[32];
	int iHp;
	int iMaxHp;
	int iPower;

}STATUS;

enum JOB
{
	Warrior = 1,
	Magician,
	Archer
};

enum MONSTER
{
	Bear = 1,
	Goblin,
	Devil
};

STATUS SelectJob();
void StatusView(STATUS* _pStatus);
void HuntingField(STATUS* _pPlayer);
void CreateMonster(STATUS* _pMonster, int _iInput);
void HuntingMonster(STATUS* _pPlayer, STATUS* _pMonster);

int main()
{
	STATUS tPlayer = {};

	tPlayer = SelectJob();

	int iInput = 0;

	while (true)
	{
		system("cls");
		StatusView(&tPlayer);
		cout << "1. 사냥하기 2. 종료하기 > ";
		cin >> iInput;

		switch (iInput)
		{
		case 1:
			HuntingField(&tPlayer);
			break;
		case 2:
			exit(0);
		default:
			cout << "잘못 입력하셨습니다. 다시 입력해 주세요." << endl;
			system("pause");
			continue;
		}
	}


	return 0;
}

STATUS SelectJob()
{
	STATUS tStatus = {};

	int iInput = 0;

	cout << "1. 전사 2. 마법사 3. 궁수 4. 종료하기 > ";
	cin >> iInput;

	switch (iInput)
	{
	case Warrior:
		strcpy_s(tStatus.szJob, 32, "전사");
		tStatus.iMaxHp = 100;
		tStatus.iHp = tStatus.iMaxHp;
		tStatus.iPower = 20;
		break;
	case Magician:
		strcpy_s(tStatus.szJob, 32, "마법사");
		tStatus.iMaxHp = 45;
		tStatus.iHp = tStatus.iMaxHp;
		tStatus.iPower = 40;
		break;
	case Archer:
		strcpy_s(tStatus.szJob, 32, "궁수");
		tStatus.iMaxHp = 60;
		tStatus.iHp = tStatus.iMaxHp;
		tStatus.iPower = 30;
		break;
	default:
		cout << "게임을 종료합니다." << endl;
		break;
	}

	return tStatus;

}

void StatusView(STATUS* _pStatus)
{
	cout << "======================================" << endl;
	cout << "직업: " << _pStatus->szJob << endl;
	cout << "체력/최대 체력: " << _pStatus->iHp << "/" << _pStatus->iMaxHp << endl;
	cout << "공격력: " << _pStatus->iPower << endl;
	cout << "======================================" << endl;
}

void HuntingField(STATUS* _pPlayer)
{
	int iInput = 0;
	STATUS tMonster[3] = {};

	while (true)
	{
		system("cls");
		StatusView(_pPlayer);
		cout << "1. 초급 던전 2. 중급 던전 3. 고급 던전 4. 뒤로 가기 > ";
		cin >> iInput;

		if (0 >= iInput || 4 < iInput)
			continue;
		else if (4 == iInput)
			return;
		else if (3 >= iInput)
		{
			CreateMonster(tMonster, iInput);
			HuntingMonster(_pPlayer, &tMonster[iInput - 1]);
		}
	}
}

void CreateMonster(STATUS* _pMonster, int _iInput)
{
	switch (_iInput)
	{
	case Bear:
		strcpy_s(_pMonster[_iInput - 1].szJob, 32, "곰");
		_pMonster[_iInput - 1].iMaxHp = 30;
		_pMonster[_iInput - 1].iHp = _pMonster[_iInput - 1].iMaxHp;
		_pMonster[_iInput - 1].iPower = 10;
		break;
	case Goblin:
		strcpy_s(_pMonster[_iInput - 1].szJob, 32, "고블린");
		_pMonster[_iInput - 1].iMaxHp = 50;
		_pMonster[_iInput - 1].iHp = _pMonster[_iInput - 1].iMaxHp;
		_pMonster[_iInput - 1].iPower = 30;
		break;
	case Devil:
		strcpy_s(_pMonster[_iInput - 1].szJob, 32, "악마");
		_pMonster[_iInput - 1].iMaxHp = 60;
		_pMonster[_iInput - 1].iHp = _pMonster[_iInput - 1].iMaxHp;
		_pMonster[_iInput - 1].iPower = 40;
		break;
	default:
		break;
	}
}

void HuntingMonster(STATUS* _pPlayer, STATUS* _pMonster)
{
	int iInput = 0;
	while (true)
	{
		system("cls");
		StatusView(_pPlayer);
		StatusView(_pMonster);

		cout << "1. 공격하기 2. 도망가기 > ";
		cin >> iInput;

		switch (iInput)
		{
		case 1:
			_pMonster->iHp -= _pPlayer->iPower;
			_pPlayer->iHp -= _pMonster->iPower;

			if (0 >= _pPlayer->iHp)
			{
				_pPlayer->iHp = _pPlayer->iMaxHp;
				_pMonster->iHp = _pMonster->iMaxHp;
				cout << "당신은 사망하셨습니다... 안녕히 가세요." << endl;
				system("pause");
				break;
			}

			if (0 >= _pMonster->iHp)
			{
				_pMonster->iHp = _pMonster->iMaxHp;
				cout << "축하합니다! 사냥에 성공하셨습니다!" << endl;
				system("pause");
				break;
			}
			break;
		case 2:
			return;
		default:
			break;
		}
	}
}