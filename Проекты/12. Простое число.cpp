// 12. Простое число.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
using namespace std;

int main()
{
	
	int n;
	bool fl = true;
	cout << " n = ";
	cin >> n;
	setlocale(0, "rus");

	for (int i = 2; i < n; i++) {
		if (n % i == 0) {
			fl = false;
			break;
		}
	}

	if (fl == true) {
		cout << " Простое " << "\n";
	}
	else {
		cout << " Составное " << "\n";
	}
	return 0;
}
