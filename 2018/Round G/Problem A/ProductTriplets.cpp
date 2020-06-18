#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;

int main()
{

    ifstream in("A-large.in");
    ofstream out("A-large.out");

    ll t;
    in >> t;

    for(ll tc=1;tc<=t;tc++)
    {
        cout << tc << endl;

        ll n;
        in >> n;

        vector<ll> v(n);
        for(ll i=0;i<n;i++)
            in >> v[i];

        vector<ll> uv;
        map<ll,ll> h;
        for(ll i=0;i<n;i++)
        {
            if(h.find(v[i]) == h.end())
            {
                uv.push_back(v[i]);
                h[v[i]] = 1;
            }
            else
            {
                h[v[i]]++;
            }
        }

        sort(uv.begin(),uv.end());

        ll un = uv.size();
        ll ans = 0;
        for(ll i=0;i<un;i++){

            for(ll j=i+1;j<un;j++){
                ll k = uv[i]*uv[j];
                if(h.find(k) != h.end()){
                    if(uv[j] == k){
                        ans += (h[uv[i]]*(h[k]*(h[k]-1))/2);
                    }
                    else if(uv[i] == k){
                      ans += (h[uv[j]]*(h[k]*(h[k]-1))/2);
                    }
                    else{
                      ans += (h[uv[i]]*h[uv[j]]*h[k]);
                    }
                }
            }

            if(uv[i] > 1){
                ll si = uv[i]*uv[i];
                if(h.find(si) != h.end())
                    ans += (h[si] * (h[uv[i]] * (h[uv[i]]-1))/2);
            }

        }

        if(h.find(1) != h.end()) ans += (((h[1]*(h[1]-1))/2)*(h[1]-2))/3;

        if(h.find(0) != h.end()) ans += (((h[0]*(h[0]-1))/2)*(h[0]-2))/3;

        out << "Case #" << tc << ": " << ans << endl;
    }

}
