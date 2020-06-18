#include<bits/stdc++.h>
using namespace std;

int pow(int a, int n, int p){

    if(n == 0) return 1;

    if(n == 1) return a%p;

    long long int tpow = pow(a,n/2,p);
    if(n%2 == 0)
        return (tpow*tpow)%p;
    else
        return ((tpow*tpow)%p*a)%p;
}

int main()
{
    ifstream in("A-large-practice.in");
    ofstream out("A-large-practice.out");

    int t;
    in >> t;

    for(int tc=1;tc<=t;tc++)
    {
        int a,n,p;
        in >> a >> n >> p;

        int ans = a%p;
        for(int i=2;i<=n;i++) ans = pow(ans,i,p);

        out << "Case #" << tc << ": " << ans << endl;
    }


    return 0;
}
