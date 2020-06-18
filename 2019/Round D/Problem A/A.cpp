#include<bits/stdc++.h>
using  namespace std;

bool isXorEven(int num)
{
    int c = 0;
    while(num)
    {
        c++;
        num &= (num-1) ;
    }
    return (c%2 == 0);
}

int main()
{
    int t;
    cin >> t;

    for(int tc=1;tc<=t;tc++)
    {
        int n,q;
        cin >> n >> q;

        set<int> s;
        for(int i=0;i<n;i++){
            int temp;
            cin >> temp;
            if(!isXorEven(temp)) s.insert(i);
        }
        cout << "Case #" << tc << ":";
        while(q--){
            int a,b;
            cin >> a >> b;
            set<int>::iterator ele = s.find(a);
            if(ele != s.end()) s.erase(ele);
            if(!isXorEven(b)) s.insert(a);
            set<int>::iterator si,ei;
            int x = s.size();
            int ans;
            if(x > 0){

                si = s.begin();
                ei = s.end();
                ei--;
            }

            if(x%2 == 0) ans = n;
            else ans = max(n-(*si)-1,*ei);
            cout << " " << ans;
        }
        cout << endl;
    }



    return 0;
}
