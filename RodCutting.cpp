#include <limits.h> 
#include <stdio.h> 

int max(int a, int b) { return (a > b) ? a : b; } 


int cutRod(int price[], int n) 
{ 
	int val[n + 1]; 
	val[0] = 0; 
	int i, j; 

	for (i = 1; i <= n; i++) { 
		int max_val = INT_MIN; 
		for (j = 0; j < i; j++) 
			max_val = max(max_val, price[j] + val[i - j - 1]); 
		val[i] = max_val; 
	} 

	return val[n]; 
} 


int main() 
{ 
	int arr[] = { 1, 5, 8, 9, 10, 17, 17, 20,24,30}; 

    for (int i=1;i<=10;i++)
	    printf("Length = %d, Maximum Value is %d\n", i, cutRod(arr, i)); 
	return 0; 
} 
