// Факторизация числа 2.0.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//
//#include <math.h>
#include <iostream>
//#include <conio.h>

using namespace std;

void factorize(int n)
{
	int  step;
	cout << n << " = 1";
	int delitel = 2;
	
	while (n > 1) {
		step = 0;
		while (n % delitel==0) {
			
			n /= delitel;
			step++;
			if (step <= 1) {
				cout << " * " << delitel;
			}
		}
		if(step>1)cout<<"^"<<step;
		delitel++;
		
	}
	
}
int main() {
	int nnn;
	cin >> nnn;
	factorize(nnn);
	return 0;
}


