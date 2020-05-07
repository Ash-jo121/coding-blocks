#include<bits/stdc++.h>
using namespace std;
int a[101]={0};
int main(){

	int t=0;
	cin>>t;
	while(t--){
		int n=0;
		cin>>n;
		int count=0;
		int flag=0;
		int first=0;
		for(int i=0;i<n;i++){
			count++;
			int x;
			cin>>x;
			a[i]=x;
			if(first==1){
				if(a[i]==1){
					if(count>=6){
						count=0;
					}
					else{
						flag=1;
						count=0;
						break;
					}

				}
			}
			if(first==0){
				if(a[i]==1){
					count=0;
					first=1;
					continue;
				}
			}
		}
		if(flag==0){
			cout<<"YES"<<"\n";
		}
		else{
			cout<<"NO"<<"\n";
		}
	}




	return 0;
}