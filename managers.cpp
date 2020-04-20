/*
matt stevenson
cs202 program #1
4/16/2020

managers.cpp

this file contains the function definitions for the Storage and Manager class.

the Storage class provides the main program's functionality and gives access
to the data structure via a member array of three Manager objects. each Manager
is responsible for one class type: index 0's Manager works with a LLL of
Assignments; index 1 works with Videos; and index 2 works with Notes. 

use the Storage class top level interaction with Managers, and Managers to work
with Resource derived objects.

while each Manager is expected to work with only one class, each has member
pointers to all three Resource derived classes. 


*/

#include "managers.h"



//class constructor. initalizes array with 3 manager objects, one for each type
Storage::Storage()
{
	//create array of three Managers; 0 is Assignment, 1 is Videos,
	//2 is Notes
	resources = new Manager[3];
}



//copy constructor. takes aother Storage object and deep copies its array
Storage::Storage(const Storage &storage)
{
	resources = new Manager[3];
	
	//call the copy node functions for each type,
	//passing in the source Managers' lists and the calling object's
	copy_A_nodes(storage.resources[0].get_assign(), resources[0].get_assign());
	copy_V_nodes(storage.resources[1].get_vid(), resources[1].get_vid());
	copy_N_nodes(storage.resources[2].get_notes(), resources[2].get_notes());
}




Storage::~Storage()
{
	delete [] resources;
}



//main menu. provides top level command interface. commands offer access to sub
//menus with additional commands
void Storage::main_menu()
{
	int input = 0;//stores user selection

	do//display menu until user exists program
	{
		cout << "choose from the following: " << endl
		     << endl
		     << "(1) work on assignments" << endl
		     << "(2) work on videos" << endl
		     << "(3) work on notes" << endl
		     << "(0) to exit program" << endl
		     << endl
		     << "enter command: ";
		
		cin >> input;
		cin.ignore(100, '\n');
		cout << endl;

		switch (input)
		{
			case 1: //call the Manager's Assignment menu
				assign_menu();
				break;
			

			case 2://call the Manager's Video menu 
				vid_menu();
				break;

			case 3://call the Manager's Notes menu 
				notes_menu();
				break;
		}

	} while (input != 0);//loop until user enter '0'

	cout << "goodbye" << endl;
}



//menu for working with objects of type (Assignment). user can add, delete, display, display
//all, or access object type's sub menu
void Storage::assign_menu()
{
	int input = 0;//stores user selection

	do//display until user exits
	{
		cout << "choose from the following: " << endl
		     << endl
		     << "(1) add assignment" << endl
		     << "(2) delete assignment" << endl
		     << "(3) display assignment" << endl
		     << "(4) display all assignments" << endl
		     << "(5) work on assignment" << endl
		     << "(6) link notes to assignment" << endl
		     << "(0) to exit" << endl
		     << endl
		     << "enter command: ";

		cin >> input;
		cin.ignore(100, '\n');
		cout << endl;

		switch (input)
		{
			case 1: //call function to add one object of type
				add_assign();
				break;

			case 2: //call function to remove an object of type
				rem_assign();
				break;

			case 3: //call function to display one object of type
				display_assign();
				break;

			case 4: //call function to display all objects of type
				display_all_assign();
				break;

			case 5: //call function to retrieve object of type and
				//access its sub menu
				retrieve_assign();
				break;

			case 6: //calls function to link notes to assignment
				link_notes();
				break;
		}

	} while (input != 0);//loop until user enters '0'
}



//menu for working with objects of type (Video). user can add, delete, display, 
//display all, or access object type's sub menu
void Storage::vid_menu()
{
	int input = 0;//stores user selection

	do//display until user exits
	{

		cout << "choose from the following: " << endl
		     << endl
		     << "(1) add video" << endl
		     << "(2) delete video" << endl
		     << "(3) display video" << endl
		     << "(4) display all video" << endl
		     << "(5) work on video" << endl
		     << "(0) to exit" << endl
		     << endl
		     << "enter command: ";

		cin >> input;
		cin.ignore(100, '\n');
		cout << endl;

		switch (input)
		{
			case 1: //call function to add one object of type
				add_video();
				break;

			case 2: //call function to remove an object of type
				rem_video();
				break;

			case 3: //call function to display one object of type
				display_vid();
				break;

			case 4: //call function to display all objects of type
				display_all_vid();
				break;

			case 5: //call function to retrieve object of type and
				//access its sub menu
				retrieve_vid();
				break;
		}

	} while (input != 0);//loop until user enters '0'

}



