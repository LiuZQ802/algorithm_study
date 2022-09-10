#include<bits/stdc++.h>
using namespace std;
//判断胜负 
int pb(int id_1,char case_1,int id_2,char case_2){
	if('r'==case_1){
		if('r'==case_2){
			return 0; //代表平局 
		}else if('s'==case_2){
			return id_1;
		}else if('p'==case_2){
			return id_2;
		}
	}else if('s'==case_1){
		if('r'==case_2){
			return id_2;
		}else if('s'==case_2){
			return 0;
		}else if('p'==case_2){
			return id_1;
		}
	}else if('p'==case_1){
		if('r'==case_2){
			return id_1;
		}else if('s'==case_2){
			return id_2;
		}else if('p'==case_2){
			return 0;
		}
	}
	return 0;
}
int main(void){
	//freopen("H.in","r",stdin);
	//freopen("H.out","w",stdout); 
	int n,k,op=0;
	while(~scanf("%d%d",&n,&k)){
		if(n==0)break;
		if(op++)printf("\n");
		double q[n]; 
		int win_nums[n+1];  //每位选手赢得比赛次数的数组 
		int lose_nums[n+1];//每位选手输的比赛次数 
		memset(win_nums,0,sizeof(win_nums));  
		memset(lose_nums,0,sizeof(lose_nums));
		for(int i=0;i<k*n*(n-1)/2;i++){
			int id_1,id_2;
			char case_1[10],case_2[10];
			scanf("%d %s %d %s",&id_1,case_1,&id_2,case_2);
			int t=pb(id_1,case_1[0],id_2,case_2[0]);
			if(t==id_1){ 
				win_nums[id_1]++;
				lose_nums[id_2]++;
			}else if(t==id_2){
				win_nums[id_2]++;
				lose_nums[id_1]++;
			}
		}
		for(int i=1;i<=n;i++){
			double p;
			if(win_nums[i]+lose_nums){
				p=(double)win_nums[i]/(double)(win_nums[i]+lose_nums[i]); 
				printf("%.3f\n",p);
			}else{
				printf("-\n"); 
			}
		} 
	}	
	return 0;
}
