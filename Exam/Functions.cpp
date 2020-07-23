#include <string.h>
#include <iostream>
#include <conio.h>
#include <Windows.h>
#include <ctime>
#include <algorithm>

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

void gotorc(short r, short c) {
	HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleCursorPosition(handle, { c,r });
}
void Color(unsigned short Back, unsigned short Forg) {
	HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
	unsigned short c = ((Back & 0x0F) << 4) + (Forg & 0x0F);
	SetConsoleTextAttribute(handle, c);
}
void paintmenu(const char** s, int sizem, int  pm, int left, int top) {
	system("cls");
	gotorc(top, left);
	Color(BACKGROUND, FOREGROUND);
	cout << "------Menu-------\n";
	for (size_t i = 0; i < sizem; i++)
	{
		gotorc(top + i + 1, left);
		cout << (i == pm ? Color(BACKGROUND, SELECTITEM), "=>" : "  ");
		cout << s[i] << endl;
		Color(BACKGROUND, FOREGROUND);
	}
}
int menu(const char** s, int sizem, int  pm = 0, int left = MENULEFT, int top = MENUTOP) {
	char c = 80;
	while (true)
	{
		if (c == 72 || c == 80) paintmenu(s, sizem, pm, left, top);
		c = _getch();
		switch (c)
		{
		case 27: //esc
			return -1;
		case 80: //down
			pm++;
			if (pm == sizem) pm = 0;
			break;
		case 72: //up
			if (pm == 0) pm = sizem;
			pm--;
			break;
		case 13: //enter
			return pm;
		}
	}
}
void Inemploye(employees& Date) {
	cout << "Ent.surname \t\t";				cin >> Date.s_name;
	cout << "Ent.name\t\t";					cin >> Date.name;
	cout << "Ent.by father\t\t";			cin >> Date.f_name;
	cout << "Ent.birthday\n";
	cout << "Day\t\t\t";					cin >> Date.brthd.day;
	cout << "Month\t\t\t";					cin >> Date.brthd.month;
	cout << "Year\t\t\t";					cin >> Date.brthd.year;
	cout << "Ent.sex\t\t\t";				cin >> Date.sex;
	cout << "Date getting started.\n";
	cout << "Day\t\t\t";					cin >> Date.in_work.day;
	cout << "Month\t\t\t";					cin >> Date.in_work.month;
	cout << "Year\t\t\t";					cin >> Date.in_work.year;
	getchar();
	cout << "Ent.unit\t\t";					cin.getline(Date.unit, 50);
	cout << "Ent.office\t\t";				cin.getline(Date.office, 50);
	cout << "Ent.number tel\t\t";			cin >> Date.tel;
	cout << "Ent.date of dismissal\n";
	cout << "Day  ->\t\t\t";				cin >> Date.out_work.day;
	cout << "Month->\t\t\t";				cin >> Date.out_work.month;
	cout << "Year ->\t\t\t";				cin >> Date.out_work.year;
	//getchar();
}
void AddEmployees(employees*& Date, size_t& n) {
	employees* New = new employees[n + 1];
	for (size_t i = 0; i < n; i++)
		New[i] = Date[i];
	Inemploye(New[n]);
	delete[] Date;
	Date = New;
	//delete[] New;
	n++;
}
const char** ToString(employees* Date, size_t n) {
	const char** String = new const char* [n] {0};
	char buf[35]{0};
	for (size_t i = 0; i < n; i++) {
		strcpy(buf, Date[i].s_name);
		strcat(buf, " ");
		strcat(buf, Date[i].name);
		String[i] = _strdup(buf);
		
		//cout << String[i] << endl;
		//system("pause");
		//String[i] = Date[i].s_name;
	}
	return String;
}
void Head() {
	cout << "----------------------------------------------------------------------------------------------------------------------------------------------\n";
	cout << "|Name                                       |Birthday    |Sex   |Get Start  |Unit             |Office           |Tel.            |Dismissal  |\n";
	cout << "----------------------------------------------------------------------------------------------------------------------------------------------\n";
}
void Print(employees* Date, size_t i) {
	printf_s("|%-15s %-10s %-15s |%-1d%-1d.%-1d%-1d.%-4d  |%-5s |%-1d%-1d.%-1d%-1d.%-4d |%-16s |%-16s |%-15s |%-1d%-1d.%-1d%-1d.%-4d |",
		Date[i].s_name, Date[i].name, Date[i].f_name,
		(Date[i].brthd.day / 10), (Date[i].brthd.day % 10), Date[i].brthd.month / 10, Date[i].brthd.month % 10, Date[i].brthd.year,
		Date[i].sex,
		Date[i].in_work.day / 10, Date[i].in_work.day % 10, Date[i].in_work.month / 10, Date[i].in_work.month % 10, Date[i].in_work.year,
		Date[i].unit, Date[i].office, Date[i].tel,
		Date[i].out_work.day / 10, Date[i].out_work.day % 10, Date[i].out_work.month / 10, Date[i].out_work.month % 10, Date[i].out_work.year);
	cout << endl;
}
void Print2(employees* Date, size_t i) {
	Head();
	printf_s("|%-15s %-10s %-15s |%-1d%-1d.%-1d%-1d.%-4d  |%-5s |%-1d%-1d.%-1d%-1d.%-4d |%-16s |%-16s |%-15s |%-1d%-1d.%-1d%-1d.%-4d |",
		Date[i].s_name, Date[i].name, Date[i].f_name,
		(Date[i].brthd.day / 10), (Date[i].brthd.day % 10), Date[i].brthd.month / 10, Date[i].brthd.month % 10, Date[i].brthd.year,
		Date[i].sex,
		Date[i].in_work.day / 10, Date[i].in_work.day % 10, Date[i].in_work.month / 10, Date[i].in_work.month % 10, Date[i].in_work.year,
		Date[i].unit, Date[i].office, Date[i].tel,
		Date[i].out_work.day / 10, Date[i].out_work.day % 10, Date[i].out_work.month / 10, Date[i].out_work.month % 10, Date[i].out_work.year);
	cout << endl;
}
void PrintAll(employees* Date, size_t n) {
	for (size_t i = 0; i < n; i++)
		Print(Date, i);
}

