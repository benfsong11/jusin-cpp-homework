#include <iostream>

using namespace std;

void main(void)
{
	int iFirst = 0, iSecond = 0;
	cout << "���� �Է��ϼ��� > ";
	cin >> iFirst;
	cout << "���� �Է��ϼ��� > ";
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