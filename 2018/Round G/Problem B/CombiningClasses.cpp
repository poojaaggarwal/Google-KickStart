#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;

int main()
{

    ifstream in("B-small-attempt0.in");
    ofstream out("B-small-attempt0.out");

    ll t;
    in >> t;

    for(int tc=1;tc<=t;tc++)
    {
        cout << tc << endl;

        ll n,q;
        in >> n >> q;

        ll a,b,c,m;

        vector<ll> X(n);
        in >> X[0] >> X[1] >> a >> b >> c >> m;
        for(ll i=2;i<n;i++){
            X[i] = (a*X[i-1] + b*X[i-2] + c)%m;
        }
        vector<ll> Y(n);
        in >> Y[0] >> Y[1] >> a >> b >> c >> m;
        for(ll i=2;i<n;i++){
            Y[i] = (a*Y[i-1] + b*Y[i-2] + c)%m;
        }

        vector<ll> Z(q);
        in >> Z[0] >> Z[1] >> a >> b >> c >> m;
        for(ll i=2;i<q;i++){
            Z[i] = (a*Z[i-1] + b*Z[i-2] + c)%m;
        }

        vector<ll> L(n);
        vector<ll> R(n);
        for(int i=0;i<n;i++){
            L[i] = min(X[i],Y[i]) + 1;
            R[i] = max(X[i],Y[i]) + 1;
        }

        vector<ll> K(q);
        for(int i=0;i<q;i++)
            K[i] = Z[i] + 1;

        map<ll,ll> h;
        for(int i=0;i<n;i++){
            for(int j=L[i];j<=R[i];j++){
                if(h.find(j) == h.end()) h[j] = 0;
                h[j]++;
            }
        }

        cout << "Yes" << endl;

        map<ll,ll> s;
        ll sum = 0;
        map<ll,ll>::iterator it = h.end();
        it--;
        while(1){
            sum += it->second;
            s[sum] = it->first;
            if(it == h.begin()) break;
            it--;
        }

        cout << "Yes" << endl;
        ll ans = 0;
        for(ll i=1;i<=q;i++){
         if(K[i-1] > sum) continue;
         ans += (i * (*s.lower_bound(K[i-1])).second );
        }
        out << "Case #" << tc << ": " << ans << endl;

    }
}
