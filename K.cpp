#include<bits/stdc++.h>
using namespace std;
int main(void){
//	freopen("K.in","r",stdin);
//	freopen("K.out","w",stdout);
	int n,t=0;
	while(~scanf("%d",&n)){
		if(n==0)break;
		if(t++)printf("\n");
		char name[n+1][30];
		map<string,int> que;
		int a[n],b[n],cnt[n+1];
		memset(cnt,0,sizeof(cnt));
		que.clear();
		for(int i=1;i<=n;i++){
			scanf("%s",&name[i]);
			que[name[i]]=i;
		}
		char s[1000];
		int p;
		for(int i=1;i<n;i++){
			scanf("%s",&s);
			p=que[s];
			a[i]=p;
			cnt[p]++;
			scanf("%s",&s);
			p=que[s];
			b[i]=p;
			cnt[p]++;
		}
		bool flag[n+1];
		int lc=1,now=0,tm=n,k=n/2;
		memset(flag,1,sizeof(flag));
		while(tm>1){
			for(int i=1;i<n;i++){
				if(flag[a[i]]&&flag[b[i]]&&((cnt[a[i]]==1)||(cnt[b[i]]==1))){
					if(now==0)printf("Round #%d\n",lc);
					now++;
					tm--;
					cnt[a[i]]--;
					cnt[b[i]]--;
					if(cnt[a[i]])printf("%s defeats %s\n",name[a[i]],name[b[i]]);
					else if(cnt[b[i]])printf("%s defeats %s\n",name[b[i]],name[a[i]]);
					else{
						printf("%s defeats %s\n",name[b[i]],name[a[i]]);
						printf("Winner: %s\n",name[b[i]]);
					}
					flag[a[i]]=false;
					flag[b[i]]=false;
					if(now==k){
						now=0;
						k=tm/2;
						lc++;
						for(int i=1;i<=n;i++){
							if(flag[i]&&cnt[i])printf("%s advances with wildcard\n",name[i]);
							if(cnt[i])flag[i]=true;
							else flag[i]=false;
						}
					}
				}
			}
		}
	}
	printf("\n");
	return 0;
}