//menu for working with objects of type. user can add, delete, display, display
//all, or access object type's sub menu
void Storage::notes_menu()
{
	int input = 0;//stores user selection

	do//display until user exits
	{
		cout << "choose from the following: " << endl
		     << endl
		     << "(1) add notes" << endl
		     << "(2) delete notes" << endl
		     << "(3) display notes" << endl
		     << "(4) display all notes" << endl
		     << "(5) work on notes" << endl
		     << "(0) to exit" << endl
		     << endl
		     << "enter command: ";
		
		cin >> input;
		cin.ignore(100, '\n');
		cout << endl;

		switch (input)
		{
			case 1: //call function to add one object of type
				add_notes();
				break;

			case 2: //call function to remove an object of type
				rem_notes();
				break;

			case 3: //call function to display one object of type
				display_notes();
				break;

			case 4: //call function to display all objects of type
				display_all_notes();
				break;

			case 5: //call function to retrieve object of type and
				//access its sub menu
				retrieve_notes();
				break;
		}

	} while (input != 0);//loop until user enters '0'

}


//ASSIGNMENT FUNCTIONS///////////////////////////////////////////////////////// 



//calls Manager of type's add object function
void Storage::add_assign()
{
	resources[0].add_assign();
}



//call Manager of type's delete object function
void Storage::rem_assign()
{
	resources[0].rem_assign();
}



//calls Manager of types display object function
void Storage::display_assign()
{
	resources[0].display_assign();
}



//calls Manager of type's display all objects function
void Storage::display_all_assign()
{
	resources[0].display_all_assign();
}



//calls Manager of type's 'work on' function which returns an
//object of type. object of type's 'work on' function is then called
//to give access to type specific commands
void Storage::retrieve_assign()
{
	char *name = new char[50];//array to hold object name to be retrieved

	cout << "enter assignment name: ";
	cin.get(name, 100);
	cin.ignore(100, '\n');

	A_node *temp = NULL;//pointer to hold retrieved object

	//call Manager's 'work on' function with the name array to find
	//the object to work on
	temp = resources[0].work_assign(name);

	if (temp)//if found, call the object's 'work on' function
		temp->work_on(resources[2].get_notes());

	temp = NULL;
	delete [] name;
}



//STORAGE:VIDEO////////////////////////////////////////////////////////////////



//calls Manager of type's add object function
void Storage::add_video()
{
	resources[1].add_video();
}



//call Manager of type's delete object function
void Storage::rem_video()
{
	resources[1].rem_video();
}



//calls Manager of types display object function
void Storage::display_vid()
{
	resources[1].display_vid();
}



//calls Manager of type's display all objects function
void Storage::display_all_vid()
{
	resources[1].display_all_vid();
}



//calls Manager of type's 'work on' function which returns an
//object of type. object of type's 'work on' function is then called
//to give access to type specific commands
void Storage::retrieve_vid()
{
	char *name = new char[50];//array to hold object name to be retrieved

	cout << "enter video name: ";
	cin.get(name, 100);
	cin.ignore(100, '\n');

	V_node *temp = NULL;//pointer to hold retrieved object
	
	//call Manager's 'work on' function with the name array to find
	//the object to work on
	temp = resources[1].work_vid(name);

	if (temp)//if found, call the object's 'work on' function
		temp->work_on();
	
	temp = NULL;
	delete [] name;
}
	


//STORAGE:NOTES////////////////////////////////////////////////////////////////



//calls Manager of type's add object function
void Storage::add_notes()
{
	resources[2].add_notes();
}



//call Manager of type's delete object function
void Storage::rem_notes()
{
	resources[2].rem_notes();
}



//calls Manager of types display object function
void Storage::display_notes()
{
	resources[2].display_notes();
}



//calls Manager of type's display all objects function
void Storage::display_all_notes()
{
	resources[2].display_all_notes();
}



