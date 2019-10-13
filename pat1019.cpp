/* ***********************************************
Author :Chord
Email:pengrj2018@gmail.com
Created Time :2019/10/13 18:43:20
File Name :pat1019.cpp
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

vector<int> changeBase(int num,int base){
	vector<int>ans;
	while(num > 0){
		int t = num % base;
		num /= base;
		ans.push_back(t);
	}
	return ans;
}

bool check(vector<int>ans){
	int n = (int)ans.size();
	for(int i = 0 ; i < n ; i++){
		if(ans[i] != ans[n - i - 1])
			return false;
	}
	return true;
}

void solve(void){
	int t,base;
	cin>>t>>base;
	auto ans = changeBase(t,base);
	if(check(ans)) cout<<"Yes"<<endl;
	else cout<<"No"<<endl;
	int n = (int)ans.size();
	for(int i = n-1 ; i >= 0 ; i--){
		cout<<ans[i];
		if(i == 0) cout<<'\n';
		else cout<<' ';
	}
}

int main()
{
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);
	solve();
 
 	return 0;
}
