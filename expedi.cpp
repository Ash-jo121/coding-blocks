#include<bits/stdc++.h>
using namespace std;
bool compare(pair<int,int>p1,pair<int,int>p2){
	return p1.first>p2.first;
}


int main(){
	int t,n,d,f,D,F,tx,prev=0;
	cin>>t;
	while(t--){
		vector<pair<int,int>>v;
		priority_queue<int>pq;
		cin>>n;
		for (int i = 0; i < n; i++)
		{
			cin>>d>>f;
			v.push_back(make_pair(d,f));
		}
		//Logic
		sort(v.begin(),v.end(),compare);

		cin>>D>>F;

		for(int i=0;i<n;i++){
			v[i].first=D-v[i].first;
		}





	}





	return 0;
}