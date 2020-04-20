/*
matt stevenson
cs202 program #1
4/16/2020

ressource.cpp

this file includes all function definitions for the Resource, Assignment, Video
and Notes classes. Assignments, Videos, and Notes are subclasses of Resource.
Resource provides the common attributes and interface that is shared among the
three subclasses. 

*/


#include "resource.h"



//RESOURCE FUNCTIONS///////////////////////////////////////////////////////////



//default contructor; set pointers to null
Resource::Resource()
{
	name = NULL;
	course = NULL;
	subject = NULL;
}




//explicit constructor. takes character arrays as arguments and deep copies
//their contents to the new Resource's pointers
Resource::Resource(char *_name, char *_course, char *_subject)
{
	//create new character arrays for each pointer member
	//dynamically sized to match argument's size
	//repeat for each memeber pointer
	name = new char [strlen(_name) + 1];
	strcpy(name, _name);

	course = new char [strlen(_course) + 1];
	strcpy(course, _course);

	subject = new char [strlen(_subject) + 1];
	strcpy(subject, _subject);
}




//copy constructor. takes a Resouce object as an argument and deep copies
//its member data as in previous constructor
Resource::Resource(const Resource &resource)
{
	//create new character arrays for each pointer member
	//dynamically sized to match argument's size
	//repeat for each memeber pointer
	name = new char [strlen(resource.name) + 1];
	strcpy(name, resource.name);

	course = new char [strlen(resource.course) + 1];
	strcpy(course, resource.course);

	subject = new char [strlen(resource.subject) + 1];
	strcpy(subject, resource.subject);
}



//destructor. deletes all dynamic memory and sets pointer members to null
Resource::~Resource()
{

	delete [] name;
	delete [] course;
	delete [] subject;

	name = NULL;
	course = NULL;
	subject = NULL;

}



//outputs member data 
void Resource::display()
{
	cout << "name: " << name << endl
	     << "course: " << course << endl
	     << "subject: " << subject << endl;
}



//function compares argument array to name pointer array. returns true
//if they match; false otherwise
bool Resource::cmp_name(char *to_cmp)
{
	if (strcmp(name, to_cmp) == 0)//if argument matches name member:
		return true;

	return false;
}



//ASSIGNMENT FUNCTIONS/////////////////////////////////////////////////////////



//deault constructor. sets member data to null values
Assignment::Assignment()
{
	due_date = NULL;
	due_time = NULL;
	grade_points = 0;
	type = NULL;
	notes = NULL;
}



//explicit constructor. takes data member arguments and invokes the base
//class's constructor with appropriate arguments
Assignment::Assignment(char *_name, char *_course, char *_subject, 
char *_due_date, char *_due_time, int _grade_points, char *_type):
Resource(_name, _course, _subject), notes(NULL)
{
	//sets sizes for date and time arrays
	int date_len = 7;
	int time_len = 5;
	
	//dynamically allocates new arrays for data members copies
	//argument data in. repeats for all data members
	due_date = new char [date_len];
	strcpy(due_date, _due_date);

	due_time = new char [time_len];
	strcpy(due_time, _due_time);

	grade_points = _grade_points;

	type = new char [strlen(_type)+1];
	strcpy(type, _type);
}



//copy constructor. takes an Assignment object as an argument and invokes
//the base class constructor with the argument object
Assignment::Assignment(const Assignment &assign): Resource(assign)
{
	//sets sizes for date and time arrays
	int date_len = 7;
	int time_len = 5;

	//dynamically allocates new arrays for data members and copies
	//argument data in. repeats for all data members
	due_date = new char [date_len];
	strcpy(due_date, assign.due_date);

	due_time = new char [time_len];
	strcpy(due_time, assign.due_time);

	grade_points = assign.grade_points;

	type = new char [strlen(assign.type)+1];//sized accoring to argument
	strcpy(type, assign.type);

	notes = NULL;
}



//destructor. delete dynamic memory and sets member data to null values
Assignment::~Assignment()
{
	delete [] due_date;
	delete [] due_time;
	delete [] type;
	delete_notes(notes);
	due_date = NULL;
	due_time = NULL;
	type = NULL;
	notes = NULL;
}



