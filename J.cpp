#include<bits/stdc++.h>
using namespace std;
const int py[4][2]={{0,1},{1,0},{1,1},{-1,1}};
bool valid(int x,int y){
	if(x<0||x>=19||y<0||y>=19)return false;
	else return true;
}
int main(void){
//	freopen("J.in","r",stdin);
//	freopen("J.out","w",stdout);
	int t;
	scanf("%d",&t);
	while(t--){
		int data[19][19];
		for(int i=0;i<19;i++){
			for(int j=0;j<19;j++){
				scanf("%d",&data[i][j]);
			}
		}
		int i,j;
		for(j=0;j<19;j++){
			for(i=0;i<19;i++){
				if(data[i][j]==0)continue;
				int k;
				for(k=0;k<4;k++){
					int x=i-py[k][0],y=j-py[k][1];
					if(valid(x,y)&&data[i][j]==data[x][y])continue;
					int u;
					for(u=1;u<6;u++){
						x=i+py[k][0]*u;
						y=j+py[k][1]*u;
						if(valid(x,y)&&data[i][j]==data[x][y])continue;
						else break;
					}
					if(u==6)continue;
					if(u==5)break;
				}
				if(k<4)break;
			}
			if(i<19)break;
		}
		if(j<19){
			printf("%d\n",data[i][j]);
			printf("%d %d\n",i+1,j+1);
		}else printf("0\n");
	}
	return 0;
}
