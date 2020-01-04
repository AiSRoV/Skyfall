// 6. Корни уравнения.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
using namespace std;
#include <cmath>


int main()
{
	double a, b, c;

	cout << " a = ";
	cin >> a;
	cout << " b = ";
	cin >> b;
	cout << " c = ";
	cin >> c;
	if (a != 0)
	{
		double d = b * b - 4 * a * c;

		if (d < 0)
		{
			cout << " net korney";
		}
		else
			if (d == 0)
			{
				double x = -b / (2.0 * a);
				cout << " x = " << x << "\n";
			}
			else
			{
				double x1 = (-b + sqrt(d)) / (2.0 * a);
				double x2 = (-b - sqrt(d)) / (2.0 * a);
				cout << " x1 = " << x1 << "\n";
				cout << " x2 = " << x2 << "\n";
			}

	}
	else if (a == 0 && b != 0) { // x = -c / b

		double x;
		x = -c / b;
		cout << " x = " << x << "\n";
	}
	else if (a == 0 && b == 0 && c == 0)
	{
		cout << " mnojestvo resh" << "\n";
	}
	else { cout << " net reshenyi"; }
	return 0;
}