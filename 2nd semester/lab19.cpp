#include <iostream>

using namespace std;

struct Node{ //Singly linked list
	int d;
	Node *next;
};
struct ring{ //Doubly linked list
	int name; 
	Node *list;
	Node *listEnd;
	ring *next; 
	ring *prev; 
};
int N = 0; //Amount of elements in a list
ring* cur; //Current element of the list

/*
======================================================
=============Singly linked list opeations=============
======================================================
*/
Node* first_list(int d);//Creating the first element of the list
Node* find_list(Node * const pbeg, int k); //Searching for an element
Node* find_prev_list(Node * const pbeg, Node* k); //Searching for an element before the searched
void add_list_beg(int d); //Adding an element to the beginning of the list
void add_list_end(int d); //Adding an element to the end of the list
void add_after_list(int k, int d); //Adding an element after the searched
void add_before_list(int k, int d); //Adding an element before the searched
void delete_list_if(int k); //Deleting an element
void delete_list_after(int k); //Deleting after the searched
void delete_list_before(int k); //Deleting before the searched

/*
======================================================
=============Doubly linked list opeations=============
======================================================
*/
void add_ring(int n); //Adding an element after the current
ring* find_ring(int k); //Searching for an element
void add_ring_after(int k, int n); //Adding an element after searched
void add_ring_before(int k, int n); //Adding an element before the searched
void print_list(Node *pbeg); //Printing the list
void print_ring_r(); //List view clockwise
void print_ring_l(); //List view counter-clockwise
void delete_ring(int k); //Deleting the searched element
void delete_ring_before(int k); //Deleting an element before the searched
void delete_ring_after(int k); //Deleting an element after the searched


int main()
{
	cur = NULL;
	int x;
    int d;
    int k;
	N = 0;
	cout << "Please enter the first element of the doubly-linked list (DLL)" << endl;
	cin >> x;
	add_ring(x);
	print_ring_r();
	char run = 'y';
	while(run=='y')
    {
		int a, b;
		cout << endl << "Please choose what to do." << endl 
        << "1. Add a new element to the DLL" << endl 
        << "2. Add a new element to an SLL (singly linked list)" << endl 
        << "3. View one element clockwise (DLL)" << endl 
        << "4. View one element counter-clockwise (DLL)" << endl;
		cin >> b;
		switch (b)
        {
			case 1:
			{
				cout << "Please choose what to do." << endl 
            	<< "1. Add an element before the another one" << endl 
            	<< "2. Add an element after the another one" << endl 
            	<< "3. Delete an element before another one" << endl 
            	<< "4. Delete an element after another one" << endl;
		    	cin >> a;
				    switch (a)
            	    {
				    	case 1:
            	        {
							cout << "Enter the number you would like to add to the list please" << endl;
					    	cin >> d;
					    	cout << "Please enter the number before which you would like to add it" << endl;
					    	cin >> k;
					    	add_ring_before(k, d);
							break;
						}
						case 2:
            	        {
							cout << "Enter the number you would like to add to the list please" << endl;
					    	cin >> d;
					    	cout << "Please enter the number before which you would like to add it" << endl;
					    	cin >> k;
					    	add_ring_after(k, d);
							break;
						}
						case 3:
            	        {
							cout << "Please enter the number which is right after the element you want to delete" << endl;
							cin >> k;
							delete_ring_before(k);
							break;
						}
						case 4:
               	    	{
							cout << "Please enter the number which is right before the element you want to delete" << endl;
							cin >> k;
							delete_ring_after(k);
							break;
						}
			    	}
					break;
			}
			case 2:
			{
				int k1;
				cout << "Please choose an option on the list" << endl; 
				cin >> k1;
				cur = find_ring(k1);
				if(cur)
                {
					cout << "Please choose an action" << endl 
                    << "0. Add an element to the beginning of the list" << endl 
                    << "1. Add an element to the end of the list" << endl 
                    << "2. Add an element before given" << endl 
                    << "3. Add an element after given" << endl 
                    << "4. Delete an element before given" << endl 
                    << "5. Delete an element after given" << endl;
			        cin >> a;
			        switch (a)
                    {
			        	case 0:
                        {
			        		cout << "Please enter the number you would like to add" << endl;
							cin >> x;
							add_list_beg(x);
			        		break;
			        	}
					    case 1:
                        {
							cout << "Please enter the number you would like to add" << endl;
							cin >> x;
							add_list_end(x);			
				    		break;
						}
					    case 2:
                        {
							cout << "Please enter the number you would like to add" << endl;
							cin >> d;
							cout << "Now please enter the element before which it should be added" << endl;
							cin >> k;
							add_before_list(k, d);
							break;				
					    }
					    case 3:
                        {
							cout << "Please enter the number you would like to add" << endl;
							cin >> d;
							cout << "Now please enter the element before which it should be added" << endl;
							cin >> k;
							add_after_list(k, d);
							break;			
					    }
					    case 4:
                        {
							cout << "Please enter an element that is right after the one you want to delete" << endl;
							cin >> k;
							delete_list_before(k);
							break;					
					    }
					    case 5:
                        {
							cout << "Please enter an element that is right before the one you want to delete" << endl;
							cin >> k;
							delete_list_after(k);
							break;					
					    }
				    	default: cout << "An error has occured. Please try again" << endl;
					}	
				}
				else cout << "Error has somehow occured. Why?" << endl;
			}
            break;
			case 3:
            {
                print_ring_r();
                break;
            }
		    case 4:
            {
                print_ring_l();
                break;
            } 
		    default: 
            {
                cout << "An error has occured. Please try inputting again" << endl;
                break;
            }
		}
        cout << "If you want to continue, enter \"Y\"" << endl;
		cin >> run;
        run = tolower(run);
	} 
}



