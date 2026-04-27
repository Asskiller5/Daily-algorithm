#include<bits/stdc++.h>
using namespace std;
int main(){
	string a,b;
	cin>>a>>b;
	vector<vector<int> > dp(a.size()+1,vector<int>(b.size()+1));
	for(size_t i=1;i<=a.size();++i){
		for(size_t j=1;j<=b.size();++j){
			if(a[i-1]==b[j-1]){
				dp[i][j]=dp[i-1][j-1]+1;
			}
			else{
				dp[i][j]=max(dp[i][j-1],dp[i-1][j]);
			}
		}
	}
	for(size_t i=1;i<=a.size();++i){
		for(size_t j=1;j<=b.size();++j){
			cout<<"  "<<dp[i][j];
		}
		cout<<endl;
	}
	cout<<endl;
	string res="";
	for(size_t i=a.size(),j=b.size();i>=1&&j>=1;){
		if(a[i-1]==b[j-1]){
			res=a[i-1]+res;
			i-=1;
			j-=1;
		}
		else{
			if(dp[i-1][j]>=dp[i][j-1]){
				i-=1;
			}
			else{
				j-=1;
			}
		}
	}
	for(size_t i=0;i<res.size();++i){
		cout<<res[i]<<" ";
	}
	return 0;
}
