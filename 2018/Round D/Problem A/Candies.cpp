#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;

int main()
{

    ifstream in("A-large-practice.in");
    ofstream out("A-large-practice.out");

    ll t;
    in >> t;

    for(ll tc=1;tc<=t;tc++)
    {
        cout << tc << endl;
        ll n,o,d;
        in >> n >> o >> d;

        vector<ll> X(n);

        ll  A, B, C, M, L;
        in >> X[0] >> X[1] >> A >> B >> C >> M >> L;

        for(ll i=2;i<n;i++)
            X[i] = (A * X[i - 1] + B * X[i - 2] + C) % M;

        for(ll i=0;i<n;i++)
            X[i] = X[i] + L;

        vector<ll> CS(n);
        CS[0] = X[0];
        for(int i=1;i<n;i++)
            CS[i] = CS[i-1] + X[i];

        multiset<ll> s;
        ll nod = 0;
        ll ans = LONG_MIN;
        ll j = n-1;
        for(ll i=n-1;i>=0;i--){

            if(X[i]%2) nod++;
            s.insert(CS[i]);

            while(nod > o){
                s.erase(CS[j]);
                if(X[j]%2) nod--;
                j--;
            }

            multiset<ll>::iterator it;
            if(i > 0) it = s.upper_bound(CS[i-1] + d);
            else it = s.upper_bound(d);

            if(it == s.begin()) continue;

            it--;

            if(i > 0) ans = max(ans,(*it)-CS[i-1]);
            else ans = max(ans,*it);

        }

        if(ans == LONG_MIN) out << "Case #" << tc << ": IMPOSSIBLE" << endl;
        else out << "Case #" << tc << ": " << ans << endl;


    }

    return 0;
}
