#include<iostream>
#include<stack>
using namespace std;

#define ll long long

int main()
{
    ll test, a, b;
    cin >> test;

    while(test--)
    {
        stack<ll> stk;
        bool solution = true;
        cin >> a >> b;

        while(a != 0)
        {
            int x = a % 10;
            int y = b % 10;

            if(a != 0 && b == 0)
            {
                solution = false;
                break;
            }
            else if(x <= y) stk.push(y-x), a /= 10, b /= 10;
            else
            {
                if(b < 10)
                {
                    solution = false;
                    break;
                }
                int ex = b % 100;
                if(ex/10 > 1 || ex == 0 || (ex - x) < 0)
                {
                    solution = false;
                    break;
                }
                stk.push(ex - x), a /= 10, b /= 100;
            }
        }

        if(a == 0 && b != 0 && solution)
        {
            while(b != 0) stk.push(b%10), b /= 10;
        }

        if(!solution) cout << "-1\n";
        else
        {
            while(stk.top() == 0) stk.pop();
            while(!stk.empty())
            {
                cout << stk.top() ;
                stk.pop();
            }
            cout << endl;
        }
    }
    return 0;
}
