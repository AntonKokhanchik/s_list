// s_list_menu.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include "iostream"
#include "conio.h"
#include "s_list.h"
#include "stdlib.h"
#include "time.h"


using namespace std;

#define txt "Enter:\n"\
	"1 push\n"\
	"2 pop\n"\
	"3 find element\n"\
	"4 clear list\n"\
	"5 show me all\n"\
	"6 clear screen\n"\
	"ESC to exit\n\n"

char menu(s_list&);
void PUSH(s_list&);
void POP(s_list&);
void FIND(s_list&);
void CLEAR(s_list&);
void SHOW(s_list&);

int _tmain(int argc, _TCHAR* argv[])
{
	s_list List;
	char ch;
	do
	{
		ch = menu(List);
	} while (ch != 27);
	return 0;
}

char menu(s_list& List)
{
	cout << txt;
	char ch = _getch();
	switch (ch)
	{
	case '1': PUSH(List); break;
	case '2': POP(List); break;
	case '3': FIND(List); break;
	case '4': CLEAR(List); break;
	case '5': SHOW(List); break;
	case '6': system("cls"); break;
	}
	return ch;
}

void PUSH(s_list& List)
{
	cout << "Enter element:\n";

	cout << "Family:  ";
	string fam;
	cin >> fam;

	cout << "Phone:  ";
	int phone;
	cin >> phone;

	List.push(phone, fam);
}

void POP(s_list& List)
{
	cout << "1. pop to phone\n" << "2. pop to family\n";
	char ch = _getch();
	switch (ch)
	{
	case '1':
		{
			int ph;
			cout << "Enter element's phone:  ";
			cin >> ph;
			try
			{
				List.pop(ph);
			}
			catch(char* exc)
			{
				if(exc=="element not exist")
					cout << "looking element is not exist\n";
				else if(exc=="empty list")
					cout << "list is empty\n";
			}
		} break;

	case '2':
		{
			string f;
			cout << "Enter element's family:  ";
			cin >> f;
			try
			{
				List.pop(f);
			}
			catch(char* exc)
			{
				if(exc=="element not exist")
					cout << "looking element is not exist\n";
				else if(exc=="empty list")
					cout << "list is empty\n";
			}
		} break;
	}
}

void FIND(s_list& List)
{
	cout << "1. find to phone\n" << "2. find to family\n";
	char ch = _getch();
	switch (ch)
	{
	case '1':
		{
			int ph;
			cout << "Enter element's phone:  ";
			cin >> ph;
			try
			{
				bool flag = List.find(ph);
				if (flag)
					cout << "Element " << ph << " was finded\n";			
				//по-моему, не полезно, надо вывести фамилию, зная телефон
				else
					cout << "Element " << ph << " wasn't finded\n";
			}
			catch(char* exc)
			{
				if(exc=="empty list")
					cout << "list is empty\n";
			}
		} break;

	case '2':
		{
			string f;
			cout << "Enter element's phone:  ";
			cin >> f;
			try
			{
				bool flag = List.find(f);
				if (flag)
					cout << "Element " << f << " was finded\n";
				else
					cout << "Element " << f << " wasn't finded\n";
			}
			catch(char* exc)
			{
				if(exc=="empty list")
					cout << "list is empty\n";
			}
		} break;
	}
}

void CLEAR(s_list& List)
{
	try
	{
		List.clear();
	}
	catch (char* exc)
	{
		if (exc=="empty list")
			cout << "list is empty\n";
	}

}

void SHOW(s_list& List)
{
	if (List.is_empty())
	{
		cout << "list is empty\n";
		return;
	}
	cout << "1. show to phone\n" << "2. show to family\n";
	char ch = _getch();
	switch (ch)
	{
	case '1':
		{
			s_list::iterator l = List.get_iph_first();
			s_list::iterator r = List.get_dph_first();

			cout << "forvard\t\tinvers\n";
			while (r)
			{
				cout << List.get_fam(l) << "\t" << List.get_fam(r) << endl;
				cout << List.get_phone(l) << "\t" << List.get_phone(r) << endl << endl;

				l = List.get_iph_next(l);
				r = List.get_dph_next(r);
			}
		}break;

	case '2':
		{
			s_list::iterator r = List.get_if_first();
			s_list::iterator l = List.get_df_first();

			cout << "forvard\t\tinvers\n";
			while (r)
			{
				cout << List.get_fam(r) << "\t" << List.get_fam(l) << endl;
				cout << List.get_phone(r) << "\t" << List.get_phone(l) << endl << endl;

				r = List.get_if_next(r);
				l = List.get_df_next(l);
			}
		}
	}
}

