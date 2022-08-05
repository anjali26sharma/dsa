#include <iostream>
#include <stack>
#include <vector>
#include <bits/stdc++.h>
#include <algorithm>
using namespace std;
vector<int> NsrIndex(int *arr, int n)
{
    stack<pair<int, int>> s;
    vector<int> v;
    for (int i = n - 1; i >= 0; i--)
    {
        if (s.size() == 0)
            v.push_back(n);
        else if (s.size() > 0 && s.top().first < arr[i])
            v.push_back(s.top().second);
        else if (s.size() > 0 && s.top().first >= arr[i])
        {
            while (s.size() > 0 && s.top().first >= arr[i])
                s.pop();
            if (s.size() == 0)
                v.push_back(n);
            else if (s.top().first < arr[i])
                v.push_back(s.top().second);
        }
        s.push({arr[i], i});
    }

    reverse(v.begin(), v.end());
    return v;
}

vector<int> NslIndex(int *arr, int n)
{
    stack<pair<int, int>> s;
    vector<int> v;
    for (int i = 0; i < n; i++)
    {
        if (s.size() == 0)
            v.push_back(-1);
        else if (s.size() > 0 && s.top().first < arr[i])
            v.push_back(s.top().second);
        else if (s.size() > 0 && s.top().first >= arr[i])
        {
            while (s.size() > 0 && s.top().first >= arr[i])
                s.pop();
            if (s.size() == 0)
                v.push_back(-1);
            else if (s.top().first < arr[i])
                v.push_back(s.top().second);
        }
        s.push({arr[i], i});
    }
    return v;
}

int main()
{
    int n, maxArea = 0;
    cin >> n;
    int *arr = new int[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    vector<int> NSR = NsrIndex(arr, n);
    vector<int> NSL = NslIndex(arr, n);
    int width[n];
    int area[n];

    for (int i = 0; i < n; i++)
    {
        width[i] = NSR[i] - NSL[i] - 1;
        area[i] = width[i] * arr[i];
    }
    for (int i = 0; i < n; i++)
    {
        if (area[i] > maxArea)
            maxArea = area[i];
    }
    cout << maxArea << endl;
    return 0;
}
