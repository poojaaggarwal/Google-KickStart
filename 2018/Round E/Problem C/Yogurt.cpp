#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;

int main()
{
    ifstream in("A-large-practice.in");
    ofstream out("A-large-practice.out");

    ll t;
    in >> t;

    for(int tc=1;tc<=t;tc++)
    {
        ll n,k;
        in >> n >> k;

        vector<ll> v(n+1,0);
        for(int i=0;i<n;i++){
            ll x;
            in >> x;
            v[min(x,n)]++;
        }
        ll ans = 0;
        for(int i=n;i>0;i--){
            ans += min(k,v[i]);
            v[i-1] += (v[i]-min(k,v[i]));
        }

        out << "Case #" << tc << ": " << ans << endl;
    }

}
