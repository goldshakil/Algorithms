
#include<bits/stdc++.h> 
#include<iostream>
using namespace std; 


int s[7][7];

void Print_Optimal_Parens(int i, int j) {
    if (i == j)
        cout<<"A"<<i;
    else {
        cout<<"(";
        Print_Optimal_Parens(i, s[i][j]) ;
        Print_Optimal_Parens(s[i][j]+1, j);
        cout<<")";
    }
}


int MatrixChainOrder(int p[], int n) 
{ 

	int m[n][n]; 

	int i, j, k, L, q; 

	for (i = 1; i < n; i++) 
		m[i][i] = 0; 

	
	for (L = 2; L < n; L++) 
	{ 
		for (i = 1; i < n - L + 1; i++) 
		{ 
			j = i + L - 1; 
			m[i][j] = INT_MAX; 
			for (k = i; k <= j - 1; k++) 
			{ 
				q = m[i][k] + m[k + 1][j] + 
					p[i - 1] * p[k] * p[j]; 
				if (q < m[i][j]) {
				    m[i][j] = q; 
				    s[i][j] = k;
				} 
					
			} 
		} 
	}

	Print_Optimal_Parens (1,n-1);
	cout<<endl;
	return m[1][n - 1]; 

} 

int main() 
{ 
	int arr[] = {30, 35, 15, 5, 10, 20,25}; 
	int size = sizeof(arr) / sizeof(arr[0]); 
   
	cout << "Minimum number of multiplications is: "
		<< MatrixChainOrder(arr, size); 

	getchar(); 
	return 0; 
} 

