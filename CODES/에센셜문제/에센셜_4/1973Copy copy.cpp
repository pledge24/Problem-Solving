#include<bits/stdc++.h>
using namespace std;
vector<pair<int,int>>vec[20200];
priority_queue<pair<int,int>>pq;
int V,E,K,cost[20200],vst[20200];
void djk(int k){
	pq.push({0,k});
	while(!pq.empty()){
		auto [a,b]=pq.top();
		pq.pop();
		if(vst[b]){
			continue;
		}
		vst[b]=1;
		cost[b]=-a;
		for(auto i:vec[b]){
			pq.push({a+i.second,i.first});
		}
	}
}
int main(){
	cin.tie(0);
	ios::sync_with_stdio(0);
	cin>>V>>E>>K;
	for(int i=0;i<E;i++){
		int u,v,w;
		cin>>u>>v>>w;
		vec[u].push_back({v,-1*w});
	}
	djk(K);
	for(int i=1;i<=V;i++){
		if(vst[i]==0){
			cout<<"INF"<<'\n';
			continue;
		}
		cout<<cost[i]<<'\n';
	}
}