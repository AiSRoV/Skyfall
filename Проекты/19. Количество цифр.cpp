// ConsoleApplication4.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
using namespace std; 
int main()
{
	int n, i, l;
	int num[10] = { 0 };
	cout << " n = ";
	cin >> n; 

	for (i = 0; i < n; ++i) {
		cin >> l;
		if (l < 10) {
		num[l]++;
	}
	}
	for (i = 0; i < 9; ++i) {
		if (num[i] > 0){
			cout << i << ":" << num[i] << "\n";
		}
	}

	return 0; 
}


