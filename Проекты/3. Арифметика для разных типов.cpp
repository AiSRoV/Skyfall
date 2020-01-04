// 3. Арифметика для разных типов.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//
#include <iostream>

using namespace std; 

int main()
{
	double c;
	int b;

	int a;
	double d;

	cout << " a = ";
	cin >> a;
	cout << " b = ";
	cin >> b;
	cout << " c = ";
	cin >> c;
	cout << " d = ";
	cin >> d;
	cout << c + d << " \ " << c - d << " \ " << c / d << " \ " << c * d << "\n";
	cout << b + d << " \ " << b - d << " \ " << b / d << " \ " << b * d << "\n";
	cout << c + a << " \ " << c - a << " \ " << c / a << " \ " << c * a << "\n";
	return 0; 
}

