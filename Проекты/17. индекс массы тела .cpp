// индекс массы тела 17.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
using namespace std;

double BMI(double weight, double height);
void printBMI(double BMI);

int main()
{
	float weight, height;
	cout << "zadaite ves (kg) = ";   cin >> weight;
	cout << "zadaite rost (cm) = ";  
	cin >> height;
	height /= 100; //perevod v metri
	printBMI( BMI(weight, height) );
	return 0; 
}

double BMI(double weight, double height) {
	return weight / pow(height, 2); //рост в квадр
}

void printBMI(double BMI) {
	if (BMI < 18.5) cout << "Underweight";
	else if (BMI < 25.0) cout << "Normal weight";
	else if (BMI < 30.0) cout << "Overweight";
	else cout << "Obesity";
}
