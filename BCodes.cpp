/*
name:       Egyptian Tourist
PlatForm:   CodeForces/SPOJ...etc
LANG:       C++
DIV:        Training
TIME:       *
RATE:       *
*/

/*
Time Consumed:*
Problem Topics: *
*/

#include <bits/stdc++.h>
#include <iostream>

using namespace std;
//----------------------------------//

typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;

//-------------------------------------------------------//
#define rep(i,a,b) for (int i = (a), _b = (b); i <= _b; i++)
#define repr(i,a,b) for (int i = (a), _b = (b); i >= _b; i--)
#define lp(i,n) for (int i = 0, _n = (n); i < _n; i++)
#define lpr(i,n) for (int i = (n) - 1; ~i; i--)
#define foreach(it, ar) for ( typeof(ar.begin()) it = ar.begin(); it != ar.end(); it++ )
//-------------------------------------------------------------------------------------//

#define clr(ar, val) memset(ar, val, sizeof(ar))
//----------------------------------------------//

#define inn freopen("in.in","r",stdin)
#define outt freopen("out.out","w",stdout)
#define PI 3.1415926535897932385
#define ll long long
#define ull unsigned long long
#define mp make_pair
#define pb push_back
#define pob pop_back
#define bit(n) (1<<(n))
#define Last(i) ( (i) & (-i) )
#define all(v) ((v).begin()), ((v).end())
#define sq(x) ((x) * (x))
#define INF INT_MAX
#define Ios ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);

//-------------------------------------------------------------//
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
#define _ist_ cout << "\nSTART OF INPUT DISPLAYING CHECK\n";
#define _iend_ cout << "\nEND OF INPUT DISPLAYING CHECK\n";
//------------------------------------------------------------//
#define mod (int)(1e9 + 7)
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
#define N (int)1e5+5

int lcm(int a, int b)
{
    return (a * b)/__gcd(a, b);
}
ll n, x, y;
int a[105];
ll f[105];
bool check(const int A[], int nn)
{
      return all_of(A, A+nn, [A](int x){ return x==A[0]; });
}
ll solve()
{
    ll ret = 0LL;
    for(ll j = 0; j <= n; j++)
    {
        ret += (f[n]/(f[(n - j)] * f[j]))*_f_pow(x, n - j) * _f_pow(y, j);
    }
    return ret;
}
void sol(int C)
{
    if(!C)
        cout << "0\n";
    if(C % 9 != 0)
        cout << (C % 9);
    for(int i = 1; i <= (C/9); i++)
    {
        cout << "9";
    }
    rep(i, 1, C)
        cout << "0";
    cout << endl;
}
void sol2(string x, int k)
{
    if(x.size() <= k)
    {
        puts("0");
        return;
    }
    vector<int> fr(26, 0);
    lp(i, x.size())
        fr[x[i] - 'a']++;
    priority_queue<int> p;
    lp(i, 26)
    {
        if(fr[i])
            p.push(fr[i]);
    }
    while(k--)
    {
        int tm = p.top();
        p.pop();
        --tm;
        p.push(tm);
    }
    int ans = 0;
    while(p.size())
    {
        int tm = p.top();
        p.pop();
        ans += (tm * tm);
    }
    cout << ans << endl;
}
void add(string x, string y)
{
    string res = "";
    if(x.size() > y.size())
        swap(x, y);
    int carry = 0;
    for(int i = x.size() - 1; i >= 0; i--)
    {
        int su = ((x[i] - '0') + (y[y.size() - i - 1] - '0') + carry);
        //debug(su, x[i], y[i], i);
        res = char(su%10 + '0') + res;
        carry/=10;
        y.pop_back();
    }
    //debug("000000");
    for(int i = y.size() - 1; i >= 0; i--)
    {
        int su = ((y[i] - '0') + carry);
        //debug(su, y[i], i);
        res = char(su%10 + '0') + res;
        carry/=10;
    }
    if(carry)
        res = char(carry + '0') + res;
    cout << res << endl;
}
int main()
{
    Ios;
    //inn;outt;
    //auto tt = clock();
    string n, k;
    cin >> n >> k;
    add(n, k);
    system("sleep 50");
    f[0] = f[1] = 1;
    rep(i,2, 100)
    {
        f[i] = f[i - 1]*(ll)i;
        //debug(f[i], i);
    }
    cin >> n >> x >> y;
    cout << solve() << endl;

    //system("sleep 50");
    //cout << (double(clock() - tt)/CLOCKS_PER_SEC * 1.00) << endl;
    return 0;
}
