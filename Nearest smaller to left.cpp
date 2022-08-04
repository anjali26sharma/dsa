
#include <iostream>
#include<stack>
#include<vector>
using namespace std;
vector<int> prevSmaller(vector<int> &A) {
    vector<int> v;
    stack<int> s;
    for(int i =0 ; i<A.size(); i++)
    {
        if(s.size()==0)
        v.push_back(-1);
        else if(s.size()>0 && s.top()<A[i])
        v.push_back(s.top());
        else if(s.size()>0 && s.top()>=A[i])
        {
            while(s.size()>0 && s.top()>=A[i])
            s.pop();
            if(s.size()==0)
            v.push_back(-1);
            if(s.top()<A[i])
            v.push_back(s.top());
        }
        s.push(A[i]);
    }
    return v;
    
}



int main() {
   vector<int> A;
   int n;
   cin>>n;
   int x;
   while(n--)
   {
       cin>>x;
       A.push_back(x);
   }
   vector<int> out = prevSmaller(A);
   for(int i =0; i< out.size(); i++)
   cout<<out[i];
   

    return 0;
}
