// 7. Площадь треугольника.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
using namespace std;
#include <cmath>

int main()
{

	double a, c, b;
	int d;
	setlocale(LC_ALL, "Russian");
	cout << "Введите 1 если решение через стороны треуг-ка \n Введите 2 если решение через координаты вершин \n";
	cin >> d;


	switch (d)
	{
	case 1: {  cout << "Введите длины сторон треуг-ка a b c  \n";
		cin >> a;
		cin >> b;
		cin >> c;

		if (a < b + c && b < a + c && c < a + b)
		{
			cout << "треугольник существует" << "\n";
			double p, s;
			p = (a + b + c) / 2.0;
			s = sqrt((p * (p - a) * (p - b) * (p - c)));
			cout << "Площадь треугольника =" << s << "\n";

		}
		else
		{
			cout << "треуг-к не сущ-т";
		}}break;
	case 2: {double ax, bx, cx, ay, by, cy;
		cout << " ax = ";
		cin >> ax;
		cout << " ay = ";
		cin >> ay;
		cout << " bx = ";
		cin >> bx;
		cout << " by = ";
		cin >> by;
		cout << " cx = ";
		cin >> cx;
		cout << " cy = ";
		cin >> cy;

		a = sqrt((bx - ax) * (bx - ax) + (by - ay) * (by - ay));
		b = sqrt((cx - bx) * (cx - bx) + (cy - by) * (cy - by));
		c = sqrt((cx - ax) * (cx - ax) + (cy - ay) * (cy - ay));

		if (a < b + c && b < a + c && c < a + b)
		{
			cout << "треугольник существует" << "\n";

			double p, s;
			p = (a + b + c) / 2.0;
			s = sqrt((p * (p - a) * (p - b) * (p - c)));
			cout << "Площадь треугольника =" << s << "\n";

		}
		else
		{
			cout << "треуг-к не сущ-т";
		} } break;
	default: cout << "неверный выбор";
		break;
	}
	return 0;
}