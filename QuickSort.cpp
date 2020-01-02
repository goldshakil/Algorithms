#include <iostream>
#include <vector>
#include <time.h>
#include <stdlib.h>
using namespace std;

int count =0;

int Partition (int array[], int low, int high) {
    int x = array[high];
    int i = low-1;
    int j;
    for (j=low;j<=high-1;j++) {
        count++;
        if (array[j]<x) {
            i++;
            int temp = array[i];
	        array[i] = array[j];
	        array[j] = temp;
        }
        
    }
    
    int temp = array[i+1];
	array[i+1] = array[high];
	array[high] = temp;
// 	cout<<"count="<<count<<endl;
// 	for (int m =0;m<8;m++)
// 	    cout<<array[m]<<" ";
//	cout<<endl;
	
    return i+1;
}

int Randomized_Partition (int array[], int low, int high) {
    srand(time(NULL));
    int random = (rand() % (high - low + 1)) + low;
    int temp = array[high];
	array[high] = array[random];
	array[random] = temp;
	return Partition (array, low, high);
    
}

void Randomized_QuickSort(int array[], int low, int high) {

    if (low<high) {
        int q = Randomized_Partition (array, low, high);
        Randomized_QuickSort(array, low,q-1);
        Randomized_QuickSort (array, q+1,high);
    
    }
}

void QuickSort(int array[], int low, int high) {

    if (low<high) {
        int q = Partition (array, low, high);
        QuickSort (array, low,q-1);
        QuickSort (array, q+1,high);
    
    }
}

void main() {
    int arr11[8]={2,8,7,1,3,5,6,4};
    int arr12[8]={2,8,7,1,3,5,6,4};
    int arr21[8]={1,2,3,4,5,6,7,8};
    int arr22[8]={1,2,3,4,5,6,7,8};

    QuickSort(arr11, 0,7);
    cout<<"QickSort comparison counts for arr1: "<<count<<endl;
    count = 0;
    QuickSort(arr21, 0,7);
    cout<<"QickSort comparison counts for arr2: "<<count<<endl;
    count = 0;
    Randomized_QuickSort(arr12, 0,7);
    cout<<"Randomized_QuickSort comparison counts for arr1: "<<count<<endl;
    count = 0;
    Randomized_QuickSort(arr22, 0,7);
    cout<<"Randomized_QuickSort comparison counts for arr2: "<<count<<endl;
}

