#include<iostream>
using namespace std;

#define ll long long

int main()
{
    ll test;
    scanf("%lld", &test);

    while(test--)
    {
        ll sz;
        string text1, text2, answer;
        bool flag = true;

        cin >> sz >> text1 >> text2;
        ll position = sz - 1;

        answer += text1[0];
        for(ll i = 0; i < sz-1; i++)
        {
            if(!flag) answer += text2[i];
            else if(flag && text1[i+1] <= text2[i]) answer += text1[i+1];
            else if(text1[i+1] > text2[i])
            {
                if(flag) position = i;
                answer += text2[i];
                flag = false;
            }
        }

        answer += text2[sz - 1];

        ll counts = 1;

        for(ll i=position; i >= 0 ; i--)
        {
            if(text1[i] == text2[i-1]) counts++;
            else break;
        }

        cout << answer << endl << counts << endl;
    }

    return 0;
}