bool name(employees emp1, employees emp2) {
	return strcoll(emp1.s_name, emp2.s_name) > 0;
}
bool birthday(employees emp1, employees emp2) {
	return emp1.brthd.month > emp2.brthd.month;
}
bool unit(employees emp1, employees emp2) {
	return strcoll(emp1.unit, emp2.unit) > 0;
}
bool office(employees emp1, employees emp2) {
	return strcoll(emp1.office, emp2.office) > 0;
}
typedef bool (*CMP)(employees, employees);
void Sort(employees* gr, size_t n, CMP func) {
	if (n == 0)return;
	bool f;
	int j = 0;
	do
	{
		f = false;
		for (size_t i = 0; i < n - 1 - j; i++)
			if (func(gr[i], gr[i + 1]))
			{
				swap(gr[i], gr[i + 1]);
				f = true;
			}
		j++;
	} while (f);
}

void Edit(employees*& Date, size_t n) {
	const char* Edit_menu[]{
		"Name",
		"Birthday",
		"Sex",
		"Date started ",
		"Unit",
		"Office",
		"Tel",
		"Dismissal"
	};
	int SizeEdit = sizeof(Edit_menu) / 4;
	int i = 0;
	bool bo = true;

	while (bo) {
		i = menu(Edit_menu, SizeEdit);
		system("cls");

		switch (i)
		{
		case -1: bo = false;
			break;
		case 0:
			cout << "Old surname\t\t";
			cout << Date[n].s_name << " ";
			cout << Date[n].name << " ";
			cout << Date[n].f_name << "\n";
			cout << "Ent.surname \t\t";				cin >> Date[n].s_name;
			cout << "Ent.name\t\t";					cin >> Date[n].name;
			cout << "Ent.by father\t\t";			cin >> Date[n].f_name;
			break;
		case 1:
			cout << "Old birthday\t";
			cout << Date[n].brthd.day / 10 << Date[n].brthd.day % 10 << ".";
			cout << Date[n].brthd.month / 10 << Date[n].brthd.month % 10 << ".";
			cout << Date[n].brthd.year;
			cout << "\nEnt.New birthday\n";
			cout << "Day   -> ";	scanf_s("%d", &Date[n].brthd.day);
			cout << "Month -> ";	scanf_s("%d", &Date[n].brthd.month);
			cout << "Year  -> ";	scanf_s("%d", &Date[n].brthd.year);
			break;
		case 2:
			cout << "Sex cannot edit\n";
			system("pause");
			break;
		case 3:
			cout << "Old date getting started\t";
			cout << Date[n].in_work.day / 10 << Date[n].in_work.day % 10 << ".";
			cout << Date[n].in_work.month / 10 << Date[n].in_work.month % 10 << ".";
			cout << Date[n].in_work.year;
			cout << "\nEnt.New birthday\n";
			cout << "Day   -> ";	scanf_s("%d", &Date[n].in_work.day);
			cout << "Month -> ";	scanf_s("%d", &Date[n].in_work.month);
			cout << "Year  -> ";	scanf_s("%d", &Date[n].in_work.year);
			break;
		case 4:
			cout << "Old unit\t";
			cout << Date[n].unit << "\n";
			cout << "Ent.New unit\t";
			cin >> Date[n].unit;
			break;
		case 5:
			cout << "Old office\t";
			cout << Date[n].office << "\n";
			cout << "Ent.New office\t";
			cin >> Date[n].office;
			break;
		case 6:
			cout << "Old tel.\t";
			cout << Date[n].tel << "\n";
			cout << "Ent.New tel\t";
			cin >> Date[n].tel;
			break;
		case 7:
			cout << "Old date of dismissal\t";
			cout << Date[n].out_work.day / 10 << Date[n].out_work.day % 10 << ".";
			cout << Date[n].out_work.month / 10 << Date[n].out_work.month % 10 << ".";
			cout << Date[n].out_work.year;
			cout << "\nEnt.new date of dismissal\n";
			cout << "Day   ->";	scanf_s("%d", &Date[n].out_work.day);
			cout << "Month ->";	scanf_s("%d", &Date[n].out_work.month);
			cout << "Year  ->";	scanf_s("%d", &Date[n].out_work.year);
			break;
		}
	}
}

