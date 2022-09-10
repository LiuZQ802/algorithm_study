#include<bits/stdc++.h> 
using namespace std;
int main(void){
	int anli;
	int jieguo[anli*2];
	scanf("%d",&anli);
	for(int i=0;i<anli;i++){
			int length,num;
			scanf("%d%d",&length,&num);
			int wz[num];
			for(int j=0;j<num;j++){
				scanf("%d",&wz[j]);
			} 
			int k=min(length-wz[0],wz[0]);
			for(int j=1;j<num;j++){
				int k1=min(length-wz[j],wz[j]);
				if(k1>k){
					k=k1;
				}
			}
			jieguo[i*2]=k;
			k=max(length-wz[0],wz[0]);
			for(int j=1;j<num;j++){
				int k1=max(length-wz[j],wz[j]);
				if(k1>k){
					k=k1;
				}
			}
			jieguo[i*2+1]=k;
		}
	for(int i=0;i<anli;i++){
		printf("%d %d\n",jieguo[i*2],jieguo[i*2+1]);
	}
	return 0;
}
