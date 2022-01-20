#include <iostream>

using namespace std;

void main(void)
{
	string strStar = "*";
	for (int i = 0; i < 5; ++i)
	{
		cout << strStar << endl;
		strStar.append("*"); // star에 "*"을 추가한다.
	}

	// *
	// **
	// ***
	// ****
	// *****



	cout << "======================" << endl;

	string strStars = "*****";
	for (int i = 0; i < 5; ++i)
	{
		cout << strStars << endl;
		strStars.erase(0, 1); // 0번째 인덱스에서 1개의 문자를 지운다.
	}
	
	// *****
	// ****
	// ***
	// **
	// *



	cout << "======================" << endl;

	string strStars2 = "*****";
	for (int i = 0; i < 5; ++i)
	{
		cout << strStars2 << endl;
		for (int j = 0; j < 5; ++j)
		{
			strStars2.erase(0, 1);
			strStars2.insert(i, " "); // 0번째 인덱스의 문자 1개를 지우고 i번째 인덱스에 빈 칸을 추가하여 모양을 만든다.
		}
	}

	// *****
	//  ****
	//   ***
	//    **
	//     *



	cout << "======================" << endl;

	string strStar2 = "*";
	int iSpace = 4; // 처음 공백의 수
	for (int i = 0; i < 5; ++i)
	{
		for (int j = 0; j < iSpace; ++j)
		{
			strStar2.insert(0, " "); // iSpace의 수 만큼 공백을 추가한다.

		}
		
		cout << strStar2 << endl;
		strStar2.erase(0, iSpace); // 위의 for문을 통해 공백을 다시 추가할 것이므로 공백을 모두 지운다.
		strStar2.append("*"); // "*"을 추가한다.
		--iSpace; // 추가할 공백 수를 1 줄인다.
		
	}

	//     *
	//    **
	//   ***
	//  ****
	// *****
}