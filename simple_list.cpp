#include "simple_list.h"

info_list::info_list()          //List constructor
{
    size = 0;
    start = NULL; 
}


void info_list::create_simplelist(thread stoixeio, int i,int *error) //Create siple list node
{
    *error = 0;
    list_node *temp = new list_node;
    if ( temp == NULL )  *error = 1;   
    temp->posts = stoixeio.get_whole_post(i);   //Get creator's post
    temp->next = NULL;
    if (start == NULL)              //First node-list is empty
        start = temp;
    else                            //List isn't empty-make node first
    {
        temp->next = start;
        start = temp;
    }
    size++;                         //Increase list's size
}

void info_list::list_entry(info_list list)     //Merge list with parameter list
{
    list_node *temp = start;
    while(temp->next != NULL) temp = temp->next;    //Go at the end of the list
    
    list_node *temp2 = list.start;
    
    while(temp2 != NULL)                 //While you aren't at the end of the second list
    {
        list_node *temp1 = new list_node;
        temp1->posts = temp2->posts;
        temp->next = temp1;
        temp1->next = NULL;
        temp2 = temp2->next;
    }  
}

void info_list::Delete()            //Delete whole list
{
    list_node *temp1, *temp2;
    temp1 = start;
    while(temp1 != NULL)
    {   
        temp2 = temp1;
        temp1 = temp1->next;
        delete temp2;
    }
    start = NULL;   
}

void info_list::print_list()        //Print whole list
{
    int month, day, year;
    list_node *temp = start;
    while (temp != NULL)
    {
        cout << "" << temp->posts.get_post() << endl;
        cout << "Post title: "<<  temp->posts.get_post() <<  endl;
        cout << "Post id: "<<  temp->posts.get_post_id() <<  endl;
        cout << "Post writer: "<<  temp->posts.get_post_creator() <<  endl;
        temp->posts.get(month, day, year);
        cout << "Post date: " <<  day << " "<< month << "  " << year <<  endl;
        cout << "Post text: "<<  temp->posts.get_post_txt() <<  endl;
        temp = temp->next;
    }
}

