#include <iostream>

using namespace std;

void main(void)
{
	// int ch = getchar(); // ���� �� ���ڸ� �Է¹޴� �Լ�
	// putchar(ch);

	// int ch = fgetc(stdin); // ����ڰ� ���� ��Ʈ���� �����Ͽ� ���� �� ���ڸ� �Է¹޴� �Լ�
	// fputc(ch, stdout);

	// EOF(End Of File): ������ ���� ǥ���ϱ� ���� ������ ��� ��(-1)

	// �ܼ� �ܰ迡�� EOF�� �߻���Ű�� ����Ű�� ctrl + z
	/*while (true)
	{
		char ch = getchar();

		if (EOF == ch)
		{
			break;
		}

		putchar(ch);
	}*/

	// �빮�ڸ� �ҹ��ڷ�, �ҹ��ڸ� �빮�ڷ� ��ȯ�Ͽ� ����ϴ� �ڵ�
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
	// puts("Hello"); // �ڵ� ���� ����
	
	// int fputs(const char* pBuffer, FILE* stream);
	// fputs("Hello", stdout); // �ڵ� ���� ������

	// char* gets_s(char* pBuffer, size_t Size);
	// char szTemp[16] = "";
	// gets_s(szTemp, 16); // ���ڿ� �Է¹޴� �Լ�, ���Ⱑ �ν��� �ȴ�
	// ����� �ʰ��ϴ� �Է��� ������ ����, �����̽��� �̿��� ���� �Է� ����, �׷��� enter �Է��� �Ұ���
	// puts(szTemp);

	// char szTemp[16] = "";
	// fgets(szTemp, sizeof(szTemp), stdin); // ����� �ʰ��ϸ� ������ ������ ��ŭ�� �о���δ�
	// ��� null ���ڸ� ����� ������ ��ŭ�̴�
	// fputs(szTemp, stdout);

	// ��� ���� ���� �Լ�: fflush -> ���� ��������� �ʴ´�

	// �Է� ���۸� ����� �ϴ� ���(�Է� ���� ���� �Լ��� ����)
	/*char szID[9] = "";
	char szName[16] = "";

	fgets(szID, sizeof(szID), stdin);
	while ('\n' != getchar());
	fputs(szID, stdout);

	fgets(szName, sizeof(szName), stdin);
	fputs(szName, stdout);*/
}