#include<iostream>
#include<queue>
#include<iterator>
using namespace std;

#define ll long long

int main()
{
    string emails;
    bool flag = true, solution = true, cool = false;
    ll pre;
    cin >> emails;

    if(emails[0] == '@' || emails[emails.size()-1] == '@') solution = false;

    for(int i=0; i<emails.size() && solution; i++)
    {
        if(emails[i] == '@')
        {
            cool = true;
            if(flag) flag = false;
            else
            {
                if((i - pre) <= 2) solution = false;
            }
            pre = i;
        }
    }

    if(solution && cool)
    {
        string answer = "";
        ll lastComma;
        for(ll i=0; i<emails.size(); i++)
        {
            answer += emails[i];
            if(emails[i-1] == '@')
            {
                answer += ',';
                lastComma = answer.size() - 1;
            }
        }
        for(ll i=0; i<answer.size(); i++)
        {
            if(i == lastComma) continue;
            cout << answer[i];
        }
        cout << endl;
    }
    else cout << "No solution" << endl;
    return 0;
}
