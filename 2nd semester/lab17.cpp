#include <windows.h>
#include <iostream>
#include <cstdlib>
#include <time.h>
using namespace std;

double InsertionSort (int *a, int N);
double BInInsertionSort(int *a, int N);
double SelectionSort(int *a, int N);
double BubbleSort(int *a, int N);
double ShakerSort(int *a, int N);
double ShellSort (int *a, int N);
void sift(int l,int r, int *a);
double HeapSort(int *a, int N);
void qsort(int *a, int first, int last);
double QuickSort(int *a, int N);

int main(){
	setlocale(0, "");
	srand(time(NULL));
 int s; int i; int x;
    double search_time_smas1;
	double search_time_smas2;
	double search_time_smas3;
			 
	double search_time_bmas1;
	double search_time_bmas2;
	double search_time_bmas3;
	
	int amountA=5;
	int amountB=50;
	
    int smas1[5] = {11, 14, 13, 12, 15};
    int smas2[5] = {5, 40, 2, 18, 16};
    int smas3[5] = {50, 20, 30, 40, 10};
    
    int bmas1[50] = {1, 6, 8, 5, 12, 94, 17, 18, 19, 20, 21, 22, 23, 26, 27, 28, 29, 31, 34, 35, 40, 41, 44, 2, 46, 50, 51, 52, 59, 7, 60, 64, 65, 68, 71, 72, 73, 3, 75, 76, 78, 80, 82, 84, 86, 87, 95, 96, 98, 99};
    int bmas2[50] = {85, 2, 28, 38, 57, 5, 32, 60, 89, 65, 26, 48, 3, 18, 36, 8, 34, 35, 77, 95, 46, 69,17, 49, 67, 66, 51, 9, 37, 93, 22, 54, 8, 38, 24, 12, 7, 59, 1, 78, 70, 81, 2, 91, 52, 88, 42, 73, 74, 98};
    int bmas3[50] = {99, 98, 94, 3, 88, 84, 83, 82, 79, 78, 4, 75, 74, 72, 68, 65, 4, 64, 11, 61, 58, 57, 53, 4, 50, 49, 46, 44, 3, 42, 40, 39, 38, 37, 36, 21, 19, 17, 12, 15, 13, 11, 77, 10, 9, 8, 7, 6, 5, 1};
	
	cout << "Please choose sorting method:" << endl; 
    cout << "1. Insertion sort" << endl <<  "2. Binary insertion sort" << endl << "3. Selection sort" << endl;
    cout << "4. Bubble sort" << endl << "5. Shaker sort" << endl << "6. Shell sort" << endl;
    cout << "7. Shaler sort" << endl << "8. Quick (Hoare) sort"<<endl;
	cin >> s;
	
	switch (s) {
			case 1:
			search_time_smas1=InsertionSort (smas1, amountA);
			search_time_smas2=InsertionSort (smas2, amountA);
			search_time_smas3=InsertionSort (smas3, amountA);
			 
			search_time_bmas1=InsertionSort (bmas1, amountB);
			search_time_bmas2=InsertionSort (bmas2, amountB);
			search_time_bmas3=InsertionSort (bmas3, amountB);
			 break;
			 	
			case 2:
			search_time_smas1=BInInsertionSort (smas1, amountA);
			search_time_smas2=BInInsertionSort (smas2, amountA);
			search_time_smas3=BInInsertionSort (smas3, amountA);
			 
			search_time_bmas1=BInInsertionSort (bmas1, amountB);
			search_time_bmas2=BInInsertionSort (bmas2, amountB);
			search_time_bmas3=BInInsertionSort (bmas3, amountB);
			 break;
				
			case 3:
			search_time_smas1=SelectionSort (smas1, amountA);
			search_time_smas2=SelectionSort (smas2, amountA);
			search_time_smas3=SelectionSort (smas3, amountA);
			 
			search_time_bmas1=SelectionSort (bmas1, amountB);
			search_time_bmas2=SelectionSort (bmas2, amountB);
			search_time_bmas3=SelectionSort (bmas3, amountB);
			 break;
				
			case 4:
			search_time_smas1=BubbleSort (smas1, amountA);
			search_time_smas2=BubbleSort (smas2, amountA);
			search_time_smas3=BubbleSort (smas3, amountA);
			 
			search_time_bmas1=BubbleSort (bmas1, amountB);
			search_time_bmas2=BubbleSort (bmas2, amountB);
			search_time_bmas3=BubbleSort (bmas3, amountB);
			 break;
				
			case 5:
			search_time_smas1=ShakerSort (smas1, amountA);
			search_time_smas2=ShakerSort (smas2, amountA);
			search_time_smas3=ShakerSort (smas3, amountA);
			 
			search_time_bmas1=ShakerSort (bmas1, amountB);
			search_time_bmas2=ShakerSort (bmas2, amountB);
			search_time_bmas3=ShakerSort (bmas3, amountB);
			 break;
				
			case 6:
			search_time_smas1=ShellSort (smas1, amountA);
			search_time_smas2=ShellSort (smas2, amountA);
			search_time_smas3=ShellSort (smas3, amountA);
			 
			search_time_bmas1=ShellSort (bmas1, amountB);
			search_time_bmas2=ShellSort (bmas2, amountB);
			search_time_bmas3=ShellSort (bmas3, amountB);
			 break;
				
			case 7:
			search_time_smas1=HeapSort (smas1, amountA);
			search_time_smas2=HeapSort (smas2, amountA);
			search_time_smas3=HeapSort (smas3, amountA);
			 
			search_time_bmas1=HeapSort (bmas1, amountB);
			search_time_bmas2=HeapSort (bmas2, amountB);
			search_time_bmas3=HeapSort (bmas3, amountB);
			 break;
				
			case 8:
			search_time_smas1=QuickSort (smas1, amountA);
			search_time_smas2=QuickSort (smas2, amountA);
			search_time_smas3=QuickSort (smas3, amountA);
			 
			search_time_bmas1=QuickSort (bmas1, amountB);
			search_time_bmas2=QuickSort (bmas2, amountB);
			search_time_smas3=QuickSort (bmas3, amountB);
			 break;
		};
	cout << "Sorting time for small arrays" << endl;	
 	for(i=0; i<amountA; i++) cout<< smas1[i]<< ' ';
 	cout << endl <<"Almost sorted, ascending: " << search_time_smas1<< endl;
 	for(i=0; i<amountA; i++) cout<< smas2[i] << ' ';
 	cout << endl << "Random: " << search_time_smas2 << endl;
 	for(i=0; i<amountA; i++) cout<< smas3[i]<< ' ';
 	cout << endl << "Almost sorted, descending: " << search_time_smas3<<endl;
 	
 	cout << "Sorting time for big arrays" << endl;
 	for(i=0; i<amountB; i++) cout << bmas1[i]<< ' ';
 	cout << endl << "Almost sorted, ascending: " << search_time_bmas1<<endl;
 	for(i=0; i<amountB; i++) cout << bmas2[i]<< ' ';
 	cout << endl << "Random: " << search_time_bmas2 << endl;
 	for(i=0; i<amountB; i++) cout << bmas3[i] << ' ';
	cout << endl << "Almost sorted, descending: " << search_time_bmas3 << endl;
	system("pause");
}

