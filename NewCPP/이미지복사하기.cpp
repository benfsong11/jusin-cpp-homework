#include <iostream>

using namespace std;

int main()
{
	FILE* fp = nullptr; // 읽기 스트림
	FILE* fp2 = nullptr; // 쓰기 스트림

	// 바이너리로 이미지 파일을 불러온다
	errno_t err = fopen_s(&fp, "../Data/Image.jpg", "rb");

	// 바이너리 코드는 0 또는 1의 정수값이니까 정수형 변수 하나를 준비한다
	int iTemp = 0;

	if (err == 0)
	{
		// 읽기 스트림이 열리면 쓰기 스트림을 개방하고 바이너리로 이미지 파일을 저장한다
		errno_t err2 = fopen_s(&fp2, "../Data/Copy.jpg", "wb");
		if (err2 == 0)
		{
			
			while (true)
			{
				int iDest = fread(&iTemp, sizeof(int), 1, fp);
				

				fwrite(&iTemp, sizeof(int), 1, fp2);
				// &iTemp 자리에 &iDest를 넣으면 안 되는 이유
				// iDest가 iTemp의 주소를 참조하여 값이 대입되니까...?

				
				// 1이면 값이 있으니까 계속 출력하다가 0이 되면 출력할 것이 없으니 break
				if (iDest < 1)
					break;

			}
			fclose(fp2);
		}
		fclose(fp);
		
		
	}
	else
	{
		cout << "파일 개방 실패..." << endl;
	}

	
	

	

	return 0;
}