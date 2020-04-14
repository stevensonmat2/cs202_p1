#include "managers.h"


//STORAGE CLASS FUNCTIONS//////////////////////////////////////////////////////



Storage::Storage()
{
	resources = new Manager[3];
}



Storage::~Storage()
{
	delete [] resources;
}



//ASSIGNMENT FUNCTIONS///////////////////////////////////////////////////////// 



void Storage::add_assign()
{
	resources[0].add_assign();
}


/*
void Storage::edit_assign()
{
	resources[0].edit_assign();

}
*/

bool Storage::rem_assign()
{
	resources[0].rem_assign();
}


void Storage::display_assign()
{
	resources[0].display_assign();
}



bool Storage::display_all_assign()
{
	resources[0].display_all_assign();
}



//VIDEO FUNCTIONS//////////////////////////////////////////////////////////////



void Storage::add_video()
{
	resources[1].add_video();
}



void Storage::rem_video()
{
	resources[1].rem_video();
}



void Storage::display_vid()
{
	resources[1].display_vid();
}



void Storage::display_all_vid()
{
	resources[1].display_all_vid();
}
	


//MANAGER CLASS FUNCTIONS//////////////////////////////////////////////////////



Manager::Manager()
{
	assignments = NULL;

}



Manager::~Manager()
{
	delete_all_assign(assignments);
	delete_all_vid(videos);
}



//ASSIGNMENT FUNCTIONS/////////////////////////////////////////////////////////



void Manager::add_assign()
{
	char *name = new char[50];
	cout << "enter assignment name: ";
	cin.get(name, 100);
	cin.ignore(100, '\n');

	char *course = new char[50];
	cout << "enter course: ";
	cin.get(course, 100);
	cin.ignore(100, '\n');

	char *subject = new char[50];
	cout << "enter subject: ";
	cin.get(subject, 100);
	cin.ignore(100, '\n');

	char * due_date = new char[50];
	cout << "enter due date (ddmmyy): ";
	cin.get(due_date, 100);
	cin.ignore(100, '\n');
	
	int grade_points = 0;
	cout << "enter subject: ";
	cin >> grade_points;
	cin.ignore(100, '\n');

	char *type = new char[50];
	cout << "enter assignment type (test, hw, etc.): ";
	cin.get(type, 100);
	cin.ignore(100, '\n');
	
	cout << endl;

	A_node *temp = new A_node(name, course, subject, due_date, grade_points, type);
	temp->set_next(assignments);
	assignments = temp;
	temp = NULL;

	//assignments->display();

	delete [] name;
	delete [] course;
	delete [] subject;
	delete [] due_date;
	delete [] type;
}



bool Manager::rem_assign()
{
	//dispaly_all();

	char *name = new char[50];
	bool val;

	cout << "enter assignment name: ";
	cin.get(name, 100);
	cin.ignore(100, '\n');

	val = rem_assign(assignments, name);

	delete [] name;

	return val;
}



bool Manager::rem_assign(A_node *&node, char *&name)
{
	if (!node) return false;

	if (node->cmp_name(name))
	{
		A_node *temp = node->get_next();
		delete node;
		node = temp;
		return true;
	}

	return rem_assign(node->get_next(), name);


}



void Manager::display_assign()
{
	char *name = new char[50];

	cout << "enter assignment name: ";
	cin.get(name, 100);
	cin.ignore(100, '\n');

	display_assign(name, assignments);
}



void Manager::display_assign(char *name, A_node *&node)
{
	if (!node) return;

	if (node->cmp_name(name))
	{
		node->display();
	}

	display_assign(name, node->get_next());
}



bool Manager::display_all_assign()
{
	display_all_assign(assignments);
}



bool Manager::display_all_assign(A_node *node)
{
	if (!node) return 0;

	node->display();

	display_all_assign(node->get_next());

	return true;
}



void Manager::delete_all_assign(A_node *&node)
{
	if (!node) return;

	delete_all_assign(node->get_next());
	delete node;
	node = NULL;
}
	



/*
void Manager::edit_assign()
{
	char *temp = new char[50];
	cout << "enter name to edit: ";
	cin.get(temp, 100);
	cin.ignore(100, '\n');

	edit_assign(name, assignments);
}


void Manager::edit_assign(char *name, A_node *&node)
{
	if (!node) return;

	if (node->cmp_name(name))
		return;

	edit_assign(name, node->get_next());
}
*/

//VIDEO FUNCTIONS////////////////////////////////////////////////////////////// 



void Manager::add_video()
{
	char *name = new char[50];
	cout << "enter assignment name: ";
	cin.get(name, 100);
	cin.ignore(100, '\n');

	char *course = new char[50];
	cout << "enter course: ";
	cin.get(course, 100);
	cin.ignore(100, '\n');

	char *subject = new char[50];
	cout << "enter subject: ";
	cin.get(subject, 100);
	cin.ignore(100, '\n');

	char * url = new char[50];
	cout << "enter video url: ";
	cin.get(url, 100);
	cin.ignore(100, '\n');
	
	char *length = new char[50];
	cout << "enter video length (mmss): ";
	cin.get(length, 100);
	cin.ignore(100, '\n');
	
	cout << endl;

	V_node *temp = new V_node(name, course, subject, url, length, false, false);
	temp->set_next(videos);
	videos= temp;
	temp = NULL;

	//assignments->display();

	delete [] name;
	delete [] course;
	delete [] subject;
	delete [] url;
	delete [] length;
}



void Manager::rem_video()
{
	char *name = new char[50];
	bool val;

	cout << "enter video name: ";
	cin.get(name, 100);
	cin.ignore(100, '\n');

	rem_video(videos, name);

	delete [] name;
}



void Manager::rem_video(V_node *&node, char *name)
{
	if (!node) return;

	if (node->cmp_name(name))
	{
		V_node *temp = node->get_next();
		delete node;
		node = temp;
		return;
	}

	rem_video(node->get_next(), name);
}



void Manager::display_vid()
{
	char *name = new char[50];

	cout << "enter video name: ";
	cin.get(name, 100);
	cin.ignore(100, '\n');

	display_vid(name, videos);
}



void Manager::display_vid(char *name, V_node *&node)
{
	if (!node) return;

	if (node->cmp_name(name))
	{
		node->display();
	}

	display_vid(name, node->get_next());
}



void Manager::display_all_vid()
{
	display_all_vid(videos);
}



void Manager::display_all_vid(V_node *node)
{
	if (!node) return;

	node->display();

	display_all_vid(node->get_next());

	return;
}



void Manager::delete_all_vid(V_node *&node)
{
	if (!node) return;

	delete_all_vid(node->get_next());
	delete node;
	node = NULL;
}




