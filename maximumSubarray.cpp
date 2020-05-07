#include<bits/stdc++.h>
using namespace std;
int maxSubarray(int arr[],int n){
	int dp[100]={0};
	dp[0]=arr[0]>0?arr[0]:0;
	int max_so_far=0;
	for(int i=1;i<n;i++){
		dp[i]=dp[i-1]+arr[i];
		if(dp[i]<0){
			dp[i]=0;
		}
		max_so_far=max(max_so_far,dp[i]);
	}
	return max_so_far;
}

int main(){

	int arr[]={-3,2,5,-1,6,3,-2,7,-5,2};
	int n=sizeof(arr)/sizeof(int);
	int ans=maxSubarray(arr,n);
	return 0;
}