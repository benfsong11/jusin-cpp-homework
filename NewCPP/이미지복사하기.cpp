#include <iostream>

using namespace std;

int main()
{
	FILE* fp = nullptr; // �б� ��Ʈ��
	FILE* fp2 = nullptr; // ���� ��Ʈ��

	// ���̳ʸ��� �̹��� ������ �ҷ��´�
	errno_t err = fopen_s(&fp, "../Data/Image.jpg", "rb");

	// ���̳ʸ� �ڵ�� 0 �Ǵ� 1�� �������̴ϱ� ������ ���� �ϳ��� �غ��Ѵ�
	int iTemp = 0;

	if (err == 0)
	{
		// �б� ��Ʈ���� ������ ���� ��Ʈ���� �����ϰ� ���̳ʸ��� �̹��� ������ �����Ѵ�
		errno_t err2 = fopen_s(&fp2, "../Data/Copy.jpg", "wb");
		if (err2 == 0)
		{
			
			while (true)
			{
				int iDest = fread(&iTemp, sizeof(int), 1, fp);
				

				fwrite(&iTemp, sizeof(int), 1, fp2);
				// &iTemp �ڸ��� &iDest�� ������ �� �Ǵ� ����
				// iDest�� iTemp�� �ּҸ� �����Ͽ� ���� ���ԵǴϱ�...?

				
				// 1�̸� ���� �����ϱ� ��� ����ϴٰ� 0�� �Ǹ� ����� ���� ������ break
				if (iDest < 1)
					break;

			}
			fclose(fp2);
		}
		fclose(fp);
		
		
	}
	else
	{
		cout << "���� ���� ����..." << endl;
	}

	
	

	

	return 0;
}