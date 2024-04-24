#include<iostream>
#include<map>
#include<set>
#include<iterator>
using namespace std;

#define ll long long

int main()
{
    ll n;
    map<string,ll> mp, mp1;
    map<string,ll> :: iterator it;

    cin >> n;
    string name[n+2];
    ll point[n+2], mx = -1000;

    for(int i=0; i<n; i++)
    {
        cin >> name[i] >> point[i];
        it = mp.find(name[i]);
        if(it == mp.end()) mp[name[i]] = point[i];
        else mp[name[i]] += point[i];
    }

    it = mp.begin();
    while(it != mp.end())
    {
        mx = max(mx, it->second);
        it++;
    }

    it = mp.begin();
    set<string> st;
    while(it != mp.end())
    {
        if(it->second == mx) st.insert(it->first);
        it++;
    }

    for(int i=0; i<n; i++)
    {
        it = mp1.find(name[i]);
        if(it == mp1.end())
        {
            if(mx <= point[i] && st.find(name[i]) != st.end())
            {
                cout << name[i] << endl;
                break;
            }
            mp1[name[i]] = point[i];
        }
        else
        {
            if(mx <= (point[i] + it->second) && st.find(name[i]) != st.end())
            {
                cout << name[i] << endl;
                break;
            }
            mp1[name[i]] += point[i];
        }
    }

    return 0;
}
