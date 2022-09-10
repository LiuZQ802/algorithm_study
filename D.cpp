#include<bits/stdc++.h> 
using namespace std;
int M[4122];
int main(void){
	int y,k,j=0;
	memset(M,0,sizeof(M));
	while(~scanf("%d",&y)){
		if(y==0)break;
		M[j++]=y;
	}
	j=0;
	while(M[j]!=0){
		int m=(M[j]-1940)/10;
		m=m*m;
		double max=m*log(2); 
		double t=0;
		int i=1;
		for(i;t<max;i++){
			t+=log(i);
		} 
		printf("%d\n",i-2);
		j++;
	}
	return 0;
}
