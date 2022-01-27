#include <iostream>

using namespace std;



void Rotation(int iArray[][3]);


int main()
{
	int iArray[3][3] = {
		{ 1, 2, 3 },
		{ 4, 5, 6 },
		{ 7, 8, 9 }
	};

	// iArray 출력
	for (int i = 0; i < 3; ++i)
	{
		for (int j = 0; j < 3; ++j)
		{
			cout << iArray[i][j] << "\t";
		}
		cout << endl;
	}

	cout << "=====================================" << endl;

	Rotation(iArray); // 한 번 회전

	for (int i = 0; i < 3; ++i)
	{
		for (int j = 0; j < 3; ++j)
		{
			cout << iArray[i][j] << "\t";
		}
		cout << endl;
	}
	
	cout << "=====================================" << endl;

	Rotation(iArray); // 한 번 더 회전

	for (int i = 0; i < 3; ++i)
	{
		for (int j = 0; j < 3; ++j)
		{
			cout << iArray[i][j] << "\t";
		}
		cout << endl;
	}

	cout << "=====================================" << endl;

	Rotation(iArray); // 한 번 더 회전

	for (int i = 0; i < 3; ++i)
	{
		for (int j = 0; j < 3; ++j)
		{
			cout << iArray[i][j] << "\t";
		}
		cout << endl;
	}




	return 0;
}

void Rotation(int iArray[][3])
{
	int iRotation[3][3] = {};
	for (int i = 0; i < 3; ++i)
	{
		for (int j = 0; j < 3; ++j)
		{
			iRotation[i][j] = iArray[2 - j][i];
			
		}
	}

	for (int i = 0; i < 3; ++i)
	{
		for (int j = 0; j < 3; ++j)
		{
			iArray[i][j] = iRotation[i][j];

		}
	}

}

