// 29. Аргументы команднй стоки.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <stdlib.h> // system
#include <iostream>
#include <string.h>

using namespace std;

int main(int argc, char* argv[]) {
	int i;
	// state == 1 2 4 8 // (-help)  (-n <name>) (-b) (-w)
	int state[4] = { 0 };
	int result,
		index;
	char s[255];

	if (argc > 1) { // количество аргументов в командной строке == 1 -> имя программы
		for (i = 1; i < argc; ++i) { // смотрим переданные аргументы в командной строке
			if (strcmp(argv[i], "-help") == 0) { //
				state[0] = 1;
			}
			if (strcmp(argv[i], "-n") == 0) {
				state[1] = 2;
				index = i;
			}
			if (strcmp(argv[i], "-b") == 0) {
				state[2] = 4;
				index = i;
			}
			if (strcmp(argv[i], "-w") == 0) {
				state[3] = 8;
			}
		}

		if (state[0]) {
			result = 1;
		}
		else {
			result = state[0] + state[1] + state[2] + state[3];
		}

		switch (result) {
		/*-help*/  case 1: cout << "-help      'show help'" << "\n";
			cout << "-n <name>  'hello, <name>'" << "\n";
			cout << "-b <name>  'poka, <name>'" << "\n";
			cout << "-w         'asks <name>'" << "\n";
			cout << "           'can use -w -n'" << "\n\n";
			break;
		/*-n name*/case 2: if (index + 1 == argc) { // если аргументов больше нет
			cout << "error! use '-help' for help" << "\n";
		}
		else {
			cout << "privet, " << argv[index + 1] << "\n";
		}
		break;
		/*-b name*/case 4: if (index + 1 == argc) { // если аргументов больше нет
			cout << "error! use '-help' for help" << "\n";
		}
		else {
			cout << "poka, " << argv[index + 1] << "\n";
		}
		break;
		/*-w*/     case 8: cout << "kak vas zovut? --> ";
			cin.getline(s, 255, '\n');
			break;
		/*-w -n*/  case 10:cout << "kak vas zovut? --> ";
			cin.getline(s, 255, '\n');
			cout << "privet, " << s << "\n";
			break;
		}

	}
	else {
		cout << "no arguments!\n";
	}

	system("pause");
	return 0;
}
