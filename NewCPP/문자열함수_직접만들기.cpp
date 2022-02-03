#include <iostream>

using namespace std;

int StringLength(char _szArray[]);
void ReverseString(char _szArray[], int _iSize);

int main()
{
	char szArray[100] = "jusin";

	int iSize = StringLength(szArray);
	cout << iSize << endl;

	ReverseString(szArray, iSize); // 위에서 리턴받은 길이값을 뒤바꾸기 함수의 매개 변수로 대입한다.
	cout << szArray << endl;

	return 0;
}

int StringLength(char _szArray[])
{
	// 밑의 주석 코드는 배열의 동적 할당을 배우고 다시 시도해 볼 코드이다. szArray의 인덱스에 변수를 대입할 수 있는 방법을 찾아야 한다.
	/*char szArray[6] = {};
	for (int i = 0; i < 6; ++i)
	{
		szArray[i] = _szArray[i];
	}

	return sizeof(szArray) / sizeof(char) - 1;*/

	// 밑의 코드는 새롭게 시도하여 성공한 코드이다.
	int i = 0;
	while (_szArray[i] != '\0') // 종료 문자 '\0'을 만날 때까지 계속 i를 1씩 증가시킨다.
		++i;
	return i; // 증가가 끝난 i를 리턴한다.

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