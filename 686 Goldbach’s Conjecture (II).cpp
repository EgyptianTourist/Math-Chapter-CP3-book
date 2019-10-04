//#pragma GCC optimize("03")
#include <bits/stdc++.h>
#include <iostream>
using namespace std;
#ifndef DEBUG
#define debug(...) __f(#__VA_ARGS__, __VA_ARGS__)
template <typename Arg1>
void __f(const char* name, Arg1&& arg1)
{
    cerr << name << " : " << arg1 << std::endl;
}
template <typename Arg1, typename... Args>
void __f(const char* names, Arg1&& arg1, Args&&... args)
{
    const char* comma = strchr(names + 1, ',');
    cerr.write(names, comma - names) << " : " << arg1<<" | ";
    __f(comma+1, args...);
}
#else

#define debug(...)
#endif
#define Ios ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
#define sz(a) ((int)(a).size())
#define all(n) (n).begin(),(n).end()
#define ll long long
#define ull unsigned long long
#define pb push_back
#define EPS 1e-9
#define itn int
const ll mod = (ll)1e9 + 7;
//const int mod = int(1e6 + 3);
int dcmp(const double &a, const double &b)
{
    if (fabs(a - b) < EPS)
        return 0;
    return ((a > b) << 1) - 1;
}
//#define iter(x) for(int i = 0; i < (int)x; ++i)
int OO = 0x3f3f3f3f;
const int N = 2e6 + 5;
const int M = 1e6 + 6;
//__builtin_ctz count of trailing zeros in number
int p[N];
vector<int> pr;

int main()
{
    Ios;
    //freopen("in.in", "r",stdin);
    //freopen("out.out", "w",stdout);
    //memset(dp, -1, sizeof(dp));
    //pr.pb(1);
    p[1] = 1;
    for(int i = 2; i * i < N; ++i)
    {
        if(!p[i])
        {
            pr.pb(i);
            for(int j = i * i; j < N; j += i)
            {
                p[j] = 1;
            }
        }
    }
    int n;
    while(cin >> n , n)
    {
        set<pair<int, int>> cnt;
        int x, y;
        for(int i = n - 1; i > 0; --i)
        {
            if(!p[i] && !p[n - i])
            {
                x = min(n - i, i);
                y = max(n - i, i);
                cnt.insert({x, y});
            }
        }
        cout << cnt.size() << endl;
    }

    //cout << ans << endl;
    //system("sleep 5");
    return 0;
}