/*
======================================================
=============Singly linked list opeations=============
======================================================
*/

Node* first_list(int d) //Creating the first element of the list
{
	Node *pv = new Node;
	pv -> d = d; pv -> next = 0;
	return pv;
}

Node* find_list(Node * const pbeg, int k) //Searching for an element
{ 
	Node *pv = pbeg;
	while (pv)
    {
		if(pv -> d == k)break;
		pv = pv -> next;
	}
	return pv;
}

Node* find_prev_list(Node * const pbeg, Node* k) //Searching for an element before the searched
{ 
	Node *pv = pbeg;
	while (pv)
    {
		if(pv -> next == k)break;
		pv = pv -> next;
	}
	return pv;
}

void add_list_beg(int d) //Adding an element to the beginning of the list
{
	if(cur -> list)
    {
		Node *pv = new Node;
		pv -> d = d;
		pv -> next = cur -> list;
		cur -> list = pv;		
	}
	else 
    {
		cur -> list = first_list(d);
		cur -> listEnd = cur -> list;	
	}		
}

void add_list_end(int d) //Adding an element to the end of the list
{ 
	if(cur -> list)
    {
		Node *pv = new Node;
		pv -> d = d;
		pv -> next = 0;
		cur -> listEnd -> next = pv;
		cur -> listEnd = pv;		
	}
	else 
    {
		cur -> list = first_list(d);
		cur -> listEnd = cur -> list;	
	}
}

void add_after_list(int k, int d) //Adding an element after the searched
{ 
	Node* f = find_list(cur -> list, k);
	if(f)
    {
		if (f == cur -> listEnd) add_list_end(d);
		else
        {
			Node* pv = new Node;
			pv -> d = d;
			pv -> next = f -> next;
			f -> next = pv;
		}
	}
	else cout << "The thing was not found" << endl;
}

