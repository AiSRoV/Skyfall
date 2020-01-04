// 21 Найти ячейку в двумерн масс.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <time.h>
using namespace std; 
int main()
{ 
	int a[10][8] = { 0 };
	int str, stb, popitka = 0;
	srand((unsigned)time(NULL));

	str = rand() % 10;
	stb = rand() % 8;
	a[str][stb] = 1;
	//cout << str << ":" << stb << endl;

	while (popitka < 5) {
		cout << " zadaite stroku = ";	cin >> str;
		cout << " zadaite stolbec= ";	cin >> stb;
		
	    while ((str < 0) || (str > 9) || (stb < 0) || (stb > 7)) {
			cout << "Vihod za granizy\n";
			cout << " zadaite stroku = ";	cin >> str;
			cout << " zadaite stolbec= ";	cin >> stb;
		}

		if (a[str][stb] == 0) {
			popitka++;
			a[str][stb] = -1;
			cout << " ne popal\n";
		}
		else if (a[str][stb] == -1) {
			cout << " Uge vibirali\n";
		}
		else if (a[str][stb] == 1) {
			cout << "YOU WIN";
			break;
		}
	
		if (popitka == 5) {
			cout << "Game over\n";
		}
	}
	return 0;
}


