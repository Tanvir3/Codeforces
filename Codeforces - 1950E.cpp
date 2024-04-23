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
        string text;
        cin >> sz >> text;
        ll answer = text.size();

        for(ll i=1; i<=sz; i++)
        {
            if(sz%i == 0)
            {
                int phase = sz/i;
                int start = 1, flag = 0;

                while(phase--)
                {
                    for(int j = i*start, ons = 0; j < (i*(start + 1)) && j < sz; j++, ons++)
                    {
                        if(text[ons] != text[j]) flag++;
                    }
                    start++;
                }
                if(flag <= 1) answer = min(answer, i);

                phase = sz/i;
                start = 0;
                flag = 0;
                int on = ((phase - 1) * i );

                while(phase-- > 0)
                {
                    for(int j = i*start, ons = on; j < (i*(start + 1)) && j < on; j++, ons++)
                    {
                        if(text[ons] != text[j]) flag++;
                    }
                    start++;
                }
                if(flag <= 1) answer = min(answer, i);
            }
        }

        printf("%lld\n", answer);
    }

    return 0;
}
