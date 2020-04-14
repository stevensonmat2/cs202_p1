#include "resource.h"


class A_node:public Assignment {
	
	public:
		A_node();
		A_node(char *_name, char *_course, char *_subject, char *_due_date, int _grade_points, char *_type);
		~A_node();
		void set_next(A_node *&node);
		A_node *& get_next();
		
	protected:
		A_node *next;
};


class V_node:public Video {

	public:
		V_node();
		V_node(char *_name, char *_course, char *_subject, char *_url, char *_length, bool _watched, bool _playing);
		~V_node();
		void set_next(V_node *&node);
		V_node *&get_next();

	protected:
		V_node *next;
};



class N_node:public Notes {

	public:
		N_node();
		N_node(char *name, char *course, char *subject, char *author, char *body, bool read);
		~N_node();
		void set_next(N_node *&node);
		N_node *&get_next();

	protected:
		N_node *next;
};

