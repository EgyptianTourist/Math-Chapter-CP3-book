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


ll pow2[55];

int main() {
	//freopen("out.out", "w", stdout);

	pow2[0] = 1LL;
	for(int i = 1; i <= 50; ++i)
		pow2[i] = 2LL * pow2[i - 1];

	int n;

	while(cin >> n, n)
	{
		ll tmp = (n - pow2[(int)log2(n)]);
		ll value = tmp ? tmp * 2 : n;
		cout << value << endl;
	}
	return 0;

}
