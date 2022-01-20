#include <iostream>

using namespace std;

void main(void)
{
	int iFirst = 0, iSecond = 0;
	cout << "단을 입력하세요 > ";
	cin >> iFirst;
	cout << "곱을 입력하세요 > ";
	cin >> iSecond;

	for (int i = 2; i <= iFirst; ++i)
	{
		for (int j = 1; j <= iSecond; ++j)
		{
			cout << i << " x " << j << " = " << i * j << endl;
		}
		cout << "" << endl;
	}
}