void Assignment::delete_notes(N_node *&_notes)
{
	if (!_notes) return;

	delete_notes(_notes->get_next());

	delete _notes;
	_notes = NULL;
}



//calls base class display function and outputs member data
bool Assignment::display()
{
	Resource::display();//call base class display
	
	//output formatted date array
	if (due_date)
	{
		cout << "due date: " 
		     << due_date[0] << due_date[1] << "/"
		     << due_date[2] << due_date[3] << "/"
		     << due_date[4] << due_date[5] << endl;
	}
	
	//output formatted time array
	if (due_time)
	{
		cout << "time due: "
		     << due_time[0] << due_time[1] << ":"
		     << due_time[2] << due_time[3] << endl;
	}

	display_grade();//call display grade function
	
	cout << "type: " << type << endl
	     << endl;

	return true;
}



//outputs letter grade corresponding to grade points member data
void Assignment::display_grade()
{
	if (grade_points > 90)
	{
		cout << "grade: A" << endl;
	}
	
	else if (grade_points > 80)
	{
		cout << "grade: B" << endl;
	}

	else if (grade_points > 70)
	{
		cout << "grade: C" << endl;
		return;
	}
	
	else if (grade_points > 60)
	{
		cout << "grade: D" << endl;
		return;
	}

	else
	{
		cout << "grade: F" << endl;
		return;
	}
}



//function enables user to change grade points data member value
void Assignment::edit_gp()
{
	do
	{
		cout << "set grade points (0-100): ";
		cin >> grade_points;
		cin.ignore(100, '\n');

	} while (grade_points < 0 || grade_points > 100);

	cout << "grade points set to " << grade_points << endl
	     << endl;
}



//allows user to link a Notes object to an Assignment object. takes a Notes
//pointer as an argument. creates a new N_node object with the Notes argument
//as a copy constructor argument. adds the new N_node object to the calling 
//object's notes list
void Assignment::link_notes(Notes *_notes)
{
	if (!_notes) return;
	
	//create a new N_node with the argument's values
	N_node *temp = new N_node(*(_notes));
	
	//set new N_node as head of notes list by passing in Assignments
	//notes list
	temp->set_next(notes);
	notes = temp;

}



//wrapper function to call the display function for each linked N_node object
void Assignment::show_notes()
{
	if (!notes)//if list empty, exit
	{
		cout << "no notes linked" << endl
		     << endl;
		return;
	}
	
	show_notes(notes);//call recursive function
}



//recusively call display function for each linked N_node object
void Assignment::show_notes(N_node *_notes)
{
	if (! _notes) return;//if empty or at end of list, exit

	_notes->display();//call N_node's display function

	show_notes(_notes->get_next());//recursively traverse to next N_Node
}



//allows user to change the due date member data
void Assignment::edit_due_date()
{
	do
	{
		//prompt user for due date and save data to member array
		cout << "enter due date (mmddyy): ";
		cin.get(due_date, 100);
		cin.ignore(100, '\n');
		
		cout << endl;
	
	} while(strlen(due_date) != 6);

	cout << "due date set: " << due_date << endl
	     << endl;
}	



//allows user to change author data member
void Assignment::edit_due_time()
{
	do
	{
		//prompt user for due time and save to member array
		cout << "enter due time (hhmm): ";
		cin.get(due_time, 100);
		cin.ignore(100, '\n');

		cout << endl;

	} while(strlen(due_time) != 4);

	cout << "due time set: " << endl
	     << endl;
}




