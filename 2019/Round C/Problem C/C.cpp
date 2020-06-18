#include<bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;

    for(int tc=1;tc<=t;tc++){

        int n,k;
        cin >> n >> k;

        vector<int> pos(n), col(n);
        for(int i=0;i<n;i++) cin >> pos[i];
        for(int i=0;i<n;i++) cin >> col[i];

        vector<bool> sel(n,false);
        int sk = 0, pi=-1;
        int ans = 0, fans = -1;
        while(k>0){
            map<int,int> dcol;
            int mdist=-1, msel, mcol, tdist, tsel, tcol, ci;
            float mscore,tscore;
            for(int i=0;i<n;i++){
                if(!sel[i]){
                    dcol[col[i]]++;
                    if(pi != -1 && col[i] == col[pi]){
                        tdist = pos[i]-pos[pi], tsel = min(k,dcol[col[i]]), tcol = col[i];
                        tscore = (float)tsel/tdist;
                    }
                    else{
                        tdist = pi == -1 ? pos[i]:pos[i]+pos[pi], tsel = min(k,dcol[col[i]]), tcol = col[i];
                        tscore = (float)tsel/tdist;
                    }

                    cout << tdist << " " << tsel << " "<< k <<endl;
                    if(tsel == k) fans == -1 ? (ans + tdist) : min(fans, ans + tdist);

                    if(mdist == -1 || mscore < tscore){
                        mdist = tdist, msel = tsel, mcol = tcol, mscore=tscore, ci=i;
                    }
                }
            }

            k -= msel;
            ans += mdist;
            pi = ci;

            for(int i=0;i<=ci;i++){
                if(col[i] == col[ci]){
                   sel[i] = true;
                }
            }



        }

        if(fans != -1) ans = min(ans,fans);
        cout << "Case #" << tc << ": " << ans << endl;

    }


    return 0;
}
