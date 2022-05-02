// ex2.cpp : 하노이 타워
#include <iostream>

using namespace std;


int move(int n, char start, char end)
{
	cout << n << "번째 원반을 " << start << "에서 " << end << "로 이동." << endl;
	return 1;
}
int Hanoi(int n, char start, char way, char dest)
{
	if (n == 1) return move(n, start, dest);
	return Hanoi(n-1, start, dest, way) + move(n, start, dest) + Hanoi(n-1, way, start, dest);
}
int main()
{
	cout << Hanoi(2, 'A', 'B', 'C') << endl;
}