//sub menu for object of type. displays command options for working with 
//this object's functions. prompts user for a selection and calls the
//corresponding function
//this class's version tajes a Notes object as an argument to allow for
//the linking of Notes to the calling object
void Assignment::work_on(Notes *notes)
{

	int input = 0;//stores user selection

	do
	{
		cout << "choose from the following: " << endl
		     << endl
		     << "(1) display grade" << endl
		     << "(2) edit grade points" << endl
		     << "(3) display all notes" << endl
		     << "(4) edit due date" << endl
		     << "(5) edit due time" << endl
		     << "(0) exit" << endl
		     << endl
		     << "enter command: ";
		
		cin >> input;
		cin.ignore(100, '\n');
		cout << endl;

		switch (input)
		{
			case 1: //output letter grade based on numeric value
				display_grade();
				break;

			case 2: //edit grade points
				edit_gp();
				break;

			case 3: //display linked notes
				show_notes();
				break;

			case 4: //edit due date for assignment
				edit_due_date();
				break;

			case 5: //edit due time
				edit_due_time();
				break;
		}

	} while (input != 0);//loop menu until user exits
}


//VIDEO FUNCTIONS//////////////////////////////////////////////////////////////



//default constructor. sets member data to null values
Video::Video()
{
	url = NULL;
	length = NULL;
	watched = false;
}



//explicit constructor. takes data member arguments and invokes the base
//class's constructor with appropriate arguments
Video::Video(char *_name, char *_course, char *_subject, char *_url, 
char *_length, bool _watched, bool _playing): 
Resource(_name, _course, _subject)
{
	//dynamically allocates new arrays for data members and copies
	//argument data in. repeats for all data members
	url = new char[strlen(_url)+1];
	strcpy(url, _url);

	length = new char[strlen(_length)+1];
	strcpy(length, _length);
	
	//set bool values to match arguments'
	watched = _watched;
	playing = _playing;
}



//copy constructor. takes a Video object as an argument and invokes
//the base class constructor with the argument object
Video::Video(const Video &vid): Resource(vid)
{
	//dynamically allocates new arrays for data members and copies
	//argument data in. repeats for all data members
	url = new char[strlen(vid.url)+1];
	strcpy(url, vid.url);

	length = new char[strlen(vid.length)+1];
	strcpy(length, vid.length);

	//set bool values to match arguments'
	watched = vid.watched;
	playing = vid.playing;
}


//destructor. deletes all dynamic memory
Video::~Video()
{
	if (url)
	{
		delete [] url;
		url = NULL;
	}

	if (length)
	{
		delete [] length;
		length = NULL;
	}
}



//outputs object's data and calls parent class display function
void Video::display()
{
	Resource::display();//call parent class display

	cout << "url: " << url << endl
	     << "length: " << length << endl;
	
	//check if video has been watched
	if (watched)
	{
		cout << "watched: yes" << endl;
	}

	else
	{
		cout << "watched: no" << endl;
	}

	cout << endl;
}



//"plays" video; if video is unwatched, sets 'watched' value to true
void Video::play()
{
	if (!watched)
		watched = true;
	
	if (!playing)//"play" video
	{
		playing = true;
		cout << "the video is now playing. really." << endl
		     << endl;
	}

	else
	{
		cout << "video already playing" << endl
		     << endl;
	}
}



//"pauses" video if video is playing
void Video::pause()
{
	if (playing)
	{
		cout << "video paused" << endl
		     << endl;
	}

	else 
	{
		cout << "no video is playing" << endl
		     << endl;
	}
}



//"stops" video if video is playing
void Video::stop()
{
	if (playing)
	{
		playing = false;
		cout << "video stopped" << endl
		     << endl;
	}

	else
	{
		cout << "no video is playing" << endl
		     << endl;
	}
}



//"fast forwards" video
void Video::fast_forward()
{
	cout << "fast forwarding" << endl
	     << endl;
}



//"rewinds" video
void Video::rewind()
{
	cout << "rewinding" << endl
	     << endl;
}



//sub menu for object of type. displays command options for working with 
//this object's functions. prompts user for a selection and calls the
//corresponding function
void Video::work_on()
{

	int input = 0;//stores user selection

	do
	{
		cout << "choose from the following: " << endl
		     << endl
		     << "(1) play" << endl
		     << "(2) pause" << endl
		     << "(3) stop" << endl
		     << "(4) fast forward" << endl
		     << "(5) rewind" << endl
		     << "(0) exit" << endl
		     << endl
		     << "enter command: ";
		
		cin >> input;
		cin.ignore(100, '\n');
		cout << endl;

		switch (input)
		{
			case 1: //play video
				play();
				break;

			case 2: //pause video
				pause();
				break;

			case 3: //stop video
				stop();
				break;
		}

	} while (input != 0);//loop until user exits
}



