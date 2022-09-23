#include<bits/stdc++.h>
using namespace std;
char name[5];
char mp[15][15];
int n,x,y;
const int py[4][2]={{1,0},{-1,0},{0,1},{0,-1}};
const int ma[8][2]={{2,-1},{2,1},{-2,-1},{-2,1},{-1,-2},{1,-2},{-1,2},{1,2}};//�ж������ȣ�ǰ����x-1,���ĸ�x+1,������y+1,�߰˸�y-1 
//�ж������ƶ����Ƿ�Ϸ� 
bool valid(int x,int y){
	if(x<=0||y<=0||x>10||y>10)return false;
	return true;
} 
//�жϺڽ��ƶ����Ƿ�Ϸ�
bool black_valid(int x,int y){
	if(y<4||y>6||x<=0||x>3)return false;
	return true;
} 
//�жϺڷ��Ƿ���Էɽ� 
bool black_fly(){
	for(int i=x+1;i<=10;i++){
		if(mp[i][y]==0)continue;
		if(mp[i][y]!='G')break;
		return true;
	}
	return false;
}
int main(void){
	//freopen("L.in","r",stdin);
	//freopen("L.out","w",stdout);
	int ok=0;
	while(~scanf("%d %d %d",&n,&x,&y)){
		if((n+x+y)==0)break;
		memset(mp,0,sizeof(mp));
		for(int i=0;i<n;i++){
			int a,b;
			scanf("%s %d %d",name,&a,&b);
			mp[a][b]=name[0];
		}
		if(black_fly())printf("NO\n");
		else{
			int t=0;  //�ж��Ƿ�ɱ����0��ʾ��ɱ����1��ʾû��ɱ�� 
			for(int i=0;i<4;i++){
				int py_x=x+py[i][0],py_y=y+py[i][1];
				if(!black_valid(py_x,py_y))continue;
				int num=0;
				
				//�жϺڽ���һ�����ܱ��ɽ��� 
				if(i==2||i==3){
					for(int j=py_x+1;j<=10;j++){
						if(num)continue;
						if(mp[j][py_y]==0)continue;
						if(mp[j][py_y]!='G')break;
						num++;
					}
				}
				if(num)continue;  //�ܱ��ɽ���������һ��
				//�жϺڽ���һ������Ա���ɱ����
				 for(int j=py_x+1;j<=10;j++){
					if(mp[j][py_y]==0)continue;
					if(mp[j][py_y]!='R')break;
					num++;	
				}
				for(int j=py_x-1;j>0;j--){
					if(num)break;
					if(mp[j][y]==0)continue;
					if(mp[j][y]!='R')break;
					num++;
				}
				for(int j=py_y+1;j<=9;j++){
					if(num)break;
					if(mp[py_x][j]==0)continue;
					if(mp[py_x][j]!='R')break;
					num++;
				}
				for(int j=py_y-1;j>9;j--){
					if(num)break;
					if(mp[py_x][j]==0)continue;
					if(mp[py_x][j]!='R')break;
					num++;
				}
				if(num)continue;  //�ڽ���һ������ܱ���ɱ��
				
				//�жϺڽ���һ����᲻�ᱻ��ɱ��
				int zjz=0;  //�Ƿ����м��� 
				for(int j=py_x+1;j<=10;j++){
					if(mp[j][py_y]==0)continue;
					if(!zjz){
						zjz++;
						continue;
					}
					if(mp[j][py_y]!='C')break;
					num++;	
				}
				for(int j=py_x-1;j>0;j--){
					if(num)break;
					if(mp[j][py_y]==0)continue;
					if(!zjz){
						zjz++;
						continue;
					}
					if(mp[j][py_y]!='C')break;
					num++;	
				}
				for(int j=py_y+1;j<=10;j++){
					if(num)break;
					if(mp[py_x][j]==0)continue;
					if(!zjz){
						zjz++;
						continue;
					}
					if(mp[py_x][j]!='C')break;
					num++;	
				}
				for(int j=py_y-1;j>0;j--){
					if(num)break;
					if(mp[py_x][j]==0)continue;
					if(!zjz){
						zjz++;
						continue;
					}
					if(mp[py_x][j]!='C')break;
					num++;	
				} 
				if(num)continue;  //�ڽ����ܱ���ɱ��
				
				//�жϺڽ����ܱ���ɱ����
				for(int j=0;j<2;j++){
					int ma_x=ma[j][0]+py_x,ma_y=ma[j][1]+py_y;
					if(!valid(ma_x,ma_y))continue;
					if(mp[ma_x][ma_y]!='H')continue;
					if(mp[ma_x-1][ma_y]!=0)continue;
					num++;
				} 
				if(num)continue;
				for(int j=2;j<4;j++){
					int ma_x=ma[j][0]+py_x,ma_y=ma[j][1]+py_y;
					if(!valid(ma_x,ma_y))continue;
					if(mp[ma_x][ma_y]!='H')continue;
					if(mp[ma_x+1][ma_y]!=0)continue;
					num++;
				} 
				if(num)continue;
				for(int j=4;j<6;j++){
					int ma_x=ma[j][0]+py_x,ma_y=ma[j][1]+py_y;
					if(!valid(ma_x,ma_y))continue;
					if(mp[ma_x][ma_y]!='H')continue;
					if(mp[ma_x][ma_y+1]!=0)continue;
					num++;
				} 
				if(num)continue;
				for(int j=6;j<8;j++){
					int ma_x=ma[j][0]+py_x,ma_y=ma[j][1]+py_y;
					if(!valid(ma_x,ma_y))continue;
					if(mp[ma_x][ma_y]!='H')continue;
					if(mp[ma_x+1][ma_y-1]!=0)continue;
					num++;
				}
				if(num)continue; 	
				//�����ܱ�ɱ�� 
				printf("NO\n");
				t=1;
				break;	
			}
			if(!t)printf("YES\n");
		}
	} 
	return 0;
} 
