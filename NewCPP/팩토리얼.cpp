#include <iostream>

using namespace std;

int factorial(int n);

int main(void)
{

	cout << factorial(5) << endl;



	return 0;
}

int factorial(int n)
{
	if (n > 1)
		return n * factorial(n - 1);
	else
		return 1;
}