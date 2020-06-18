#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;

int main()
{

    ifstream in("B-large.in");
    ofstream out("B-large.out");

    ll t;
    in >> t;

    for(ll tc=1;tc<=t;tc++)
    {
        ll v,e;
        in >> v >> e;

        vector<pair<ll,pair<ll,ll> > > edges;
        for(ll i=0;i<e;i++){
            ll v1,v2,c;
            in >> v1 >> v2 >> c;
            edges.push_back(make_pair(c,make_pair(v1-1,v2-1)));
        }

        sort(edges.begin(),edges.end());

        vector<int> dist(v,-1);

        ll ans = 1;
        for(ll i=0;i<e;i++){

            ll v1 = edges[i].second.first;
            ll v2 = edges[i].second.second;
            ll c = edges[i].first;
            if(dist[v1] == -1 && dist[v2] == -1){
                dist[v1] = dist[v2] = c;
                ans *= 2;
            }
            else if(dist[v1] == -1){
                if(dist[v2] == 0)
                    ans *= 2;
                dist[v1] = c;
            }
            else if(dist[v2] == -1){
                if(dist[v1] == 0)
                    ans *= 2;
                dist[v2] = c;
            }
            else{
                continue;
            }

        }

        out << "Case #" << tc << ": " << ans << endl;
    }

    return 0;
}

