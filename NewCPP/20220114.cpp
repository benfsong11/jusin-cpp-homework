#include <iostream>

using namespace std;

int main(void) {
	int iKoreanScore = 0, iEnglishScore = 0, iMathScore = 0;


	cout << "���� ������ �Է��ϼ���. > ";
	cin >> iKoreanScore;
	cout << "���� ������ �Է��ϼ���. > ";
	cin >> iEnglishScore;
	cout << "���� ������ �Է��ϼ���. > ";
	cin >> iMathScore;

	cout << "" << endl;

	cout << "���� ������ " << iKoreanScore << "���Դϴ�." << endl;
	cout << "���� ������ " << iEnglishScore << "���Դϴ�." << endl;
	cout << "���� ������ " << iMathScore << "���Դϴ�." << endl;

	cout << "" << endl;

	int iTotalScore = iKoreanScore + iEnglishScore + iMathScore;
	float fAverageScore = (float)iTotalScore / 3;

	cout << "������ ������ ������ " << iTotalScore << "���Դϴ�." << endl;
	cout << "������ ������ ����� " << fAverageScore << "���Դϴ�." << endl;

	cout << "" << endl;

	if (fAverageScore >= 90)
	{
		cout << "A����Դϴ�!" << endl;
	}
	else if (fAverageScore >= 80)
	{
		cout << "B����Դϴ�!" << endl;
	}
	else if (fAverageScore >= 70)
	{
		cout << "C����Դϴ�!" << endl;
	}
	else if (fAverageScore >= 60)
	{
		cout << "D����Դϴ�!" << endl;
	}
	else
	{
		cout << "F����Դϴ�!" << endl;
	}

	return 0;

}
