#include <iostream>

using namespace std;

int StringLength(char _szArray[]);
void ReverseString(char _szArray[], int _iSize);

int main()
{
	char szArray[100] = "jusin";

	int iSize = StringLength(szArray);
	cout << iSize << endl;

	ReverseString(szArray, iSize); // ������ ���Ϲ��� ���̰��� �ڹٲٱ� �Լ��� �Ű� ������ �����Ѵ�.
	cout << szArray << endl;

	return 0;
}

int StringLength(char _szArray[])
{
	// ���� �ּ� �ڵ�� �迭�� ���� �Ҵ��� ���� �ٽ� �õ��� �� �ڵ��̴�. szArray�� �ε����� ������ ������ �� �ִ� ����� ã�ƾ� �Ѵ�.
	/*char szArray[6] = {};
	for (int i = 0; i < 6; ++i)
	{
		szArray[i] = _szArray[i];
	}

	return sizeof(szArray) / sizeof(char) - 1;*/

	// ���� �ڵ�� ���Ӱ� �õ��Ͽ� ������ �ڵ��̴�.
	int i = 0;
	while (_szArray[i] != '\0') // ���� ���� '\0'�� ���� ������ ��� i�� 1�� ������Ų��.
		++i;
	return i; // ������ ���� i�� �����Ѵ�.

}

void ReverseString(char _szArray[], int _iSize)
{
	char cTemp = 'a';

	for (int i = 0; i < _iSize; ++i)
	{
		if (_szArray[_iSize - i - 1] == _szArray[i] || _iSize - i - 1 - i == -1) 
			break;
		else
		{
			cTemp = _szArray[_iSize - i - 1];
			_szArray[_iSize - i - 1] = _szArray[i];
			_szArray[i] = cTemp;
		}
		
	}
}