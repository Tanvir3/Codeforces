#include<iostream>
#include<vector>
#include<queue>
#include<deque>
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
    ll test, number, attack, power;

    cin >> test;

    while(test--)
    {
        cin >> number >> attack;

        deque<ll> dq;
        deque<ll> :: iterator it;
        bool indicate = true;
        ll cnt = 0;

        for(int i=0; i<number; i++)
        {
            cin >> power;
            dq.push_back(power);
        }

        while(attack != 0)
        {
            if(dq.size() == 0) break;
            if(dq.size() == 1)
            {
                if(dq.front() <= attack) cnt++;
                break;
            }
            ll fro = dq.front();
            ll bac = dq.back();
            if(indicate)
            {
                if(fro <= bac)
                {
                    if(attack >= (fro*2)-1)
                    {
                        dq.pop_front();
                        dq.pop_back();
                        bac -= (fro-1);
                        dq.push_back(bac);
                        attack -= ((fro*2)-1);
                        indicate = false;
                        cnt++;
                    }
                    else break;
                }
                else
                {
                    if(attack >= (bac*2))
                    {
                        dq.pop_front();
                        fro -= bac;
                        dq.push_front(fro);
                        dq.pop_back();
                        attack -= (bac*2);
                        indicate = true;
                        cnt++;
                    }
                    else break;
                }
            }
            else
            {
                if(fro >= bac)
                {
                    if(attack >= (bac*2)-1)
                    {
                        dq.pop_back();
                        dq.pop_front();
                        fro -= (bac-1);
                        dq.push_front(fro);
                        attack -= ((bac*2)-1);
                        indicate = true;
                        cnt++;
                    }
                    else break;
                }
                else
                {
                    if(attack >= (fro*2))
                    {
                        dq.pop_front();
                        bac -= fro;
                        dq.pop_back();
                        dq.push_back(bac);
                        attack -= (fro*2);
                        indicate = false;
                        cnt++;
                    }
                    else break;
                }
            }
        }
        cout << cnt << endl;
    }
    return 0;
}
