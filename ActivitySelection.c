
#include <stdio.h>
#include <stdlib.h>

typedef struct activity
{
	int start;
	int finish;
	int original_index;
	
}activity;

void initialization (activity S[])
{
	int counter=1;
	
	activity a1;
	a1.start=1;
	a1.finish=4;
	a1.original_index=counter++;
	S[0]=a1;
	
	activity a2;
	a2.start=3;
	a2.finish=5;
	a2.original_index=counter++;
	S[1]=a2;
	
	activity a3;
	a3.start=0;
	a3.finish=6;
	a3.original_index=counter++;
	S[2]=a3;
	
	activity a4;
	a4.start=5;
	a4.finish=7;
	a4.original_index=counter++;
	S[3]=a4;
	
	activity a5;
	a5.start=3;
	a5.finish=9;
	a5.original_index=counter++;
	S[4]=a5;
	
	activity a6;
	a6.start=5;
	a6.finish=9;
	a6.original_index=counter++;
	S[5]=a6;
	
	activity a7;
	a7.start=6;
	a7.finish=10;
	a7.original_index=counter++;
	S[6]=a7;
	
	activity a8;
	a8.start=8;
	a8.finish=11;
	a8.original_index=counter++;
	S[7]=a8;
	
	activity a9;
	a9.start=8;
	a9.finish=12;
	a9.original_index=counter++;
	S[8]=a9;
	
	activity a10;
	a10.start=2;
	a10.finish=14;
	a10.original_index=counter++;
	S[9]=a10;
	
	activity a11;
	a11.start=12;
	a11.finish=16;
	a11.original_index=counter++;
	S[10]=a11;
	
}

void greedy_selector(activity S[])
{
	activity A[11]; //maximum size subset of mutually compatible activities
	int size_A=1;	//size of this subset
	int n=11; //s.length
	A[0]=S[0]; //first activity
	int k=0;
	int m=1;
	for(m=1;m<n;m++)
	{
		if(S[m].start>=S[k].finish)
		{
			A[size_A]=S[m];
			size_A++;
			k=m;
			
		}
	}
	
	printf("Iterative Compatible Subset Size %d:\n",size_A);
	printf("A Subset:\n");
	int z=0;
	for(z=0;z<size_A;z++)
	{
		printf("a%d:[%d,%d)\n",A[z].original_index,A[z].start,A[z].finish);
	}
}
void recursive_greedy_selector(activity S[],int k,activity A[], int size_A)
{
	int m=k+1;
	while(m<=10&&S[m].start<S[k].finish)
	{
		m++;
	}
	if(m<=10)
	{
		A[size_A]=S[m];
		size_A++;
		recursive_greedy_selector(S,m,A,size_A);
	}
	else
	{
		printf("Recusrive Compatible Subset Size %d:\n",size_A);
		printf("A Subset:\n");
		int z=0;
		for(z=0;z<size_A;z++)
		{
			printf("a%d:[%d,%d)\n",A[z].original_index,A[z].start,A[z].finish);
		}
	}
}


int main(int argc, char *argv[]) 
{
	int i=0;
	activity S[11]; // 11 activities
	
	// Initialization
	initialization(S);
	
	printf("Original S set is:\n");
	for(i=0;i<11;i++)
	{
		printf("a%d:[%d,%d)\n",S[i].original_index,S[i].start,S[i].finish);
	}
	printf("\n---------------------------------\n\n");
	greedy_selector(S); //iterative greedy Selector
	printf("\n---------------------------------\n\n");
	activity A[11];
	recursive_greedy_selector(S,-1,A,0); //recursive greedy Selector
	
	
	return 0;
}

