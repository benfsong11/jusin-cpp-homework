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
		j = 1; // ���ο� ���� ���� j�� ���� �ٽ� 1�� �ǵ�����, �̰� ���� ������ j�� ���� 10�� �Ǿ� �� �̻� ��µ��� �ʴ´�

	}


	return 0;
}