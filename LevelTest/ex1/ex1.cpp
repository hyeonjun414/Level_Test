// ex1.cpp : 피보나치 수열

#include <iostream>

using namespace std;

int Fibonacci(int num)
{
	if (num == 1 || num == 2) return 1;

	return Fibonacci(num - 1) + Fibonacci(num - 2);
}

int main()
{
	cout << Fibonacci(6);
}
