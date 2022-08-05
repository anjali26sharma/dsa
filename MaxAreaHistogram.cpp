#include <iostream>
#include <stack>
#include <vector>
#include <bits/stdc++.h>
using namespace std;
vector<int> NSL(int arr[], int n)
{
    stack<pair<int, int>> s1;
    vector<int> l;
    for (int i = 0; i < n; i++)
    {
        if (s1.size() == 0)
            l.push_back(-1);
        else if (s1.size() > 0 && s1.top().first < arr[i])
            l.push_back(s1.top().second);
        else if (s1.size() > 0 && s1.top().first >= arr[i])
        {
            while (s1.size() > 0 && s1.top().first >= arr[i])
                s1.pop();
            if (s1.size() == 0)
                l.push_back(-1);
            else if (s1.top().first < arr[i])
                l.push_back(s1.top().second);
        }
        s1.push({arr[i], i});
    }
    return l;
}
vector<int> NSR(int arr[], int n)
{
    vector<int> r;
    stack<pair<int, int>> s2;
    for (int i = n; i >= 0; i--)
    {
        if (s2.size() == 0)
            r.push_back(n);
        else if (s2.size() > 0 && s2.top().first < arr[i])
            r.push_back(s2.top().second);
        else if (s2.size() > 0 && s2.top().first >= arr[i])
        {
            while (s2.size() > 0 && s2.top().first >= arr[i])
                s2.pop();
            if (s2.size() == 0)
                r.push_back(n);
            else if (s2.top().first < arr[i])
                r.push_back(s2.top().second);
        }
        s2.push({arr[i], i});
    }
    reverse(r.begin(), r.end());
    return r;
}
int MAH(int arr[], int n)
{
    int width[n];
    int area[n];
    int max = 0;
    vector<int> l;
    vector<int> r;
    l = NSL(arr, n);
    r = NSR(arr, n);
    for (int i = 0; i < n; i++)
    {
        width[i] = r[i] - l[i] - 1;
    }

    for (int i = 0; i < n; i++)
    {
        area[i] = width[i] * arr[i];
    }

    max = area[0];
    for (int i = 1; i < n; i++)
    {
        if (area[i] > max)
            max = area[i];
    }
    return max;
}
int main()
{
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    cout << MAH(arr, n);
}
