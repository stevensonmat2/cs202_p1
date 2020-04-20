/*
matt stevenson
cs202 program #1
4/16/2020

ressource.h

this file contains the class definitions for the parent class Resource and its
child classes (Assignment, Video, and Notes). it also contains and additional
set of child node classes that are derived from the first set of subclasses.
the first set (Assignment, Video, Notes) of classes offer the functionality 
needed to work with objects of each type. each subclass inherits some 
essential shared attributes from Resource, but also contain unique qualities 
and functions.

each subclass also posesses a sub menu to provide access to their object
specific functionality.

the node classes exist simply to provide functionality needed to manage a data
structure of linked node objects. while conceptually the program works with the
first set of subclasses, in implementation the nodes are the main objects being
worked with.

*/



#include <iostream>
#include <cstring>
#include <cctype>



using namespace std;



//Resource class. provides base functionality and data members to be shared
//amongst all subclasses
class Resource {

	public:
		//cosntructor
		Resource();
		
		//explicit constructor
		Resource(char *_name, char *_course, char *_subject);

		//copy constructor
		Resource(const Resource &resource);

		//destructor
		~Resource();

		//outputs data member info
		void display();

		//compares array argument to name member; returns true if match
		bool cmp_name(char *to_cmp);

	protected:
		//pointers to arrays representing object attributes
		char *name;
		char *course;
		char *subject;
};



//Assignment class. represents a school assignment and contains all
//functionality to work with Assignment objects. subclass of Resource
class Assignment:public Resource {

	public:
		//constructor
		Assignment();

		//explicit constructor
		Assignment(char *_name, char *_course, char *_subject, 
		char *_due_date, char *due_time, int _grade_points, char *_type);

		//copy constructor
		Assignment(const Assignment &assign);

		//destructor
		~Assignment();

		//outputs data memeber info; calls parent class display
		bool display();

		//outputs letter grade based on grade points
		void display_grade();

		//allows user to edit grade points
		void edit_gp();

		//allows user to link notes to assignment object;
		//takes Notes object as argument
		void link_notes(class Notes *notes);

		//wrapper; calls function that calls linked 
		//Notes object's display
		void show_notes();

		//allows user to edit due date
		void edit_due_date();

		//allows user to edit author
		void edit_due_time();

		//sub menu to access class specific functions;
		//takes notes object to enable linking notes
		void work_on(Notes *notes);
	
	protected:
		//partial declaration; pointer  to Notes object
		class N_node *notes;

		//calls linked Notes object's display; recusrively
		//traverses passed in list of Notes nodes
		void show_notes(N_node *notes);

		//recursively deletes notes in notes list
		void delete_notes(N_node *&notes);

		//data members; represent attributes of class
		char *due_date;
		char *due_time;
		int grade_points;
		char *type;
};



//Video class. represents a link to a video and provides functionality
//needed to interact with the Video object
class Video:public Resource {

	public:
		//constructor
		Video();

		//explicit constructor
		Video(char *_name, char *_course, char *_subject, char *_url, 
		char *_length, bool _watched, bool _playing);

		//copy constructor
		Video(const Video &vid);

		//destructor
		~Video();

		//outputs data member info
		void display();

		//"plays" video if not playing
		void play();

		//"pauses" video if playing
		void pause();

		//"stops" video if playing
		void stop();
		
		//"fast forwards" video
		void fast_forward();
		
		//"rewinds" video
		void rewind();

		//allows user to edit info of object
		void edit();

		//sub menu to access class specific functions
		void work_on();

	private:
		//data members; represent attributes of class
		char *url;
		char *length;
		bool watched;
		bool playing;
};



class Notes:public Resource {

	public:
		//constructor
		Notes();

		//explicit constructor
		Notes(char *name, char *course, char *subject, char *author, 
		char *body, bool read);

		//copy constructor
		Notes(const Notes &notes);

		//destructor
		~Notes();

		//outputs member data info
		void display();

		//allows user to change body text
		void edit_body();
		
		//allows user to edit author
		void edit_author();
	
		//compares passed in name to object author member
		bool compare_author(char *name);

		//marks object as read
		void mark_read();
		
		//sub menu to access class specific functions
		void work_on();
		
	private:
		//data members; represent attributes of class
		char *author;
		char *body;
		bool read;
};



//Assignment node class. child of Assignment class. provides functionality
//to create data structure to manage object of parent class
class A_node:public Assignment {
	
	public:
		//contructor
		A_node();

		//explicit cnstructor
		A_node(char *_name, char *_course, char *_subject, 
		char *_due_date, char *due_time, int _grade_points, char *_type);

		//copy constructor
		A_node(const A_node &node);

		//destructor
		~A_node();

		//function takes object of same type and sets to calling
		//objects next pointer
		void set_next(A_node *&node);

		//returns calling object's next pointer's object
		A_node *& get_next();
		
	protected:
		//pointer to another object of type
		A_node *next;
};


//Video node class. child of Video class. provides functionality to create
//data structure to manage objects of parent class
class V_node:public Video {

	public:
		//constructor
		V_node();

		//explicit constructor
		V_node(char *_name, char *_course, char *_subject, char *_url, 
		char *_length, bool _watched, bool _playing);

		//copy constructor
		V_node(const V_node &node);

		//destructor
		~V_node();
		
		//function takes object of same type and sets to calling
		//objects next pointer
		void set_next(V_node *&node);
		
		//returns calling object's next pointer's object
		V_node *&get_next();

	protected:
		//pointer to another object of type
		V_node *next;
};



//Notes node class. child of Notes class. provides functionality to create data
//structure to manage objects of parent class
class N_node:public Notes {

	public:
		//constructor
		N_node();

		//explicit constructor
		N_node(char *name, char *course, char *subject, char *author, char *body, bool read);

		//copy constructor
		N_node(const N_node &node);
		
		//conversion constructor; turns Notes object into N_Node
		N_node(const Notes &notes);
		~N_node();
		
		//function takes object of same type and sets to calling
		//objects next pointer
		void set_next(N_node *&node);
		
		//returns calling object's next pointer's object
		N_node *&get_next();

	protected:
		//pointer to another object of type
		N_node *next;
};



