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
const int N = 1e7 + 5;
const int M = 1e6 + 6;
//__builtin_ctz count of trailing zeros in number
int p[N];
vector<int> pr, coolSet;
bool is_anagram(string num)
{
    do
    {
        if(p[stoi(num)])return false;
    }
    while(next_permutation(all(num)));
    return true;
}
int main()
{
    Ios;
    //freopen("in.in", "r",stdin);
    //freopen("out.out", "w",stdout);
    //memset(dp, -1, sizeof(dp));
    p[1] = 1;
    //debug((10000000>>5));

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
    for(auto vl: pr)
    {
        string tmp = "";
        int num = vl;
        while(vl)
        {
            tmp += (vl%10) + '0';
            vl /=10;
        }
        sort(all(tmp));
        if(is_anagram(tmp))
            coolSet.pb(num);
    }

    int n;
    while(cin >> n, n)
    {
        int ans = 0;
        int len = log10(n) + 1;
        int next_p_ten = (int)pow(10, len);
        for(int i = 0; i < sz(coolSet); ++i)
        {
            if(coolSet[i] > n && coolSet[i] < next_p_ten)
            {
                ans = coolSet[i];
                break;
            }
        }
        cout << ans << endl;
    }

    //cout << ans << endl;
    //system("sleep 5");
    return 0;
}
