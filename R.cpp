#include<bits/stdc++.h>
using namespace std;
int main(void){
	//freopen("R.in","r",stdin);
	//freopen("R.out","w",stdout);
	int N;
	while(scanf("%d",&N)&&N){
		string card[N],word[N];
		int order[N];
		for(int i=0;i<N;i++){
			cin>>card[i]>>word[i];
			order[i]=-1;
		}
		for(int i=0,j=0;i<N;i++){
			int k=word[i].length();
			for(k;;j=(j+1)%N){
				if(order[j]==-1&&--k==0)break;
			}
			order[j]=i;
		}
		for(int i=0;i<N;i++){
			if(i!=0)cout<<" ";
			cout<<card[order[i]];
		}
		cout<<endl;
	}
	return 0;
}
