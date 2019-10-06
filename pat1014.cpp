/* ***********************************************
Author :Chord
Email:pengrj2018@gmail.com
Created Time :2019/10/5 12:27:36
File Name :pat1014.cpp
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
const int maxn = 1e4 + 7;
#define EPS 1e-9
int ans[maxn],N,M,K,Q,cusNow = 1;
typedef struct{
	int id,Time;
}cus;
cus cusInf[maxn];

queue<cus>q[30];

void solve(void){
	cin>>N>>M>>K>>Q;
	for(int i = 1 ; i <= K ; i++ ){
		cin>>cusInf[i].Time;
		cusInf[i].id = i;
	}
	int endTime = 60 * 9,nowTime = 0,pushIndex = 1;
	for(int i = 1 ; i <= N*M && i <= K; i++){
		q[pushIndex].push(cusInf[i]);
		pushIndex++;
		cusNow++;
		pushIndex = pushIndex > N ? 1 : pushIndex;
	}
	while(nowTime < endTime){
		//find mind Time 
		int minQueueIndex = 0,minQueueTime = 0x3f3f3f3f;
		for(int i = 1 ; i <= N ; i++){
			if(!q[i].empty() && q[i].front().Time < minQueueTime){
				minQueueTime = q[i].front().Time;
				minQueueIndex = i;
			}
		}
		if(minQueueIndex == 0) break;   
		//updata Time 
		nowTime += minQueueTime;
		//if(nowTime > endTime) break;
		ans[q[minQueueIndex].front().id] = nowTime;
		q[minQueueIndex].pop();
		if(cusNow <= K)
			q[minQueueIndex].push(cusInf[cusNow++]);
		
		// updata queue 
		for(int i = 1 ; i <= N ; i++){
			if(i == minQueueIndex || q[i].empty()) continue;
			if(nowTime >= endTime){
				if(!q[i].empty())
					ans[q[i].front().id] = nowTime + q[i].front().Time - minQueueTime;
				continue;
			}
			
			q[i].front().Time -= minQueueTime;
			auto p = q[i].front();
			if(p.Time == 0){		//if somebody has same minQueueTime 
									//pop it and make one into his queue 
				q[i].pop();
				if(cusNow <= K){
					q[i].push(cusInf[cusNow++]);
				}
				ans[p.id] = nowTime;
			}
		}
	}
	while(Q--){
		int Index;
		cin>>Index;
		if(ans[Index] == 0)
			cout<<"Sorry"<<endl;
		else{
			int h = ans[Index] / 60 + 8;
			int min = ans[Index] % 60; 
			cout<<fixed<<setw(2)<<setfill('0')<<h<<':'<<setw(2)<<setfill('0')<<min<<endl;
		}
	}
}

int main()
{
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);
	solve();
 
 	return 0;
}
