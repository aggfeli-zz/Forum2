#ifndef BINARY_TREE_H
#define	BINARY_TREE_H
#include "forum.h"
#include "simple_list.h"

typedef class binary_tree * type_pointer;

class binary_tree{
private:
    struct tree_node{
        string creator;    
        info_list list;
        tree_node *left;
        tree_node *right;
    };
    tree_node *root;
public:
    binary_tree();
    void destroy();
    void destroy_tree(tree_node *temp);
    void Tree_entry(thread stoixeio, int i, int *error);
    int Tree_keno();
    void printsorted();
    void inorder(tree_node *temp);
    void insert(thread stoixeio, int i, int *error);
    void enhance(binary_tree tree, int *error);
    void enhance(tree_node *temp, tree_node *temp1, int *error );
};

#endif	/* BINARY_TREE_H */

