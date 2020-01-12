#include<bits/stdc++.h>
const int p[5]={11261,14843,19997,21893,22877};
char str[10000];
bool flag[5][30000];
int a[5][200],ans[2000000],n,m,tot=0;
using namespace std;
void readit(){
	scanf("%d%d",&n,&m);
	for (int i=0;i<=n;i++){
		scanf("%s",str);
		int len=strlen(str);
		bool flag=0;
		for (int j=0;j<5;j++)
			if (str[0]=='-') flag=1;
			else a[j][i]=str[0]-48;
		for (int j=0;j<5;j++){
			for (int k=1;k<len;k++)
				a[j][i]=(a[j][i]*10+str[k]-48)%p[j];
			if (flag) a[j][i]=-a[j][i];
		}
	}
}
void writeit(){
	printf("%d\n",tot);
	for (int i=1;i<=tot;i++)
		printf("%d\n",ans[i]);
}
void work(){
	for (int i=0;i<5;i++)
		for (int j=1;j<p[i];j++){
			int sum=0;
			for (int k=n;k>=0;k--)
				sum=(sum*j%p[i]+a[i][k])%p[i];
			flag[i][j]=(bool)sum;
		}
	for (int i=1;i<=m;i++){
		bool f=1;
		for (int j=0;j<5;j++)
			if (flag[j][i%p[j]]){
				f=0;
				break;
			}
		if (f) ans[++tot]=i;
	} 
}
int main(){
	readit();
	work();
	writeit();
	return 0;
}
