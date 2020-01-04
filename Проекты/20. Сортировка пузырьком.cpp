// ПУЗЫРЕК.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
using namespace std;
void output(int* M, int n) {
	for (int i = 0; i < n; i++) {  // вывод всех элементов массива
		cout << M[i] << " ";
	}
	
}

void bubble_sort(int*a, int n) { 
	for (int j = 0; j < n; j++) { //сколько элем нужно отсеять
		for (int i = 0; i < (n - j) - 1; i++) { //отсеивает посл элемент отсортированный  //-1 для невыхода из массива 

			if (a[i] > a[i + 1]) {
				a[i] = a[i] + a[i + 1];
				a[i + 1] = a[i] - a[i + 1];
				a[i] = a[i] - a[i + 1];
			}
			
		}
		
	}
}


int main()
{
	int n;
	cout << " n = ";
	cin >> n;
	int* a = new int[n];
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	bubble_sort(a, n);
	output(a, n);
	delete[] a;
	return 0;

}

