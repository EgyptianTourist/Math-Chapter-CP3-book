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

int main() {
	int t;
	cin >> t;
	//freopen("out.out", "w", stdout);
	while(t--)
	{
		int n;
		cin >> n;
		double a0, an;
		cin >> a0 >> an;
		long double ans = n * a0 + an;
		for(int i = 0; i < n; ++i)
		{
			long double ci;
			cin >> ci;
			ans -= ((n - i) * 2.0 * ci);
		}
		cout << fixed << setprecision(2) << ans / (n + 1) << endl;
		if(t)
		{
			cout << endl;
		}
	}
	return 0;

}
