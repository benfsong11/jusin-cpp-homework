#include <iostream>

using namespace std;

int main(void) {
	int iKoreanScore = 0, iEnglishScore = 0, iMathScore = 0;


	cout << "국어 점수를 입력하세요. > ";
	cin >> iKoreanScore;
	cout << "영어 점수를 입력하세요. > ";
	cin >> iEnglishScore;
	cout << "수학 점수를 입력하세요. > ";
	cin >> iMathScore;

	cout << "" << endl;

	cout << "국어 점수는 " << iKoreanScore << "점입니다." << endl;
	cout << "영어 점수는 " << iEnglishScore << "점입니다." << endl;
	cout << "수학 점수는 " << iMathScore << "점입니다." << endl;

	cout << "" << endl;

	int iTotalScore = iKoreanScore + iEnglishScore + iMathScore;
	float fAverageScore = (float)iTotalScore / 3;

	cout << "국영수 점수의 총합은 " << iTotalScore << "점입니다." << endl;
	cout << "국영수 점수의 평균은 " << fAverageScore << "점입니다." << endl;

	cout << "" << endl;

	if (fAverageScore >= 90)
	{
		cout << "A등급입니다!" << endl;
	}
	else if (fAverageScore >= 80)
	{
		cout << "B등급입니다!" << endl;
	}
	else if (fAverageScore >= 70)
	{
		cout << "C등급입니다!" << endl;
	}
	else if (fAverageScore >= 60)
	{
		cout << "D등급입니다!" << endl;
	}
	else
	{
		cout << "F등급입니다!" << endl;
	}

	return 0;

}
