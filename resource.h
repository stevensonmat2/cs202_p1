#include <iostream>
#include <cstring>
#include <cctype>



using namespace std;


class N_node;



class Resource {

	public:
		Resource();
		Resource(char *_name, char *_course, char *_subject);
		~Resource();
		bool display();
		bool display_course();
		bool change_course();
		bool display_subject();
		bool change_subject();
		bool display_name();
		bool change_name();
		bool cmp_name(char *to_cmp);

	protected:
		char *name;
		char *course;
		char *subject;
};



class Assignment:public Resource {

	public:
		Assignment();
		Assignment(char *_name, char *_course, char *_subject, char *_due_date, int _grade_points, char *_type);
		~Assignment();
		bool display();
		void display_grade();
		void edit_gp();
		bool link_notes();
		void edit_due_date();
	
	protected:
		N_node *notes;
		char *due_date;
		int grade_points;
		char *type;
};



class Video:public Resource {

	public:
		Video();
		Video(char *_name, char *_course, char *_subject, char *_url, char *_length, bool _watched, bool _playing);
		~Video();
		void display();
		void play();
		void pause();
		void stop();
		void edit();

	private:
		char *url;
		char *length;
		bool watched;
		bool playing;
};



class Notes:public Resource {

	public:
		Notes();
		Notes(char *name, char *course, char *subject, char *author, char *body, bool read);
		~Notes();
		void display();
		void edit_author();
		void edit_body();
		bool compare_author(char *name);
		void mark_read();
		
	private:
		char *author;
		char *body;
		bool read;
};





