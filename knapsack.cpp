#include <iostream>
#include<algorithm>
using namespace std;

int knapSack(int v[], int weight[], int W, int n) 
{ 
   int i, w; 
   int c[n+1][W+1]; 
   for (w = 0; w <= W; w++) 
       c[0][w]=0;
   for (i = 1; i <= n; i++) 
   {
       c[i][0]=0;
       for (w = 1; w <= W; w++) 
       { 
           if (weight[i-1] <= w) 
                 c[i][w] = max(v[i-1] + c[i-1][w-weight[i-1]],  c[i-1][w]); 
           else
                 c[i][w] = c[i-1][w]; 
       } 
   } 
  
   return c[n][W]; 
} 

int main() {
    int v[] = {60, 120, 130,150,180};  
    int weight[] = {10, 20, 30, 40, 50};  
    int W = 100;  
    int n = sizeof(v)/sizeof(v[0]);  
    cout<<knapSack(v, weight, W, n);
    
}
