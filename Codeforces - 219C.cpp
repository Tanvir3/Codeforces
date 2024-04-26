#include<iostream>
using namespace std;

#define ll long long

int main()
{
    ll sizeString, Colours, cnt=0;
    string pattern;

    cin >> sizeString >> Colours >> pattern;

    if(Colours >= 3)
    {
        for(int i=1; i<sizeString-1; i++)
            if(pattern[i-1] == pattern[i])
            {
                for(ll j=0; j<Colours; j++)
                {
                    if(pattern[i-1] == char(j+65)) continue;
                    if(pattern[i+1] == char(j+65)) continue;

                    pattern[i] = char(j+65);
                    break;
                }
                cnt++;
            }

        if(pattern[sizeString-2] == pattern[sizeString-1] && pattern[sizeString - 2] != 'A') pattern[sizeString - 1] = 'A', cnt++;
        else if(pattern[sizeString-2] == pattern[sizeString-1] && pattern[sizeString - 2] != 'B') pattern[sizeString - 1] = 'B', cnt++;

        cout << cnt << endl << pattern << endl;
    }
    else
    {
        ll ox = 0, fox = 0, ox1 = 0, fox1 = 0;
        for(int i=0; i<sizeString; i++)
        {
            if(i % 2 == 0)
            {
                if(pattern[i] == 'A') ox++;
                else fox++;
            }
            else
            {
                if(pattern[i] == 'A') ox1++;
                else fox1++;
            }
        }

        ll option1 = sizeString - (ox + fox1);
        ll option2 = sizeString - (fox + ox1);

        cout << min(option1, option2) << endl;
        if(option1 == min(option1, option2))
        {
            for(ll i=0; i<sizeString; i++)
            {
                if(i % 2 == 0) printf("A");
                else printf("B");
            }
        }
        else
        {
            for(ll i=0; i<sizeString; i++)
            {
                if(i % 2 == 0) printf("B");
                else printf("A");
            }
        }
        cout << endl;
    }

    return 0;
}
