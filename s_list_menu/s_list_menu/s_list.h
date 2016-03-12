#pragma once
#include <string>

using namespace std;

class s_list
{
private:
	struct node
	{
		string fam;
		int phone;
		node* fam_next;
		node* fam_prev;
		node* phone_next;
		node* phone_prev;
	};

	node* iph_first;		//указатель на первый элемент по возрастанию телефона
	node* if_first;			//указатель на первый элемент по возрастанию фамилий
	node* dph_first;		//указатель на первый эелемент по убыванию телефона
	node* df_first;			//указатель на первыф эелемент по убыванию фамилий

	node* stels_find(int);
	node* stels_find(string);
	void pop(node*);

public:
	s_list();
	~s_list();

	bool is_empty();

	typedef node* iterator;

	void push(int, string);
	void pop(int);
	void pop(string);

	bool find(int);
	bool find(string);
	void clear();

	iterator get_iph_first();					//iph = телефон по возрастанию
	iterator get_dph_first();					//dph = телефон по убыванию
	iterator get_df_first();					//df  = фамилия по убыванию
	iterator get_if_first();					//if  = фамилия по возрастанию


	int get_phone(iterator);
	string get_fam(iterator);
	iterator get_if_next(iterator);
	iterator get_df_next(iterator);
	iterator get_iph_next(iterator);
	iterator get_dph_next(iterator);
};