//calls Manager of type's 'work on' function which returns an
//object of type. object of type's 'work on' function is then called
//to give access to type specific commands
void Storage::retrieve_notes()
{
	char *name = new char[50];//array to hold object name to be retrieved

	cout << "enter notes name: ";
	cin.get(name, 100);
	cin.ignore(100, '\n');

	N_node *temp = NULL;//pointer to retrieved object
	
	//call Manager's 'work on' function with the name array to find
	//the object to work on
	temp = resources[2].work_notes(name);

	if (temp)//if found, call the object's 'work on' function
		temp->work_on();
	
	temp = NULL;
	delete [] name;
}




//wrapper; prompts user to enter name of notes object and assignment object
//and passes the names and Manager's notes and assignments lists to 
//recursive function that searches for the named objects
void Storage::link_notes()
{
	char *name = new char[50];//stores user input for notes name

	cout << "enter notes name: ";
	cin.get(name, 100);
	cin.ignore(100, '\n');
	
	char *assign = new char[50];//stores user input for assignment name

	cout << "enter assignment name: ";
	cin.get(assign, 100);
	cin.ignore(100, '\n');

	cout << endl;
	
	//create pointers to notes and assignment
	N_node *tempN = resources[2].get_notes();
	A_node *tempA = resources[0].get_assign();

	link_notes(name, assign, tempN, tempA);//call recursive function

	delete [] name;
	delete [] assign;
}



//recursive function to find a notes object and link it to an assignment object.
//takes two name arrays; one for notes, one for assignments. searches Manager's 
//notes and assignment lists for the matching objects, then calls the found
//assignmnet object's link notes function. 
void Storage::link_notes(char *n_name, char *a_name, N_node *&_notes, A_node *&_assign)
{
	if (!_notes || !_assign)//if notes or assignment not found, exit with fail
	{
		cout << "notes not linked" << endl;
		return;
	}

	if (_notes->cmp_name(n_name))//call notes object's compare name 
				     //function
	{
		if (_assign->cmp_name(a_name))//call assignment's compare
			                     //name function
		{
			_assign->link_notes(_notes);//if found, call assignments
						  //link notes function
			cout << "notes linked" << endl
			     << endl;

			return;

		}

		else//if assignment doesnt match, traverse with next object
			link_notes(n_name, a_name, _notes, _assign->get_next());
	}
	
	//if notes doesnt match, traverse with next notes object
	link_notes(n_name, a_name, _notes->get_next(), _assign);
}



//STORAGE:PRIVATE///////////////////////////////////////////////////////////////



//recurively copies first argument's data into second argument object.
//takes two node pointers of same type as arguments. used in copy constructor
void Storage::copy_A_nodes(A_node *&node, A_node *&pointer)
{
	if (!node) return;//if first list empty or at end, exit

	pointer = new A_node(*node);//copy source into new object

	copy_A_nodes(node->get_next(), pointer->get_next());//traverse
}



//recurively copies first argument's data into second argument object.
//takes two node pointers of same type as arguments. used in copy constructor
void Storage::copy_V_nodes(V_node *&node, V_node *&pointer)
{
	if (!node) return;//if first list empty or at end, exit

	pointer = new V_node(*node);//copy source into new object

	copy_V_nodes(node->get_next(), pointer->get_next());//traverse
}



//recurively copies first argument's data into second argument object.
//takes two node pointers of same type as arguments. used in copy constructor
void Storage::copy_N_nodes(N_node *&node, N_node *&pointer)
{
	if (!node) return;//if first list empty or at end, exit

	pointer = new N_node(*node);//copy source into new object

	copy_N_nodes(node->get_next(), pointer->get_next());//traverse
}
	


//MANAGER CLASS FUNCTIONS//////////////////////////////////////////////////////



//default constructor. sets pointer members to null
Manager::Manager()
{
	assignments = NULL;
	videos = NULL;
	notes = NULL;
}



//copy constructor. takes another Manager as an argument and deep copies its
//data into self
Manager::Manager(Manager &manager)
{
	assignments = new A_node(*(manager.get_assign()));
	videos = new V_node(*(manager.get_vid()));
	notes = new N_node(*(manager.get_notes()));
}



//destructor. calls delete all functions for each member pointer type
Manager::~Manager()
{
	delete_all_assign(assignments);
	delete_all_vid(videos);
	delete_all_notes(notes);
}



//ASSIGNMENT FUNCTIONS/////////////////////////////////////////////////////////