int StringToNumber(char* str) {
	int number;
	int dec = 10;
	size_t i = 0;
	while (true)
	{
		if (str[i] == 0) {
			number = (str[i - 1] - 48);
			break;
		}
		i++;
	}
	i--;
	while (i > 0)
	{
		number += dec * (str[i - 1] - 48);
		dec *= 10;
		i--;
	}

	return number;
}
int mystrcmp(const char* str1, const char* str2) {
	size_t i = 0;
	size_t j = 0;
	bool bo = true;
	while (true)
	{
		if (str1[i] != str2[j])bo = false;
		if (str1[i] == str2[j] && bo == true) {
			i++; j++;
			if (str1[i] == 0 && str2[j] == 0)return 0;
			else
				continue;
		}
		if (bo == false && str1[i] != 0 && str2[j] == 0)return 1;
		if (bo == false && str1[i] == 0 && str2[j] != 0 || str2[j] == 0)return -1;
		i++; j++;
	}
}
bool mystrstr(char* str1, char* str2) {
	size_t j = 0;
	size_t i = 0;
	bool in = false;
	bool out = true;
	while (true)
	{
		if (str1[i] == str2[j]) {
			in = true; j++;
			if (str1[i + 1] != str2[j] && str2[j] != 0)
				out = false;
		}		
		if (str2[j] == '\0')
			break;
		i++;
	}
	if (in == true && out == false)
		return 0;
	else 
		return 1;
}
void Search(employees* Date, size_t n) {
	char str[50];
	bool bo = false;
	bool res = false;
	cout << "Search -> ";
	cin >> str;
	if (str[0] == '\0') return;
	Head();
	 //Перевірка введеня ( число чи рядок )
	if ((str[0] > 48 && str[0] < 57) || (str[0] == '+' && str[1] == '3'))
			bo = true; 		
	
	if (!bo) {   //Якщо рядок
		for (size_t i = 0; i < n; i++)
		{
			if (!strcoll(str, Date[i].s_name)) {
				Print(Date, i);
				res = true;
			}
			if (!strcoll(str, Date[i].name)) {
				Print(Date, i);
				res = true;
			}	
			if (!strcoll(str, Date[i].f_name)) {
				Print(Date, i);
				res = true;
			}
		}		
	}
	if (bo)  // Якщо число
	{
		//int Numb = StringToNumber(str);
		for (size_t i = 0; i < n; i++)
		{
			if (mystrstr((Date[i].tel), str)) {
				Print(Date, i); res = true;
			}			
		}
		if (!res)
			cout << "No documents found" << endl;
	}
}

