#include<bits/stdc++.h>
using namespace std;
#define ll long long
vector<ll>v;
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t=0;
	scanf("%d",&t);
	while(t--){
		ll n=0;
		scanf("%lld",&n);
		v.clear();
		for(ll i=0;i<n;i++){
			ll x=0;
			scanf("%lld",&x);
			v.push_back(x);
		}
		sort(v.begin(),v.end(),greater<ll>());
		//cout<<v[0]<<" "<<v[1]<<"\n";
		ll s=0;
		for(ll i=0;i<n;i++){
			ll x=0;
			x=v[i]-i;
			if(x<0){
				x=0;
			}
			s=s+x;
		}
		printf("%lld\n",s%1000000007);
	}



	return 0;
}