void add_before_list(int k, int d) //Adding an element before the searched
{ 
	Node* f=find_list(cur -> list, k);
	if(f)
    {
		if(f == cur -> list) add_list_beg(d);
		else
        {
			Node* pv = new Node;
			pv -> next = f;
			pv -> d = d;
			Node* p  =  find_prev_list(cur -> list, f);
			p  ->  next = pv;
		}		
	}
	else cout << "The thing was not found" << endl;
}

void delete_list_if(int k) //Deleting an element
{ 
	Node* f = find_list(cur -> list, k);
	if(f)
    {
		Node* p = find_prev_list(cur -> list, f);
		if (f == cur -> list) cur -> list = (cur -> list)  ->  next;
		else if (f == cur -> listEnd) p -> next = 0;
		else p -> next = f -> next;
		delete f;
	}
	else cout << "The thing was not found" << endl;
}

void delete_list_after(int k) //Deleting after the searched
{ 
	Node* f = find_list(cur -> list, k);
	if (f -> next)
    {
		f = f -> next;
		delete_list_if(f -> d);	
	}
	else cout << "Error!" << endl;
}

void delete_list_before(int k) //Deleting before the searched
{ 
	Node* f = find_list(cur -> list, k);
	f = find_prev_list(cur -> list, f);
	if (f) delete_list_if(f -> d);
	else cout << "Error!" << endl;
}

void print_list(Node *pbeg) //Printing the list
{
	Node* pv = pbeg;
	while(pv)
    {
		cout << pv -> d << ' ';
		pv = pv -> next;
	}
}

/*
======================================================
=============Doubly linked list opeations=============
======================================================
*/
void add_ring(int n) //Adding an element after the current
{
	N++;
	ring *temp = new ring;
	temp -> name = n;
	temp -> list = NULL;
	temp -> listEnd = NULL;
	if(cur)
    {
		temp -> next = cur -> next;
		temp -> prev = cur; 
		cur -> next -> prev = temp;
		(cur) -> next = temp;	
	}
	else{
		temp -> prev = temp;
		temp -> next = temp;	
	}
	cur = temp;	
}

ring* find_ring(int k)  //Searching for an element
{ 
	ring *pv = cur; 
	while (pv)
    {
		if(pv -> name == k)break;
		pv = pv -> next;
	}
	return pv;
}

void add_ring_after(int k, int n) //Adding an element after searched
{ 
	cur=find_ring(k);
	add_ring(n);
}

void add_ring_before(int k, int n) //Adding an element before the searched
{ 
	N++;
	cur = find_ring(k);
	ring *temp = new ring;
	temp -> name = n;
	temp -> list = NULL;
	temp -> listEnd = NULL;
	if(cur)
    {
		temp -> prev = cur -> prev; //Previous to the new one
		temp -> next = cur; 
		cur -> prev -> next = temp;
		(cur) -> prev = temp;
	}
	else temp -> prev = temp;
	cur = temp;	
}



void print_ring_r() //List view clockwise
{
	ring* pv = cur;
	for(int i = 0; i<N; i++)
    {
		cout << endl << "List number " << pv -> name << ": ";
		print_list(pv -> list);
		pv = pv -> next;
	}
}

void print_ring_l() //List view counter-clockwise
{ 
	ring* pv = cur;
	for(int i = 0; i<N; i++)
    {
		cout << endl << "List number " << pv -> name << ": ";
		print_list(pv -> list);
		pv = pv -> prev;
	}
}

void delete_ring(int k) //Deleting the searched element
{ 
	N--;
	ring *pcur = find_ring(k);
	pcur -> next -> prev = pcur -> prev;
	pcur -> prev -> next = pcur -> next;
	cur = pcur -> next;
	delete pcur;
}

void delete_ring_before(int k) //Deleting an element before the searched
{ 
	ring *pcur = find_ring(k);
	pcur = pcur -> prev;
	delete_ring(pcur -> name);
}

void delete_ring_after(int k) //Deleting an element after the searched
{ 
	ring *pcur = find_ring(k);
	pcur = pcur -> next;
	delete_ring(pcur -> name);
}