//function to add new object of type. prompts user for all object member data 
//and creates a new object of type with that data passed as arguments to the
//constructor.  inserts new object into Manager member pointer list of type
void Manager::add_assign()
{
	//create array to hold data and prompt user for input
	char *name = new char[50];
	cout << "enter assignment name: ";
	cin.get(name, 100);
	cin.ignore(100, '\n');

	//create array to hold data and prompt user for input
	char *course = new char[50];
	cout << "enter course: ";
	cin.get(course, 100);
	cin.ignore(100, '\n');

	//create array to hold data and prompt user for input
	char *subject = new char[50];
	cout << "enter subject: ";
	cin.get(subject, 100);
	cin.ignore(100, '\n'); 

	
	//create array to hold data and prompt user for input
	char *due_date = new char[50];

	do//prompt user for due date until valid entry given
	{
		cout << "enter due date (ddmmyy): ";
		cin.get(due_date, 100);
		cin.ignore(100, '\n');

	} while(strlen(due_date) != 6);//loop until valid format given
	
	//create array to hold data and prompt user for input
	char *due_time = new char[50];

	do
	{
		cout << "enter due time (hhmm): ";
		cin.get(due_time, 100);
		cin.ignore(100, '\n');

	} while (strlen(due_time) != 4);//loop until valid format given

	int grade_points = 0;
	
	do
	{
		cout << "enter grade points (0-100): ";
		cin >> grade_points;
		cin.ignore(100, '\n');

	} while(grade_points < 0 || grade_points > 100);

	//create array to hold data and prompt user for input
	char *type = new char[50];
	cout << "enter assignment type (test, hw, etc.): ";
	cin.get(type, 100);
	cin.ignore(100, '\n');
	
	cout << endl;
	
	//create pointer to new object of type with user input as arguments
	A_node *temp = new A_node(name, course, subject, due_date, due_time, grade_points, type);

	//set new pointer as head of type list
	temp->set_next(assignments);
	
	//point Manager member list pointer to new pointer
	assignments = temp;
	temp = NULL;

	//delete all dynamic memory
	delete [] name;
	delete [] course;
	delete [] subject;
	delete [] due_date;
	delete [] due_time;
	delete [] type;
}



//wrapper; prompts user for name of object then calls recursive function to 
//search list of object type
void Manager::rem_assign()
{
	char *name = new char[50];//array to hold name of object

	cout << "enter assignment name: ";
	cin.get(name, 100);
	cin.ignore(100, '\n');
	
	cout << endl;
	//call recursive function with object list and name
	rem_assign(assignments, name);

	delete [] name;//delete dynamic memory
}



//recursive function to traverse object list and delete object is it matches
//name argument; if not, outputs error message. takes object pointer and array
void Manager::rem_assign(A_node *&node, char *&name)
{
	if (!node)//if list empty or end reached
	{
		cout << "not found" << endl
		     << endl;
		return;
	}

	if (node->cmp_name(name))//if node matches name argument
	{
		//get node's next pointer, delete matching object
		//and set node to next pointer
		A_node *temp = node->get_next();
		delete node;
		node = temp;

		return;
	}

	rem_assign(node->get_next(), name);//traverse
}



//wrapper; prompts user for name of object to display and calls recursive
//function to retrieve object
void Manager::display_assign()
{
	char *name = new char[50];//array to store object name
	A_node *temp = NULL;//pointer to hold retrieved object

	cout << "enter assignment name: ";
	cin.get(name, 100);
	cin.ignore(100, '\n');
	
	cout << endl;

	//call recursive function; if object found:
	if (display_assign(name, assignments, temp))
	{
		//call retrieved object's display function
		// and then delete dynamic memory
		temp->display();
		delete temp;
		delete [] name;

		return;
	}
	
	//otherwise output error message
	cout << "assignment not found" << endl
	     << endl;

	delete [] name;
}



//recursive function to retrieve object to display. takes a name array,
//list of object type, and pointer to a node of type as arguments
bool Manager::display_assign(char *name, A_node *&node, A_node *&temp)
{
	if (!node) return false;//if empty or end of list exit with fail

	if (node->cmp_name(name))//if list node matches name
	{
		//set pointer to new copy of list node
		temp = new A_node(*(node));
		return true;
	}

	return display_assign(name, node->get_next(), temp);//traverse
}


//wrapper; calls function to display all assignments
void Manager::display_all_assign()
{
	if (!display_all_assign(assignments))
	{
		cout << "none found" << endl
		     << endl;
	}
}


