/* ***********************************************
Author :Chord
Email:pengrj2018@gmail.com
Created Time :2019/9/30 14:06:32
File Name :pat1010.cpp
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

ll changToDec(string str,int aim){
	int n = (int)str.length();
	ll ans = 0,base = 1;
	for(int i = n - 1 ; i >= 0 ; i-- ){
		int num;
		if(str[i] <= '9' && str[i] >= '0')
			num = str[i] - '0';
		else
			num = str[i] - 'a' + 10;
		ans += num * num;
		base *= aim;
	}
	return ans;
}

pair<bool,ll> check(ll aim,string a,int radix){
	ll ans = changToDec(a,radix);
	if(aim == ans) return make_pair(true,ans);
	else return make_pair(false,ans);
}

void read(void){
	string a,b;
	int tag,radix;
	cin>>a>>b>>tag>>radix;
	ll ans1,ans2 = 0;
	if(tag == 2) swap(a,b);
	ans1 = changToDec(a,radix);
	for(int i = 2 ; ans2 < ans1 ; i++){
		auto tans = check(ans1,b,i);
		if(tans.first){
			cout<<i<<endl;
			return;
		}
		ans2 = tans.second;
	}
}

void solve(void)
{
	read(); 
}

int main()
{
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);
	solve();
 
 	return 0;
}
