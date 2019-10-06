/* ***********************************************
Author :Chord
Email:pengrj2018@gmail.com
Created Time :2019/9/28 17:03:18
File Name :pat1008.cpp
************************************************ */

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <string>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <cstring>
#include <stack>
#include <bitset>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, int> pli;
typedef pair<ll, ll> pll;
const int maxn = 1e5 + 7;

void solve(void)
{
	int n;
	cin>>n;
	int ans = 0,last = 0;
	for(int i = 0 ; i < n ; i++){
		int nw;
		cin>>nw;
		if(nw > last)
			ans += (nw - last) * 6;
		else ans += (last - nw) * 4;
		ans += 5;
		last = nw;
	}
	cout<<ans<<endl;
}

int main()
{
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);
	solve();
 
 	return 0;
}
