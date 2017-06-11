#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include "binary_tree.h"


binary_tree::binary_tree()                      //Tree constructor
{
    cout << "Tree has been created" << endl;
    root = NULL;
}

void binary_tree::destroy()
{
  destroy_tree(root);
  cout << "Tree has been deleted" << endl;
}

void binary_tree::destroy_tree(tree_node *temp)         //Destroy tree recursively
{   
    if(temp != NULL)
    {
        destroy_tree(temp->left);
        destroy_tree(temp->right);
        temp->list.Delete();                            //Destroy tree_node list
        delete temp;
    }
}

int binary_tree::Tree_keno()
{    
    return (root == NULL);
}

void binary_tree::insert(thread stoixeio, int i, int *error)
{
    tree_node* temp = new tree_node;
    tree_node* parent;
    temp->creator = stoixeio.get_post_creator(i);
    temp->list.create_simplelist(stoixeio, i, error);
    temp->left = NULL;
    temp->right = NULL;
    parent = NULL;
    
    if(Tree_keno()) root = temp;
    else
    {
        tree_node* curr;
        curr = root;

        while(curr)
        {
            parent = curr;
            if(temp->creator > curr->creator) curr = curr->right;       //Go to right subtree
            else if (temp->creator < curr->creator) curr = curr->left;  //Go to left subtree
            else 
            {
                //If creator exists add his/her post to existed list
                curr->list.create_simplelist(stoixeio, i, error);
                return;
            }
        }
        if(temp->creator < parent->creator)
           parent->left = temp;
        else
           parent->right = temp;
    }
}


void binary_tree::printsorted()
{
    cout << "Print sorted tree" << endl ;
    inorder(root);
}

void binary_tree::inorder(tree_node *temp)
{
    if(temp != NULL)
    {        
        if(temp->left != NULL) inorder(temp->left);
        temp->list.print_list();
        if(temp->right != NULL) inorder(temp->right);
    }
    else return;
}

void binary_tree::enhance(binary_tree tree, int *error)
{
    enhance(root, tree.root, error);
}

void binary_tree::enhance(tree_node *temp, tree_node *temp1,  int *error )
{
    int found = 0;
    if(temp1 != NULL)
    {        
        if(temp1->left != NULL) enhance(temp, temp1->left, error); //Go to left subtree
        
        tree_node *parent = NULL, *curr = temp;     

        while(curr != NULL)             //Find where to put temp1-tree_node in wanted tree
	{  
            parent = curr;
            if(temp1->creator > curr->creator) curr = curr->right;
            else if (temp1->creator < curr->creator) curr = curr->left;
            else {
                curr->list.list_entry(temp1->list);   //Post creator exists so add his/her post at existed list
                found = 1;
                break;
            }
        }

        if (found != 1)     //If post creator doesn't exist on tree
        {
            tree_node *node = new tree_node;    //Allocate new tree node
            node->creator = temp1->creator;
            node->list = temp1->list;           //Copy list with his/her posts
            node->left = node->right = NULL;
            if(temp1->creator < parent->creator)    //Put creator in the right place
                parent->left = node;
            else
                parent->right = node;       
        }
        if(temp1->right != NULL) enhance(temp, temp1->right, error);    
    }
    else return;
}


