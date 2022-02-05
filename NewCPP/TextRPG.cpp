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

    tagStatus tStatusArray[3] = { { "����", 100, 20 }, { "������", 45, 40 }, { "�ü�", 60, 30} };

    tagStatus tMonsterArray[3] = { { "��", 30, 10 }, { "���", 50, 30 }, { "�Ǹ�", 60, 40} };







    int iInput = 0;

    cout << "1. ���� 2. ������ 3. �ü� 4. ���� > ";

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



    cout << "������ ����Ǿ����ϴ�!" << endl;



    return 0;

}



void Status(JOB _job, tagStatus _tStatusArray[])

{



    cout << "����� " << _tStatusArray[_job - 1].cJob << "�Դϴ�!" << endl;

    cout << "=====================================" << endl;

    cout << "����: " << _tStatusArray[_job - 1].cJob << endl;

    cout << "ü��: " << _tStatusArray[_job - 1].iHp << endl;

    cout << "���ݷ�: " << _tStatusArray[_job - 1].iPower << endl;

    cout << "=====================================" << endl;



}



int HuntOrQuit()

{

    int iInput = 0;

    cout << "1. ��� 2. ���� > ";

    cin >> iInput;



    switch (iInput)

    {

    case 1:

    {

        int iHuntingGround = 0;

        cout << "1. �ʱ� 2. �߱� 3. ��� 4. ���� > ";

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

        cout << "�÷��̾� ����" << endl;

        cout << "=====================================" << endl;

        cout << "����: " << _tStatusArray[_job - 1].cJob << endl;

        cout << "ü��: " << _tStatusArray[_job - 1].iHp << endl;

        cout << "���ݷ�: " << _tStatusArray[_job - 1].iPower << endl;

        cout << "=====================================" << endl;

        cout << endl;



        cout << "���� ����" << endl;

        cout << "=====================================" << endl;

        cout << "�̸�: " << _tMonsterArray[_iMonster - 1].cJob << endl;

        cout << "ü��: " << _tMonsterArray[_iMonster - 1].iHp << endl;

        cout << "���ݷ�: " << _tMonsterArray[_iMonster - 1].iPower << endl;

        cout << "=====================================" << endl;



        int iAttack = 0;

        cout << "1. ���� 2. �������� > ";

        cin >> iAttack;



        switch (iAttack)

        {

        case 1:

        {

            int iMonsterHp = AttackPlayer(_job, _iMonster, _tStatusArray, _tMonsterArray);

            int iMyHp = AttackMonster(_job, _iMonster, _tStatusArray, _tMonsterArray);



            // �Լ��� ���� ���ϵ� HP������ ������ �迭�� �־��ش�.

            _tStatusArray[_job - 1].iHp = iMyHp;

            _tMonsterArray[_iMonster - 1].iHp = iMonsterHp;



            // HP���� ������ �� ��쿡�� 0���� �ٲ��ش�.

            if (_tMonsterArray[_iMonster - 1].iHp < 0)

                _tMonsterArray[_iMonster - 1].iHp = 0;

            if (_tStatusArray[_job - 1].iHp < 0)

                _tStatusArray[_job - 1].iHp = 0;



            // ������� ü���� 0���� ũ�鼭 ������ ü���� 0�� �Ǹ� ��ɿ� �����ϸ� ���� ������� �̵��Ѵ�.

            if (_tMonsterArray[_iMonster - 1].iHp == 0 && _tStatusArray[_job - 1].iHp > 0)

            {

                cout << endl;

                cout << "���� ��ɿ� �����߽��ϴ�!" << endl;

                if (_iMonster == 1)

                    _tMonsterArray[_iMonster - 1].iHp = 30; // ���� ü���� �ٽ� ���󺹱���Ų��.

                else if (_iMonster == 2)

                    _tMonsterArray[_iMonster - 1].iHp = 50; // ����� ü���� �ٽ� ���󺹱���Ų��.

                else if (_iMonster == 3)

                    _tMonsterArray[_iMonster - 1].iHp = 60; // �Ǹ��� ü���� �ٽ� ���󺹱���Ų��.

                HuntOrQuit();

            }

            // ������� ü���� 0�� �Ǹ� ������ ü�°��� ������� ������ ����ȴ�.

            if (_tStatusArray[_job - 1].iHp == 0)

            {

                cout << endl;

                cout << "����� �׾����ϴ�..." << endl;

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



// ����ڰ� �����ϴ� �Լ�

int AttackPlayer(JOB _job, int _iMonster, tagStatus _tStatusArray[], tagStatus _tMonsterArray[])

{

    int monsterHp = _tMonsterArray[_iMonster - 1].iHp;

    int myPower = _tStatusArray[_job - 1].iPower;



    return monsterHp - myPower; // ������ HP���� ������� ���ݷ� ��ŭ ����.



}



// ���Ͱ� �����ϴ� �Լ�

int AttackMonster(JOB _job, int _iMonster, tagStatus _tStatusArray[], tagStatus _tMonsterArray[])

{

    int myHp = _tStatusArray[_job - 1].iHp;

    int monsterPower = _tMonsterArray[_iMonster - 1].iPower;



    return myHp - monsterPower; // ������� HP���� ������ ���ݷ� ��ŭ ����.



}