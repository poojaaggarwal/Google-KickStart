#include<bits/stdc++.h>
using namespace std;

int main()
{

    int t;
    cin >> t;

    for(int tc=1;tc<=t;tc++){

        int r,c,k;
        cin >> r >> c >> k;

        vector<vector<int> > v(r,vector<int>(c));
        for(int i=0;i<r;i++)
            for(int j=0;j<c;j++)
                cin >> v[i][j];

        vector<vector<int> > p(r,vector<int>(c));
        for(int i=0;i<r;i++){
            p[i][c-1] = 1;
            int li=c-1, mine=c-1 , maxe=c-1;
            set<pair<int,int> > s;
            s.insert(make_pair(v[i][c-1],c-1));
            for(int j=c-2;j>=0;j--){
                if(v[mine] >= v[j]) mine = j;
                if(v[maxe] <= v[j]) maxe = j;
                if(v[maxe] - v[mine] > k){
                    if(maxe == j){
                        li = mine - 1;
                        mine = min_in_range(i,li);
                    }
                    else{
                        li = maxe-1;
                        maxe = max_in_range(i,li)
                    }
                }
                p[i][j] = li-i+1;
            }
        }


        vector<vector<pair<int,int> > > s(r);
        for(int i=0;i<r;i++){

            int maxe=v[i][0], mine=v[i][0], st = 0;
            for(int j=0;j<c;j++){

                if(v[i][j] > maxe){
                    maxe = v[i][j];
                    if(maxe - mine > k){
                        s[i].push_back(make_pair(st,j-1));
                        int pj = j,tmine = v[i][pj];
                        while(v[i][pj] != mine) tmine = min(tmine,v[i][pj--]);
                        st = pj+1,mine = tmine;
                    }
                }

                if(v[i][j] < mine){
                    mine = v[i][j];
                    if(maxe - mine > k){
                        s[i].push_back(make_pair(st,j-1));
                        int pj = j,tmaxe = v[i][pj];
                        while(v[i][pj] != maxe) tmaxe = max(tmaxe,v[i][pj--]);
                        st = pj+1, maxe = tmaxe;
                    }
                }

                if(j == c-1) s[i].push_back(make_pair(st,j));

            }
        }

        int ans = 0;
        for(int i=0;i<r;i++){
            vector<pair<int,int> > cv = s[i];
            for(int j=i;j<r;j++){
                cv = common(cv,s[j]);
                for(int l=0;l<cv.size();l++) ans = max(ans,(cv[l].second-cv[l].first+1)*(j-i+1));
            }
        }

        cout << "Case #" << tc << ": " << ans << endl;



    }


    return 0;
}
