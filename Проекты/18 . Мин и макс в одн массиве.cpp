// 18 . Мин и макс в одн массиве.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <ctime>

using namespace std; 
int main()
{
	srand(time(0));
		int a[20];
		int min, max;
		for (int i = 0; i < 20; i++) {
			a[i] = -100 + rand() % 201;
			cout << a[i] << "  ";
		}
		min = a[0];
		max = a[0];
		for (int i = 0; i < 20; i++) {
			if (min > a[i]) {
				min = a[i];
			}
			if (max < a[i]) {
				max = a[i];
			}
		}
		cout << "\n";
		cout << " max = " << max << "\n";
		cout << " min = " << min << "\n";
		cout << "\n";
		return 0;
}

