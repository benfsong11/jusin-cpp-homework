#include <iostream>
using namespace std;

void ScoreOutput(char _szName[], int _iKor, int _iEng, int _iMath, int _iTotal, float _fAver);

struct tagGrade
{
	int iKoreanScore;
	int iEnglishScore;
	int iMathScore;
	int iTotalScore;
	float fAverageScore;
};

int main()
{
	for (int i = 0; i < 3; ++i)
	{
		char szName[3][5] = { "�μ�", "ö��", "����" };

		int iKor = 0, iEng = 0, iMath = 0;
		cout << szName[i] << "�� ����, ����, ���� ������ ���ʴ�� �Է��ϼ��� > ";
		cin >> iKor >> iEng >> iMath;
		cout << endl;

		int iTotal = iKor + iEng + iMath;
		float fAver = (float)iTotal / 3.f;

		ScoreOutput(szName[i], iKor, iEng, iMath, iTotal, fAver);
		cout << "================================================" << endl;
		cout << endl;
	}




	return 0;
}

void ScoreOutput(char _szName[], int _iKor, int _iEng, int _iMath, int _iTotal, float _fAver)
{
	tagGrade tScore = { _iKor, _iEng, _iMath, _iTotal, _fAver };

	cout << _szName << "�� ���� ������ " << tScore.iKoreanScore << "���Դϴ�." << endl;
	cout << _szName << "�� ���� ������ " << tScore.iEnglishScore << "���Դϴ�." << endl;
	cout << _szName << "�� ���� ������ " << tScore.iMathScore << "���Դϴ�." << endl;

	cout << _szName << "�� ������ ������ " << tScore.iTotalScore << "���Դϴ�." << endl;
	cout << _szName << "�� ��� ������ " << tScore.fAverageScore << "���Դϴ�." << endl;
}