#include <stdio.h>
#include<iostream>
#include<cstdlib>
#include<cstdio>
#include<iomanip>
#include<Windows.h>
#include<time.h>
#include<limits.h>


using namespace std;


//Insertion Sort
void InsertSort(int array[], int len)
{
	for(int i=1;i<len;i++) //assume the first element to be sorted
	{
	    int key=array[i];//the element to be sorted
	    
	    int j=i-1; //the last element in the sorted section
	    while(j>=0&&array[j]>key) //found a smaller element
	    {
	        array[j+1]=array[j]; //copy the elements to right to create space
	        j--;
	    }
	    array[j+1]=key;
	}
}


//Selection Sort
void SelectionSort(int array[], int len)
{
	int min_index=0;
	for(int i=0;i<len-1;i++)
    {
        min_index=i;
        for(int j=i+1;j<len;j++)
        {
            if(array[j]<array[min_index])//Ascending order
            {
                min_index=j;//new_min found
            }
        }
        
        //new min found swap i with new min_index
        int temp=0;
        temp=array[i];
        array[i]=array[min_index];
        array[min_index]=temp;
    }
}


//Bubble Sort
void BubbleSort(int array[], int len) 
{
	 for(int i=0;i<len-1;i++)
    {
        for(int j=0;j<len-i-1;j++)
        {
            if(array[j]>array[j+1])//Ascending order
            {
                int temp=0;
                temp=array[j];
                array[j]=array[j+1];
                array[j+1]=temp;
            }
        }
        
    }

}


//Merge function used in merge sort 
void Merge(int array[],int low,int middle,int high)
{
    //following the  pesudo code in the ppt the code can be written as follows
    int n1=middle-low+1; 
    int n2=high-middle;
    int Left[n1+1], Right[n2+1];
    
    //Copying the elements in left array and right array
    for (int i = 0; i < n1; i++) 
	{
		Left[i] = array[low + i]; 
	}
        
    for (int j = 0; j < n2; j++) 
    { 
        Right[j] = array[middle + j+1]; 
    }
    
	//There is no infinity in c/c++ but any sufficiently large value is enough (larger than 3000)   
	Left[n1]=INT_MAX;
    Right[n2]=INT_MAX;
     
      
    int i=0;
    int j=0;
    int k=low;
    //Instead of using infinity we can stop when one array reaches its top then copy from other array
    for(k=low; k<=high; k++)
	{
        if(Left[i] <= Right[j])
		{
            array[k] = Left[i];
            i++;
        }

        else
		{
            array[k] = Right[j];
            j++;
        }
    }
}
//Merge Sort
void MergeSort(int array[],int low, int high) 
{		
	if(low<high)
	{
		int middle=(low+high)/2;
		MergeSort(array,low,middle);	//left recursion
		MergeSort(array,middle+1,high);	//right recursion
		Merge(array,low,middle,high);	//merging of two sorted sub-arrays
	}
}


//partition function used in Quicksort
int partition(int my_array[], int left, int right)
{
   int pivot = my_array[right];
   int i = left - 1;
   for (int j = left; j <= right - 1; j++) //j indicates the element to be sorted
   {
      if (my_array[j] <= pivot)
      {
         i++; //i=the last element of the small partition 	//i+1 = the first element in the large partition
    
    	//bring the small element to the left/small partititon
         int temp = my_array[j];
         my_array[j] = my_array[i];
         my_array[i] = temp;
      }
   }
   //bring pivot to middle
   int temp = my_array[i + 1];
   my_array[i + 1] = my_array[right];
   my_array[right] = temp;
   return (i + 1);
}

//Quicksort
void QuickSort(int array[], int low, int high) 
{
   if (low < high)
   {
      int middle = partition(array, low, high);
      QuickSort(array, low, middle - 1);
      QuickSort(array, middle + 1, high);
   }
}

int* generateRandomArray(int len, int rangeL, int rangeR)
{
	int* array = new int[len];

	//example: generateRandomArray (10, 0, 100) will return an array with 10 random numbers between 0 and 100
	for(int i=0;i<len;i++)
    {
        array[i]=rand() % (rangeR + 1)+rangeL;  //rand() % (rangeR + 1) will generate from  to Ranger then we can move the left range

    }
    return array;
}

// a helping  function  for printing the array
void printarray(int array[],int len)
{
    for(int i=0;i<len;i++)
    {
        printf("%d ",array[i]);
    }
    printf("\n");
}



int main()
{

	//############################################################################################################
	//Please WRITE YOUR CODE for all TODO parts

	//The following main function will list 10 trials with 6 dataSizes for one sort method each time.
	//If it is possible, please keep the main function UNMODIFIED.

	//The Time Count method is using functions included in <Windows.h>.
	//If you are using other systems, or you want to use other Time Count method, you can change this part.
	//############################################################################################################

	srand(time(NULL)); //setting the random seed to null -> this makes sure different numbers are generated each time


	int dataSize[6] = {500,1000,1500,2000,2500,3000};
	
	for (int count = 0; count < 10; count++)
	{
		cout << "Trial " << count + 1 << endl;

		for (int i = 0; i < 6; i++) {			
			int* array = new int[dataSize[i]];
			array = generateRandomArray(dataSize[i], 0, 3000);
			LARGE_INTEGER BegainTime;
			LARGE_INTEGER EndTime;
			LARGE_INTEGER Frequency;
			QueryPerformanceFrequency(&Frequency);
			QueryPerformanceCounter(&BegainTime);
						
			//BubbleSort(array, dataSize[i]);
			//SelectionSort(array, dataSize[i]);
			//InsertSort(array, dataSize[i]);
			//MergeSort(array, 0, dataSize[i] - 1);
			QuickSort(array, 0, dataSize[i] - 1);
			
			QueryPerformanceCounter(&EndTime);
			cout << "dataSize is: " << dataSize[i] << ",total time: " << fixed << setprecision(6) << 
				(double)(EndTime.QuadPart - BegainTime.QuadPart) / Frequency.QuadPart << "s" << endl;
		}
	}

	return 0;
}


