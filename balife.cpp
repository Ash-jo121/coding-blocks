#include<bits/stdc++.h>
using namespace std;
int main(){
	while(true){
		int n;
		cin>>n;
		int arr[n]={0};
		int totalSum=0;
		for(int i=0;i<n;i++){
			cin>>arr[i];
			totalSum=totalSum+arr[i];
		}
		int target=totalSum/n;
		int count=1;
		int sum1=0,sum2=totalSum;
		int target1,target2;
		int maxArray[n-1]={0};
		for(count=1;count<=n-1;count++){
			target1=count*target;
			target2=(n-count)*target;
			sum1=sum1+arr[count-1];
			sum2=sum2-arr[count-1];
			int import=abs(sum1-target1);
			maxArray[count-1]=import;
		}
		int ans=0;
		for(int k=0;k<n-1;k++){
			ans=max(maxArray[k],ans);
		}
		cout<<ans<<"\n";
	}

	return 0;
}