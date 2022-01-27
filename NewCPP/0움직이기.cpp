#include <iostream>

using namespace std;

void MoveZero(int _iArray[][5], int _iUser, int* _iRowIndex, int* _iColIndex);

int main()
{
	int iArray[5][5] = {};
	int iUser = 0;

	int iRowIndex = 0, iColIndex = 0;

	int* pRowIndex = &iRowIndex;
	int* pColIndex = &iColIndex;

	// 0부터 24까지 2차원 배열에 대입한다.
	int iNumber = 0;
	for (int i = 0; i < 5; ++i)
	{
		for (int j = 0; j < 5; ++j)
		{
			iArray[i][j] = iNumber;
			++iNumber;
		}
	}

	while (true)
	{
		system("cls");
		// 2차원 배열을 출력하는 코드
		for (int i = 0; i < 5; ++i)
		{
			for (int j = 0; j < 5; ++j)
			{
				cout << iArray[i][j] << "\t";
			}
			cout << endl;
		}

		cout << "=======================================" << endl;

		cout << "이동할 방향을 선택하세요. 위(8), 아래(2), 왼쪽(4), 오른쪽(6) > ";
		cin >> iUser;

		MoveZero(iArray, iUser, pRowIndex, pColIndex);

		system("pause");
	}
	


	return 0;
}

void MoveZero(int _iArray[][5], int _iUser, int* _iRowIndex, int* _iColIndex)
{
	int iTemp = 0;
	
	int iZero = _iArray[*_iRowIndex][*_iColIndex];

	switch (_iUser)
	{
	case 2:
		// 밑으로 이동
		if (*_iRowIndex < 4)
		{
			iTemp = _iArray[*_iRowIndex][*_iColIndex];
			_iArray[*_iRowIndex][*_iColIndex] = _iArray[*_iRowIndex + 1][*_iColIndex];
			_iArray[*_iRowIndex + 1][*_iColIndex] = iTemp;
			++(*_iRowIndex);
			break;
		}
		else
		{
			cout << "더 이상 움직일 수 없습니다..." << endl;
			break;
		}
	case 4:
		// 왼쪽으로 이동
		if (*_iColIndex > 0)
		{
			iTemp = _iArray[*_iRowIndex][*_iColIndex];
			_iArray[*_iRowIndex][*_iColIndex] = _iArray[*_iRowIndex][*_iColIndex - 1];
			_iArray[*_iRowIndex][*_iColIndex - 1] = iTemp;
			--(*_iColIndex);
			break;
		}
		else
		{
			cout << "더 이상 움직일 수 없습니다..." << endl;
			break;
		}
		break;
	case 6:
		// 오른쪽으로 이동
		if (*_iColIndex < 4)
		{
			iTemp = _iArray[*_iRowIndex][*_iColIndex];
			_iArray[*_iRowIndex][*_iColIndex] = _iArray[*_iRowIndex][*_iColIndex + 1];
			_iArray[*_iRowIndex][*_iColIndex + 1] = iTemp;
			++(*_iColIndex);
			break;
		}
		else
		{
			cout << "더 이상 움직일 수 없습니다..." << endl;
			break;
		}
		break;
	case 8:
		// 위로 이동
		if (*_iRowIndex > 0)
		{
			iTemp = _iArray[*_iRowIndex][*_iColIndex];
			_iArray[*_iRowIndex][*_iColIndex] = _iArray[*_iRowIndex - 1][*_iColIndex];
			_iArray[*_iRowIndex - 1][*_iColIndex] = iTemp;
			--(*_iRowIndex);
			break;
		}
		else
		{
			cout << "더 이상 움직일 수 없습니다..." << endl;
			break;
		}
		break;
	default:
		cout << "숫자를 다시 입력해 주세요." << endl;
		break;
	}
	
}