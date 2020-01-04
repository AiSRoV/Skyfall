// 22 работа с указателями.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
using namespace std;

void swap(int*, int*);
int msort(int*, int*, int*);
void info(const int*);
int* add(int*, const int*);

int main()
{
	int a=5, b=3, c=4;

	info(&a);
	info(&b);
	info(&c);
	
	cout << "max = " << msort(&a,&b,&c) << "\n";
    
	info( add(add(&a, &b), &c));
	return 0; 
}

void info(const int* n) { //выводит на экран информацию о переменной в формате: Адрес: {Адрес переменной}; Значение: {Значение переменной}
	cout <<"Adres : {0x"<< n <<"} ; Value : {"<<*n << "}\n"; //n просто адрес(указатель), а  *n число (указательна указатель) 
}

int* add(int* v1, const int* v2) { //вычисляет сумму значений по указанным адреса и сохраняет результат по первому адресу
	*v1 += *v2;
	return v1; 
}

void swap(int* v1, int* v2) { //обменивает значениями переменные адреса которых передали в функцию.
	int temp; 
	 { //не нужно менять !!!!!
		temp = *v1;
		*v1 = *v2;
		*v2 = temp;
	}
}

int msort(int*v1, int*v2, int*v3) { //сортирует значения переданных переменных по возрастанию. Возвращает функция максимальное из трёх значений.
	if (*v1 > * v2)
	swap(*v1, *v2);
	if (*v2 > * v3)
	swap(*v2, *v3);
	if (*v1 > * v3)
	swap(*v1, *v2);
	return *v3;
}