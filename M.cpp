#include<bits/stdc++.h>
using namespace std;
int main(void){
	//freopen("M.in","r",stdin);
	//freopen("M.out","w",stdout);
	//1个6，1个5+11个1，1个4+5个2 / 1个4+20个1，4个3，9个2，36个1。3=2+5*1
	int a[7];
	while(~scanf("%d %d %d %d %d %d",&a[0],&a[1],&a[2],&a[3],&a[4],&a[5])){
		if(a[1]==0&&a[2]==0&&a[3]==0&&a[4]==0&&a[5]==0)break;
		int num=0;
		while(a[5]){
			a[5]--;
			num++;
		}
		while(a[4]){
			a[4]--;
			for(int i=0;i<11;i++){
				if(a[0])a[0]--;
				else break;
			}
			num++;
		}
		while(a[3]){
			a[3]--;
			int i;
			for(i=0;i<5;i++){
				if(a[1])a[1]--;
				else break;
			}
			for(int j=0;j<(4*(5-i));j++){
				if(a[0])a[0]--;
				else break;
			}
			num++;
		}
		while(a[2]){
			while(a[2]>=4){
				a[2]-=4;
				num++;			
			}
			if(a[2]==0)break;
			if(a[2]==1){
				int i;
				for(i=0;i<5;i++){
					if(a[1])a[1]--;
					else break;
				}
				for(int j=0;j<7+4*(5-i);j++){
					if(a[0])a[0]--;
					else break;
				}
				num++;
				a[2]--;
			}else if(a[2]==2){
				int i;
				for(i=0;i<3;i++){
					if(a[1])a[1]--;
					else break;
				}
				for(int j=0;j<6+4*(3-i);j++){
					if(a[0])a[0]--;
					else break;
				}
				num++;
				a[2]-=2;
			}else if(a[2]==3){
				int i;
				for(i=0;i<1;i++){
					if(a[1])a[1]--;
					else break;
				}
				for(int j=0;j<5+4*(1-i);j++){
					if(a[0])a[0]--;
					else break;
				}
				num++;
				a[2]-=3;
			}
		}
		while(a[1]){
			while(a[1]>=9){
				a[1]-=9;
				num++;
			}
			if(a[1]==0)break;
			a[1]=0;
			for(int i=0;i<4*(9-a[1]);i++){
				if(a[0])a[0]--;
				else break;
			}
			num++;
		}
		while(a[0]){
			if(a[0]%36==0){
				int t=a[0]/36;
				num+=t;
			}else{
				int t=a[0]/36;
				num=num+t+1;
			}
		}
		printf("%d\n",num);
	} 
} 
