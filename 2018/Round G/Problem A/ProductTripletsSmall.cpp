#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;

int main()
{

    ifstream in("A-small-attempt1.in");
    ofstream out("A-small-attempt1_brute.out");


    ll t;
    in >> t;

    for(ll tc=1;tc<=t;tc++)
    {
        cout << tc << endl;

        ll n;
        in >> n;

        vector<ll> v(n);
        for(int i=0;i<n;i++)
            in >> v[i];

        ll ans = 0;
        for(ll i=0;i<n;i++){
            for(ll j=i+1;j<n;j++){
                for(ll k=j+1;k<n;k++){
                    if(v[k] == v[i]*v[j] || v[i] == v[k]*v[j] || v[j] == v[i]*v[k])
                        ans++;
                }
            }
        }

        out << "Case #" << tc << ": " << ans << endl;
    }

    return 0;
}
