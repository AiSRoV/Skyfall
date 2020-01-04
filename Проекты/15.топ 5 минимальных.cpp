// 15 здание топ 5 минимальных.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
using namespace std;
int main() {
	int n;
	cout << " n = ";
	cin >> n;
	int* a = new int[n];

	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}

	for (int i = 0; i < n; i++) {

		int j = i;
		int s = a[i];

		while ((j > 0) && (i != 0) && (a[j - 1] < s)) {
			a[j] = a[j - 1];
			j--;
		}
		a[j] = s;
		int d;
		if (i + 1 > 5) {
			d = (i + 1) - 5; //вычитам, чтоб начиналось с последнийх 5 //
		}
		else {
			d = 0;
		}
		for (int k = d; k < (i + 1); k++) {///output
			cout << " " << a[k];

			if (k == 4 + d) {

				break;
			}
		}

		cout << "\n";
	}
	return 0;
}