void ChooseName(employees* Date, size_t n) {
	char symb, symb2;
	cout << "Enter letter -> ";
	cin >> symb;
	symb2 = tolower(symb);
	Head();
	for (size_t i = 0; i < n; i++)
		if (symb == Date[i].s_name[0]|| symb2 == Date[i].s_name[0])
			Print(Date, i);
	
}
void ChooseUnit(employees* Date, size_t n) {
	char str[20];
	cout << "Enter unit -> ";
	cin >> str;
	Head();
	for (size_t i = 0; i < n; i++)
		if (mystrstr(Date[i].unit, str))
			Print(Date, i);
}
void ChooseBirth(employees* Date, size_t n) {

}
void ChoosePensioner(employees* Date, size_t n) {

}

void SaveFile(employees* Date, size_t n, const char* file) {
	FILE* fs = NULL;
	int err = fopen_s(&fs, file, "w");
	if (err) {
		cout << "Can not write file";
		exit(err);
	}
		fprintf(fs, "%d\n", n);
	for (size_t i = 0; i < n; i++)
	{
		fputs(Date[i].s_name, fs);	 fputs("\n", fs);
		fputs(Date[i].name, fs);	 fputs("\n", fs);
		fputs(Date[i].f_name, fs);	 fputs("\n", fs);

		fprintf(fs, "%d\t", Date[i].brthd.day);
		fprintf(fs, "%d\t", Date[i].brthd.month);
		fprintf(fs, "%d\n", Date[i].brthd.year);
		fputs(Date[i].sex, fs);		fputs("\n", fs);

		fprintf(fs, "%d\t", Date[i].in_work.day);
		fprintf(fs, "%d\t", Date[i].in_work.month);
		fprintf(fs, "%d\n", Date[i].in_work.year);
		fputs(Date[i].unit, fs);   	fputs("\n", fs);
		fputs(Date[i].office, fs);  fputs("\n", fs);
		fputs(Date[i].tel, fs);  fputs("\n", fs);
		fprintf(fs, "%d\t", Date[i].out_work.day);
		fprintf(fs, "%d\t", Date[i].out_work.month);
		fprintf(fs, "%d\n", Date[i].out_work.year);
	}
	fclose(fs);
}
void LoadFile(employees*& Date, size_t& n, const char* file) {
	FILE* fs = NULL;
	int err = fopen_s(&fs, file, "r");
	if (err) {
		cout << "Can not load file";
	}
	
	size_t t = 0;
	fscanf_s(fs, "%d", &t);
	employees* DateNew = new employees[t];
	for (size_t i = 0; i < n; i++)
		DateNew[i] = Date[i];

	for (size_t i = 0; i < t; i++)
	{
		fgets(DateNew[i].s_name, 25, fs);
		fgets(DateNew[i].s_name, 25, fs);
		DateNew[i].s_name[strlen(DateNew[i].s_name) - 1] = 0;
		fgets(DateNew[i].name, 25, fs);
		DateNew[i].name[strlen(DateNew[i].name) - 1] = 0;
		fgets(DateNew[i].f_name, 25, fs);
		DateNew[i].f_name[strlen(DateNew[i].f_name) - 1] = 0;
		fscanf_s(fs, "%d", &DateNew[i].brthd.day);
		fscanf_s(fs, "%d", &DateNew[i].brthd.month);
		fscanf_s(fs, "%d", &DateNew[i].brthd.year);
		fgets(DateNew[i].sex, 10, fs);
		fgets(DateNew[i].sex, 10, fs);
		DateNew[i].sex[strlen(DateNew[i].sex) - 1] = 0;
		fscanf_s(fs, "%d", &DateNew[i].in_work.day);
		fscanf_s(fs, "%d", &DateNew[i].in_work.month);
		fscanf_s(fs, "%d", &DateNew[i].in_work.year);
		fgets(DateNew[i].unit, 50, fs);
		fgets(DateNew[i].unit, 50, fs);
		DateNew[i].unit[strlen(DateNew[i].unit) - 1] = 0;
		fgets(DateNew[i].office, 50, fs);
		DateNew[i].office[strlen(DateNew[i].office) - 1] = 0;
		fgets(DateNew[i].tel, 50, fs);
		DateNew[i].tel[strlen(DateNew[i].tel) - 1] = 0;
		fscanf_s(fs, "%d", &DateNew[i].out_work.day);
		fscanf_s(fs, "%d", &DateNew[i].out_work.month);
		fscanf_s(fs, "%d", &DateNew[i].out_work.year);
	}
	n = t;
	fclose(fs);
	delete[] Date;
	Date = DateNew;
}
void Delete(employees*& Date, size_t& n, employees*& DelArr, size_t& t, int d) {

	employees* New1 = new employees[t + 1];
	for (size_t i = 0; i < t; i++) {
		New1[i] = DelArr[i];
	}
	New1[t] = Date[d];
	delete[] DelArr;
	DelArr = New1;
	t++;
	employees* New = new employees[n - 1];
	for (size_t i = 0; i < n-1; i++) {
		if (i >= d)
			New[i] = Date[i+1];
		else
		New[i] = Date[i];
	}	
	delete[] Date;
	Date = New;
	n--;
}
void DeleteDes(employees*& DelArr, size_t& t, int d) {
	employees* New = new employees[t - 1];
	for (size_t i = 0; i < t; i++) {
		if (i >= d)
			New[i] = DelArr[i + 1];
		else
			New[i] = DelArr[i];
	}
	delete[] DelArr;
	DelArr = New;
	t--;
}


void SaveFile2(employees* Date, size_t n, const char* file) {
	FILE* fs = NULL;
	int err = fopen_s(&fs, file, "wb");
	if (err) {
		cout << "Can not write file";
		exit(err);
	}
	fwrite(Date, sizeof(employees), n, fs);
	//for (size_t i = 0; i < n; i++)
	//	fwrite(&Date[i], sizeof(employees), 1, fs);
		
	fclose(fs);
}
void LoadFile2(employees*& Date, size_t& n, const char* file) {
	FILE* fs = NULL;
	int err = fopen_s(&fs, file, "rb");//////////////////      BINARY
	if (err) {
		cout << "Can not load file";
	}
	fseek(fs, 0, SEEK_END);
	n = ftell(fs) / sizeof(employees);
	fseek(fs, 0, SEEK_SET);
	delete[] Date;
	Date = new employees[n];
	fread(Date, sizeof(employees), n, fs);           //////////  Var 1
	
	//for (size_t i = 0; i < n; i++)                       ///////////// Var 2
		//fread(&Date[i], sizeof(employees), 1, fs);
		
	fclose(fs);
	
}