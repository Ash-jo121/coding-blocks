#include<bits/stdc++.h>
using namespace std;
int main(){
	long long int t;
	cin>>t;
	while(t--){
		long long int n;
		cin>>n;
		int countArray[n+1]={0};
		for(int i=0;i<n;i++){
			string s;
			int rank;
			cin>>s>>rank;
			countArray[rank]++;
		}
		int rank=1;
		long long int totalBadness=0;
		for(int j=1;j<=n;j++){
			while(countArray[j]>0){
				totalBadness=totalBadness+abs(rank-j);
				countArray[j]--;
				rank++;
			}
		}
		cout<<totalBadness<<"\n";
	}


	return 0;
}