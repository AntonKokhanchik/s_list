#include "stdafx.h"
#include "s_list.h"


s_list::s_list()
{
	if_first = NULL;
	iph_first = NULL;
	df_first = NULL;
	dph_first = NULL;
}
s_list::~s_list()
{
	clear();
}

bool s_list::is_empty()
{
	if (!if_first)
		return true;
	else return false;
}

s_list::node* s_list::stels_find(int ph)
{
	if (is_empty())
		throw "empty list";
	node* tmp = iph_first;
	while (tmp)
	{
		if (tmp->phone > ph)
			return tmp;
		tmp = tmp->phone_next;
	}
	return NULL;
}
s_list::node* s_list::stels_find(string f)
{
	if (is_empty())
		throw "empty list";
	node* tmp = if_first;
	while (tmp)
	{
		if (tmp->fam > f)
			return tmp;
		tmp = tmp->fam_next;
	}
	return NULL;
}

void s_list::push(int ph, string f)
{
	node* tmp = new node;
	tmp->phone = ph;
	tmp->fam = f;

	if (is_empty())
	{
		tmp->fam_next = NULL;
		tmp->fam_prev = NULL;
		tmp->phone_next = NULL;
		tmp->phone_prev = NULL;
		iph_first = tmp;
		if_first = tmp;
		dph_first = tmp;
		df_first = tmp;

		return;
	}

	node* p = stels_find(ph);				//вставляем tmp перед p

	if (p)
	{
		if (p->phone_prev)
			p->phone_prev->phone_next = tmp;
		else iph_first;
		tmp->phone_next = p;
		tmp->phone_prev = p->phone_prev;
		p->phone_prev = tmp;
	}
	else
	{
		tmp->phone_next = NULL;
		dph_first->phone_next = tmp;
		tmp->phone_prev = dph_first;
		dph_first = tmp;
	}

	p = stels_find(f);
	if (p)
	{
		if (p->fam_prev)
			p->fam_prev->fam_next = tmp;
		else if_first;
		tmp->fam_next = p;
		tmp->fam_prev = p->fam_prev;
		p->fam_prev = tmp;
	}
	else
	{
		tmp->fam_next = NULL;
		df_first->fam_next = tmp;
		tmp->fam_prev = df_first;
		df_first = tmp;
	}

}

void s_list::pop(int ph)
{
	node* tmp = stels_find(ph);
	if (!tmp || (ph != tmp->phone))
	{
		throw "element not exist";
	}
	pop(tmp);
}
void s_list::pop(string f)
{
	node* tmp = stels_find(f);
	if (!tmp || (f != tmp->fam))
	{
		throw "element not exist";
	}
	pop(tmp);
}
void s_list::pop(node* tmp)
{
	if (tmp == iph_first)
	{
		if (iph_first == dph_first)
			dph_first = NULL;
		else
			iph_first->phone_next->phone_prev = NULL;
		iph_first = iph_first->phone_next;
	}
	else if (tmp == dph_first)
	{
		if (iph_first == dph_first)
			iph_first = NULL;
		else
			dph_first->phone_prev->phone_next = NULL;
		dph_first = dph_first->phone_prev;
	}
	else
	{
		tmp->phone_prev->phone_next = tmp->phone_next;
		tmp->phone_next->phone_prev = tmp->phone_prev;
	}


	if (tmp == if_first)
	{
		if (if_first == df_first)
			df_first = NULL;
		else
			if_first->fam_next->fam_prev = NULL;
		if_first = if_first->fam_next;
	}
	else if (tmp == df_first)
	{
		if (if_first == df_first)
			if_first = NULL;
		else
			df_first->fam_prev->fam_next = NULL;
		df_first = df_first->fam_prev;
	}
	else
	{
		tmp->fam_prev->fam_next = tmp->fam_next;
		tmp->fam_next->fam_prev = tmp->fam_prev;
	}

	delete tmp;
}

bool s_list::find(int ph)
{
	if (is_empty())
		throw "empty list";
	node* tmp = iph_first;
	while (tmp)
	{
		if (tmp->phone == ph)
			return true;
		tmp = tmp->phone_next;
	}
	return false;
}
bool s_list::find(string f)
{
	if (is_empty())
		throw "empty list";
	node* tmp = if_first;
	while (tmp)
	{
		if (tmp->fam == f)
			return true;
		tmp = tmp->fam_next;
	}
	return false;
}

void s_list::clear()
{
	if (is_empty())
		throw "empty list";
	node*tmp = if_first;
	if (tmp)
	{
		pop(tmp);
		tmp = tmp->fam_next;
	}
}

s_list::iterator s_list::get_iph_first(){ return iph_first; }
s_list::iterator s_list::get_dph_first(){ return if_first; }
s_list::iterator s_list::get_df_first(){ return dph_first; }
s_list::iterator s_list::get_if_first(){ return df_first; }

int s_list::get_phone(iterator i)
{
	if (!i)
		throw "null iterator";
	return i->phone;
}
string s_list::get_fam(iterator i)
{
	if (!i)
		throw "null iterator";
	return i->fam;
}

s_list::iterator s_list::get_if_next(s_list::iterator i)
{
	if (!i)
		throw "null iterator";
	return i->fam_next;
}
s_list::iterator s_list::get_df_next(s_list::iterator i)
{
	if (!i)
		throw "null iterator";
	return i->fam_prev;
}
s_list::iterator s_list::get_iph_next(s_list::iterator i)
{
	if (!i)
		throw "null iterator";
	return i->phone_next;
}
s_list::iterator s_list::get_dph_next(s_list::iterator i)
{
	if (!i)
		throw "null iterator";
	return i->phone_prev;
}