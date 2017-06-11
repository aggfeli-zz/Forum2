#ifndef SIMPLE_LIST_H
#define	SIMPLE_LIST_H
#include "forum.h"


typedef class info_list  * info_pointer;

class info_list{   
private:
    struct list_node{
        class post posts;
        list_node *next;
    };
    int size ;	
    list_node *start; 	//Pointer at first list node
public:
    info_list();
    void dimiourgia();
    void create_simplelist(thread stoixeio, int i, int *error);
    void list_entry(info_list list);
    void Delete();
    void print_list();
};

#endif	/* SIMPLE_LIST_H */

