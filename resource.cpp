#include "resource.h"



Resource::Resource()
{
	name = NULL;
	course = NULL;
	subject = NULL;
}



Resource::Resource(char *_name, char *_course, char *_subject)
{
	name = new char [strlen(_name) + 1];
	strcpy(name, _name);

	course = new char [strlen(_course) + 1];
	strcpy(course, _course);

	subject = new char [strlen(_subject) + 1];
	strcpy(subject, _subject);
}



Resource::~Resource()
{

	delete [] name;
	delete [] course;
	delete [] subject;

	name = NULL;
	course = NULL;
	subject = NULL;

}



bool Resource::cmp_name(char *to_cmp)
{
	if (strcmp(name, to_cmp) == 0)
		return true;

	return false;
}



bool Resource::display()
{
	cout << "name: " << name << endl
	     << "course: " << course << endl
	     << "subject: " << endl;
	
	return true;
}



Assignment::Assignment()
{
	due_date = NULL;
	grade_points = 0;
	type = NULL;
}



Assignment::Assignment(char *_name, char *_course, char *_subject, char *_due_date, int _grade_points, char *_type):Resource(_name, _course, _subject)
{
	due_date = new char [strlen(_due_date)+1];
	strcpy(due_date, _due_date);

	grade_points = _grade_points;

	type = new char [strlen(_type)+1];
	strcpy(type, _type);
}



Assignment::~Assignment()
{
	delete [] due_date;
	delete [] type;
	due_date = NULL;
	type = NULL;
	notes = NULL;
}



bool Assignment::display()
{
	Resource::display();

	cout << "due date: " << due_date << endl;

	display_grade();
	
	cout << "type: " << type << endl
	     << endl;

	return true;
}



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



void Assignment::edit_gp()
{
	cout << "set grade points (0-100): ";
	cin >> grade_points;
	cin.ignore(100, '\n');
	
	cout << "grade points set to " << grade_points << endl;
}



void link_notes()
{
}


void Assignment::edit_due_date()
{
	cout << "enter due date (mmddyy): ";
	cin.get(due_date, 100);
	cin.ignore(100, '\n');

}	



//VIDEO FUNCTIONS//////////////////////////////////////////////////////////////



Video::Video()
{
	url = NULL;
	length = NULL;
	watched = false;
}



Video::Video(char *_name, char *_course, char *_subject, char *_url, char *_length, bool _watched, bool _playing): Resource(_name, _course, _subject)
{
	url = new char[strlen(_url)+1];
	strcpy(url, _url);

	length = new char[strlen(_length)+1];
	strcpy(length, _length);

	watched = _watched;
	playing = _playing;
}



Video::~Video()
{
	if (url)
		delete [] url;

	if (length)
		delete [] length;
}



void Video::display()
{
	Resource::display();

	cout << "url: " << url << endl
	     << "length: " << length << endl;
	
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



void Video::play()
{
	if (!watched)
		watched = true;
	
	if (!playing)
	{
		playing = true;
		cout << "the video is now playing. really." << endl;
	}

	else
	{
		cout << "video already playing" << endl;
	}
}



void Video::pause()
{
	if (playing)
	{
		cout << "video paused" << endl;
	}

	else 
	{
		cout << "no video is playing" << endl;
	}
}


void Video::stop()
{
	if (playing)
	{
		playing = false;
		cout << "video stopped" << endl;
	}

	else
	{
		cout << "no video is playing" << endl;
	}
}



void Video::edit()
{
}



Notes::Notes()
{
	author = NULL;
	body = NULL;
	read = false;
}



Notes::Notes(char *_name, char *_course, char *_subject, char *_author, char *_body, bool _read): Resource(name, course, subject)
{
	author = new char [strlen(_author)+1];
	strcpy(author, _author);

	body = new char [strlen(_body)+1];
	strcpy(body, _body);
	
	read = _read;
}



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



void Notes::display()
{
	Resource::display();

	cout << "author: " << author << endl;
	
	cout << "body: " << body << endl;
	
	if (read)
		cout << "already read" << endl;
	
	else
		cout << "not read" << endl;
}



void Notes::edit_author()
{
	:
