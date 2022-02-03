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
		char szName[3][5] = { "민수", "철수", "영희" };

		int iKor = 0, iEng = 0, iMath = 0;
		cout << szName[i] << "의 국어, 영어, 수학 점수를 차례대로 입력하세요 > ";
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

	cout << _szName << "의 국어 점수는 " << tScore.iKoreanScore << "점입니다." << endl;
	cout << _szName << "의 영어 점수는 " << tScore.iEnglishScore << "점입니다." << endl;
	cout << _szName << "의 수학 점수는 " << tScore.iMathScore << "점입니다." << endl;

	cout << _szName << "의 점수의 총합은 " << tScore.iTotalScore << "점입니다." << endl;
	cout << _szName << "의 평균 점수는 " << tScore.fAverageScore << "점입니다." << endl;
}