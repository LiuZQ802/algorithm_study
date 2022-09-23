#include<bits/stdc++.h>
using namespace std;
int main(void){
	//freopen("Q.in","r",stdin);
	//freopen("Q.out","w",stdout);
	long long int A,L;
	int num=0;
	while(scanf("%lld %lld",&A,&L)&&(A+L)!=-2){
		int sum=0;
		int a=A;
		num++;
		while(a<=L){
			if(a==1){
				sum++;
				break;
			}
			else if(a%2==0)a=a/2;
			else a=3*a+1;
			sum++;
		}
		printf("Case %d: A = %d, limit = %d, number of terms = %d\n",num,A,L,sum);
	}
	return 0;
} 
