// 9. Угадай число.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include<time.h>


using namespace std;
int main()
{
	setlocale(0, "rus");
	int R, n, i = 0, f = 1;

	cout << " Привет! Сыграем в игру? ";

	cout << " Yгадайте число от 1 до 100 \n";
	while (f == 1) {
		srand(time(NULL));
		R = rand() % 101;
		while (i < 5) {


			cout << " n = ";
			cin >> n;

			if (R == n) {
				cout << " Поздравляю! Вы угадали\n";
				i = 0;
				break;

			}
			else {
				i++;
				if (R < n) { cout << " Загаданное число меньше \n"; }
				else { cout << "Загаданное число больше\n"; }
			}

		}
		if (i == 5) { cout << "Вы проиграли. Загаданое число было " << R << "\n"; }
		i = 0;
		cout << "Хотите начать сначала?(1 - ДА) \n";
		cin >> f;
	}

	return 0;
}

