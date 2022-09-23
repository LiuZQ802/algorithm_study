#include<bits/stdc++.h>
using namespace std;
int main(void){
	freopen("S.in","r",stdin);
	freopen("S.out","w",stdout);
	int n;
	while(scanf("%d",&n)&&n){
		queue<int>q;
		for(int i=1;i<=n;i++)q.push(i);
		printf("Discarded cards:");
		int flag=0;
		while(q.size()>1){
			int t=q.front();
			q.pop();
			if(!flag){
				printf(" %d",t);
				flag=1;
			}
			else printf(", %d",t);
			q.push(q.front());
			q.pop();
		}
		int t=q.front();
		q.pop();
		printf("\nRemaining card: %d\n",t); 
	}
	return 0;
}
