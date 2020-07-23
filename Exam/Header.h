#pragma once
#define MENUTOP 4
#define MENULEFT 20
struct DMY;
struct employees;
const char** ToString(employees* Date, size_t n);
void gotorc(short r, short c);
void Color(unsigned short Back, unsigned short Forg);
void paintmenu(const char** s, int sizem, int  pm, int left, int top);
int menu(const char** s, int sizem, int  pm = 0, int left = MENULEFT, int top = MENUTOP);
void Inemploye(employees& Date);
void AddEmployees(employees*& Date, size_t& n);
void Head();
void Print(employees* Date, size_t i);
void PrintAll(employees* Date, size_t n);

bool name(employees emp1, employees emp2);
bool birthday(employees emp1, employees emp2);
bool unit(employees emp1, employees emp2);
bool office(employees emp1, employees emp2);
typedef bool (*CMP)(employees, employees);
void Sort(employees* gr, size_t n, CMP func);

void ChooseName(employees* Date, size_t n);
void ChooseUnit(employees* Date, size_t n);

void Edit(employees*& Date, size_t n);
void Search(employees* Date, size_t n);
void SaveFile(employees* Date, size_t n, const char* file);
void LoadFile(employees*& Date, size_t& n, const char* file);
void Delete(employees*& Date, size_t& n, employees*& DelArr, size_t& t, int d);
void DeleteDes(employees*& DelArr, size_t& t, int d);
void SaveFile2(employees* Date, size_t n, const char* file);
void LoadFile2(employees*& Date, size_t& n, const char* file);