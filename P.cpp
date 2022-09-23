#include<bits/stdc++.h>
using namespace std;
int main(void){
	//freopen("P.in","r",stdin);
	//freopen("P.out","w",stdout);
	int n;
	while(~scanf("%d",&n)){
		int sum=n;
		while(n>=3){
			int t=n/3;
			sum+=t;
			n=n-t*3+t;
		}
		if(n==2)sum++;
		printf("%d\n",sum);
	}
	return 0;
}
