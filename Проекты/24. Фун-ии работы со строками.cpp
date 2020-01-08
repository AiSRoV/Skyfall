// 24. Фун-ии работы со строками.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>


using namespace std;

size_t strlen(const char* string);//длина строки
int strcmp(const char* string1, const char* string2); //сравнение двух строк
char* strstrstr(char* string1, const char* string2); // ищем первое вхождение стр2 в стр1
char* strcat(char* destptr, const char* srcptr); //объединение строк



int main()
{
	char s1[50], s2[50];
	char* ss1 = s1, * ss2 = s2;//указатели на строки

	cin.getline(s1, 50, '\n');
	cin.getline(s2, 50, '\n');

	cout << strlen(s1) << " " << strlen(s2) << "\n";

	if (strlen(s1) > strlen(s2))cout << "Stroka 1 bolshe 2 stroki\n"; //смотрим длины
	else if (strlen(s1) < strlen(s2))cout << "Stroka 1 menshe 2 stroki\n";//
	else if (strcmp(s1, s2)) cout << "stroki sovpadaut\n"; //если длины совпали смотрим посимвольно
	else cout << "stroki ne sovpadaut\n";

	// преобразование символа в число(код символа) при выводе
	// (int) -- преобразовать в целое (получить код символа)
	// * -- взять значение по адресу (символ)
	// strstrstr(ss1, ss2) -- адрес памяти, где хранится символ
	cout << (int)(*strstrstr(ss1, ss2)) << "\n";

	ss1 = strcat(s1, s2);
	cout << s1 << "\n";

	return 0;
}

size_t strlen(const char* string) {
	int i;
	for (i = 0; string[i]; ++i); //ищем пока не найдем \0; string[i]станет=folse
	return i;
}

int strcmp(const char* string1, const char* string2) {
	int i = strlen(string1); //колво символов
	int j = strlen(string2);
	int k;

	if (i == j) {
		for (k = 0; string1[k] != '\0', string1[k] != string2[k]; ++k); //проверяем сами симв на несовпадения и считаем их
		if (!k) return 1; //если кол во совпадений совпало с колическом совпадений в слове.
	}

	return 0;
}

char* strstrstr(char* string1, const char* string2) {
	int i, j, len_s1 = strlen(string1), len_s2 = strlen(string2);
	int k, z;
	char answer;

	for (i = 0; i < (len_s1 - len_s2 + 1); ++i) {
		k = 0; z = 0;
		for (j = i; j < (len_s2 + i); ++j) {
			if (string1[j] == string2[z++]) {
				k++;
			}
		}
		if (k == len_s2) {
			answer = i;
			return &answer;
		}
	}

	answer = -1;
	return &answer;
}

char* strcat(char* destptr, const char* srcptr) {
	int k1 = strlen(destptr); //колво симв в 1 строку
	int k2 = strlen(srcptr); //колво симв во 2 стр
	int p = k1 + k2; //позиция конца строки

	for (int i = 0; srcptr[i]; ++i) {
		destptr[k1 + i] = srcptr[i]; //добавили к 1 стр вторую
	}

	destptr[k1 + k2] = '\0';

	return destptr;
}

