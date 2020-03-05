Федеральное государственное автономное образовательное учреждение высшего образования  
  
"КРЫМСКИЙ ФЕДЕРАЛЬНЫЙ УНИВЕРСИТЕТ им. В. И. ВЕРНАДСКОГО"  

ФИЗИКО-ТЕХНИЧЕСКИЙ ИНСТИТУТ  

Кафедра компьютерной инженерии и моделирования
<br/></br>


### Отчет по лабораторной работе №5 </br> по дисциплине "Программирование"
<br/>

Студента 1 курса группы ИВТ-б-о-191(1)  
Гринь Татьяны Станиславовны </br>
направления подготовки 09.03.01 " Информатика и вычислительная техника"  
<br/>

<table>
<tr><td>Научный руководитель<br/> старший преподаватель кафедры<br/> компьютерной инженерии и моделирования</td>
<td>(оценка)</td>
<td>Чабанов В.В.</td>
</tr>
</table>
<br/><br/>
​
Симферополь, 2019

__Цель:__ </tr>

+ Научиться работать с текстовыми файлами; </tr>

+ Закрепить навыки работы со структурами. </tr>

__Код программы:__

 ``` C++

#include <iostream>
#include <locale> 
#include <fstream> 
#include <string>
#include <vector>
#include <stdlib.h> // atoi - строка в целое
#include <iomanip> // для потока вывода и ввода 

using namespace std;

struct Flight{
    short id;       // номер пассажира
    short survival; // *Survival (0 = No; 1 = Yes)
    short pclass;   // *Passenger Class (1 = 1st; 2 = 2nd; 3 = 3rd)
    string name;   // *Name
    string sex;    // *пол
    float age;      //  Age /*short*/
    short sibsp;    // *Number of Siblings/Spouses Aboard
    short parch;    // *Number of Parents/Children Aboard
    string ticket; // *Ticket Number
    float fare;    // *Passenger Fare (транспортные расходы)
    string cabin;  // Cabin
    string embarked; // *Port of Embarkation
                   // (C = Cherbourg; Q = Queenstown; S = Southampton)
};

// разбиваем строку данных на строки-составляющие
// разделителем выступает символ `,`
//
vector<string> split(string str, string token){
    vector<string> result;
    while(str.size()){
        int index = str.find(token);
        if(index != string::npos){ // если нашли искомый символ
            result.push_back(str.substr(0,index)); // слово от начала до запятой
            str = str.substr(index + token.size());
            if(str.size() == 0) result.push_back(str);
        }else{
            result.push_back(str);
            str = "";
        }
    }
    // т.к. разделителем выступает`,` запятая, а в имени она также присутствует,
    // то получали одно лишее поле. Теперь от него избавляемся
    if ((result.at(4) != "male") || (result.at(4) != "female")){
        result.at(3) += "," + result.at(4);
        for (int i=4; i<result.size()-1; ++i){
            result.at(i).clear();
            result.at(i) += result.at(i+1);
        }
        result.pop_back();
    }

    return result;
}

// перевод вектора строк (строк из файла) -- в вектор структуры
void vecStr_to_vecStruct(vector<string> & source, vector<Flight> & passenger){
    vector<string> arrstr;
    Flight temp_passanger;
  //переодит в вектор структут все данные
    for(int i=1; i<source.size(); ++i){
        arrstr = split(source.at(i), ",");
    
            temp_passanger.id = atoi(arrstr.at(0).c_str());
            temp_passanger.survival = atoi(arrstr.at(1).c_str());
            temp_passanger.pclass = atoi(arrstr.at(2).c_str());
            temp_passanger.name = arrstr.at(3);
            temp_passanger.sex = arrstr.at(4);
            temp_passanger.age = atof(arrstr.at(5).c_str()); //*
            temp_passanger.sibsp = atoi(arrstr.at(6).c_str());
            temp_passanger.parch = atoi(arrstr.at(7).c_str());
            temp_passanger.ticket = arrstr.at(8);
            temp_passanger.fare = atof(arrstr.at(9).c_str());
            temp_passanger.cabin = arrstr.at(10); //*
            temp_passanger.embarked = arrstr.at(11)[0];

            passenger.push_back(temp_passanger);
        
    }
}


// подсчет количества всех пассажиров
int count_all(vector<Flight> & source){
    int kkk = source.size();// количество пассажиров;
	return kkk;
}

// подсчет количества всех пассажиров заданного пола
int count_all(vector<Flight> & source, string sex){
    int kkk = 0;
    for(int i=0; i<source.size(); ++i){
        if(source[i].sex.length() && source[i].sex==sex){ //если есть параметр и пол совпадает то считаем
            kkk++;
        }
    }
    return kkk;
}

// количество выживших 
int count_alive(vector<Flight> & source){
    int kkk = 0; // счетчик живых
    for(int i=0; i<source.size(); ++i){
        if(source[i].survival){
            kkk++;
        }
    }
    return kkk;
}

// количество выживших, N-класса
int count_alive(vector<Flight> & source, short passClass){
    int kkk = 0;
    for(int i=0; i<source.size(); ++i){
        if(source[i].survival && (source[i].pclass==passClass)){
            kkk++;
        }
    }
    return kkk;
}

// количество выживших, заданного пола 
int count_alive(vector<Flight> & source, string sex){
    int kkk = 0;
    for(int i=0; i<source.size(); ++i){
        if(source.at(i).survival && source.at(i).sex==sex && source[i].sex.length()){
            kkk++;
        }
    }//если выжил, совпадет пол и он есть вообще, то считаем
    return kkk;
}

// суммарный возраст людей
double count_ages(vector<Flight> & source){
    double kkk = 0; // сумма всех возрастов
	for (int i = 0; i < source.size(); ++i) {
		if (source.at(i).age) {//если вообще есть этот параметр
			kkk += source[i].age;
		}
	}
    return kkk;
}

//количесво людей у которых указан параметр возраст
int count_people_age(vector<Flight>& source) {

	int kkk = 0; 
	for (int i = 0; i < source.size(); ++i) {
		if (source.at(i).age) {
			kkk++;
		}
	}
	return kkk;
}

//количество людей с указанным полом у которых есть параметр ВОЗРАСТ
int count_sex_age(vector<Flight>& source, string sex) {
	int kkk = 0; 
	for (int i = 0; i < source.size(); ++i) {
		if (source.at(i).sex == sex && source[i].sex.length() && source[i].age)
			kkk++;
	}
	return kkk; 
}

// количество людей из штата
int count_state(vector<Flight> & source, string state){
    int kkk = 0;
    for(int i=0; i<source.size(); ++i){
        if((source[i].embarked==state) && (source[i].embarked.length())){
            kkk ++;
        }
    }
    return kkk;
}

// список несовершеннолетних (< 18)
vector<int> before18_get(vector<Flight> & source){
    vector<int> result;
    for(int i=1; i<source.size(); ++i){
        if(source[i].age < 18 && source[i].age){
            result.push_back(source[i].id);
        }
    }
    return result;
}

// суммарный возраст людей заданного пола
int count_ages(vector<Flight> & source, string sex){
    int kkk = 0;
    for(int i=1; i<source.size(); ++i){
        if(source[i].sex==sex && source[i].sex.length() && source[i].age){
            kkk += source[i].age;
        }
    }
    return kkk;
}


void max_people_from_state(vector<Flight> states, string & state_name, int & state_amount){ //для того чтобы мы могли дальше использ переменные
    int a[3], max, imax;
    string state[3] = {"Cherbourg", "Queenstown", "Southampton"};

    a[0] = count_state(states, "C");
    a[1] = count_state(states, "Q");
    a[2] = count_state(states, "S");

    if(a[0] > a[1]) imax = 0;
    else imax = 1;
    max = a[imax];

    if(a[2] > max){
        imax = 2;
        max = a[imax];
    }

    state_amount = max;
    state_name = state[imax];

}


//поместить все строки файла в вектор 
bool getFileContent(string fileName, vector<string> & vecOfStrs){
	// открываем файл для чтения
	ifstream in(fileName.c_str());

	// если не получилось открыть
	if(!in){
		cerr << "Cannot open the File : "<<fileName<<endl; //для вывода ошибок
		return false;
	}

	string str; // строка из файла

	// читаем строки из файла, пока он не закончится
	while (getline(in, str, '\r'))
	{
		// если в строке что-то есть - запишем это в вектор
		if(str.size() > 0)
			vecOfStrs.push_back(str);
	}
	// закрыть файл для чтения
    in.close();

	return true;
}


int main()
{
	int all_alive; // общее число выживших
	int all_alive_class1; // общее число выживших 1 класса
	int all_alive_class2; // общее число выживших 2 класса
	int all_alive_class3; // общее число выживших 3 класса
	int all_alive_female; // количество выживших женщин
	int all_alive_male; // количество выживших мужчин
	float mid_passenger_age; // средний возраст пассажира
	float mid_female_age; // средний возраст женщин
	float mid_male_age; // средний возраст мужчин
	string state_name; // штат, в котором село больше всего пассажиров
	int state_amount; // количество пассажиров наибольшего штата
    vector<int> before18; // список идентификаторов несовершеннолетних


	vector<string> vecOfStr;
	vector<Flight> vecOfFlight;

    setlocale(LC_ALL, "Russian");

	// получить данные из file в vector строк
	bool result = getFileContent("train.csv", vecOfStr);

	if(result)//если получилось открыть файл и считать данные
	{
	    vecStr_to_vecStruct(vecOfStr, vecOfFlight);

	    cout << "records in file = " << vecOfStr.size() << endl;
        cout << "all records have = " << vecOfFlight.size() << endl;

        all_alive         = count_alive(vecOfFlight);
        all_alive_class1  = count_alive(vecOfFlight, 1);
        all_alive_class2  = count_alive(vecOfFlight, 2);
        all_alive_class3  = count_alive(vecOfFlight, 3);
        all_alive_male    = count_alive(vecOfFlight, "male");
        all_alive_female  = count_alive(vecOfFlight, "female");
        mid_passenger_age = count_ages(vecOfFlight) / count_people_age(vecOfFlight);
        mid_male_age      = count_ages(vecOfFlight, "male") / count_sex_age(vecOfFlight, "male");
        mid_female_age    = count_ages(vecOfFlight, "female") / count_sex_age(vecOfFlight, "female");
        before18          = before18_get(vecOfFlight);

        /////////////////////////////
        // вывод на экран результатов, которые должны быть в файле
        //////////////////////////////
	    cout << "alive = " << all_alive << endl;
	    cout << "alive 1 class = " << all_alive_class1 << endl;
	    cout << "alive 2 class = " << all_alive_class2 << endl;
	    cout << "alive 3 class = " << all_alive_class3 << endl;
	    cout << "alive male = " << all_alive_male << endl;
	    cout << "alive female = " << all_alive_female << endl;
	    cout << "middle age of passenger = " << mid_passenger_age << endl;
	    cout << "middle age of male = " << mid_male_age << endl;
	    cout << "middle age of female = " << mid_female_age << endl;

        max_people_from_state(vecOfFlight, state_name, state_amount);

        cout << "max amount of people are from `" << state_name << "` = " << state_amount << endl;

	    cout << "people before 18 = ";
	    for(int i=0; i<before18.size(); ++i){
            cout << before18[i];
            if(i < before18.size()-1){
                cout << ", ";
            }
	    }
	    cout << endl;

	    ////////////////////////////
	    // выводим все в файл
	    ////////////////////////////
       

        ofstream fout; // выходной файловый поток
        fout.open("temp_ofstream.txt", ofstream::out);

        if(!fout.is_open()){
            cout << "file write Error \"" << "temp_ofstream.txt" << "\"\n";
        }
        else{
            fout << "Общее число выживших";
            fout << setfill(' ') << setw(20) << all_alive << '\r';
            fout << "Число выживших из 1 класса";
            fout << setfill(' ') << setw(20) << all_alive_class1 << '\r';
            fout << "Число выживших из 2 класса";
            fout << setfill(' ') << setw(20) << all_alive_class2 << '\r';
            fout << "Число выживших из 3 класса";
            fout << setfill(' ') << setw(20) << all_alive_class3 << '\r';
            fout << "Количество выживших женщин";
            fout << setfill(' ') << setw(20) << all_alive_female << '\r';
            fout << "Количество выживших мужчин";
            fout << setfill(' ') << setw(20) << all_alive_male << '\r';
            fout << "Средний возраст пассажира/женский/мужской";
            fout << setfill(' ') << setw(20) << mid_passenger_age << "/" << mid_female_age << "/" << mid_male_age << '\r';
            fout << "Штат, в котором село больше всего пассажиров";
            fout << setfill(' ') << setw(20) << state_name << '\r';
            fout << "Список идентификаторов несовершеннолетних";
            fout << setfill(' ') << setw(20);
            for(int i=0; i<before18.size(); ++i){
                fout << before18[i];
                if (i < before18.size()-1){
                    fout << ", ";
                }
            }
            fout.close(); // закрыли файл, завершили вывод
        }
	}
	return 0;
}
 ```
 </tr>
 
 __Ссылка на файл с результатами расчета:__

