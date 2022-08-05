#include <iostream>
#include <vector>
#include <stack>
#include <bits/stdc++.h>
#include <algorithm>
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
int max2(int x, int y)
{
    return (x > y) ? x : y;
}
int MAH(int arr[], int n)
{
    int width[n];
    int area[n];
    int max1 = 0;
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

    max1 = area[0];
    for (int i = 1; i < n; i++)
    {
        if (area[i] > max1)
            max1 = area[i];
    }
    return max1;
}
int main()
{
    int n, m;
    cin >> n >> m;
    int arr[n][m];
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> arr[i][j];

    int v[m];
    for (int j = 0; j < m; j++)
        v[j] = arr[0][j];
    int mx = 0;
    mx = MAH(v, m);
    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (arr[i][j] == 0)
                v[j] = 0;
            else
                v[j] = v[j] + arr[i][j];
        }
        mx = max2(mx, MAH(v, m));
    }
    cout << mx;
    return 0;
}
