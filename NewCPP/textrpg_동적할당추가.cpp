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
		cout << "1. 사냥하기 2. 종료하기 > ";
		cin >> iInput;

		switch (iInput)
		{
		case 1:
			HuntingField(pPlayer);
			break;
		case 2:
			exit(0);
		default:
			cout << "잘못 입력하셨습니다. 다시 입력해 주세요." << endl;
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
		exit(0);
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

	FILE* fp = nullptr; // 저장하기 스트림
	FILE* fp2 = nullptr; // 불러오기 스트림

	while (true)
	{
		system("cls");
		StatusView(_pPlayer);
		cout << "1. 초급 던전 2. 중급 던전 3. 고급 던전 4. 뒤로 가기 5. 저장하기 6. 불러오기 > ";
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
			// 저장하기 코드(텍스트 모드)
			/*errno_t err_save = fopen_s(&fp, "../Data/text_rpg.txt", "wt");
			if (err_save == 0)
			{
				fputs(_pPlayer->szJob, fp);
				fputs("\n", fp);
				fprintf(fp, "%d\n", _pPlayer->iHp);
				fprintf(fp, "%d\n", _pPlayer->iMaxHp);
				fprintf(fp, "%d\n", _pPlayer->iPower);
				fclose(fp);
			}*/
			
			// 바이너리 모드
			errno_t err_save = fopen_s(&fp, "../Data/text_rpg.bin", "wb");
			if (err_save == 0)
			{
				fwrite(_pPlayer, sizeof(_pPlayer), 11, fp);
				// 내가 사용하는 구조체의 크기, sizeof(tagStatus)는 44바이트다.
				// fwrite 함수의 두 번째 인자, sizeof(_pPlayer)는 구조체 포인터이므로 4바이트다.
				// sizeof(_pPlayer)(4) * fwrite 함수의 세 번째 인자(11) == 44바이트 만큼 text_rpg.bin 파일에 저장한다.
				// sizeof(tagStatus)가 44바이트이기 때문에 위의 저장된 값이 44바이트 이상이어야 한다.
				// 만약 sizeof(_pPlayer) * 10 == 40바이트인 경우에는 마지막 4바이트 만큼의 데이터가 저장되지 않는다.
				fclose(fp);
			}
			else
			{
				cout << "파일 개방 실패..." << endl;
			}
			
		}
		else if (6 == iInput)
		{
			// 불러오기 코드(텍스트 모드)
			/*errno_t err_reload = fopen_s(&fp2, "../Data/text_rpg.txt", "rt");
			
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

				// _pPlayer->szJob에서 개행을 지우는 코드
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
			}*/
			
			// 바이너리 모드
			errno_t err_reload = fopen_s(&fp2, "../Data/text_rpg.bin", "rb");
			if (err_reload == 0)
			{
				fread(_pPlayer, sizeof(_pPlayer), 11, fp2);
				fclose(fp2);
			}
			else
			{
				cout << "파일 개방 실패..." << endl;
			}
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