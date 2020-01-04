// 10. Возведение в степень.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//
#include <iostream>
using namespace std;

int main()
{
	setlocale(0, "rus");
	int N, n, a = 0;
	double res = 1;
	cout << " N = ";
	cin >> N;
	cout << " n = ";
	cin >> n;

	if (n >= 0) {
		while (a < n) {
			res = res * N;
			a++;
		}

	}
	else {
		while (a < (-n)) {
			res = res * N;
			a++;
		}
		if (res == 0) {
			cout << "nevernyi vvod";
			return 1;
		}
		else {
			res = 1 / res;
		}

	}
	;
	cout << N << "^" << n << " = " << res << "\n";
	return 0;
}