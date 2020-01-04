// 13. Степень двойки.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
using namespace std; 

int main()
{
	int n, i = 0;
	cout << " n = ";
	cin >> n;

	while (n >= 1)
	{
		n = n / 2;
		i++;
	}
	cout << " i = " << i << "\n";
}
