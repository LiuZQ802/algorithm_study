#include<bits/stdc++.h> 
using namespace std;
int joseph(int k){
	int sum=k*2;
	int m=k;
	int i=1,now=0;
	for(int j=0;j<k;j++){
		now=(now+m-1)%(sum-j);
		if(now<k){
			m++;
			now=0;
			j=-1;
		}
	}
	return m;
}
int main(void){
	queue<int> q;
	int k;
	while(~scanf("%d",&k)){
		if(k==0)break;
		q.push(k);
	}
	while(!q.empty()){
		k=q.front();
	    q.pop();
		int x=joseph(k);
		printf("%d\n",x);
	}	 
	return 0;
}

