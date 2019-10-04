/* ***********************************************
Author :Chord
Email:pengrj2018@gmail.com
Created Time :2019/9/27 20:57:55
File Name :e:\2019Autumn\pat1005.cpp
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
ll sum;

void read(void){
	char c;
	while(c = getchar(),c!='\n'&&c!=EOF){
		sum += (ll)(c - '0');
	}
}

void write(void){
	stack<string>ans;
	if(sum == 0) {
		cout<<"zero"<<endl;
		return ;
	}
	while( sum > 0LL ){
		ll now = sum % 10LL;
		sum /= 10LL;
		switch (now) {
			case 0LL : ans.push("zero");
					 break;
			case 2LL : ans.push("two");
					 break;
			case 3LL : ans.push("three");
					 break;
			case 4LL : ans.push("four");
					 break;
			case 5LL : ans.push("five");
					 break;
			case 6LL : ans.push("six");
					 break;
			case 7LL : ans.push("seven");
					 break;
			case 8LL : ans.push("eight");
					 break;
			case 9LL : ans.push("nine");
					 break;
			default : ans.push("one");
		};
	}
	
	while(!ans.empty()){
		cout<<ans.top();
		ans.pop();
		if(ans.empty())
			cout<<endl;
		else cout<<' ';
	}
}
void solve(void)
{

	 read();
	 write();
}

int main()
{
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);
	solve();
 
 	return 0;
}
