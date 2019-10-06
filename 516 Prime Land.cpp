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
const int N = 1e6 + 5;
const int M = 1e6 + 6;
int parser(string parsing_string, char delimeter)
{
    int ret = 1;
    string chunck = "";
    vector<int> torn;
    parsing_string += " ";
    for(int i = 0; i < parsing_string.size(); ++i)
    {
        char ch = parsing_string[i];
        if(ch == delimeter)
        {
            torn.pb(stoi(chunck));
            //debug(chunck);
            chunck = "";
            while(i < parsing_string.size() && parsing_string[i] == delimeter)++i;
            --i;
        }
        else chunck += ch;
    }
    for(int i = 0; i + 1 < torn.size(); i += 2)
    {
        ret *= _f_pow(torn[i], torn[i + 1]);
    }
    return ret - 1;
}
vector<pair<int, int>> ans;
void factorize(int num)
{
    int cnt = 0;
    if(num%2==0)
    {
        while(num%2 == 0) ++cnt, num/=2;
        ans.push_back({2, cnt});
    }
    for(int i = 3; i * i <= num; i += 2)
    {
        cnt = 0;
        if(num%i)continue;
        while(num%i == 0)cnt++, num/=i;
        ans.push_back({i, cnt});
    }
    if(num > 1)ans.push_back({num, 1});
}
int main()
{
    Ios;
    //freopen("in.in", "r",stdin);
    //freopen("out.out", "w",stdout);
    string in;
    while(getline(cin, in))
    {
        if(in == "0")break;
        int ret = parser(in, ' ');
        ans.clear();
        factorize(ret);

        cout << ans[ans.size() - 1].first << " " << ans[ans.size() - 1].second;
        for(int i = ans.size() - 2; i >= 0; --i)
            cout << " " << ans[i].first << " " << ans[i].second;
        cout << endl;
    }
    //system("sleep 5");
    return 0;
}
