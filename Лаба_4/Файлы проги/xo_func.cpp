// Функции работы со строками.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//
#include <iostream>
#include <stdlib.h>
#include <time.h>


using namespace std;
/* game state */

Game player;

void updateDisplay(const Game game) {
	system("cls");
	cout << "|___|___|___|" << endl;
	for (int i = 0; i < 3; ++i) {
		cout << "|   |   |   |" << endl;
		cout << "| " << game.bord[i][0] << " | " << game.bord[i][1] << " | " << game.bord[i][2] << " |" << endl;
		cout << "|___|___|___|" << endl;
	}
}

void botTurn(Game* game) {
	bool bordEmpty = true, botSdelalHod = false;
	int counter;

	for (int i = 0; i < 3; ++i) {
		for (int j = 0; j < 3; ++j) {
			if (game->bord[i][j] == game->userChar || game->bord[i][j] == game->botChar) {
				bordEmpty = false;
			}
		}
	}

	if (bordEmpty) {
		game->bord[1][1] = game->botChar; // если поле пустое то ставим в центе сивол бота.
		game->isUserTurn = true;
	}
	else {
		for (int i = 0; i < 3; ++i) { //проверяем строки на наличие 2х сим-в противника
			counter = 0;
			if (game->bord[i][0] == game->userChar)	counter++;
			if (game->bord[i][1] == game->userChar)	counter++;
			if (game->bord[i][2] == game->userChar)	counter++;
			if (counter > 1) {
				for (int j = 0; j < 3; ++j) { //пров столбц
					if (game->bord[i][j] != game->userChar && game->bord[i][j] != game->botChar) {
						game->bord[i][j] = game->botChar;
						game->isUserTurn = true;
						botSdelalHod = true;
						return;
					}
				}
				//return;
				break;
			}
		}

		//проверяем столбцы
		if (!botSdelalHod) {
			for (int j = 0; j < 3; ++j) { //проверяем столбцы на наличие 2х сим-в противника
				counter = 0;
				if (game->bord[0][j] == game->userChar)	counter++;
				if (game->bord[1][j] == game->userChar)	counter++;
				if (game->bord[2][j] == game->userChar)	counter++;
				if (counter > 1) {
					for (int i = 0; i < 3; ++i) { //пров столбц
						if (game->bord[i][j] != game->userChar && game->bord[i][j] != game->botChar) {
							game->bord[i][j] = game->botChar;
							game->isUserTurn = true;
							botSdelalHod = true;
							return;
						}
					}
					break;
				}
			}
		}

		//глвн диаг
		if (!botSdelalHod) {
			counter = 0;
			for (int i = 0; i < 3; ++i) {
				if (game->bord[i][i] == game->userChar) counter++;
			}
			if (counter > 1) {
				for (int i = 0; i < 3; ++i) {
					if (game->bord[i][i] != game->userChar && game->bord[i][i] != game->botChar) {
						game->bord[i][i] = game->botChar;
						game->isUserTurn = true;
						botSdelalHod = true;
						return;
					}
				}
			}
		}

		//побочн диаг
		if (!botSdelalHod) {
			counter = 0;
			if (game->bord[0][2] == game->userChar) counter++;
			if (game->bord[1][1] == game->userChar) counter++;
			if (game->bord[2][0] == game->userChar) counter++;
			if (counter > 1) {
				if ((game->bord[0][2] != game->userChar && game->bord[0][2] != game->botChar) && !botSdelalHod) {
						game->bord[0][2] = game->botChar;
						game->isUserTurn = true;
						botSdelalHod = true;
						return;
				}
				if ((game->bord[1][1] != game->userChar && game->bord[1][1] != game->botChar) && !botSdelalHod) {
					game->bord[1][1] = game->botChar;
					game->isUserTurn = true;
					botSdelalHod = true;
					return;
				}
				if ((game->bord[2][0] != game->userChar && game->bord[2][0] != game->botChar) && !botSdelalHod) {
					game->bord[2][0] = game->botChar;
					game->isUserTurn = true;
					botSdelalHod = true;
					return;
				}
			}
		}

		//случайный ход
		if (!botSdelalHod) {
			while (true) {
				int i = rand() % 3;
				int j = rand() % 3;
				if (game->bord[i][j] != game->userChar && game->bord[i][j] != game->botChar) {
					game->bord[i][j] = game->botChar;
					game->isUserTurn = true;
					botSdelalHod = true;
					break;
				}
			}

		}

	}

}

