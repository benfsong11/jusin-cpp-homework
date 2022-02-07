#include <iostream>

using namespace std;

int main()
{
	int* p = new int(10);
	delete p;
	p = nullptr;

	if (p == nullptr)
		cout << "동적 할당 해제됐어!" << endl;
}

