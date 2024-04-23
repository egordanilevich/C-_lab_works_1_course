#include <iostream>
#include <utility.h>

using namespace std;

int main()
{
    my_list *head=NULL, *tail=NULL, *ptr=NULL;

    head = add(head,1);
    tail = add(head,99);
    ptr=add(head,2);
    for(int i=3;i<7;i++)
    {
        ptr=add(ptr,i);
    }
    ptr = head;
    while(ptr != NULL)
    {
        cout << ptr->data <<endl;
        ptr=ptr->next;
    }
    while(head != NULL)
    {
        head = delete_(head);
    }
    cout <<"clear\n";
    return 0;
}
