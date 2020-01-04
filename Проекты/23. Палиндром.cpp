// Палиндром 2.0.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.

#include <cctype>
#include <iostream>
using namespace std; 

bool pali(char* a);

int main()
{
	 char a[21];
	 cin.getline(a, 21);
	 if (pali(a)) {
		 cout << " palindrom \n";
	}
	 else {
		 cout << " no palindrom \n";
	 }
	 return 0;
}


bool pali(char* a) {
	
	int j = 0;
	char b[21];
	for (int i = 0; i < strlen(a); i++) {
		if (isalpha(a[i])) {
			b[j] = tolower(a[i]);
			j++;
		}
		if (isdigit(a[i])) {
			b[j] = a[i];
			j++;
		}
	}
	for (int i = 0; i < j / 2.0; i++) {
		if (b[i] != b[j - i - 1]) 
			return false;
		
	}
	if (j == 0) {
		return false;
	}
	return true;

}