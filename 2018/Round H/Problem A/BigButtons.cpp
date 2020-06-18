#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;

int main()
{

    ifstream in("A-large.in");
    ofstream out("A-large.out");

    vector<ll> pow2(51);
    pow2[0] = 1;
    for(ll i=1;i<51;i++)
        pow2[i] = pow2[i-1]*2;

    ll t;
    in >> t;

    for(ll tc=1;tc<=t;tc++){

        ll n,p;
        in >> n >> p;

        vector<string> v(p);
        for(ll i=0;i<p;i++)
            in >> v[i];

        ll nc = 0;
        for(ll i=0;i<p;i++){
            bool flag = true;
            for(ll j=0;j<p;j++){
                if(i == j) continue;
                if(v[i].find(v[j]) == 0){
                    flag = false;
                    break;
                }
            }
            if(flag) nc += pow2[n-v[i].length()];

        }


        out << "Case #" << tc << ": " << pow2[n] - nc << endl;;
    }

    return 0;
}
