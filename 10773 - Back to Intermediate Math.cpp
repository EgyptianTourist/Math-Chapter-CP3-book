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
	//freopen("out.out", "w", stdout);
	int t;
	cin >> t;
	int i = 1;
	while(t--)
	{
		double d, v, u;
		cin >> d >> v >> u;
		cout << "Case " << i++ <<": ";
		if(v >= u || v == 0 || u == 0)
		{
			cout << "can't determine" << endl;
		}
		else{
			double ans = fabs((d / u) - (d / sqrt(u * u - v * v)));
			cout << fixed << setprecision(3) << ans << endl;
		}
	}
	return 0;

}
