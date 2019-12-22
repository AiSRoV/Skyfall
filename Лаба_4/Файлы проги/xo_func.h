// Начинаем с директив препроцессора.
// XO_FUNC_H – это произвольное уникальное имя
// (обычно используется имя заголовочного файла)
#ifndef XO_FUNC_H
#define XO_FUNC_H

/* game state */
enum Status {
	PLAY,//continue
	USER_WIN,//player win
	BOT_WIN,//bot win
	NOT_WIN//draw, no free cells
};

struct Game {
	char bord[3][3];// game field
	bool isUserTurn;// isUserTurn = true --> user
	char userChar;// users symbol
	char botChar;// bots symbol
	Status status;
};

// А это уже содержимое заголовочного файла
Game initGame(char userChar);
void updateDisplay(const Game game);
void botTurn(Game* game);
void userTurn(Game* game);
bool updateGame(Game* game);

// Заканчиваем директивой препроцессора
#endif
