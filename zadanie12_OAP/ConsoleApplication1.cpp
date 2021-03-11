//#include "pch.h"
#include <iostream>
#include <string>
#include <Windows.h>
#include <algorithm>

using namespace std;

struct subject {
	int ocenki1[10] = { 4,3,4,5,5,2,4,2,3,5 };
	int ocenki2[10] = { 5,4,3,2,4,5,2,3,4,5 };
	string nazvanie;
	int kod;
};

struct student {
	string surname;
	string name;
	string otchestvo;
	subject predmet1;
	subject predmet2;
};
//Вывод студентов по номеру
void ponomeru(student *students, int kolvo) {
	for (int i = 0; i < kolvo; ++i) {
		cout << i + 1 << ") " << students[i].surname << " " << students[i].name << " " << students[i].otchestvo << endl;
	}
}
//Сортировка по алфавиту
void alfavit(student* students, int kolvo)
{

	for (int j = 0; j < kolvo - 1; ++j)
	{
		for (int k = 0; k < kolvo - 1; ++k)
		{

			if (students[k].surname.compare(students[k + 1].surname) > 0)
			{
				std::swap(students[k], students[k + 1]);
			}
		}
	}

	for (int i = 0; i < kolvo; ++i)
	{
		cout << i + 1 << ". " << students[i].surname;
		cout << " " << students[i].name << " " << " " << students[i].otchestvo << '\n';
	}

}
//Добавление нового студента
void newstud(int kolvo, student *dinamic)
{
	int kol = kolvo + 1;
	student *newdinamic = new student[kol];
	for (int i = 0; i < kolvo; i++)
	{
		newdinamic[i] = dinamic[i];
	}
	int num = 3;
	--num;
	for (int i = kol - 1; i > num; i--)
	{
		swap(newdinamic[i], newdinamic[i - 1]);
	}
	cout << "Введите ФИО нового студента: ";
	cin >> newdinamic[num].surname >> newdinamic[num].name >> newdinamic[num].otchestvo;
	cout << endl;
	newdinamic[num].predmet1.kod = 11;
	newdinamic[num].predmet2.kod = 12;
	newdinamic[num].predmet1.nazvanie = "Геометрия";
	newdinamic[num].predmet2.nazvanie = "Астрономия";
	ponomeru(newdinamic, kol);
	cout << endl;
	alfavit(newdinamic, kol);
}
//Выбор позиции оценки для изменения
void chach(string sub, student *students, int n)
{
	while (true)
	{
		cout << "\nВведите порядковый номер оценки (1-10) или введите 0 для отмены редактирования: ";
		int pos;
		cin >> pos;//Ввод позиции оценки для изменения 

		if (pos == 0)
		{
			cout << "Отмена редактирования оценок" << endl;
			cout << "По какому пердмету хотите изменить оценки?" << endl;
			cout << "Введите \"стоп\" чтобы отменить редактирование" << endl;
			cout << "\n";

			break;
		}
		//Ввод новой оценки
		cout << "\nВведите значение от 1 до 5: " << endl;
		int news;
		cin >> news;


		if (sub == students[n].predmet1.nazvanie)
		{	//Вывод изменненых оценок по Геометрии
			students[n].predmet1.ocenki1[pos - 1] = news;// Замена оценки на новую. (pos - 1) - индексация начинается с 0
			cout << "Измененные оценки:" << "\n" << "\n" << students[n].predmet1.nazvanie << " ( " << students[n].predmet1.kod << " ): ";
			for (int p = 0; p < 10; p++)
			{
				cout << students[n].predmet1.ocenki1[p] << "  ";
			}
		}

		else
		{	//Вывод изменненых оценок по Астрономии
			students[n].predmet2.ocenki2[pos - 1] = news;// Замена оценки на новую. (pos - 1) - индексация начинается с 0
			cout << "Измененные оценки:" << "\n" << "\n" << students[n].predmet2.nazvanie << " ( " << students[n].predmet2.kod << " ): ";
			for (int i = 0; i < 10; i++)
			{
				cout << students[n].predmet2.ocenki2[i] << "  ";
			}
		}



	}


}

