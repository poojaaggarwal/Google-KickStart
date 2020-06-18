#include <bits/stdc++.h>
using namespace std;

int n;
map < pair < int, int >, bool > visited;
map < pair < int, int >, pair < int, int > > d[4];

pair < int, int > get(pair < int, int > x, int g)
{
        if(d[g].find(x) == d[g].end()){
                d[g][x] = x;
                if(g == 0){
                        d[g][x].second -= 1;
                } else if(g == 1){
                        d[g][x].first += 1;
                } else if(g == 2){
                        d[g][x].second += 1;
                } else{
                        d[g][x].first -= 1;
                }
        }
        if(visited.find(d[g][x]) == visited.end()){
                return d[g][x];
        }
        return d[g][x] = get(d[g][x], g);
}

int main()
{
    int t;
    cin >> t;
    for(int tc=1;tc<=t;tc++)
    {
        visited.clear();
        for(int i = 0; i < 4; i++)d[i].clear();
        int x, y;
        cin >> n >> x >> y >> x >> y;
        pair < int, int > res = make_pair(x,y);
        visited[res] = 1;
        for(int i = 1; i <= n; i++){
            char c;
            cin >> c;
            int g = 0;
            if(c == 'S'){
                    g = 1;
            } else if(c == 'E'){
                    g = 2;
            } else if(c == 'N'){
                    g = 3;
            }
            res = get(res, g);
            visited[res] = 1;
        }
        cout << "Case #" << tc << ": " << res.first << " " << res.second << "\n";
    }
    return 0;
}
