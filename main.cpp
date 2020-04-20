/*
matt stevenson
cs202 program #1
4/16/2020

main.cpp

this file contains the main loop function and instantiates the main program
interface via the creation of a Storage object. 

this program enables a user to manage their Assignments, class Videos, and
Notes. users can add grades to their assignments and link notes to particular
assignments. users can edit their notes, and interact with their videos.

users may also display individual objects or lists of objects, as well as
delete them. 


*/



#include "managers.h"



//main loop
int main()
{

	Storage stor;//create interface object

	stor.main_menu();//call objects main menu function

	return 0;
}
