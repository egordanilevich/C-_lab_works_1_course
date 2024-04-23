#ifndef UTILITY_H
#define UTILITY_H

#include <iostream>

using namespace std;

struct my_list
{
    int data;
    my_list *next;
    my_list()
    {
        next = NULL;
    }
    my_list(int d)
    {
        data = d;
        next = NULL;
    }

};


my_list* add(my_list* in, int data)
{
    my_list* new_p = new my_list(data);
    my_list* temp = in;
    if(temp == NULL)
    {
        temp = new_p;
    }
    //new_p->data = data;
    else if(temp->next == NULL)
    {
        temp->next = new_p;
        temp = new_p;
    }
    else
    {
        new_p->next = temp->next;
        temp->next = new_p;
        temp = new_p;
    }
    return temp;
}

my_list* add(my_list* temp)
{
    my_list* new_p = new my_list;
    //new_p->data = data;
    if(temp->next == NULL)
    {
        temp->next = new_p;
        temp = new_p;
    }
    else
    {
        new_p->next = temp->next;
        temp->next = new_p;
        temp = new_p;
    }
    return temp;
}


my_list* delete_(my_list* temp)
{
    my_list* del;
    if(temp->next == NULL)
    {
        delete temp;
        temp = NULL;
    }
    else
    {
        del = temp->next;
        temp->next = del->next;
        delete del;
    }
    return temp;
}

#endif // UTILITY_H
