// 11. Факториал.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
using namespace std; 

int main()
{
	int n, res = 1, i = 1;
	cout << " n = ";
	cin >> n;
	if (n > 0)
	{
		while (i <= n)
		{
			res = res * i;
			i++;
		}
		cout << " " << n << "! = " << res << "\n";
	}
	else {
		if (n == 0) {
			res = 1;
			cout << " " << n << "! = " << res << "\n";
		}
		else {
			cout << "ne sushestvuet";

		}
	}
	return 0; 
}
