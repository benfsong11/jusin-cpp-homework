#include <iostream>

using namespace std;

int main()
{
	int* p = new int(10);
	delete p;
	p = nullptr;

	if (p == nullptr)
		cout << "���� �Ҵ� �����ƾ�!" << endl;
}

