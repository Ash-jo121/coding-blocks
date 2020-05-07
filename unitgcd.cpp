#include<bits/stdc++.h>
using namespace std;
#define MAX 100001 
#define ll long long
  
// prime[] for storing smallest prime divisor of element 
// count[] for storing the number of times a particular 
// divisor occurs in a subsequence 
int prime[MAX], countdiv[MAX]; 
ll divisor[MAX]={0};
ll visited[MAX]={0};
ll n=0,ct=0;
vector<ll>v;
// Simple sieve to find smallest prime factors of numbers 
// smaller than MAX 
void SieveOfEratosthenes() 
{ 
    for (int i = 2; i * i <= MAX; ++i) 
    { 
        if (!prime[i]) 
            for (int j = i * 2; j <= MAX; j += i) 
                prime[j] = i; 
    } 
  
    // Prime number will have same divisor 
    for (int i = 1; i < MAX; ++i) 
        if (!prime[i]) 
            prime[i] = i; 
} 
// Returns length of the largest subsequence 
// with GCD more than 1. 

void unitgcd(){
	ct=0;
	visited[MAX]={0};
	//cout<<divisor[1]<<" "<<divisor[2]<<" ";
	//cout<<visited[1]<<" "<<visited[2];
	for(int k=0;k<=n;k++){
		visited[k]=0;
	}
	while(ct<=n){
		v.clear();
		divisor[MAX]={0};
		for(int k=0;k<=n;k++){
			divisor[k]=0;
		}
		for(ll i=1;i<=n;i++){
			int flag=0;
			cout<<"hey jude";
			cout<<visited[i]<<"hellofucker";
			if(visited[i]==1){
				continue;
			}
			ll element = i;
			while(element > 1){
				int div = prime[element];
				cout<<"i value is "<<i;
				cout<<"cet"<<divisor[div]<<div;
				if(divisor[div] > 0){
					flag=1;
					break;
				}
				while(element % div==0){
					element /= div; 
				}
			}
			if(flag==0){
				cout<<"Ashish";
				v.push_back(i);
				//cout<<"hello";
				cout<<v[0]<<"helloashish";
				visited[i]=1;
				ct++;
				int newElement = i;
				while(newElement > 1){
					int div = prime[newElement];
					divisor[div]++;
					while(newElement % div==0){
						newElement /= div; 
					}
				}
				if(newElement==1){
					divisor[newElement]++;
				}
			}
			//cout<<"hello";
			cout<<divisor[i]<<" ashishjohn";
		}
		cout<<v.size()<<" ";
		for(int j=0;j<v.size();j++){
			cout<<v[j]<<" ";
		}
		cout<<"\n";
	}
	
} 
int main(){
	SieveOfEratosthenes();
	cin>>n;
	//cout<<divisor[1]<<" "<<divisor[2]<<" "<<divisor[3];
	unitgcd();
	return 0;
}