//============================================================================
// Name        : test.cpp
// Author      : TheAngel
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <bits/stdc++.h>
#include <stdlib.h>

using namespace std;
typedef long long ll;

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
ll sum;
ll s, d;
bool ok(ll ans)
{
	ll tmp = ans * (ans + 1) / 2LL;
	tmp -= sum;
	return tmp >= d;
}

int main() {
	//freopen("out.out", "w", stdout);
	while(cin >> s >> d)
	{
		ll tmp = s - 1;
		sum = tmp * (tmp + 1LL) / 2LL;
		ll ans = 1;
		while(!ok(ans))
			ans *= 2LL;
		ll l = 1, r = ans;
		while(l <= r)
		{
			ll mid = (l + r) / 2LL;

			if(ok(mid))
			{
				ans = mid;
				r = mid - 1;
			}
			else{
				l = mid + 1;
			}
		}
		cout << ans << endl;
	}
	return 0;

}
