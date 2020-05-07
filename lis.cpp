#include<bits/stdc++.h>
using namespace std;

int lis(int arr[],int n){
	int dp[100]={1};
	for(int i=1;i<n;i++){
		int maxLen=0;
		for(int j=0;j<i;j++){
			if(arr[i]>=arr[j]){
				int curLen=1+dp[j];
			}
			int maxLen=max(maxLen,curLen);
		}
		dp[i]=maxLen;

	}

}


int main(){
	int arr[]={10,22,9,33,21,50,41,60,80};
	int size=sizeof(arr)/sizeof(int);
	int ans=lis(arr,n);
	cout<<ans<<"\n";
	return 0;
}