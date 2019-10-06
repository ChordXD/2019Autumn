<<<<<<< HEAD
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
=======
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
>>>>>>> 863703f6d53767d4532f2bcfe36cd609aa47e6c2