//recursive function to display all objects of type. returns false if no 
//objects found. takes a list of nodes of type as an argument
bool Manager::display_all_assign(A_node *node)
{
	if (!node) return 0;//if list empty, return false
	
	if (!node->get_next())//if last object in list
	{//display and return true
		node->display();

		return 1;
	}

	node->display();

	return display_all_assign(node->get_next());//traverse
}



//deletes all objects of type from argument list
void Manager::delete_all_assign(A_node *&node)
{
	if (!node) return;//if list empty, exit

	delete_all_assign(node->get_next());//traverse to end of list

	//tail recursion to delete objects and set pointer to null
	delete node;
	node = NULL;
}
	


//VIDEO FUNCTIONS////////////////////////////////////////////////////////////// 



//function to add new object of type. prompts user for all object member data 
//and creates a new object of type with that data passed as arguments to the
//constructor.  inserts new object into Manager member pointer list of type
void Manager::add_video()
{
	//create array to hold data and prompt user for input
	char *name = new char[50];
	cout << "enter video name: ";
	cin.get(name, 100);
	cin.ignore(100, '\n');

	//create array to hold data and prompt user for input
	char *course = new char[50];
	cout << "enter course: ";
	cin.get(course, 100);
	cin.ignore(100, '\n');

	//create array to hold data and prompt user for input
	char *subject = new char[50];
	cout << "enter subject: ";
	cin.get(subject, 100);
	cin.ignore(100, '\n');

	//create array to hold data and prompt user for input
	char * url = new char[50];
	cout << "enter video url: ";
	cin.get(url, 100);
	cin.ignore(100, '\n');
	
	//create array to hold data and prompt user for input
	char *length = new char[50];

	do
	{
		cout << "enter video length (mmss): ";
		cin.get(length, 100);
		cin.ignore(100, '\n');

	} while(strlen(length) != 4);
	
	cout << endl;

	//create pointer to new object of type with user input as arguments
	V_node *temp = new V_node(name, course, subject, url, length, false, false);
	
	//set new pointer as head of type list
	temp->set_next(videos);
	
	//point Manager member list pointer to new pointer
	videos= temp;
	temp = NULL;

	//delete dynamic memory
	delete [] name;
	delete [] course;
	delete [] subject;
	delete [] url;
	delete [] length;
}



//wrapper; prompts user for name of object then calls recursive function to 
//search list of object type
void Manager::rem_video()
{
	char *name = new char[50];//array to hold name of object

	cout << "enter video name: ";
	cin.get(name, 100);
	cin.ignore(100, '\n');
	
	cout << endl;

	//call recursive function with object list and name
	rem_video(videos, name);

	delete [] name;//delete dynamic memory
}



//recursive function to traverse object list and delete object is it matches
//name argument; if not, outputs error message. takes object pointer and array
void Manager::rem_video(V_node *&node, char *name)
{
	if (!node)//if list empty or end reached
	{
		cout << "not found" << endl
		     << endl;
		return;
	}

	if (node->cmp_name(name))//if node matches name argument
	{
		//get node's next pointer, delete matching object
		//and set node to next pointer
		V_node *temp = node->get_next();
		delete node;
		node = temp;
		return;
	}

	rem_video(node->get_next(), name);
}



//wrapper; prompts user for name of object to display and calls recursive
//function to retrieve object
void Manager::display_vid()
{
	char *name = new char[50];//store user input
	V_node *temp = NULL;

	cout << "enter video name: ";
	cin.get(name, 100);
	cin.ignore(100, '\n');
	
	cout << endl;

	if (display_vid(name, videos, temp))//if object found
	{
		temp->display();//call retrieved object's display
		delete temp;
		delete [] name;

		return;
	}

	cout << "video not found" << endl
	     << endl;

	delete [] name;
}



//recursive function to retrieve object to display. takes a name array,
//list of object type, and pointer to a node of type as arguments
bool Manager::display_vid(char *name, V_node *&node, V_node *&temp)
{
	if (!node) return false;

	if (node->cmp_name(name))//of object matches name
	{
		temp = new V_node(*(node));//copy object into argument pointer

		return true;
	}

	return display_vid(name, node->get_next(), temp);//traverse
}



//wrapper; calls function to display all assignments
void Manager::display_all_vid()
{
	display_all_vid(videos);
}



