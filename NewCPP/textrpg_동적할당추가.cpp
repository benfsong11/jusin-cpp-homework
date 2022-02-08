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
	STATUS* pPlayer = new STATUS;

	*pPlayer = SelectJob();

	if (nullptr == pPlayer)
		return 0;

	int iInput = 0;

	while (true)
	{
		system("cls");
		StatusView(pPlayer);
		cout << "1. ����ϱ� 2. �����ϱ� > ";
		cin >> iInput;

		switch (iInput)
		{
		case 1:
			HuntingField(pPlayer);
			break;
		case 2:
			exit(0);
		default:
			cout << "�߸� �Է��ϼ̽��ϴ�. �ٽ� �Է��� �ּ���." << endl;
			system("pause");
			continue;
		}
		
	}
	if (nullptr != pPlayer)
	{
		delete pPlayer;
		pPlayer = nullptr;
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
		exit(0);
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

	FILE* fp = nullptr; // �����ϱ� ��Ʈ��
	FILE* fp2 = nullptr; // �ҷ����� ��Ʈ��

	while (true)
	{
		system("cls");
		StatusView(_pPlayer);
		cout << "1. �ʱ� ���� 2. �߱� ���� 3. ��� ���� 4. �ڷ� ���� 5. �����ϱ� 6. �ҷ����� > ";
		cin >> iInput;

		if (0 >= iInput || 6 < iInput)
			continue;
		else if (4 == iInput)
			return;
		else if (3 >= iInput)
		{
			CreateMonster(tMonster, iInput);
			HuntingMonster(_pPlayer, &tMonster[iInput - 1]);
		}
		else if (5 == iInput)
		{
			// �����ϱ� �ڵ�
			errno_t err_save = fopen_s(&fp, "../Data/text_rpg.txt", "wt");
			if (err_save == 0)
			{
				fputs(_pPlayer->szJob, fp);
				fputs("\n", fp);
				fprintf(fp, "%d\n", _pPlayer->iHp);
				fprintf(fp, "%d\n", _pPlayer->iMaxHp);
				fprintf(fp, "%d\n", _pPlayer->iPower);
				fclose(fp);
			}
			
		}
		else if (6 == iInput)
		{
			// �ҷ����� �ڵ�
			errno_t err_reload = fopen_s(&fp2, "../Data/text_rpg.txt", "rt");
			
			if (err_reload == 0)
			{
				char szJobReload[32] = "";
				int iHpReload = 0;
				int iMaxHpReload = 0;
				int iPowerReload = 0;
				fgets(szJobReload, sizeof(szJobReload), fp2);
				fscanf_s(fp2, "%d", &iHpReload);
				fscanf_s(fp2, "%d", &iMaxHpReload);
				fscanf_s(fp2, "%d", &iPowerReload);

				strcpy_s(_pPlayer->szJob, 32, szJobReload);

				// _pPlayer->szJob���� ������ ����� �ڵ�
				for (int i = 0; _pPlayer->szJob[i] != 0; i++) {
					if (_pPlayer->szJob[i] == '\n') {
						_pPlayer->szJob[i] = 0;
						break;
					}
				}
				_pPlayer->iHp = iHpReload;
				_pPlayer->iMaxHp = iMaxHpReload;
				_pPlayer->iPower = iPowerReload;

				fclose(fp2);
			}
			
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