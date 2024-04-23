#include<iostream>
#include<conio.h>
#include<windows.h>
#include<stdlib.h>
#include<stdio.h>
using namespace std;
HDC hDC;

class animal
{
      protected:
                int x,y,time; 
      public:
             animal(int x, int y, int time)
             {
             this->x=x;
             this->y=y;
             this->time=time;
             }
               int get_x()
             {
                 return x;
             };
			   void set_x(int x)
			   {
				   this->x=x;
				   if(x<0){this->x=0;};
                   if(x>20){this->x=20;};
			   };

               int get_y()
             {
                 return y;
             };
			   void set_y(int y)
			   {
				   this->y=y;
				   if(y<0){this->y=0;};
                   if(y>20){this->y=20;};
			   };
               int get_time()
             {
                 return time;
             };
			   void move()
		   {
            set_x(x+((rand()%3)-1));
            set_y(y+((rand()%3)-1));
		   };
           virtual void printanimal()
             {
                         HBRUSH brush_animal=CreateHatchBrush(7,RGB(200,100,0));
				         SelectObject(hDC,brush_animal);
                         Rectangle(hDC,x*15,y*15,x*15+20,y*15+20);
				         DeleteObject(brush_animal);
             }  ;
		  
}; 
class predator:public animal
{
	 public:
		 predator(int x, int y, int time):animal(x,y,time){};
          void printanimal()
             {
				 HBRUSH brush_animal=CreateHatchBrush(7,RGB(255,0,0));
				 SelectObject(hDC,brush_animal);
                 Rectangle(hDC,x*15,y*15,x*15+20,y*15+20);
				 DeleteObject(brush_animal);
             }  ; 
};
class herbivore:public animal
{
	 public:
		 herbivore(int x, int y, int time):animal(x,y,time){};
          void printanimal()
             {
				 HBRUSH brush_animal=CreateHatchBrush(7,RGB(0,255,0));
				 SelectObject(hDC,brush_animal);
                 Rectangle(hDC,x*15,y*15,x*15+20,y*15+20);
				 DeleteObject(brush_animal);
             }  ; 
};

struct list_animal
{
	animal * mob;
	list_animal * next;
};
class World
{
   private:
	    int count_animal;
	    int timelife;
		int delay;
		HBRUSH brush_back;
		list_animal * head, *ptr;
		 RECT wc;
   public:
           World(int count_animal, int timelife, int delay)
             { 
                this->count_animal=count_animal;
                this->timelife=timelife;
                this->delay=delay; 
			    int i,j;
			    head=NULL;
                brush_back=CreateHatchBrush(7,RGB(100,100,200));
                RECT wc={};
                GetWindowRect(GetConsoleWindow(), &wc);
			    this->wc=wc;
	            hDC=GetDC(GetConsoleWindow());
			    for(i=0;i<count_animal;i++)
	              { 
		            ptr=new list_animal;
		            j=rand()%3;
		            if(j==0){ptr->mob=new animal(rand()%20,rand()%20,timelife);}
                    if(j==1){ptr->mob=new predator(rand()%20,rand()%20,timelife);}
		            if(j==2){ptr->mob=new herbivore(rand()%20,rand()%20,timelife);}
		            ptr->next=head;
		            head=ptr;
			      }
		   
		   }
          void worldLife()
		  {    
              while(!kbhit())
				{SelectObject(hDC,brush_back);
				Rectangle(hDC,0,0,wc.right,wc.bottom);
				ptr=head;
				 while(ptr!=NULL)
				  {
				    ptr->mob->printanimal();
				    ptr->mob->move();
				   ptr=ptr->next;
					}
				Sleep(delay);
				 }
			}
};
                                                                                          
 int main()
{
    World* newWorld;   
    newWorld=new World(12,7,100);  
	newWorld->worldLife();
	delete newWorld;
    return 0;
}