void userTurn(Game* game) {
	int i, j;
	while (true) {
		cout << "Viberite stroky 0..2 --> "; cin >> i;
		cout << "Viberite stolbec 0..2 --> "; cin >> j;
		if ((i>=0) && (i<=2) && (j>=0) && (j<=2)) {
            if ((game->bord[i][j] != game->userChar) && (game->bord[i][j] != game->botChar)){
                game->bord[i][j] = game->userChar;
                game->isUserTurn = false;
                break;
            }
            else{
                cout << " Ochen' rugaemsya, povtori vvod\n";
            }
		}
		else {
			cout << " Ochen' rugaemsya, povtori vvod\n";
		}
	}
}

bool updateGame(Game* game) {
    bool endGame = true;
    char activeChar;
    int i, j, counter;

    if (!game->isUserTurn) activeChar = game->userChar;
    else activeChar = game->botChar;

    // проверка окончания игры по строкам
    for(i=0; i<3; ++i){
        counter = 0;
        for(j=0; j<3; ++j){
            if(game->bord[i][j] == activeChar) counter++;
        }
        if (counter == 3){
            if(!game->isUserTurn) game->status = USER_WIN;
            else game->status = BOT_WIN;
            return endGame;
        }
    }

    // проверка окончания игры по столбцам
    for(j=0; j<3; ++j){
        counter = 0;
        for(i=0; i<3; ++i){
            if(game->bord[i][j] == activeChar) counter++;
        }
        if (counter == 3){
            if(!game->isUserTurn) game->status = USER_WIN;
            else game->status = BOT_WIN;
            return endGame;
        }
    }

    // проверка окончания игры по главной диагонали
    counter = 0;
    if (game->bord[0][0] == activeChar)	counter++;
    if (game->bord[1][1] == activeChar)	counter++;
	if (game->bord[2][2] == activeChar)	counter++;
    if (counter == 3){
        if(!game->isUserTurn) game->status = USER_WIN;
        else game->status = BOT_WIN;
        return endGame;
    }

    // проверка окончания игры по побочной диагонали
    counter = 0;
    if (game->bord[2][0] == activeChar)	counter++;
    if (game->bord[1][1] == activeChar)	counter++;
	if (game->bord[0][2] == activeChar)	counter++;
    if (counter == 3){
        if(!game->isUserTurn) game->status = USER_WIN;
        else game->status = BOT_WIN;
        return endGame;
    }

    // проверка на отсутствие пустых полей
    counter = 0;
    for(i=0; i<3; ++i){
        for(j=0; j<3; ++j){
            if ((game->bord[i][j] != game->userChar) && (game->bord[i][j] != game->botChar)){
                counter++;
            }
        }
    }

    if (!counter){
            game->status = NOT_WIN;
            return endGame;
    }
    else endGame = false;

	return endGame;
}

Game initGame(char userChar){
    int first = rand() % 2;
    char botChar;

    if (userChar == 'X') botChar = 'O';
    else botChar = 'X';

	player.userChar = userChar;
    player.botChar = botChar;

	if (first) player.isUserTurn = true;
    else player.isUserTurn = false;

    player.status = PLAY;

	for (int i = 0; i < 3; ++i) {
		for (int j = 0; j < 3; ++j) {
			player.bord[i][j] = ' ';
		}
	}

    system("chcp 1251 > nul"); //меняем кодовую страницу на 1251 (866 дос)
    return player;
}