//NOTES FUNCTIONS//////////////////////////////////////////////////////////////



//default constructor; sets member values to null
Notes::Notes()
{
	author = NULL;
	body = NULL;
	read = false;
}



//explicit constructor. takes data member arguments and invokes the base
//class's constructor with appropriate arguments
Notes::Notes(char *_name, char *_course, char *_subject, char *_author, 
char *_body, bool _read): Resource(_name, _course, _subject)
{
	//dynamically allocates new arrays for data members and copies
	//argument data in. repeats for all data members
	author = new char [strlen(_author)+1];
	strcpy(author, _author);

	body = new char [strlen(_body)+1];
	strcpy(body, _body);
	
	read = _read;//set bool to match argument
}



//copy constructor. takes a Video object as an argument and invokes
//the base class constructor with the argument object
Notes::Notes(const Notes &notes): Resource(notes)
{
	//dynamically allocates new arrays for data members and copies
	//argument data in. repeats for all data members
	author = new char [strlen(notes.author)+1];
	strcpy(author, notes.author);

	body = new char [strlen(notes.body)+1];
	strcpy(body, notes.body);
	
	read = notes.read;//set bool value to match arguments'
}



//destructor; deletes all dynamic memory
Notes::~Notes()
{
	if (author)
	{
		delete [] author;
		author = NULL;
	}
	
	if (body)
	{
		delete [] body;
		body = NULL;
	}
}



//outputs object's data and calls parent class display function
void Notes::display()
{
	Resource::display();//call parent class display function

	cout << "author: " << author << endl;
	
	cout << "body: " << body << endl;
	
	if (read)
		cout << "already read" << endl;
	
	else
		cout << "not read" << endl;
	
	cout << endl;

}



//allows user to change body text for object
void Notes::edit_body()
{
	char temp[200];//variable to hold user input
	
	cout << "enter body text: ";
	cin.get(temp, 100);
	cin.ignore(100, '\n');

	cout << endl;

	delete [] body;//delete old text
	
	//create new array and set to body pointer
	body = new char[strlen(temp) + 1];
	strcpy(body, temp);

	cout << "body edited: " << body << endl
	     << endl;
}



//allows user to change author data member
void Notes::edit_author()
{
	char temp[50];
	cout << "enter author: ";
	cin.get(temp, 100);
	cin.ignore(100, '\n');

	cout << endl;

	delete [] author;
	author = new char [strlen(temp) + 1];
	strcpy(author, temp);
	
	cout << "author edited: " << author << endl
	     << endl;
}



//marks object as read
void Notes::mark_read()
{
	if (!read)
		read = true;
	
	if (read)
		read = false;
}



//sub menu for object of type. displays command options for working with 
//this object's functions. prompts user for a selection and calls the
//corresponding function
void Notes::work_on()
{
	int input = 0;//stores user selection

	do
	{
		cout << "choose from the following: " << endl
		     << endl
		     << "(1) read" << endl
		     << "(2) edit body" << endl
		     << "(3) edit author" << endl
		     << "(4) mark read/not read" << endl
		     << "(5) get notes length" << endl
		     << "(0) exit" << endl
		     << endl
		     << "enter command: ";
		
		cin >> input;
		cin.ignore(100, '\n');
		cout << endl;

		switch (input)
		{
			case 1: //mark object as read and display
				read = true;
				display();
				break;

			case 2: //edit body text of object
				edit_body();
				break;

			case 3: //edit author
				edit_author();
				break;
			
			case 4: //mark object as read
				mark_read();
				break;

			case 5: //get character count of body
				cout << strlen(body) << " characters" << endl
				     << endl;
				    break;
		}

	} while (input != 0);//loop until user exits
}
