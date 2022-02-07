#include <iostream>

using namespace std;

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

struct tagStatus
{
    char cJob[20];
    int iHp;
    int iPower;
};

void Status(JOB _job, tagStatus _tStatusArray[]);
int HuntOrQuit();
void HuntMonster(JOB _job, int _iMonster, tagStatus _tStatusArray[], tagStatus _tMonsterArray[]);
int AttackPlayer(JOB _job, int _iMonster, tagStatus _tStatusArray[], tagStatus _tMonsterArray[]);
int AttackMonster(JOB _job, int _iMonster, tagStatus _tStatusArray[], tagStatus _tMonsterArray[]);

int main()
{
    tagStatus tStatusArray[3] = { { "전사", 100, 20 }, { "마법사", 45, 40 }, { "궁수", 60, 30} };
    tagStatus tMonsterArray[3] = { { "곰", 30, 10 }, { "고블린", 50, 30 }, { "악마", 60, 40} };

    int iInput = 0;

    cout << "1. 전사 2. 마법사 3. 궁수 4. 종료 > ";
    cin >> iInput;

    switch (iInput)
    {
    case Warrior:
    {
        Status(Warrior, tStatusArray);
        int iMonster = HuntOrQuit();
        HuntMonster(Warrior, iMonster, tStatusArray, tMonsterArray);
        break;
    }
    case Magician:
    {
        Status(Magician, tStatusArray);
        int iMonster = HuntOrQuit();
        HuntMonster(Magician, iMonster, tStatusArray, tMonsterArray);
        break;
    }
    case Archer:
    {
        Status(Archer, tStatusArray);
        int iMonster = HuntOrQuit();
        HuntMonster(Archer, iMonster, tStatusArray, tMonsterArray);
        break;
    }
    case 4:
    {
        exit(0);
    }
    default:
        break;
    }

    cout << "게임이 종료되었습니다!" << endl;

    return 0;
}

void Status(JOB _job, tagStatus _tStatusArray[])
{
    cout << "당신은 " << _tStatusArray[_job - 1].cJob << "입니다!" << endl;
    cout << "=====================================" << endl;
    cout << "직업: " << _tStatusArray[_job - 1].cJob << endl;
    cout << "체력: " << _tStatusArray[_job - 1].iHp << endl;
    cout << "공격력: " << _tStatusArray[_job - 1].iPower << endl;
    cout << "=====================================" << endl;
}



int HuntOrQuit()
{
    int iInput = 0;
    cout << "1. 사냥 2. 종료 > ";
    cin >> iInput;

    switch (iInput)
    {
    case 1:
    {
        int iHuntingGround = 0;
        cout << "1. 초급 2. 중급 3. 고급 4. 종료 > ";
        cin >> iHuntingGround;
        return iHuntingGround;
    }
    case 2:
    {
        exit(0);
    }
    default:
        exit(0);
    }
}

void HuntMonster(JOB _job, int _iMonster, tagStatus _tStatusArray[], tagStatus _tMonsterArray[])
{
    while (_tStatusArray[_job - 1].iHp > 0 || _tMonsterArray[_iMonster - 1].iHp > 0)
    {
        system("cls");

        cout << "플레이어 상태" << endl;
        cout << "=====================================" << endl;
        cout << "직업: " << _tStatusArray[_job - 1].cJob << endl
            cout << "체력: " << _tStatusArray[_job - 1].iHp << endl;
        cout << "공격력: " << _tStatusArray[_job - 1].iPower << endl;
        cout << "=====================================" << endl;
        cout << endl;

        cout << "몬스터 상태" << endl;
        cout << "=====================================" << endl;
        cout << "이름: " << _tMonsterArray[_iMonster - 1].cJob << endl;
        cout << "체력: " << _tMonsterArray[_iMonster - 1].iHp << endl;
        cout << "공격력: " << _tMonsterArray[_iMonster - 1].iPower << endl;
        cout << "=====================================" << endl;



        int iAttack = 0;

        cout << "1. 공격 2. 도망가기 > ";
        cin >> iAttack;

        switch (iAttack)
        {
        case 1:
        {
            int iMonsterHp = AttackPlayer(_job, _iMonster, _tStatusArray, _tMonsterArray);
            int iMyHp = AttackMonster(_job, _iMonster, _tStatusArray, _tMonsterArray);

            // 함수를 통해 리턴된 HP값들을 기존의 배열에 넣어준다.
            _tStatusArray[_job - 1].iHp = iMyHp;
            _tMonsterArray[_iMonster - 1].iHp = iMonsterHp;

            // HP값이 음수가 될 경우에는 0으로 바꿔준다.
            if (_tMonsterArray[_iMonster - 1].iHp < 0)
                _tMonsterArray[_iMonster - 1].iHp = 0;
            if (_tStatusArray[_job - 1].iHp < 0)
                _tStatusArray[_job - 1].iHp = 0;



            // 사용자의 체력이 0보다 크면서 몬스터의 체력이 0이 되면 사냥에 성공하며 다음 사냥으로 이동한다.
            if (_tMonsterArray[_iMonster - 1].iHp == 0 && _tStatusArray[_job - 1].iHp > 0)
            {
                cout << endl;
                cout << "몬스터 사냥에 성공했습니다!" << endl;

                if (_iMonster == 1)
                    _tMonsterArray[_iMonster - 1].iHp = 30; // 곰의 체력을 다시 원상복구시킨다.
                else if (_iMonster == 2)
                    _tMonsterArray[_iMonster - 1].iHp = 50; // 고블린의 체력을 다시 원상복구시킨다.
                else if (_iMonster == 3)
                    _tMonsterArray[_iMonster - 1].iHp = 60; // 악마의 체력을 다시 원상복구시킨다.
                HuntOrQuit();
            }

            // 사용자의 체력이 0이 되면 몬스터의 체력과는 상관없이 게임이 종료된다.
            if (_tStatusArray[_job - 1].iHp == 0)
            {
                cout << endl;
                cout << "당신은 죽었습니다..." << endl;
                exit(0);
            }
            break;
        }
        case 2:
        {
            exit(0);
        }
        default:
            break;
        }
    }
}



// 사용자가 공격하는 함수
int AttackPlayer(JOB _job, int _iMonster, tagStatus _tStatusArray[], tagStatus _tMonsterArray[])
{
    int monsterHp = _tMonsterArray[_iMonster - 1].iHp;
    int myPower = _tStatusArray[_job - 1].iPower;
    return monsterHp - myPower; // 몬스터의 HP에서 사용자의 공격력 만큼 뺀다.
}



// 몬스터가 공격하는 함수
int AttackMonster(JOB _job, int _iMonster, tagStatus _tStatusArray[], tagStatus _tMonsterArray[])
{
    int myHp = _tStatusArray[_job - 1].iHp;
    int monsterPower = _tMonsterArray[_iMonster - 1].iPower;
    return myHp - monsterPower; // 사용자의 HP에서 몬스터의 공격력 만큼 뺀다.
}