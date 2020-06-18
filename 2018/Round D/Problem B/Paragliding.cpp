#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;

ll binarySearch(vector<pair<ll,ll> > arr, ll val){

    ll l = 0;
    ll h = arr.size();

    while(l < h){
        ll m = l + (h-l)/2;
        if(arr[m].first <= val && arr[m+1].first >= val) return m;
        else if(arr[m].first > val) h = m;
        else l = m+1;
    }
    return -1;
}

bool canReach(ll kite_x, ll kite_y, ll tower_x, ll tower_y)
{
    return (tower_y >= kite_y + abs(kite_x-tower_x));
}

int main()
{
    ifstream in("B-small-practice.in");
    ofstream out("B-small-practice.out");

    ll T;
    in >> T;

    for(ll tc=1;tc<=T;tc++){
        cout << tc << endl;
        ll N,K;
        in >> N >> K;
        ll A,B,C,M;

        vector<ll> p(N);
        in >> p[0] >> p[1] >> A >> B >> C >> M;
        for(ll i=2;i<N;i++)
            p[i] = (A*p[i-1] + B*p[i-2] + C)%M + 1;

        vector<ll> h(N);
        in >> h[0] >> h[1] >> A >> B >> C >> M;
        for(ll i=2;i<N;i++)
            h[i] = (A*h[i-1] + B*h[i-2] + C)%M + 1;

        vector<ll> x(K);
        in >> x[0] >> x[1] >> A >> B >> C >> M;
        for(ll i=2;i<K;i++)
            x[i] = (A*x[i-1] + B*x[i-2] + C)%M + 1;

        vector<ll> y(K);
        in >> y[0] >> y[1] >> A >> B >> C >> M;
        for(ll i=2;i<K;i++)
            y[i] = (A*y[i-1] + B*y[i-2] + C)%M + 1;

        // find x position sorted tower list
        vector<pair<ll,ll> > allTowers(N);
        for(ll i=0;i<N;i++)
            allTowers[i] = make_pair(p[i],h[i]);
        sort(allTowers.begin(),allTowers.end());

        vector<pair<ll,ll> > relevantTowers;
        for(ll i=0;i<N;i++){
            while(!relevantTowers.empty() &&
                   relevantTowers.back().second <= allTowers[i].second - abs(relevantTowers.back().first - allTowers[i].first))
            {
                relevantTowers.pop_back();
            }

            if(relevantTowers.empty() ||
                   allTowers[i].second > relevantTowers.back().second - abs(relevantTowers.back().first - allTowers[i].first))
	{
                relevantTowers.push_back(allTowers[i]);
            }
        }

        ll ans = 0;
        for(ll i=0;i<K;i++)
        {

            if(x[i] < relevantTowers[0].first){
                if(canReach(x[i],y[i],relevantTowers[0].first,relevantTowers[0].second)) ans++;
            }
            else if(x[i] > relevantTowers.back().first){
                if(canReach(x[i],y[i],relevantTowers.back().first,relevantTowers.back().second)) ans++;
            }
            else
            {
                ll pos = binarySearch(relevantTowers,x[i]);
                if(canReach(x[i],y[i],relevantTowers[pos].first,relevantTowers[pos].second)) ans++;
                else if(canReach(x[i],y[i],relevantTowers[pos+1].first,relevantTowers[pos+1].second)) ans++;
            }
        }

        out << "Case #" << tc << ": " << ans << endl;

    }

    return 0;

}
