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
		cout << "1. ����ϱ� 2. �����ϱ� > ";
		cin >> iInput;

		switch (iInput)
		{
		case 1:
			HuntingField(&tPlayer);
			break;
		case 2:
			exit(0);
		default:
			cout << "�߸� �Է��ϼ̽��ϴ�. �ٽ� �Է��� �ּ���." << endl;
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

	cout << "1. ���� 2. ������ 3. �ü� 4. �����ϱ� > ";
	cin >> iInput;

	switch (iInput)
	{
	case Warrior:
		strcpy_s(tStatus.szJob, 32, "����");
		tStatus.iMaxHp = 100;
		tStatus.iHp = tStatus.iMaxHp;
		tStatus.iPower = 20;
		break;
	case Magician:
		strcpy_s(tStatus.szJob, 32, "������");
		tStatus.iMaxHp = 45;
		tStatus.iHp = tStatus.iMaxHp;
		tStatus.iPower = 40;
		break;
	case Archer:
		strcpy_s(tStatus.szJob, 32, "�ü�");
		tStatus.iMaxHp = 60;
		tStatus.iHp = tStatus.iMaxHp;
		tStatus.iPower = 30;
		break;
	default:
		cout << "������ �����մϴ�." << endl;
		break;
	}

	return tStatus;

}

void StatusView(STATUS* _pStatus)
{
	cout << "======================================" << endl;
	cout << "����: " << _pStatus->szJob << endl;
	cout << "ü��/�ִ� ü��: " << _pStatus->iHp << "/" << _pStatus->iMaxHp << endl;
	cout << "���ݷ�: " << _pStatus->iPower << endl;
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
		cout << "1. �ʱ� ���� 2. �߱� ���� 3. ��� ���� 4. �ڷ� ���� > ";
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
		strcpy_s(_pMonster[_iInput - 1].szJob, 32, "��");
		_pMonster[_iInput - 1].iMaxHp = 30;
		_pMonster[_iInput - 1].iHp = _pMonster[_iInput - 1].iMaxHp;
		_pMonster[_iInput - 1].iPower = 10;
		break;
	case Goblin:
		strcpy_s(_pMonster[_iInput - 1].szJob, 32, "���");
		_pMonster[_iInput - 1].iMaxHp = 50;
		_pMonster[_iInput - 1].iHp = _pMonster[_iInput - 1].iMaxHp;
		_pMonster[_iInput - 1].iPower = 30;
		break;
	case Devil:
		strcpy_s(_pMonster[_iInput - 1].szJob, 32, "�Ǹ�");
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

		cout << "1. �����ϱ� 2. �������� > ";
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
				cout << "����� ����ϼ̽��ϴ�... �ȳ��� ������." << endl;
				system("pause");
				break;
			}

			if (0 >= _pMonster->iHp)
			{
				_pMonster->iHp = _pMonster->iMaxHp;
				cout << "�����մϴ�! ��ɿ� �����ϼ̽��ϴ�!" << endl;
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