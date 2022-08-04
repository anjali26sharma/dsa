#include <iostream>
#include <vector>
#include <stack>
using namespace std;

int main()
{
    vector<int> v;
    stack<pair <int,int>> s;
    int n;
    cin >> n;
    int * arr = new int[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    for (int i = 0; i <n; i++)
    {
        if (s.size() == 0)
            v.push_back(-1);
        else if (s.size() > 0 && s.top().first > arr[i])
            v.push_back(s.top().second);
        else if (s.size() > 0 && s.top().first <= arr[i])
        {
            while (s.size() > 0 && s.top().first <= arr[i])
            {
                s.pop();
            }
            if (s.size() == 0)
                v.push_back(-1);
            else if (s.top().first > arr[i])
                v.push_back(s.top().second);
        }
        s.push({arr[i],i});
    }
    for(int i =0; i<v.size(); i++)
    {
        cout<< i - v[i] << " ";
    }
    return 0;
}
