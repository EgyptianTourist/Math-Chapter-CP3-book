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
const int N = 1e6 + 5;
const int M = 1e6 + 6;
//__builtin_ctz count of trailing zeros in number
string operator * (const string& cool,const string& looc)
{
    if (!sz(cool) || !sz(looc))
        return "0";

    register vector<int> sol(sz(cool) + sz(looc), 0);

    for(int i = 0, carry = 0; i < sz(cool); ++i, carry = 0)
    {
        register int digit1 = cool[sz(cool) - i - 1] - '0';
        for(int j = 0; j < sz(looc); ++j)
        {
            int digit2 = looc[sz(looc) - j - 1] - '0';
            sol[i + j] += (digit1 * digit2 + carry);
            carry = sol[i + j]/10;
            sol[i + j] %= 10;
        }
        sol[i + sz(looc)] += carry;
    }

    string ret = "";

    while(sz(sol) && !sol.back())
        sol.pop_back();

    for(int i = sz(sol) - 1; ~i; --i)
        ret += (sol[i] + '0');

    if(!sz(sol))
        ret += "0";

    return ret;
}
int main()
{
    Ios;
    //freopen("in.in", "r",stdin);
    //freopen("out.out", "w",stdout);
    //memset(dp, -1, sizeof(dp));
    int n;
    register string f[1005];
    f[0] = f[1] = "1";
    for(int i = 2; i <= 14; ++i)
    {
        f[i] = f[i - 1] * to_string(i);
    }
    while(cin >> n)
    {

        if(n > 13 || (n < 0 && abs(n)&1))
            cout << "Overflow!" << endl;
        else if(n < 8 || (n < 0 && abs(n)%2==0))
            cout << "Underflow!" << endl;
        else
            cout << f[n] << endl;
    }
    //cout << ans << endl;
    //system("sleep 5");
    return 0;
}
