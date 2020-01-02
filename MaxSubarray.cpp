#include <iostream>
#include <algorithm>
using namespace std;

//Sol#1: Divide-and-Conquer

struct subarray {
    int left;
    int right;
    int sum;
};

subarray maxCrossSubarray (int array[], int low, int mid, int high) {
    int leftSum =array[mid];
    int sum =0;
    int maxLeft=mid;
    for (int i =mid;i>=low;i--) {
        sum = sum+array[i];
        if (sum>leftSum) {
            leftSum = sum;
            maxLeft = i;
        }
    }
    
    int rightSum =array[mid+1];
    sum =0;
    int maxRight = mid+1;
    for (int j = mid+1;j<=high;j++) {
        sum = sum+array[j];
        if (sum>rightSum) {
            rightSum = sum;
            maxRight = j;
        
        }
    }
    subarray crossArray = {maxLeft, maxRight,leftSum+rightSum};
    return crossArray;
}



subarray maxSubArray(int array[], int low, int high) {
    if (high ==low) {
        subarray res = {low, low, array[low]};
         return res;
    }
       
    
    else {
        int mid = (low+high)/2;
        subarray left, right, cross;
        left = maxSubArray(array,low,mid);
        right = maxSubArray(array,mid+1,high);
        cross = maxCrossSubarray(array,low,mid,high);
        
        if (left.sum>right.sum &&left.sum>cross.sum) 
            return left;
        else if (right.sum>left.sum &&right.sum>cross.sum) 
            return right;
        else 
            return cross;
            
    }
    
}

//Sol#2: Dynamic Programming
int maxSubArrayDP(int array[],int n) {
    int F[n];
        int maxSum = array[0];
        for (int i = 0;i<n;i++) {
            if (i == 0) F[i]=array[i];
            else 
                F[i] = max(F[i-1]+array[i],array[i]);
            maxSum = max(maxSum, F[i]);
        }
        return maxSum;
        
}



int main() {
    int arr1[16] = {13, -3, -25, 20, -3, -16, -23, 18, 20, -7, 12, -5, -22, 15, -4, 7};
    subarray res = maxSubArray(arr1,0,15);
    cout<<res.left<<" "<<res.right<<" "<<res.sum<<endl;
    
    int arr2[16] = {13, -3, -25, 20, -3, -16, -23, 18, 20, -7, 12, -5, -22, 15, -4, 7};
    int result = maxSubArrayDP(arr2, 15);
    cout<<result<<endl;
    
    
}
