#include <iostream>

using namespace std;

const int MaxVal = 9999;

const int n = 5;

double p[n + 1] = {-1,0.15,0.1,0.05,0.1,0.2};
double q[n + 1] = {0.05,0.1,0.05,0.05,0.05,0.1};

int root[n + 1][n + 1];
double w[n + 2][n + 2];
double e[n + 2][n + 2];

void optimalBST(double *p,double *q,int n)
{
    
    for (int i = 1;i <= n + 1;++i)
    {
        w[i][i - 1] = q[i - 1];
        e[i][i - 1] = q[i - 1];
    }
    
    for (int len = 1;len <= n;++len)
    {
        for (int i = 1;i <= n - len + 1;++i)
        {
            int j = i + len - 1;
            e[i][j] = MaxVal;
            w[i][j] = w[i][j - 1] + p[j] + q[j];
            
            for (int k = i;k <= j;++k)
            {
                double temp = e[i][k - 1] + e[k + 1][j] + w[i][j];
                if (temp < e[i][j])
                {
                    e[i][j] = temp;
                    root[i][j] = k;
                }
            }
        }
    }
    cout<<"The minimal cost is: "<<e[1][n]<<endl;
}

void printOptimalBST(int i,int j,int r)
{
    int rootChild = root[i][j];
    if (rootChild == root[1][n])
    {
        
        cout << "k" << rootChild << " is the root" << endl;
        printOptimalBST(i,rootChild - 1,rootChild);
        printOptimalBST(rootChild + 1,j,rootChild);
        return;
    }
    
    if (j < i - 1)
        return;
    else if (j == i - 1)
    {
        if (j < r)
            cout << "d" << j << " is the left child of " << "k" << r << endl;
        else
            cout << "d" << j << " is the right child of " << "k" << r << endl;
        return;
    }
    else
    {
        if (rootChild < r)
            cout << "k" << rootChild << " is the left child of " << "k" << r << endl;
        else
            cout << "k" << rootChild << " is the right child of " << "k" << r << endl;
    }
    
    printOptimalBST(i,rootChild - 1,rootChild);
    printOptimalBST(rootChild + 1,j,rootChild);
}

int main()
{
    optimalBST(p,q,n);
    cout << "The Optimal Binary Tree isï¼š" << endl;
    printOptimalBST(1,n,-1);
}
