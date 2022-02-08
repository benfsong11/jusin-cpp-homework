#include <iostream>

using namespace std;

void main(void)
{
	// 스트림을 생성한다는 표현보다는 파일을 개방하고 소멸시킨다는 표현을 사용한다

	// 텍스트 모드 파일 저장
	/*FILE* fp = nullptr;

	errno_t err = fopen_s(&fp, "../Data/Test.txt", "wt");

	if (0 == err) // 파일 스트림 개방이 성공한 예
	{
		fputs("World", fp);
		cout << "파일 개방 성공" << endl;
	}
	else
	{
		cout << "파일 개방 실패" << endl;
	}

	fclose(fp); // 파일 스트림 소멸의 예*/


	// 텍스트 모드 파일 불러오기
	/*FILE* fp = nullptr;

	errno_t err = fopen_s(&fp, "../Data/Test.txt", "rt");

	char szTest[32] = "";

	if (0 == err) // 파일 스트림 개방이 성공한 예
	{
		fgets(szTest, sizeof(szTest), stdin);
		fputs(szTest, stdout);
		cout << "파일 개방 성공" << endl;

		fclose(fp); // 파일 스트림 소멸의 예
	}
	else
	{
		cout << "파일 개방 실패" << endl;
	}*/




	// 바이너리 모드 입출력 함수
	// size_t fwrite();
	// 1. 출력할 메모리의 시작 주소
	// 2. 출력할 메모리의 사이즈
	// 3. 출력할 메모리의 개수
	// 4. 개방한 스트림

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
		cout << "파일 개방 실패" << endl;
	}*/
}


// 첫 번째 숙제
// 파일 입출력을 이용해서 이미지의 복사본 만들기
// 텍스처의 픽셀 정보를 불러와서 새로운 파일에 저장하면 된다

// 두 번째 숙제
// TextRPG에 저장, 불러오기 만들기
// 웬만하면 경험치 정보를 추가하여 이것들을 저장할 수 있게 만들기
// 저장 시점은 마음대로, 불러오기 시점은 잘 판단해서