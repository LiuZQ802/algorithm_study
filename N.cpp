#include<bits/stdc++.h>
using namespace std;
int ncuts(int a,int b,int c,int d,int e,int f){
	if(a*c>e||b*d>f)return INT_MAX;
	return a*b-1+(a*c<e)+(b*d<f);
}
void do_solve(int a,int b,int c,int d,int e,int f){
	int x,m;
	m=ncuts(a,b,c,d,e,f);
	if((x=ncuts(b,a,c,d,e,f))<m)m=x;
	if((x=ncuts(a,b,d,c,e,f))<m)m=x;
	if((x=ncuts(b,a,d,c,e,f))<m)m=x;
	if(m==INT_MAX)printf("The paper is too small.\n");
	else printf("The minimum number of cuts is %d.\n",m);
}
int main(void){
	freopen("N.in","r",stdin);
	freopen("N.out","w",stdout);
	int a,b,c,d,e,f;
	while(1){
		scanf("%d%d%d%d%d%d",&a,&b,&c,&d,&e,&f);
		if((a+b+c+d+e+f)==0)break;
		do_solve(a,b,c,d,e,f);
	}
	return 0;
} 
