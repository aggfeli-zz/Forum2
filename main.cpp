#include <cstdlib>
#include "binary_tree.h"
#include "simple_list.h"
#include "forum.h"

int main(int argc, char** argv) 
{
    int i, error;
    forum f("Αντικειμενοστραϕής Προγραμματισμός");
    f.set_forum();
    cout << "Forum with title: "<<  f.get_title() << " has just been created!"<< endl;
    
    thread tmp_thread;
    tmp_thread = f.get_whole_thread(0);     //Get first thread
    
    binary_tree tree;                       //Construct first tree
    for(i = 0; i < SIZE; i++)
    {
        tree.insert(tmp_thread, i, &error);     
        if (error == 1) cout << "error while inserting tree node" << endl;
    }     

    binary_tree tree1; 
    tmp_thread = f.get_whole_thread(1);
    for(i = 0; i < SIZE; i++)
    {
        tree1.insert(tmp_thread, i, &error);
        if (error == 1) cout << "error while inserting tree node" << endl;
    }     
    
    binary_tree tree2; 
    tmp_thread = f.get_whole_thread(2);
    for(i = 0; i < SIZE; i++)
    {
        tree2.insert(tmp_thread, i, &error);
        if (error == 1) cout << "error while inserting tree node" << endl;
    }     
    
    binary_tree tree3; 
    tmp_thread = f.get_whole_thread(3);
    for(i = 0; i < SIZE; i++)
    {
        tree3.insert(tmp_thread, i, &error);
        if (error == 1) cout << "error while inserting tree node" << endl;
    }     
        

    tree.enhance(tree1, &error);
    tree.enhance(tree2, &error);
    tree.enhance(tree3, &error);

    tree.printsorted(); 
    

    tree1.destroy();
    tree2.destroy();
    tree3.destroy();

    cout << "Just exiting the main function ...." << endl << endl;
    return 0;
}



