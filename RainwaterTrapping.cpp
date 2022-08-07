#include<iostream>
#include<math.h>
using namespace std;
int main()
{
    int n; 
    cin>>n;
    int *arr = new int[n];
    for(int i =0; i<n; i++)
    cin>>arr[i];
    int *mxr = new int[n];
    int *mxl = new int [n];
    mxl[0] = arr[0];
    mxr[0] = arr[n-1];
    for(int i = 1; i<n ; i++)
    mxl[i] = max(mxl[i-1],arr[i]);
    for(int i =n-2; i>=0; i--)
    mxr[i] = max(mxr[i+1],arr[i]);
    int *waterLevel = new int[n];
    for(int i =0; i<n; i++)
    waterLevel[i] = min(mxr[i],mxl[i]) - arr[i];
    int sum =0;
    for(int i =0; i<n ; i++)
    sum = sum+waterLevel[i];
    cout<<sum;
    return 0;
}
