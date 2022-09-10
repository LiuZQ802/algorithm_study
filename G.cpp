#include<bits/stdc++.h>
using namespace std;
int main(void){
	queue<string>q;
	string temp;
	getline(cin,temp);
	while("ENDOFINPUT"!=temp){
		if("START"==temp){
			getline(cin,temp);
			q.push(temp);
		}
		getline(cin,temp);
	}
	while(!q.empty()){
		temp=q.front();
		q.pop();
		for(int i=0;i<temp.length();i++){
			int x=temp[i];
			if(x>=65&&x<=69){
				x=90+x-65-4;
				string s(1,x);
				temp.replace(i,1,s);
			}else if(x>=70&&x<=90){
				x=x-5;
				string s(1,x);
				temp.replace(i,1,s);
			}
		}
		cout<<temp<<endl;
	}
	return 0;
} 
