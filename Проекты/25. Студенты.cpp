// 25. Студенты.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//
#include <iostream>
#include <string.h>

using namespace std;

struct STUDENT {
	char name[101];
	int group;
	int sec[5];
};

int main() {
	STUDENT stud[10] = { {"Ivanov I.I.", 1,{3,2,3,4,5}},
						{"Avanov I.I.", 2,{4,2,3,4,5}},
						{"Cvanov I.I.", 4,{3,3,3,4,5}},
						{"Mvanov I.I.", 1,{4,2,3,4,5}},
						{"Yavanov I.I.",5,{5,3,3,4,5}},
						{"Zvanov I.I.", 3,{3,2,3,4,5}},
						{"Pvanov I.I.", 1,{3,3,3,4,5}},
						{"Klanov I.I.", 2,{3,2,3,4,5}},
						{"Svanov I.I.", 1,{4,3,3,4,5}},
						{"Mivanov I.I.",6,{5,2,3,4,5}} };
	int i, j,
		less3, countLess3;

	STUDENT temp;

	// сортировка по фамилии
	for (i = 9; i >= 0; --i) {
		for (j = 0; j < i; ++j) {
			if (strcmp(stud[j].name, stud[j + 1].name) == 1) {
				temp = stud[j];
				stud[j] = stud[j + 1];
				stud[j + 1] = temp;
			}
		}
	}

	countLess3 = 0; // колич студ с оценками < 3
	// вывод имеющих оценки < 3
	for (i = 0; i < 10; ++i) {
		less3 = 0; // количество оценок < 3
		for (j = 0; j < 5; ++j) {
			if (stud[i].sec[j] < 3) { // если есть < 3, то плюсуем
				less3++;
			}
		}
		if (less3) { // 0 - false, !=0 - true
			cout << stud[i].name << "\t" << stud[i].group << "\n";
			countLess3++;
		}
	}


	if (!countLess3) {
		cout << "not found\n";
	}

	return 0;
}

