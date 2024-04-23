#include <iostream>
#include <cstdlib>

using namespace std;

struct Node{
	int d;
	Node *next;
};

Node* first(int d); //Creating the first element of the list
void add_beg(Node **pbeg, int d); //Adding to the beginning
void add_end(Node **pend, int d); //Adding to the end
void printS(Node * pbeg); //Printing the list
Node* find(Node * const pbeg, int k); //Searching for an element
Node* findB(Node * const pbeg, Node* k); //Searching for the previous to the given element in the list
void add_before(Node **pbeg, int k, int d);  
void add_after(Node **pbeg, Node **pend, int k, int d); //Adding after the given element
void delete_if(Node **pbeg, Node **pend, int k); //Deleting an element

int main(){
	int x; 
	int d; 
	int k;
	Node *pbeg = first(1);
	Node *pend = pbeg; 
	printS(pbeg);
	char run = 'y';
	while(run == 'y'){
		int a;
		cout << "Choose an action" << endl 
		<< "1: Add a number in the beginning of the list" << endl 
		<< "2: Add an element at the end of the list" << endl 
		<< "3: Add before a given element" << endl 
		<< "4: Add after a given element" << endl 
		<< "5: Deleta an element" << endl;
		cin >> a;
		
		switch (a){
			case 1:{
				cout << "Please enter the number you would like to add to the end of the list" << endl;
				cin >> x;
				add_end(&pend, x);
				printS(pbeg);				
				
			}break;
			case 2:{
				cout << "Please enter the number you would like to add to the beginning of the list" << endl;
				cin >> x;
				add_beg(&pbeg, x);
				printS(pbeg);				
			}break;
			case 3:{
				cout << "Please enter the number you would like to add" << endl;
				cin >> d;
				cout << "Now enter the number before which you would like to place it, please" << endl;
				cin >> k;
				add_before(&pbeg, k, d);
				printS(pbeg);					
			}break;
			case 4:{
				cout << "Please enter the number you would like to add" << endl;
				cin >> d;
				cout << "Now enter the number after which you would like to place it, please" << endl;
				cin >> k;
				add_after(&pbeg, &pend, k, d);
				printS(pbeg);				
			}break;
			case 5:{
				cout << "Please enter the element that is to be deleted" << endl;
				cin >> k;
				delete_if(&pbeg, &pend, k);
				printS(pbeg);					
			}break;
			default: cout << "An error has occured. Please try again" << endl;
		}
		
		cout << "If you want to continue, enter \"Y\". Otherwise the program will close" << endl;
		cin >> run;
		run = tolower(run);
	}
	cout << "Closing" << endl;
}

Node* first(int d) //Creating the first element
{ 
	Node *pv = new Node;
	pv -> d = d; pv -> next = 0;
	return pv;
}
void add_beg(Node **pbeg, int d) //Adding to the beginning
{ 
	Node *pv = new Node;
	pv -> d = d;
	pv -> next = *pbeg;
	*pbeg = pv;
}
void add_end(Node **pend, int d) //Adding to the end
{ 
	Node* pv = new Node;
	pv -> d = d;
	pv -> next = 0; 
	(*pend) -> next = pv;
	*pend = pv;
}
void printS(Node *pbeg) //Printing the list
{
	Node* pv = pbeg;
	while(pv)
    {
		cout << pv -> d << ' ';
		pv = pv -> next;
	}
	cout << endl;
}
Node* find(Node * const pbeg, int k) //Searching for an element
{ 
	Node *pv = pbeg;
	while (pv){
		if(pv -> d == k)break;
		pv = pv -> next;
	}
	return pv;
}
Node* findB(Node * const pbeg, Node* k) //Searching for the previous to the given element in the list
{
	Node *pv = pbeg;
	while (pv){
		if(pv -> next == k)break;
		pv = pv -> next;
	}
	return pv;
}
void add_before(Node **pbeg, int k, int d) //Adding before the given element
{ 
	Node* f = find(*pbeg, k);
	if(f){
		if(f == *pbeg) add_beg(&*pbeg, d);
		else{
			Node* pv = new Node;
			pv -> next = f;
			pv -> d = d;
			Node* p = findB(*pbeg, f);
			p -> next = pv;
		}		
	}
	else cout << "An error has occured" << endl;
}
void add_after(Node **pbeg, Node **pend, int k, int d) //Adding after the given element
{ 
	Node* f = find(*pbeg, k);
	if(f){
		if (f == *pend) add_end(&*pend, d);
		else{
			Node* pv = new Node;
			pv -> d = d;
			pv -> next = f -> next;
			f -> next = pv;
		}
	}
	else cout << "An error has occured" << endl;
}
void delete_if(Node **pbeg, Node **pend, int k) //Deleting an element
{ 
	Node* f = find(*pbeg, k);
	if(f){
		Node* p = findB(*pbeg, f);
		if (f == *pbeg) *pbeg = (*pbeg) -> next;
		else if (f == *pend) p -> next = 0;
		else p -> next = f -> next;
	}
	else cout << "An error has occured" << endl;}
