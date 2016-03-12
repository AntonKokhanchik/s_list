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

	node* iph_first;		//��������� �� ������ ������� �� ����������� ��������
	node* if_first;			//��������� �� ������ ������� �� ����������� �������
	node* dph_first;		//��������� �� ������ �������� �� �������� ��������
	node* df_first;			//��������� �� ������ �������� �� �������� �������

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

	iterator get_iph_first();					//iph = ������� �� �����������
	iterator get_dph_first();					//dph = ������� �� ��������
	iterator get_df_first();					//df  = ������� �� ��������
	iterator get_if_first();					//if  = ������� �� �����������


	int get_phone(iterator);
	string get_fam(iterator);
	iterator get_if_next(iterator);
	iterator get_df_next(iterator);
	iterator get_iph_next(iterator);
	iterator get_dph_next(iterator);
};

