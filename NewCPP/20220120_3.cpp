#include <iostream>

using namespace std;

void main(void)
{
	string strStar = "*";
	for (int i = 0; i < 5; ++i)
	{
		cout << strStar << endl;
		strStar.append("*"); // star�� "*"�� �߰��Ѵ�.
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
		strStars.erase(0, 1); // 0��° �ε������� 1���� ���ڸ� �����.
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
			strStars2.insert(i, " "); // 0��° �ε����� ���� 1���� ����� i��° �ε����� �� ĭ�� �߰��Ͽ� ����� �����.
		}
	}

	// *****
	//  ****
	//   ***
	//    **
	//     *



	cout << "======================" << endl;

	string strStar2 = "*";
	int iSpace = 4; // ó�� ������ ��
	for (int i = 0; i < 5; ++i)
	{
		for (int j = 0; j < iSpace; ++j)
		{
			strStar2.insert(0, " "); // iSpace�� �� ��ŭ ������ �߰��Ѵ�.

		}
		
		cout << strStar2 << endl;
		strStar2.erase(0, iSpace); // ���� for���� ���� ������ �ٽ� �߰��� ���̹Ƿ� ������ ��� �����.
		strStar2.append("*"); // "*"�� �߰��Ѵ�.
		--iSpace; // �߰��� ���� ���� 1 ���δ�.
		
	}

	//     *
	//    **
	//   ***
	//  ****
	// *****
}