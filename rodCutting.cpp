#include<bits/stdc++.h>
using namespace std;
int memo[100]={-1};
int maxProfit(int arr[],int totalLen){
	if(totalLen==0){
		return 0;
	}
	if(memo[totalLen]!=-1){
		return memo[totalLen];

	}
	int best=0;
	for(int len=1;len<=totalLen;len++){
		int netProfit=arr[len]+maxProfit(arr,totalLen-len);
		best=max(best,netProfit);
	}
	memo[totalLen]=best;
	return best;
}

int maxProfit_bu(int totalLen,int priceOfEachLen[]){
	int dp[100]={0};
	for(int len =1;len<=totalLen;len++){
		int best=0;
		for(int cut=1;cut<=len;cut++){
			best=max(best,arr[cut]+dp[len-cut]);
		}
		dp[len]=best;
	}
	return dp[totalLen];
}

int main(){
	int priceOfEachLen[100]={0};
	int totalLen;
	cin>>totalLen;
	for(int eachPiece = 1;eachPiece < totalLen; eachPiece++){
		cin>>priceOfEachLen[eachPiece];
	} 
	memo[100]={-1};
	//int ans=maxProfit(priceOfEachLen,totalLen);
	int ans=maxProfit_bu(totalLen,priceOfEachLen);
	cout<<ans;


	return 0;
}