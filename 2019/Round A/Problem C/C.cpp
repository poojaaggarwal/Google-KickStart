#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;

int main()
{

    ll t;
    cin >> t;

    for(ll tc=1;tc<=t;tc++){

        ll n,q;
        cin >> n >> q;

        vector<pair<ll,ll> > v(q);
        for(ll i=0;i<q;i++){
            ll l,r;
            cin >> l >> r;
            v[i] = make_pair(l,r);
        }

        vector<bool> h(n+1,false);
        vector<ll> arr;
        for(ll i=0;i<q;i++){
            for(ll j=v[i].first;j<=v[i].second;j++){
                if(!h[j]){
                    arr.push_back(j);
                    h[j] = true;
                }
            }
        }






        cout << "Case #" << tc << ": " << i << endl;

    }

}
