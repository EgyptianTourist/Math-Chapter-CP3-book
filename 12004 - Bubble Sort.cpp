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


//int grid[500][500];
ll n, t, mx;
//bool ok(int r, int c)
//{
//	return r <= n && r >= 1 && c <= m && c >= 1;
//}
//int dx[] = { -2, -1, 1, 2, -2, -1, 1, 2 };
//int dy[] = { -1, -2, -2, -1, 1, 2, 2, 1 };

//int arr[500];
//int fr[5000];
//int swaps()
//{
//	int b[n];
//	for(int i = 0; i < n;++i)
//		b[i] = arr[i];
//	int ret = 0;
//	for(int i = 0; i < n ; ++i)
//	{
//		for(int j = 0; j < n - 1; ++j)
//		{
//			if(b[j] > b[j + 1])
//			{
//				swap(b[j], b[j + 1]);
//				++ret;
//			}
//		}
//	}
//	++fr[ret];
//
//	return ret;
//}

int main() {
	//freopen("out.out", "w", stdout);

	cin >> t;

	for(int i = 1; i <= t; ++i)
	{
		cin >> n;
		mx = n * (n - 1) / 2;
		cout << "Case " << i << ": ";
		if(mx&1)
		{
			cout << mx << '/' << 2 << endl;
		}
		else{
			cout << mx/2  << endl;
		}
	}
	return 0;

}
