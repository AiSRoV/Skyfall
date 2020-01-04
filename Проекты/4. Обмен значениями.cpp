// 4. Обмен значениями.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//
#include <iostream>
using namespace std;

int main()
{
	int a, b, c;
	cout << " a = ";
	cin >> a;
	cout << " b = ";
	cin >> b;

	c = a;
	a = b;
	b = c;

	a = a + b;
	b = a - b;
	a = a - b;

	cout << a << "\n" << b << "\n";
	return 0;

}
