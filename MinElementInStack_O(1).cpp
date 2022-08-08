#include <iostream>
#include <stack>

using namespace std;

int minEle;

class Mystack
{
    stack<int> s;

public:
    int getMin()
    {
        if (s.size() == 0)
            return -1;
        else
            return minEle;
    }

    void push(int x)
    {
        if (s.size() == 0)
        {
            s.push(x);
            minEle = x;
        }
        else
        {
            if (x > minEle)
                s.push(x);
            else if (x < minEle)
            {
                s.push(2 * x - minEle);
                minEle = x;
            }
        }
    }

    void pop()
    {
        if (s.size() == 0)
            cout << "Underflow";
        else
        {
            if (s.top() >= minEle)
                s.pop();
            else if (s.top() < minEle)
            {
                minEle = (2 * minEle) - s.top();
                s.pop();
            }
        }
    }

    int top()
    {
        if (s.size() == 0)
            return -1;
        else
        {
            if (s.top() >= minEle)
                return s.top();
            else if (s.top() < minEle)
            {
                return minEle;
            }
        }
    }
};

int main()
{
    Mystack ms;
    ms.push(10);
    ms.push(8);
    ms.push(3);
    ms.pop();
    ms.push(9);
    int min = ms.getMin();
    cout << min;
    return 0;
}
