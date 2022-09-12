#include<bits/stdc++.h>
using namespace std;
int main(void){
	//freopen("I.in","r",stdin);
	//freopen("I.out","w",stdout);
	int T;
	scanf("%d",&T);
	for(int i=0;i<T;i++){
		long long m,n,p,sum=0;
		scanf("%lld %lld %lld",&n,&m,&p);
		long long team[n+1];
		long long nohappy[n+1];
		for(int i=1;i<=n;i++){
			scanf("%lld",&team[i]);
		}
		long long ans=1e18;
		for(int i=1;i<=p;i++){
			long long x,y;
			scanf("%lld %lld",&x,&y);
			nohappy[i]=(team[x]+m-1-y)%m;
			sum+=nohappy[i];       
		}
		sort(nohappy+1,nohappy+p+1);
		for(int i=1;i<=p;i++){
			ans=min(ans,sum-(p-i+1)*nohappy[i]+(m-nohappy[i])*(i-1));
		}
		printf("%lld\n",ans);
	}
	return 0;
} 
