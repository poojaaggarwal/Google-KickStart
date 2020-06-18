#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;

vector<ll> parent;
vector<ll> rank_vertex;

struct edge
{
    ll v1;
    ll v2;
    ll cost;
    edge(ll a,ll b, ll c):v1(a),v2(b),cost(c){};
};

bool compare(edge a , edge b){
    return (a.cost < b.cost);
}

ll findParent(ll a)
{
    if(parent[a] != a)
        parent[a] = findParent(parent[a]);
    return parent[a];
}

ll union_vertex(ll a, ll b)
{
    ll pa = findParent(a);
    ll pb = findParent(b);

    if(rank_vertex[pa] > rank_vertex[pb])
        parent[pb] = pa;
    else
        parent[pa] = pb;

    if(rank_vertex[pa] == rank_vertex[pb])
        rank_vertex[pb]++;

}

int main()
{
    ifstream in("B-large-practice.in");
    ofstream out("B-large-practice.out");

    ll t;
    in >> t;

    for(ll tc=1;tc<=t;tc++)
    {
        ll n;
        in >> n;

        vector<ll> red(n);
        for(ll i=0;i<n;i++) in >> red[i];

        vector<ll> blue(n);
        for(ll i=0;i<n;i++) in >> blue[i];


        vector<edge> v;
        for(ll i=0;i<n;i++)
            for(ll j=i+1;j<n;j++)
                v.push_back(edge(i,j,min(red[i]^blue[j],blue[i]^red[j])));

        sort(v.begin(),v.end(),compare);

        rank_vertex.resize(n);
        parent.resize(n);
        for(int i=0;i<n;i++){
            parent[i] = i;
            rank_vertex[i] = 1;
        }

        ll cedge = 0;
        ll ans = 0;
        for(ll i=0;i<v.size();i++){

            if(findParent(v[i].v1) == findParent(v[i].v2)) continue;

            union_vertex(v[i].v1,v[i].v2);

            ans += v[i].cost;
            cedge++;

            if(cedge == n-1) break;

        }

        out << "Case #" << tc << ": " << ans << endl;

    }

    return 0;
}
