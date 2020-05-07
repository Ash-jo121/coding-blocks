#include<bits/stdc++.h>
using namespace std;
struct tasks{
	int s,e;
};
bool compare(tasks a,tasks b){
	return a.e>=b.e;
}
int busyMan(int n,tasks a[]){
	sort(a , a + n,compare);
	int count=1;
	int ending=a[0].e;
	for(int i=1;i<n;i++){
		//top element of structure add it
		if(a[i].s>=ending){
			count++;
			ending=a[i].e;
		}
	}
	return count;
}
int main(){
	int t;
	cin>>t;
	while(t--){
		int n;
		tasks task[n];
		int i=0; 
		while(n--){
			cin>>task[i++].s>>task[i++].e;
		}
		cout<<busyMan(n,task)<<"\n";
	}
	return 0;
}