#include<bits/stdc++.h> 
using namespace std;
int main(void){
	//freopen("O.in","r",stdin);
	//freopen("O.out","w",stdout);
	string str1,str2;
	while(cin>>str1&&str1!="#"){
		int sum=0;
		while(str1!="0"){
			int mile;
			char n;
			cin>>str2>>mile>>n;
			switch(n){
				case 'F':sum+=(mile*2);break;
				case 'B':sum+=(mile*1.5);break;
				case 'Y':if(mile<500)sum+=500;
						 else sum+=mile;break;
				default:break;
			}
			cin>>str1;
		}
		printf("%d\n",sum);
	}
	
	return 0;
}
