#include <iostream>

using namespace std;

int main(void)
{
	int i = 2, j = 1;

	while (10 > i)
	{
		while (10 > j)
		{
			cout << i << " x " << j << " = " << i * j << endl;
			++j;
		}
		cout << "" << endl;
		++i;
		j = 1; // 새로운 단을 위해 j의 값을 다시 1로 되돌린다, 이걸 하지 않으면 j의 값은 10이 되어 더 이상 출력되지 않는다

	}


	return 0;
}