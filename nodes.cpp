/*
matt stevenson
cs202 program #1
4/16/2020

nodes.cpp

this file contains the function definitions for all node classes.

nodes are derived from the Resource derived classes; A_node derives from
Assignment; V_node derives from Video; N_node derives from Notes. this
strucutre allows the creation of Resource derived objects that also posess
the required functionality to build and work with LLL of said objects. 

all objects worked with during the course of a user session will be of a
node type, though they will be refered to by their parent class in any
input, output, or public function calls.

*/


#include "resource.h"



//class constructor
A_node::A_node()
{
	next = NULL;

}


//explicit constructor. takes arguments for each data member of parent class
//and ancestor. calls paent class constructor as well
A_node::A_node(char *_name, char *_course, char *_subject, char *_due_date, 
char *_due_time, int _grade_points, char *_type):
Assignment(_name, _course, _subject, _due_date, _due_time, _grade_points, _type)
{
	next = NULL;
}


//copy constructor; calls parent constructor as well
A_node::A_node(const A_node &node): Assignment(node)
{
	next = NULL;
}



//destructor
A_node::~A_node()
{
	next = NULL;
}


//takes object of class type and sets to calling object's next pointer
void A_node::set_next(A_node *&node)
{
	next = node;
}



//returns object at calling object's next pointer
A_node *& A_node::get_next()
{
	return this->next;
}



//class constructor
V_node::V_node()
{
	next = NULL;
}



//explicit constructor. takes arguments for each data member of parent class
//and ancestor. calls paent class constructor as well
V_node::V_node(char *_name, char *_course, char *_subject, char *_url, 
char *_length, bool _watched, bool _playing): 
Video(_name, _course, _subject, _url, _length, _watched, _playing)
{
	next = NULL;	
}



//copy constructor; calls parent constructor as well
V_node::V_node(const V_node &node): Video(node)
{
	next = NULL;
}



//destructor
V_node::~V_node()
{
	next = NULL;
}



//takes object of class type and sets to calling object's next pointer
void V_node::set_next(V_node *&node)
{
	next = node;
}



//returns object at calling object's next pointer
V_node *& V_node::get_next()
{
	return this->next;
}



//class constructor
N_node::N_node()
{
	next = NULL;
}



//explicit constructor. takes arguments for each data member of parent class
//and ancestor. calls paent class constructor as well
N_node::N_node(char *_name, char *_course, char *_subject, char *_author, 
char *_body, bool _read): 
Notes(_name, _course, _subject, _author, _body, _read)
{
	next = NULL;	
}



//copy constructor; calls parent constructor as well
N_node::N_node(const N_node &node): Notes(node)
{
	next = NULL;
}



//copy constructor; converts Notes object into Node; calls parent constructor
N_node::N_node(const Notes &notes): Notes(notes)
{
	next = NULL;
}



//destructor
N_node::~N_node()
{
	next = NULL;
}



//takes object of class type and sets to calling object's next pointer
void N_node::set_next(N_node *&node)
{
	next = node;
}


//returns object at calling object's next pointer
N_node *& N_node::get_next()
{
	return this->next;
}
