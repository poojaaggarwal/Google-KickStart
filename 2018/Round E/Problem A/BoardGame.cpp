#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef pair<ll,pair<ll,ll> > pp;
void findAllPermutation(vector<ll> &v, vector<bool> vis, vector<pp> &vpermute, ll &n, pp cv, int c){

    if(c == 3){
        vpermute.push_back(cv);
    }

    for(int i=0;i<n;i++){
        if(!vis[i]){
            vis[i] = true;
            for(int j=i+1;j<n;j++){
                if(!vis[j]){
                    vis[j] = true;
                    for(int k=j+1;k<n;k++){
                        if(!vis[k]){
                            vis[k] = true;
                            if(c == 0) cv.first = v[i] + v[j] + v[k];
                            else if(c == 1) cv.second.first = v[i] + v[j] + v[k];
                            else cv.second.second = v[i] + v[j] + v[k];
                            findAllPermutation(v,vis,vpermute,n,cv,c+1);
                            vis[k] = false;
                        }
                    }
                    vis[j] = false;
                }
            }
            vis[i] = false;
        }
    }

}

bool success(pp A, pp B){

    ll c = 0;

    if(A.first > B.first) c++;
    if(A.second.first > B.second.first) c++;
    if(A.second.second > B.second.second) c++;

    if(c>1) return true;
    else return false;


}

int main()
{
    ifstream in("C-small-practice.in");
    ofstream out("C-small-practice.out");

    ll t;
    in >> t;

    for(ll tc=1;tc<=t;tc++)
    {
        cout << tc << endl;

        ll n;
        in >> n;

        n = 3*n;

        vector<ll> bahu(n);
        for(ll i=0;i<n;i++) in >> bahu[i];

        vector<ll> bala(n);
        for(ll i=0;i<n;i++) in >> bala[i];

        vector<pp> bahu_permute ;
        pp tp1;
        vector<bool> visited1(n,false);
        findAllPermutation(bahu,visited1,bahu_permute,n,tp1,0);

        vector<pp> bala_permute;
        pp tp2;
        vector<bool> visited2(n,false);
        findAllPermutation(bala,visited2,bala_permute,n,tp2,0);

        ll ans = 0;
        for(ll i=0;i<bahu_permute.size();i++){
            ll tans = 0;
            for(ll j=0;j<bala_permute.size();j++)
                if(success(bahu_permute[i],bala_permute[j]))
                 tans++;
            ans = max(ans,tans);
        }

        out << "Case #" << tc << ": " << setprecision(9) << fixed << ((double)ans)/bala_permute.size() << endl;


    }


    return 0;
}
