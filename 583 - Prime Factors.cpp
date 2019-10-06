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
#define pb push_back
#define EPS 1e-9
const int mod = int(1e9 + 7);
//const int mod = int(1e6 + 3);
int dcmp(const double &a, const double &b)
{
    if (fabs(a - b) < EPS)
        return 0;
    return ((a > b) << 1) - 1;
}
template<class T, class T2>
T _f_pow(T a, T2 b)
{
    T res = 1LL;
    //a%=mod;
    while (b > 0)
    {
        if (b & 1)
            res = (res*a);//res = (res * a)%mod;
        a = (a * a);
        //a%=mod;
        b >>= 1;
    }
    return (res);
}
//#define iter(x) for(int i = 0; i < (int)x; ++i)
int OO = 0x3f3f3f3f;
const int N = 1e7 + 5;
const int M = 1e5 + 6;
int p[N];

vector<ll> ans, pr;
void seive()
{
    p[0] = p[1] = 1;
    for(int i = 2; i * i < N; ++i)
    {
        if(!p[i])
        {
            pr.pb(i);
            for(int j = i * i; j < N; j += i)
                p[j] = 1;
        }
    }
}
void factorize(int num)
{
    if(num%2LL==0)
    {
        while(num%2LL == 0) num/=2, ans.push_back(2LL);
    }
    for(int i = 0; i < sz(pr) && pr[i] * pr[i] <= num; ++i)
    {
        if(num%pr[i])continue;
        while(num%pr[i] == 0)num/=pr[i], ans.push_back(pr[i]);
    }
    if(num > (int)1e6)
        for(ll i = 3; i * i <= num; i += 2)
        {
            if(num%i)continue;
            while(num%i == 0)num/= i, ans.push_back(i);
        }
    if(num > 1)ans.push_back(num);
}

int main()
{
    Ios;
    //freopen("in.in", "r",stdin);
    //freopen("out.out", "w",stdout);
    ll in, ret;
    seive();
    while(cin >> in, in)
    {
        ans.clear();
        cout << in << " = ";
        ret = in;
        if(in < 0)
        {
            ret = in * -1;
            cout << -1;
        }
        if(abs(in) == 1)
        {
            if(in < 0)cout <<" x ";
            cout << endl;
            continue;
        }
        factorize(ret);
        if(in < 0)
        {
            cout << " x ";
        }
        cout << ans[0];
        for(int i = 1; i < ans.size(); ++i)
            cout << " x " << ans[i];
        cout << endl;
    }
    //system("sleep 5");
    return 0;
}