//1 Insertion sort

double InsertionSort (int *a, int N){
	LARGE_INTEGER time_s, time_e, freq;
	QueryPerformanceCounter(&time_s);
	QueryPerformanceFrequency(&freq);
	int x;
	int j;
		for(int i=1; i<N; i++){
			x=a[i]; j=i-1;
			while(j>=0 && a[j]>x){
				a[j+1]=a[j]; j--;
				}
			a[j+1]=x;
		}
	QueryPerformanceCounter(&time_e);
	double search_time = ((static_cast<double>(time_e.QuadPart)/static_cast<double>(freq.QuadPart)) - (static_cast<double>(time_s.QuadPart)/static_cast<double>(freq.QuadPart)))*1000000000;
    return search_time;
}

//2 Binary insertion sort

double BInInsertionSort(int *a, int N){
	LARGE_INTEGER time_s, time_e, freq;
	QueryPerformanceCounter(&time_s);
	QueryPerformanceFrequency(&freq);
	int x, l, r, m;
	for (int i=1; i<N; i++){
		if (a[i-1]>a[i]) {
		x=a[i]; l=0; r=i-1;
		while (l<=r){
			m=(l+r)/2;
			if (a[m]<x) l=m+1;
			else r=m-1;
	 	}
		for(int j=i-1; j>=l; j--)
		a[j+1]=a[j]; a[l]=x;
	}
	}
	QueryPerformanceCounter(&time_e);
	double search_time = ((static_cast<double>(time_e.QuadPart)/static_cast<double>(freq.QuadPart)) - (static_cast<double>(time_s.QuadPart)/static_cast<double>(freq.QuadPart)))*1000000000;
    return search_time;
}

//3 Selection sort

double SelectionSort(int *a, int N){
	LARGE_INTEGER time_s, time_e, freq;
	QueryPerformanceCounter(&time_s);
	QueryPerformanceFrequency(&freq);
	int j,k,x;
	for(int i=0; i<N-1; i++){
		x=a[i]; k=i; 
		for(j=i+1; j<N; j++)
		if (a[j]<a[k]) k=j;
		if (k!=i){
		 a[i]=a[k]; a[k]=x;
		}
	}
	QueryPerformanceCounter(&time_e);
	double search_time = ((static_cast<double>(time_e.QuadPart)/static_cast<double>(freq.QuadPart)) - (static_cast<double>(time_s.QuadPart)/static_cast<double>(freq.QuadPart)))*1000000000;
    return search_time;
}

//4 Bubble sort