//recursive function to display all objects of type. returns false if no 
//objects found. takes a list of nodes of type as an argument
void Manager::display_all_vid(V_node *node)
{
	if (!node) return;

	node->display();//call object's display function

	display_all_vid(node->get_next());//traverse

	return;
}



//deletes all objects of type from argument list
void Manager::delete_all_vid(V_node *&node)
{
	if (!node) return;//if list empty, exit

	delete_all_vid(node->get_next());
	
	//tail recursion to delete objects and set pointer to null
	delete node;
	node = NULL;
}



//NOTES FUNCTIONS//////////////////////////////////////////////////////////////



void Manager::add_notes()
{
	//create array to hold data and prompt user for input
	char *name = new char[50];
	cout << "enter notes name: ";
	cin.get(name, 100);
	cin.ignore(100, '\n');

	//create array to hold data and prompt user for input
	char *course = new char[50];
	cout << "enter course: ";
	cin.get(course, 100);
	cin.ignore(100, '\n');

	//create array to hold data and prompt user for input
	char *subject = new char[50];
	cout << "enter subject: ";
	cin.get(subject, 100);
	cin.ignore(100, '\n');

	//create array to hold data and prompt user for input
	char * author = new char[50];
	cout << "enter author: ";
	cin.get(author, 100);
	cin.ignore(100, '\n');
	
	//create array to hold data and prompt user for input
	char *body= new char[50];
	cout << "enter text body: ";
	cin.get(body, 100);
	cin.ignore(100, '\n');
	
	cout << endl;

	//create pointer to new object of type with user input as arguments
	N_node *temp = new N_node(name, course, subject, author, body, false);
	
	//set new pointer as head of type list
	temp->set_next(notes);
	
	//point Manager member list pointer to new pointer
	notes = temp;
	temp = NULL;

	//delete dynamic memory
	delete [] name;
	delete [] course;
	delete [] subject;
	delete [] author;
	delete [] body;
}



//wrapper; prompts user for name of object then calls recursive function to 
//search list of object type
void Manager::rem_notes()
{
	char *name = new char[50];//stores user input

	cout << "enter notes name: ";
	cin.get(name, 100);
	cin.ignore(100, '\n');

	cout << endl;

	rem_notes(notes, name);//call recursive function

	delete [] name;
}



//recursive function to traverse object list and delete object is it matches
//name argument; if not, outputs error message. takes object pointer and array
void Manager::rem_notes(N_node *&node, char *name)
{
	if (!node)//if list empty or end reached
	{
		cout << "not found" << endl
		     << endl;
		return;
	}

	if (node->cmp_name(name))//if node matches name argument
	{
		//get node's next pointer, delete matching object
		//and set node to next pointer
		N_node *temp = node->get_next();
		delete node;
		node = temp;
		return;
	}

	rem_notes(node->get_next(), name);//traverse
}



//wrapper; prompts user for name of object to display and calls recursive
//function to retrieve object
void Manager::display_notes()
{
	char *name = new char[50];//store user input
	N_node *temp = NULL;//pointer for retrieved object

	cout << "enter notes name: ";
	cin.get(name, 100);
	cin.ignore(100, '\n');
	
	cout << endl;

	//if recursive function finds object, object is returned via function
	//and display function is called
	if (display_notes(name, notes, temp))
	{	//call display and delete dynamic memory
		temp->display();
		delete temp;
		delete [] name;

		return;
	}

	cout << "notes not found" << endl
	     << endl;

	delete [] name;
}



//recursive function to retrieve object to display. takes a name array,
//list of object type, and pointer to a node of type as arguments
bool Manager::display_notes(char *name, N_node *&node, N_node *&temp)
{
	if (!node) return false;

	if (node->cmp_name(name))//if name matches object
	{	//copy object into new object at pointer argument
		temp = new N_node(*(node));

		return true;
	}
	//else traverse
	return display_notes(name, node->get_next(), temp);
}



//wrapper; calls function to display all assignments
void Manager::display_all_notes()
{
	display_all_notes(notes);
}



//recursive function to display all objects of type. returns false if no 
//objects found. takes a list of nodes of type as an argument
void Manager::display_all_notes(N_node *node)
{
	if (!node) return;//exit if list list empty or at end

	node->display();//call display for each object

	display_all_notes(node->get_next());//traverse
}



