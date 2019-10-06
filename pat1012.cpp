/* ***********************************************
Author :Chord
Email:pengrj2018@gmail.com
Created Time :2019/10/4 11:50:36
File Name :pat1012.cpp
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

typedef struct{
	string id;
	int C,M,E,A;
	void getA(){
		A = (M + C + E) / 3;
	}
}student;

student a[maxn];
map<string,int>haStudent;
int rankNumC[200],rankNumM[200],rankNumE[200],rankNumA[200];
int rankC[200],rankM[200],rankE[200],rankA[200];

void solve(void){
	int n,m;
	cin>>n>>m;
	for(int i = 1 ; i <= n ; i++){
		cin>>a[i].id>>a[i].C>>a[i].M>>a[i].E;
		haStudent[a[i].id] = i;
		a[i].getA(); 
		rankNumC[a[i].C]++;
		rankNumE[a[i].E]++;
		rankNumM[a[i].M]++;
		rankNumA[a[i].A]++;
	}
	int nowRankC = 1,nowRankM = 1,nowRankE = 1,nowRankA = 1;
	for(int i = 100 ; i >= 0 ; i--){
		if(rankNumC[i] != 0){
			rankC[i] = nowRankC;
			nowRankC += rankNumC[i];
		}
		if(rankNumE[i] != 0){
			rankE[i] = nowRankE;
			nowRankE += rankNumE[i];
		}
		if(rankNumM[i] != 0){
			rankM[i] = nowRankM;
			nowRankM += rankNumM[i];
		}
		if(rankNumA[i] != 0){
			rankA[i] = nowRankA;
			nowRankA += rankNumA[i];
		}
	}
	
	while(m--){
		string f;
		cin>>f;
		int id = haStudent[f];
		if(!id)
			cout<<"N/A"<<endl;
		else{
			int sC = rankC[a[id].C],sE = rankE[a[id].E],sM = rankM[a[id].M],sA = rankA[a[id].A];
			int bestRank = sA;
			char bestRankC = 'A';
			if(sC < bestRank){
				bestRank = sC;
				bestRankC = 'C';
			}
			if(sM < bestRank){
				bestRank = sM;
				bestRankC = 'M';
			}
			if(sE < bestRank){
				bestRank = sE;
				bestRankC = 'E';
			}
			cout<<bestRank<<' '<<bestRankC<<endl;
		}
	}
}

int main()
{
	freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);
	solve();
 
 	return 0;
}
