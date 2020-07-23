//Smirnov Gennadiy
#include <string.h>
#include <iostream>
#include <conio.h>
#include <Windows.h>
#include <ctime>
#include <algorithm>
#include "Header.h"

using namespace std;
#define MENUTOP 4
#define MENULEFT 20
#define BACKGROUND 8
#define FOREGROUND 15
#define SELECTITEM 4

struct DMY {
	int day;
	int month;
	int year;
};

struct employees {
	char s_name[25];
	char name[25];
	char f_name[25];
	DMY brthd{};
	char sex[10];
	DMY in_work;
	char unit[50];    //підрозділ
	char office[50];  //посада
	char tel[15];
	DMY out_work;
};

int main() {
	setlocale(LC_ALL, "");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	const char* fileTXT = "Work_Date.txt";
	const char* DelTXT = "Del_Date.txt";
	const char* fileBIN = "Work_Date.bin";
	const char* DelBIN = "Del_Date.bin";
	size_t n = 0;
	employees* Arr = NULL;
	size_t t = 0;
	employees* DelArr = NULL;
	int pm = 0;
	int language = 0;
	Color(BACKGROUND, FOREGROUND);
	system("cls");

	const char* Lng[]{
		"EN",
		"UA"
	};
	const char* UAMain_menu[]{
		"Додати запис",
		"Вставити запис",
		"Редагувати",
		"Друкувати всіх",
		"Друкувати одного",
		"Сортувати по",
		"Пошук",
		"Вибірка по",    //вибірка по:
		"Зберегти",
		"Завантажити",
		"Видалити"
	};
	const char* Main_menu[]{
		"Add employee",
		"Insert",
		"Edit",
		"Print All",
		"Print One",
		"Sort by",
		"Search",
		"Choose by",    //вибірка по:
		"Save date",
		"Load date",
		"Delete"
	};
	const char* Sort_menu[]{
		"Sort by name",
		"Sort by birthday",
		"Sort by unit",
		"Sort by office"
	};
	const char* choose[]{
		"by letter",
		"by unit",
		"by birthday month",
		"by zodiac",
		"by pensioner"
	};
	const char* Del_menu[]{
	"Delete employee",
	"Load dismissed",
	"Print dismissed",
	"Delete dismissed"};
	int SizeLng = sizeof(Lng) / 4;
	int SizeUA = sizeof(UAMain_menu) / 4;
	int SizeMain = sizeof(Main_menu) / 4;
	int SizeSort = sizeof(Sort_menu) / 4;
	int SizeChoose = sizeof(choose) / 4;
	int SizeDel = sizeof(Del_menu) / 4;
	bool bo = true;
	language = menu(Lng,SizeLng, language);
	system("cls");
	while (true)
	{
		pm = 0;
		if(language == 0)
		pm = menu(Main_menu, SizeMain, pm);
		else
			pm = menu(UAMain_menu, SizeUA, pm);
		system("cls");
		switch (pm)
		{
		case -1: return 0;
		case 0:             ////////////////////////////////////////        Add empl.........
			AddEmployees(Arr, n);
			break;
		case 1:
			cout << "Insert\n";
			break;
		case 2:            /////////////////////////////////////////////////////////   EDIT
		{
			bo = true;
		while (bo) {
			pm = 0;
			const char** Str = ToString(Arr, n);
			pm = menu(Str, n, pm,1,0);
			if (pm == -1) {
				bo = false; break;
			}
			Edit(Arr, pm);
			delete[] Str;
			system("cls");
		}
		}
		break;
		case 3:
			Head();
			PrintAll(Arr, n);
			cout << endl;
			break;
		case 4:             /////////////////////////////////////////////       Print One
		{
			pm = 0;
			bo = true;
		while (bo) {
			
			const char** Str = ToString(Arr, n);
			pm = menu(Str, n, pm, 1, 0);
			//system("cls");
			if (pm == -1) {
				bo = false; break;
			}
			Head();
			Print(Arr, pm);
			delete[] Str;
			cout << "\n\n";
			system("pause");
		}
		}
		break;
		case 5:                  ////////////////////////////////////////////              Sort by.......
			pm = 0;
			bo = true;
			while (bo) {
			pm = menu(Sort_menu, SizeSort, pm); 
			if (pm == -1) {
				bo = false; break;
			}
			system("cls");
			{
				switch (pm)
				{
				case -1:
					break;
				case 0:
					cout << "Sort by name\n";
					Sort(Arr, n, name);
					Head();
					PrintAll(Arr, n);
					break;
				case 1:
					cout << "Sort by birthday\n";
					Sort(Arr, n, birthday);
					Head();
					PrintAll(Arr, n);
					break;
				case 2:
					cout << "Sort by unit\n";
					Sort(Arr, n, unit);
					Head();
					PrintAll(Arr, n);
					break;
				case 3:
					cout << "Sort by office\n";
					Sort(Arr, n, office);
					Head();
					PrintAll(Arr, n);
					break;
				}
			}
				Color(BACKGROUND, 2);
				cout << "done\n";
				_getch();
			}
			break;
		case 6://////////////////////////////////////////////////// Search
			Search(Arr, n);
			break;
		case 7:
			//////////////////////////////////////////////         To choose by
			pm = 0;
			bo = true;
			while (bo) {
				pm = menu(choose, SizeChoose, pm);
				if (pm == -1) {
					bo = false; break;
				}
				system("cls");
				{
					switch (pm)
					{
					case -1:
						break;
					case 0:
						ChooseName(Arr, n);
						break;
					case 1:
						ChooseUnit(Arr, n);
						break;
					case 2:

						break;
					}
					Color(BACKGROUND, 2);
					cout << "done\n";
					_getch();
				}
			}
			break;
		case 8:////////////////////////////////////////////////////      Save
			cout << "Save Date\n";
			SaveFile2(Arr, n, fileBIN);   //change function save and fileTXT
			break;
		case 9:///////////////////////////////////////////////////       Load
			cout << "Load Date\n";
			LoadFile2(Arr, n, fileBIN);   //change function load and fileTXT
			break;
		case 10://///////////////////////////////////////////////        Delete
			bo = true;			
			while(bo){
			pm = 0;
			pm = menu(Del_menu, SizeDel, pm);
			if (pm == -1) {
				bo = false; break;
			}
			system("cls");
			{
				switch (pm)
				{
				case -1:
					break;
				case 0:
				{
					bo = true;
					while (bo) {
						pm = 0;
						const char** Str = ToString(Arr, n);
						pm = menu(Str, n, pm);
						if (pm == -1) {
							bo = false; break;
						}
						if (n == 0) {
							cout << "No employees\n";
							system("pause");
							break;
						}
						Delete(Arr, n, DelArr, t, pm);
						SaveFile(DelArr, t, DelTXT);
						delete[] Str;
					}
					system("cls");
				}
				break;
				case 1:       /////////////////////////////////////////// Load Dismi.......
					LoadFile(DelArr, t, DelTXT);
					PrintAll(DelArr, t);
					break;
				case 2:       ///////////////////////////////////////////  Print Dismi.....
					PrintAll(DelArr, t);
					break;
				case 3:      ///////////////////////////////////////////   Delete Dismi....
				{
					bo = true;
					while (bo) {
						pm = 0;
						const char** Str = ToString(DelArr, t);
						pm = menu(Str, t, pm);
						if (pm == -1) {
							bo = false; break;
						}
						if (t == 0) {
							cout << "No dismissed employees\n";
							system("pause");
							break;
						}
						DeleteDes(DelArr, t, pm);
						delete[] Str;
					}
					system("cls");
				}
				break;
				}
			}
				Color(BACKGROUND, 2);
				cout << "done\n";
				_getch();
			}
			
		}
		Color(BACKGROUND, 2);
		cout << "done\n";
		_getch();
	}
	delete[] Arr;
}




