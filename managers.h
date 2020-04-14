#include "nodes.h"



class Manager {

	public:
		Manager();
		~Manager();
		void add_assign();
	//	void edit_assign();
		bool rem_assign();
		void display_assign();
		bool display_all_assign();
		
		void add_video();
		void rem_video();
		void display_vid();
		void display_all_vid();
		
		void add_notes();
		void rem_notes();
		void display_notes();
		void display_all_notes();

		void link_notes();

	private:
		A_node *assignments;
		V_node *videos;
	//	void edit_assign(char *name, A_node *&node)
		bool rem_assign(A_node *&node, char *&name);
		void display_assign(char *name, A_node*&);
		bool display_all_assign(A_node *node);
		void delete_all_assign(A_node *&node);
		
		void rem_video(V_node *&node, char *name);
		void display_vid(char *name, V_node *&);
		void display_all_vid(V_node *node);
		void delete_all_vid(V_node *&node);

};



class Storage {

	public:
		Storage();
		~Storage();
		void set_res();
		void add_assign();
//		void edit_assign();
		bool rem_assign();
		void display_assign();
		bool display_all_assign();

		void add_video();
		void rem_video();
		void display_vid();
		void display_all_vid();

		void add_notes();
		void rem_notes();
		void display_notes();
		void display_all_notes();

		void link_notes();

	private:
		Manager *resources;
};



