#include "nodes.h"



A_node::A_node()
{
	next = NULL;

}



A_node::A_node(char *_name, char *_course, char *_subject, char *_due_date, int _grade_points, char *_type):Assignment(_name, _course, _subject, _due_date, _grade_points, _type)
{
	
}



A_node::~A_node()
{
	next = NULL;
}



void A_node::set_next(A_node *&node)
{
	next = node;
}



A_node *& A_node::get_next()
{
	return this->next;
}



V_node::V_node()
{
	next = NULL;
}



V_node::V_node(char *_name, char *_course, char *_subject, char *_url, char *_length, bool _watched, bool _playing): Video(_name, _course, _subject, _url, _length, _watched, _playing)
{
	
}



V_node::~V_node()
{
	next = NULL;
}



void V_node::set_next(V_node *&node)
{
	next = node;
}



V_node *& V_node::get_next()
{
	return this->next;
}



N_node::N_node()
{
	next = NULL;
}



N_node::N_node(char *_name, char *_course, char *_subject, char *_author, char *_body, bool _read): Notes(_name, _course, _subject, _author, _body, _read)
{
	
}



N_node::~N_node()
{
	next = NULL;
}



void N_node::set_next(N_node *&node)
{
	next = node;
}



N_node *& N_node::get_next()
{
	return this->next;
}
