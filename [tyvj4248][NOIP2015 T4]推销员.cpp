#include<bits/stdc++.h>
using namespace std;
struct node{
	int v,id;
};
struct cmp{
	bool operator()(node a,node b){
		return a.v<b.v;
	}
};
priority_queue<int> la;
priority_queue<node,vector<node>,cmp> ra;
int s[200000],a[200000],ans[200000],n;
void readit(){
	scanf("%d",&n);
	for (int i=1;i<=n;i++)
		scanf("%d",s+i);
	for (int i=1;i<=n;i++)
		scanf("%d",a+i);
}
void writeit(){
	for (int i=1;i<=n;i++)
		printf("%d\n",ans[i]);
}
void pushl(int l,int r){
	for (int i=l;i<=r;i++)
		la.push(a[i]);
}
void pushr(int l,int r){
	for (int i=l;i<=r;i++)
		ra.push((node){i,(s[i]-s[l-1])*2+a[i]});
}
void work(){
	int maxd=-1,p=-1;
	for (int i=1;i<=n;i++){
		int d=s[i]*2+a[i];
		if (d>maxd){
			maxd=d;
			p=i;
		}
	}
	ans[1]=maxd;
	pushl(1,p-1);
	pushr(p+1,n);
	for (int i=2;i<=n;i++){
		node topr;
		int tl=-1,tr=-1;
		ans[i]=ans[i-1];
		if (la.size())
			tl=la.top();
		if (ra.size()){
			topr=ra.top();
			tr=topr.v;
		}
		if (tl>tr){
			ans[i]+=tl;
			la.pop();
		}
		else{
			int pos=topr.id;
			ans[i]+=tr;
			pushl(p+1,pos-1);
			while (!ra.empty())
				ra.pop();
			pushr(pos+1,n);
			p=pos;
		}
	}
}
int main(){
	readit();
	work();
	writeit();
	return 0;
}
