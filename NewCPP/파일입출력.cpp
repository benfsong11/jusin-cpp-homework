#include <iostream>

using namespace std;

void main(void)
{
	// ��Ʈ���� �����Ѵٴ� ǥ�����ٴ� ������ �����ϰ� �Ҹ��Ų�ٴ� ǥ���� ����Ѵ�

	// �ؽ�Ʈ ��� ���� ����
	/*FILE* fp = nullptr;

	errno_t err = fopen_s(&fp, "../Data/Test.txt", "wt");

	if (0 == err) // ���� ��Ʈ�� ������ ������ ��
	{
		fputs("World", fp);
		cout << "���� ���� ����" << endl;
	}
	else
	{
		cout << "���� ���� ����" << endl;
	}

	fclose(fp); // ���� ��Ʈ�� �Ҹ��� ��*/


	// �ؽ�Ʈ ��� ���� �ҷ�����
	/*FILE* fp = nullptr;

	errno_t err = fopen_s(&fp, "../Data/Test.txt", "rt");

	char szTest[32] = "";

	if (0 == err) // ���� ��Ʈ�� ������ ������ ��
	{
		fgets(szTest, sizeof(szTest), stdin);
		fputs(szTest, stdout);
		cout << "���� ���� ����" << endl;

		fclose(fp); // ���� ��Ʈ�� �Ҹ��� ��
	}
	else
	{
		cout << "���� ���� ����" << endl;
	}*/




	// ���̳ʸ� ��� ����� �Լ�
	// size_t fwrite();
	// 1. ����� �޸��� ���� �ּ�
	// 2. ����� �޸��� ������
	// 3. ����� �޸��� ����
	// 4. ������ ��Ʈ��

	/*FILE* fp = nullptr;

	int iArray[5] = { 1, 2, 3, 4, 5 };

	errno_t err = fopen_s(&fp, "../Data/Binary.txt", "wb");

	if (0 == err)
	{
		fwrite(iArray, sizeof(iArray), 1, fp);

		fclose(fp);
	}
	else
	{
		cout << "���� ���� ����" << endl;
	}*/
}


// ù ��° ����
// ���� ������� �̿��ؼ� �̹����� ���纻 �����
// �ؽ�ó�� �ȼ� ������ �ҷ��ͼ� ���ο� ���Ͽ� �����ϸ� �ȴ�

// �� ��° ����
// TextRPG�� ����, �ҷ����� �����
// �����ϸ� ����ġ ������ �߰��Ͽ� �̰͵��� ������ �� �ְ� �����
// ���� ������ �������, �ҷ����� ������ �� �Ǵ��ؼ