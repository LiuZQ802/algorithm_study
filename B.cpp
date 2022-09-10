#include<bits/stdc++.h> 
using namespace std;
const int MAX=1000001;
const int t=500000;
int arry[MAX];
int main(void){
	int a,m,n;
	memset(arry,0,sizeof(arry));
	while(~scanf("%d %d",&n,&m)){
		for(int i=0;i<n;i++){
			scanf("%d",&a);
			arry[t+a]++;
		}
		for(int i=MAX;i>=0;i--){
			while(arry[i]){
				if(m){
					printf("%d ",i-t);
					arry[i]--;
					m--;
				}else break;
			}
		}
	}
	return 0;
}
