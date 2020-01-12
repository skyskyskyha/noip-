#include<bits/stdc++.h>
using namespace std;
int sum[2][200000],cnt[2][200000],val[200000],c[200000],n,m,ans=0;
void readit(){
	scanf("%d%d",&n,&m);
	for (int i=1;i<=n;i++){
		scanf("%d",val+i);
		val[i]%=10007;
	}
	for (int i=1;i<=n;i++)
		scanf("%d",c+i);
}
void writeit(){
	printf("%d\n",ans);
}
void work(){
	for (int i=1;i<=n;i++){
		sum[i&1][c[i]]=(sum[i&1][c[i]]+val[i])%10007;
		cnt[i&1][c[i]]++;
	}
	for (int i=1;i<=n;i++)
		ans=(ans+i%10007*((sum[i&1][c[i]]+(cnt[i&1][c[i]]-2)%10007*val[i]+10007)%10007))%10007;
}
int main(){
	readit();
	work();
	writeit();
	return 0;
}