*https://github.com/Starfall-6969/Skyfall/blob/master/%D0%9B%D0%B0%D0%B1%D0%BE%D1%80%D0%B0%D1%82%D0%BE%D1%80%D0%BD%D0%B0%D1%8F%205/temp_ofstream.txt*
</tr>

__Рассчитанные характеристики:__
 
<table>
<tr><td>Общее число выживших </td>
<td> 342

<tr><td>Число выживших из 1 класса</td>
<td>136

<tr><td>Число выживших из 2 класса </td>
<td>87

<tr><td>Число выживших из 3 класса </td>
<td>119

<tr><td>Количество выживших женщин</td>
<td> 233

<tr><td>Количество выживших мужчин</td>
<td>109

<tr><td>Средний возраст пассажира/женский/мужской</td>
<td>29.9731/28/30

<tr><td>Штат, в котором село больше всего пассажиров</td>
<td>Southampton

<tr><td>Список идентификаторов несовершеннолетних</td>
<td>8, 10, 11, 15, 17, 23, 25, 40, 44, 51, 59, 60, 64, 69, 72, 85, 87, 112, 115, 120, 126, 139, 148, 157, 164, 165, 166, 172, 173, 183, 184, 185, 194, 206, 209, 221, 234, 238, 262, 267, 279, 283, 298, 308, 330, 334, 341, 349, 353, 375, 382, 387, 390, 408, 420, 434, 436, 446, 447, 449, 480, 481, 490, 501, 505, 531, 533, 536, 542, 543, 550, 551, 575, 619, 635, 643, 684, 687, 690, 692, 721, 722, 732, 747, 751, 752, 765, 778, 781, 782, 788, 789, 792, 803, 814, 820, 825, 828, 831, 842, 845, 851, 853, 854, 870, 876</td>
</tr>
</table>
<br/><br/>

__Вывод:__

В ходе выполнения данной лабораторной работы был приобретен навык работы с текстовыми файлами, закреплен навык работы со структурами.  











