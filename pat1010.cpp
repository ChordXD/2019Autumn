/* ***********************************************
Author :Chord
Email:pengrj2018@gmail.com
Created Time :2019/10/2 22:28:21
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
#include <iomanip>
using namespace std;
typedef long long ll;
const int maxn = 1e5 + 7;
#define EPS 1e-9
/*change str to dex and return */
ll changToDex(string str,ll jz){
	ll ans = 0,t = 1;
	int n = str.length();
	for(int i = n - 1 ; i >= 0 ; i--){
		if(str[i] >= '0' && str[i]<='9')
			ans += (str[i] - '0') * t;
		else 
			ans += (str[i] - 'a' + 10) * t;
		t*=jz;
		if(ans < 0LL) return -1LL;
	}
	return ans;
}

ll getLast(string str){
	int n = str.length();
	char ans = -1;
	for(int i = 0 ; i < n ; i++){
		if(str[i] > ans) ans = str[i];
	}
	if(ans >= '0' && ans <= '9')
		return ans -'0' + 1LL;
	return ans -'a' + 11LL;
}

ll minAns = 0x3f3f3f;
void BinarySearch(ll adex,string bstr){
	ll l = getLast(bstr) ,r = 9999999999999999LL;
	while(l <= r){
		ll mid = (l+r) >> 1LL;
		ll bdex = changToDex(bstr,mid);
		if(bdex == adex){
		 	minAns = min(minAns,mid);
			r = mid - 1;
		}
		else if(bdex > adex || bdex == -1LL)
			r = mid - 1LL;
		else l = mid + 1LL;
	}
}

void solve(void){
	string a = "",b = "";
	int mod,jz;
	cin>>a>>b>>mod>>jz;
	if(mod == 2) swap(a,b);
	ll adex = changToDex(a,jz);
	BinarySearch(adex,b);
	if(minAns == 0x3f3f3f) cout<<"Impossible"<<endl;
	else cout<<minAns<<endl;
}

int main()
{
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);
	solve();
 	return 0;
}
