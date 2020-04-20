/*
matt stevenson
cs202 program #1
4/16/2020

managers.h

this file contains the class defintions for the Manager and Storage classes.
the Storage class offers a broad interface for working with the data structure,
while the Manager class provides the functionality to work with objects in the
data structure. 

a Storage object has an array of three Manager objects which manage LLLs of 
Assignment, Video, and Notes objects. each Manager has three pointers for
creating LLLs. 

*/



#include "resource.h"

//	REMOVE MANAGER CLASS

//Manager class. provides functionality to add, remove, and work on data in
//the data structure. has three member pointers; one to each Resource derived
//class (Assignment, Video, Notes)
class Manager {

	public:
		Manager();//constructor
		Manager(Manager &manager);//copy constructr
		~Manager();//destructor
	
		//prompts user to create a new Assignment
		void add_assign();

		//wrapper; calls function to remove an Assignment object
		void rem_assign();	  		
		
		//wrapper; calls function to display an Assignment object
		void display_assign();

		//wrapper; calls function to display all Assignments. returns
		//true if found, false if not
		void display_all_assign();

		//takes a name array, finds and returns matching Assignment
		//object to work on
		A_node *work_assign(char *name);
		
		//prompts user to create a new Video object
		void add_video();

		//wrapper; calls function to remove a Video object
		void rem_video();

		//wrapper; calls function to display Video object
		void display_vid();

		//wrapper; calls function to display all Video objects returns
		//true if found, false if not
		void display_all_vid();

		//takes a name array, finds and returns matching Video object
		V_node *work_vid(char *name);
	
		//prompts user to creare a new Notes object
		void add_notes();

		//wrapper; calls function to remove Notes object
		void rem_notes();

		//wrapper; calls function to display Notes object
		void display_notes();

		//wrapper; calls function to display all Notes objects returns
		//true if found, false if not
		void display_all_notes();

		//takes a name array, finds and returns matching Notes object
		N_node *work_notes(char *name);
	
		//wrapper; calls function to link Notes object to Assignment		
		void link_notes();
		
		//following three functions return the Manager's LLLs of each
		//respective type
		A_node *& get_assign();
		V_node *& get_vid();
		N_node *& get_notes();

	private:
		//pointers to three main classes; point to LLLs
		A_node *assignments;
		V_node *videos;
		N_node *notes;

		//takes a name array and recusrively searches for matching
		//object; deletes object if found
		void rem_assign(A_node *&node, char *&name);

		
		//takes a name array and recusrively searches for matching
		//object; displays object if found
		bool display_assign(char *name, A_node*&node, A_node *&temp);

		//recursively traverses LLL of type and displays each object
		bool display_all_assign(A_node *node);

		//recursively deletes all objects of type in respective LLL
		void delete_all_assign(A_node *&node);
		
		//takes a name array and recusrively searches for matching
		//object; deletes object if found
		void rem_video(V_node *&node, char *name);
		
		//takes a name array and recusrively searches for matching
		//object; displays object if found
		bool display_vid(char *name, V_node *&node, V_node *&temp);

		//recursively traverses LLL of type and displays each object
		void display_all_vid(V_node *node);

		//recursively deletes all objects of type in respective LLL
		void delete_all_vid(V_node *&node);

		//takes a name array and recusrively searches for matching
		//object; deletes object if found
		void rem_notes(N_node *&node, char *name);
		
		//takes a name array and recusrively searches for matching
		//object; displays object if found
		bool display_notes(char *name, N_node *&notes, N_node *&temp);
		
		//recursively traverses LLL of type and displays each object
		void display_all_notes(N_node *node);
		
		//recursively deletes all objects of type in respective LLL
		void delete_all_notes(N_node *&node);
		
		//takes two name arrays, a notes node and an assign. node;
		//recursively traverses assign. LLL to find match; if found
		//recursively traverses notes LLL and calls function to link
		void link_notes(char *n_name, char *a_name, N_node *notes, A_node *&assign);

		//the following three functions take name arrarys and two
		//node ptr objects of their respective types. the first node is
		//used to traverse recursively; if a node matches the name,
		//copy the first node into the second. if successful, the
		//returned node ptr will call its "work on" function
		void work_assign(char *name, A_node *assign, A_node *&temp);
		void work_vid(char *name, V_node *vid, V_node *&temp);
		void work_notes(char *name, N_node *note, N_node *&temp);
};



//Storage class. provides user interface for users to add, remove, display,
//and work on objects in the data structure. has an array of Manager objects
class Storage {

	public:
		Storage();//default constructor
		Storage(const Storage &storage);//copy constructor
		~Storage();//destructor
		
		//provides commands list and prompts user to choose an action;
		//provides accesss to sub menus for additional controls
		void main_menu();

		//sub menus; provide type specific command options including
		//add, delete, and display, and access to type-specific menus
		void assign_menu();
		void vid_menu();
		void notes_menu();
		
		//allows user to add new object of type to data structure
		void add_assign();

		//allows user to remove object of type
		void rem_assign();

		//prompts user to enter name of object to retrieve and
		//displays it
		void display_assign();
		
		//displays all objects of type
		void display_all_assign();

		//prompts user for name of object to access its commands
		void retrieve_assign();

		//allows user to add new object of type to data structure
		void add_video();
		
		//allows user to remove object of type
		void rem_video();
		
		//prompts user to enter name of object to retrieve and
		//displays it
		void display_vid();

		//displays all objects of type
		void display_all_vid();
		
		//prompts user for name of object to access its commands
		void retrieve_vid();

		//allows user to add new object of type to data structure
		void add_notes();
		
		//allows user to remove object of type
		void rem_notes();
		
		//prompts user to enter name of object to retrieve and
		//displays it
		void display_notes();
		
		//displays all objects of type
		void display_all_notes();
		
		//prompts user for name of object to access its commands
		void retrieve_notes();
		
		//allows user to link notes to an Assignment object
		void link_notes();

	private:
		//an array of manager objects; each controls a LLL of
		//a different type (Assignment, Video, Notes)
		Manager *resources;

		void link_notes(char *n_name, char *a_name, N_node *&_notes, A_node *&_assign);
		//used in the copy constructor; recusively traverses passed in
		//LLLs and copies the argument objects to own list
		void copy_A_nodes(A_node *&node, A_node *&pointer);
		void copy_V_nodes(V_node *&node, V_node *&pointer);
		void copy_N_nodes(N_node *&node, N_node *&pointer);
};