//Выбора предмет
void сh(student* students, int n)
{
	cout << "По какому пердмету хотите изменить оценки? (Геометрия/Астрономия)" << " ";
	cout << "Введите \"стоп\" чтобы отменить редактирование" << endl;
	while (true)
	{

		string s;
		cin >> s;

		if (s == students[n].predmet1.nazvanie || s == students[n].predmet2.nazvanie)
		{
			chach(s, students, n);
		}
		else if (s == "стоп")
		{
			cout << "Отмена редактирования" << endl;
			break;
		}
		else
			cout << "Ошибка ввода! Повторите ввод:" << endl;
	}



}
//Вывод данных о студенте
void dannie(student* students, int n)
{
	cout << "\n№ по журналу: " << n + 1 << endl;
	cout << "Фамилия студента: " << students[n].surname << endl;
	cout << "Имя студента: " << students[n].name << endl;
	cout << "Отчество студента: " << students[n].otchestvo << endl;
	cout << students[n].predmet1.kod << " - " << students[n].predmet1.nazvanie << ": ";
	for (int p = 0; p < 10; p++)
	{
		cout << students[n].predmet1.ocenki1[p] << " ";
	}
	cout << endl;
	cout << students[n].predmet2.kod << " - " << students[n].predmet2.nazvanie << ": ";
	for (int i = 0; i < 10; i++)
	{
		cout << students[n].predmet2.ocenki2[i] << " ";
	}
	while (true)
	{
		cout << "\n\nХотите изменить оценки? да|нет" << endl;
		string a;
		cin >> a;
		if (a == "нет")
			break;
		else if (a == "да")
			сh(students, n);
		else
		{
			cout << "Ошибка ввода! Повторите ввод:";
		}

	}
}

//Функция ввода фимилии 
string poisk()
{
	string surn;
	cout << "Введите фамилию студента, о котором хотите увидеть информацию или введите \"добавить\". Можете ввести \"стоп\", чтобы завершить работу" << endl;
	cin >> surn;//Ввод фимилии студента
	return surn;
}

int main()
{
	setlocale(LC_ALL, "RU");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	int kol = 0;
	int n = 0;
	string s, surn;
	student stud1 = { "Петров", "Сергей", "Александрович" };
	stud1.predmet1.kod = 11;
	stud1.predmet2.kod = 12;
	stud1.predmet1.nazvanie = "Геометрия";
	stud1.predmet2.nazvanie = "Астрономия";

	student stud2{ "Фролов", "Алексей", "Григорьевич" };
	stud2.predmet1.kod = 11;
	stud2.predmet2.kod = 12;
	stud2.predmet1.nazvanie = "Геометрия";
	stud2.predmet2.nazvanie = "Астрономия";

	student stud3{ "Нарышкина", "Анна", "Андреевна" };
	stud3.predmet1.kod = 11;
	stud3.predmet2.kod = 12;
	stud3.predmet1.nazvanie = "Геометрия";
	stud3.predmet2.nazvanie = "Астрономия";

	student stud4{ "Головин", "Артём" , "Александрович" };
	stud4.predmet1.kod = 11;
	stud4.predmet2.kod = 12;
	stud4.predmet1.nazvanie = "Геометрия";
	stud4.predmet2.nazvanie = "Астрономия";

	student stud5{ "Гунько", "Дарья", "Сергеевна" };
	stud5.predmet1.kod = 11;
	stud5.predmet2.kod = 12;
	stud5.predmet1.nazvanie = "Геометрия";
	stud5.predmet2.nazvanie = "Астрономия";

	student students[5]{ stud1, stud2, stud3, stud4, stud5 };
	student *newdinamic = new student[kol];

	int kolvo = sizeof(students) / sizeof(students[0]);

	cout << "Вывод студентов по номеру:" << endl;
	ponomeru(students, kolvo);
	cout << "\nВывод студентов по алфавиту:" << endl;
	alfavit(students, kolvo);

	cout << endl;

	student *ns = new student[kolvo];
	for (int i = 0; i < 5; ++i)
	{
		ns[i] = students[i];
	}

	while (true)
	{
		string info = poisk();	//строковая переменная, содержащая фамилию для поиска
		if (info == "стоп")	//условие выхода из цикла
			break;
		else if (info == "добавить")
		{
			newstud(kolvo, ns);
			cout << "Хотите посмотреть информацию о студенте? да/нет" << endl;
			int yn;
			cin >> yn;
			if (yn == 1)
			{
				for (int n = 0; n < 6; ++n)
				{
					if (info == newdinamic[n].surname)
					{
						dannie(newdinamic, n);
					}
				}
			}

		}
		else
		{	//если введённая фамилия есть в списке, то будет вызвана функция, выводящая информацию о студенте
			for (int n = 0; n < kolvo; ++n)
			{
				if (info == students[n].surname)
				{
					dannie(students, n);
				}
			}
		}
	}
}