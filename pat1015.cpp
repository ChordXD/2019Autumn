/* ***********************************************
Author :Chord
Email:pengrj2018@gmail.com
Created Time :2019/10/5 20:11:17
File Name :pat1015.cpp
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

bool isPrime[maxn];

void checkPrime(void){
	fill(isPrime,isPrime + maxn,true);
	isPrime[0] = isPrime[1] = 0;
	for(int i = 2 ; i * i < maxn ; i++){
		if(isPrime[i]){
			for(int j = i*i ; j < maxn ; j+=i)
				isPrime[j] = false;
		}
	}
}

int myPower(int a,int b){
	if(b == 0) return 1;
	int t = a;
	for(int i = 2 ; i <= b ; i++)
		a*=t;
	return a;
}

int changeToDex(string str,int radix){
	int n = str.length();
	int ans = 0,t = 0;
	for(int i = n - 1 ; i >= 0 ; i--){
		ans += (str[i] - '0') * myPower(radix,t);
		t++;
	}
	return ans;
}

string myReserve(int num,int radix){
	string ans = "";
	while(num > 0){
		ans += (num % radix) + '0';
		num /= radix;
	}
	return ans;
}

void solve(void){
	int a;
	checkPrime();
	while(cin>>a,a >= 0){
		int rdx;
		cin>>rdx;
		int aa = changeToDex(myReserve(a,rdx),rdx);
		if(isPrime[a] && isPrime[aa])
			cout<<"Yes"<<endl;
		else cout<<"No"<<endl;
	}
}

int main()
{
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);
	solve();
 
 	return 0;
}
