// xo.main.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <stdlib.h> //заголовочный файл
#include <time.h>
#include "xo_func.h" // здесь прототипы функций

using namespace std;

int main() {
	short int first;
	int i, j;

	system("chcp 1251 > null"); //меняем кодовую страницу на 1251

	Game player = initGame('X');

	srand((unsigned)time(NULL));
	first = rand() % 2;

	if (first) {
		player.isUserTurn = true;
		player.userChar = 'X';
		player.botChar = 'O';
		player.status = PLAY;
	}
	else {
		player.isUserTurn = false;
		player.userChar = 'O';
		player.botChar = 'X';
		player.status = PLAY;
	}

	

	// бесконечный цикл (пока может хоть кто-то сделать ход)
	while (!updateGame(&player)) {
		if (player.isUserTurn) {
			userTurn(&player);
		}
		else {
			botTurn(&player);
		}
		updateDisplay(player);
	}

	switch (player.status) {
	case USER_WIN: cout << "User WIN!"; break;
	case BOT_WIN: cout << "Bot WIN!"; break;
	case NOT_WIN: cout << "Draw!"; break;
	}

	return 0;
}
