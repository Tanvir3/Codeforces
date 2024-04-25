#include<iostream>
#include<map>
#include<set>
#include<iterator>
using namespace std;

#define ll long long

int main()
{
    ll lines, minLimit, maxLimit;
    string message;

    cin >> lines >> minLimit >> maxLimit >> message;

    if((minLimit * lines) > message.size() || message.size() > (maxLimit * lines)) printf("No solution\n");
    else
    {
        ll sz = message.size();
        ll perLine = sz / lines;
        ll extra = sz % lines;
        ll previous = 0;

        while(lines--)
        {
            ll temp;
            if(extra >= (maxLimit - perLine))
            {
                temp = perLine + (maxLimit - perLine);
                extra -= (maxLimit - perLine);
            }
            else if(extra >= 0 && extra < (maxLimit - perLine))
            {
                temp = perLine + extra;
                extra = 0;
            }
            else temp = perLine;
            for(ll i=previous; i<(previous+temp) && i<sz ; i++)
                cout << message[i];
            cout<<endl;
            previous += temp;
        }
    }
    return 0;
}
