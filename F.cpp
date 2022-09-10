#include<bits/stdc++.h> 
using namespace std;
int main(void){
	int M;
	while(~scanf("%d",&M)){
		int num[M];
		for(int i=0;i<M;i++){
			scanf("%d",&num[i]);
		}
		int t,f=num[0];
		for(int i=1;i<M;i++){
			t=f^num[i];
			f=t;
		}
		if(f==0){
			printf("No\n");
		}else{
			printf("Yes\n");
		}
	}
	
	return 0;
}