double BubbleSort(int *a, int N){
	LARGE_INTEGER time_s, time_e, freq;
	QueryPerformanceCounter(&time_s);
	QueryPerformanceFrequency(&freq);
	int i, j, x;
	for(i=1; i<N; i++){
		for(j=N-1; i<=j; j--){
			if(a[j-1]>a[j]){
			x=a[j-1]; a[j-1]=a[j]; a[j]=x;
			}
		}
	}
	QueryPerformanceCounter(&time_e);
	double search_time = ((static_cast<double>(time_e.QuadPart)/static_cast<double>(freq.QuadPart)) - (static_cast<double>(time_s.QuadPart)/static_cast<double>(freq.QuadPart)))*1000000000;
    return search_time;
}

//5 Shaker sort

double ShakerSort(int *a, int N){
	LARGE_INTEGER time_s, time_e, freq;
	QueryPerformanceCounter(&time_s);
	QueryPerformanceFrequency(&freq);
    int x;
    int k=0;
	int left=0;
    int right=N-2;
        do{
            for(int i=left; i<=right; i++)
             if (a[i]>a[i+1]){
                   x=a[i]; a[i]=a[i+1]; a[i+1]=x;
                   k=i;
                }
              right= k-1;
            for(int i=right; i>=left; i--)
             if (a[i]>a[i+1]){
                   x=a[i]; a[i]=a[i+1]; a[i+1]=x;
                   k=i;
                }
            left=k+1;
           }while(left<=right);
    QueryPerformanceCounter(&time_e);
	double search_time = ((static_cast<double>(time_e.QuadPart)/static_cast<double>(freq.QuadPart)) - (static_cast<double>(time_s.QuadPart)/static_cast<double>(freq.QuadPart)))*1000000000;
    return search_time;
        }

//6 Shell sort

double ShellSort (int *a, int N){
	LARGE_INTEGER time_s, time_e, freq;
	QueryPerformanceCounter(&time_s);
	QueryPerformanceFrequency(&freq);
	int step, i, j, tmp;
	for (step = N / 2; step > 0; step /= 2)
		for (i = step; i < N; i++) 
			for (j = i - step; j >= 0 && a[j] > a[j + step]; j -= step){			
				tmp = a[j];
				a[j] = a[j + step];
				a[j + step] = tmp;
			}
	QueryPerformanceCounter(&time_e);
	double search_time = ((static_cast<double>(time_e.QuadPart)/static_cast<double>(freq.QuadPart)) - (static_cast<double>(time_s.QuadPart)/static_cast<double>(freq.QuadPart)))*1000000000;
    return search_time;
}

//7 Heap sort

void sift(int l,int r, int *a) {
     int i,j,x;
     i=l; j=2*i; x=a[i];
     while (j<=r) {
       if (j<r) if (a[j]< a[j+1]) j++;
       if (x>=a[j]) break;
       a[i]=a[j]; i=j; j=2*i;
     } 
     a[i]=x;
}

double HeapSort(int *a, int N){
    LARGE_INTEGER time_s, time_e, freq;
	QueryPerformanceCounter(&time_s);
	QueryPerformanceFrequency(&freq);
    int left, right,x;
    left=N/2; right=N-1;
    while (left>0) {
      left--; sift(left,right,a);
    }
    while (right>0) {
      x=a[0]; a[0]=a[right]; a[right]=x; right--;
      sift(0,right,a);
    }
    QueryPerformanceCounter(&time_e);
	double search_time = ((static_cast<double>(time_e.QuadPart)/static_cast<double>(freq.QuadPart)) - (static_cast<double>(time_s.QuadPart)/static_cast<double>(freq.QuadPart)))*1000000000;
    return search_time;
}

//8 Quick (Hoare) sort

double QuickSort(int *a, int N){
	LARGE_INTEGER time_s, time_e, freq;
	QueryPerformanceCounter(&time_s);
	QueryPerformanceFrequency(&freq);
		int mid, count; int f=0, l=N-1;
		mid=a[(f+l) / 2]; 
		do{
			while (a[f]<mid) f++;
			while (a[l]>mid) l--;
			if (f<=l) {
				count=a[f];
				a[f]=a[l];
				a[l]=count;
				f++;
				l--;
			}
		} while (f<l);
		if (0<l) qsort(a, 0, l);
		if (f<N-1) qsort(a, f, N-1);
	QueryPerformanceCounter(&time_e);
	double search_time = ((static_cast<double>(time_e.QuadPart)/static_cast<double>(freq.QuadPart)) - (static_cast<double>(time_s.QuadPart)/static_cast<double>(freq.QuadPart)))*1000000000;
    return search_time;
}

void qsort(int *a, int first, int last){
	int mid, count;
	int f=first, l=last;
	mid=a[(f+l) / 2]; 
	do{
		while (a[f]<mid) f++;
		while (a[l]>mid) l--;
		if (f<=l){
			count=a[f];
			a[f]=a[l];
			a[l]=count;
			f++;
			l--;
		}
	} while (f<l);
	if (first<l) qsort(a, first, l);
	if (f<last) qsort(a, f, last);
}
