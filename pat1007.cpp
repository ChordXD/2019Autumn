/* ***********************************************
Author :Chord
Email:pengrj2018@gmail.com
Created Time :2019/9/28 14:34:12
File Name :pat1007.cpp
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
int a[maxn];
int dp[maxn],maxs,maxe,n,ansnum,flag = 1;

void make_dp(void){
	dp[0] = a[0];
	int ans = -0x3f3f3f;
	if(a[0] >=0) flag = 0;
	for(int i = 1 ; i < n ; i++){
		if(a[i] >= 0) flag = 0;
		dp[i] = max(dp[i - 1] + a[i],a[i]);
	}
	for(int i = 0 ; i < n ; i++){
		if(dp[i] > ans){
			maxe = i;
			ans = dp[i];
		}
	}
	int temp = ans;
	for(int i = maxe; i >= 0 ; i--){
		temp -= a[i];
		if(temp == 0) {
			maxs = a[i];
			maxe = a[maxe];
			ansnum = ans;
			break;
		}
	}
}

void read(void){
	cin>>n;
	for(int i = 0 ; i < n ; i++)
		cin>>a[i];
}

void write(void){
	if(flag){
		cout<<0<<' '<<a[0]<<' '<<a[n-1]<<endl;
		return;
	}
	else cout<<ansnum<<' '<<maxs<<' '<<maxe<<endl;
}

void solve(void)
{
	read();
	make_dp();
	write();
}

int main()
{
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);
	solve();
 
 	return 0;
}
