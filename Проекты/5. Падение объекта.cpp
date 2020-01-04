// 5. Падение объекта.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
using namespace std; 

int main()
{

	double x0, V0, t, g = -9.8, xt;

	cout << " x0 = ";
	cin >> x0;
	cout << " V0 = ";
	cin >> V0;
	cout << " t = ";
	cin >> t;
	cout << " xt = ";
	xt = g * t * t * 1 / 2;
	double xt2 = 1.0 / 2 * g * t * t;
	cout << xt << "\n";
	cout << xt2 << "\n";
	return 0;
}
