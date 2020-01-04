// 14. Фиксированная сумма.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
using namespace std; 
int main()
{
	int S, l1, r1, l2, r2, x1, x2; //14
	bool f = false;
	cout << " S = ";
	cin >> S;
	cout << " l1 = ";
	cin >> l1;
	cout << " r1 = ";
	cin >> r1;
	cout << " l2 = ";
	cin >> l2;
	cout << " r2 = ";
	cin >> r2;

	for (int i = 0; i <= (r1 - l1); i++) {
		for (int j = 0; j <= (r2 - l2); j++) {
			x1 = l1 + i;
			x2 = l2 + j;
			if ((x1 + x2) == S) {
				f = true;
				break;
			}

		}
		if (f == true) {
			break;
		}
	}
	if (f == true) {
		cout << " x1 = " << x1 << "\n";
		cout << " x2 = " << x2 << "\n";
	}
	else {
		cout << " -1 \n";
	}
	return 0;
}