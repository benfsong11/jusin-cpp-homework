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

	// 0���� 24���� 2���� �迭�� �����Ѵ�.
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
		// 2���� �迭�� ����ϴ� �ڵ�
		for (int i = 0; i < 5; ++i)
		{
			for (int j = 0; j < 5; ++j)
			{
				cout << iArray[i][j] << "\t";
			}
			cout << endl;
		}

		cout << "=======================================" << endl;

		cout << "�̵��� ������ �����ϼ���. ��(8), �Ʒ�(2), ����(4), ������(6) > ";
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
		// ������ �̵�
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
			cout << "�� �̻� ������ �� �����ϴ�..." << endl;
			break;
		}
	case 4:
		// �������� �̵�
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
			cout << "�� �̻� ������ �� �����ϴ�..." << endl;
			break;
		}
		break;
	case 6:
		// ���������� �̵�
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
			cout << "�� �̻� ������ �� �����ϴ�..." << endl;
			break;
		}
		break;
	case 8:
		// ���� �̵�
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
			cout << "�� �̻� ������ �� �����ϴ�..." << endl;
			break;
		}
		break;
	default:
		cout << "���ڸ� �ٽ� �Է��� �ּ���." << endl;
		break;
	}
	
}