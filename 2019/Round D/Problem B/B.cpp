#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;

    for(int tc=1;tc<=t;tc++)
    {
        int n,g,m;
        cin >> n >> g >> m;

        vector<int> h(g);
        vector<char> c(g);

        for(int i=0;i<g;i++) cin >> h[i] >> c[i];

        vector<int> lef(n), rig(n);
        for (int i = 0; i < g; ++i) {
            if (c[i] == 'C') {
              int now = (h[i] + m) % n;
              rig[now] = m;
            }
            else {
              int now = (h[i] - m) % n;
              if (now < 0) now += n;
              lef[now] = m;
            }
       }

       // anticlockwise
       int cur = -1;
       for (int i = 0; i < 2 * n; ++i) {
            cur = max(cur-1, lef[i % n]);
            lef[i % n] = cur;
        }

        // clockwise
        cur = -1;
        for (int i = 2 * n-1; i >= 0; --i) {
            cur = max(cur-1, rig[i % n]);
            rig[i % n] = cur;
        }

        vector<int> cntl(n,0), cntr(n,0);
        for (int i = 0; i < n; ++i) {
            int res = max(lef[i], rig[i]);
            if (res < 0) continue;
            if (lef[i] == res) {
              int pos = (i + res) % n;
              ++cntl[pos];
            }
            if (rig[i] == res) {
              int pos = (i - res) % n;
              if (pos < 0)
                pos += n;
              ++cntr[pos];
            }
        }
        cout << "Case #" << tc << ":";
        for (int i = 0; i < g; ++i) {
            if (c[i] == 'C') cout << " " << cntr[h[i] % n];
            else cout << " " << cntl[h[i] % n];
        }
        cout << endl;

    }

    return 0;
}



