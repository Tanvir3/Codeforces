#include<iostream>
#include<vector>
#include<queue>
#include<set>
#include<iterator>
using namespace std;

#define ll long long

ll fx[5] = {0,0,-1,1};
ll fy[5] = {-1,1,0,0};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll test, sz;

    cin >> test;

    while(test--)
    {
        cin >> sz;

        string text;
        vector<string> vec;
        bool solution = false;
        bool vis[3][sz+2];

        cin >> text; vec.push_back(text);
        cin >> text; vec.push_back(text);

        for(int i=0; i<sz; i++) vis[0][i] = vis[1][i] = false;

        queue<pair<ll,ll>> q;
        q.push({0,0});
        vis[0][0] = true;

        while(!q.empty())
        {
            pair<ll,ll> p = q.front();
            q.pop();

            if(p.first == 1 && p.second == sz-1)
            {
                solution = true;
                break;
            }

            for(ll i=0; i<4; i++)
            {
                ll x = p.first + fx[i];
                ll y = p.second + fy[i];

                if(x >= 0 && x <= 1 && y >=0 && y < sz)
                {
                    if(vec[x][y] == '>') y++;
                    else y--;

                    if(!vis[x][y]) vis[x][y] = true, q.push({x,y});
                }
            }
        }

        if(solution) cout << "YES" <<endl;
        else cout << "NO" << endl;

    }

    return 0;
}