//deletes all objects of type from argument list
void Manager::delete_all_notes(N_node *&node)
{
	if (!node) return;

	delete_all_notes(node->get_next());//traverse
	
	//tail recursion to delete all nodes
	delete node;
	node = NULL;
}



//wrapper; prompts user to enter name of notes object and assignment object
//and passes the names and Manager's notes and assignments lists to 
//recursive function that searches for the named objects
void Manager::link_notes()
{
	char *name = new char[50];//stores user input for notes name

	cout << "enter notes name: ";
	cin.get(name, 100);
	cin.ignore(100, '\n');
	
	char *assign = new char[50];//stores user input for assignment name

	cout << "enter assignment name: ";
	cin.get(name, 100);
	cin.ignore(100, '\n');

	cout << endl;

	link_notes(name, assign, notes, assignments);//call recursive function
}



//recursive function to find a notes object and link it to an assignment object.
//takes two name arrays; one for notes, one for assignments. searches Manager's 
//notes and assignment lists for the matching objects, then calls the found
//assignmnet object's link notes function. 
void Manager::link_notes(char *n_name, char *a_name, N_node *_notes, A_node *&assign)
{
	if (!notes || !assign)//if notes or assignment not found, exit with fail
	{
		cout << "notes not linked" << endl
		     << endl;

		return;
	}

	if (_notes->cmp_name(n_name))//call notes object's compare name 
				     //function
	{
		if (assign->cmp_name(a_name))//call assignment's compare
			                     //name function
		{
			assign->link_notes(_notes);//if found, call assignments
						  //link notes function
			return;

		}

		else//if assignment doesnt match, traverse with next object
			link_notes(n_name, a_name, _notes, assign->get_next());
	}
	
	//if notes doesnt match, traverse with next notes object
	link_notes(n_name, a_name, _notes->get_next(), assign);
}



//wrapper; calls recursive function to find matching object of type. returns
//pointer of object type
A_node * Manager::work_assign(char *name)
{
	A_node *temp = NULL;//pointer to retrieve object
	
	//call recursive function with name, Manager's list ob objects
	//and pointer to retrieve object
	work_assign(name, assignments, temp);

	return temp;
}



//recursive function traverses list of object type to find object
//matching argument name; returns found object via pointer argument
void Manager::work_assign(char *name, A_node *assign, A_node *&temp)
{
	if (!assign) return;
	
	if (assign->cmp_name(name))//compre object to name
	{
		//cout << "found" << endl;
		temp = assign;//set pointr to object
		return;
	}

	work_assign(name, assign->get_next(), temp);//traverse
}
	


//wrapper; calls recursive function to find matching object of type. returns
//pointer of object type
V_node * Manager::work_vid(char *name)
{
	V_node *temp = NULL;//pointer to retrieve object
	
	//call recursive function with name, Manager's list ob objects
	//and pointer to retrieve object
	work_vid(name, videos, temp);

	return temp;
}


//recursive function traverses list of object type to find object
//matching argument name; returns found object via pointer argument
void Manager::work_vid(char *name, V_node *vid, V_node *&temp)
{
	if (!vid) return;//if end of list or empty, exit
	
	if (vid->cmp_name(name))//if object matches name
	{
		temp = vid;//set pointer to object
		return;
	}

	work_vid(name, vid->get_next(), temp);
}



//wrapper; calls recursive function to find matching object of type. returns
//pointer of object type
N_node * Manager::work_notes(char *name)
{
	N_node *temp = NULL;//pointer to retrieve object
	
	//call recursive function with name, Manager's list ob objects
	//and pointer to retrieve object
	work_notes(name, notes, temp);

	return temp;
}



//recursive function traverses list of object type to find object
//matching argument name; returns found object via pointer argument
void Manager::work_notes(char *name, N_node *note, N_node *&temp)
{
	if (!note) return;
	
	if (note->cmp_name(name))//compare object to name
	{
		temp = note;//set pointer to object
		return;
	}

	work_notes(name, note->get_next(), temp);//traverse
}


//returns head of list of type
A_node *& Manager::get_assign()
{
	return assignments;
}



//returns head of list of type
V_node *& Manager::get_vid()
{
	return videos;
}



//returns head of list of type
N_node *& Manager::get_notes()
{
	return notes;
}



