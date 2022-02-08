#include <iostream>

using namespace std;

void main(void)
{
	// int ch = getchar(); // 글자 한 글자를 입력받는 함수
	// putchar(ch);

	// int ch = fgetc(stdin); // 사용자가 직접 스트림을 지정하여 글자 한 글자를 입력받는 함수
	// fputc(ch, stdout);

	// EOF(End Of File): 파일의 끝을 표현하기 위해 정의한 상수 값(-1)

	// 콘솔 단계에서 EOF를 발생시키는 단축키는 ctrl + z
	/*while (true)
	{
		char ch = getchar();

		if (EOF == ch)
		{
			break;
		}

		putchar(ch);
	}*/

	// 대문자를 소문자로, 소문자를 대문자로 변환하여 출력하는 코드
	/*while (true)
	{
		char ch = getchar();

		if (EOF == ch)
		{
			break;
		}

		if ('a' <= ch && 'z' >= ch)
		{
			ch -= 32;
		}
		else if ('A' <= ch && 'Z' >= ch)
		{
			ch += 32;
		}
		putchar(ch);
	}*/



	// int puts(const char* pBuffer);
	// puts("Hello"); // 자동 개행 적용
	
	// int fputs(const char* pBuffer, FILE* stream);
	// fputs("Hello", stdout); // 자동 개행 미적용

	// char* gets_s(char* pBuffer, size_t Size);
	// char szTemp[16] = "";
	// gets_s(szTemp, 16); // 문자열 입력받는 함수, 띄어쓰기가 인식이 된다
	// 사이즈를 초과하는 입력을 받으면 에러, 스페이스를 이용한 공백 입력 가능, 그러나 enter 입력은 불가능
	// puts(szTemp);

	// char szTemp[16] = "";
	// fgets(szTemp, sizeof(szTemp), stdin); // 사이즈를 초과하면 설정한 사이즈 만큼만 읽어들인다
	// 대신 null 문자를 고려한 사이즈 만큼이다
	// fputs(szTemp, stdout);

	// 출력 버퍼 비우기 함수: fflush -> 많이 사용하지는 않는다

	// 입력 버퍼를 비워야 하는 경우(입력 버퍼 비우기 함수는 없다)
	/*char szID[9] = "";
	char szName[16] = "";

	fgets(szID, sizeof(szID), stdin);
	while ('\n' != getchar());
	fputs(szID, stdout);

	fgets(szName, sizeof(szName), stdin);
	fputs(szName, stdout);*/
}