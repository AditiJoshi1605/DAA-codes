//tabular
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int knapsack(vector<pair<int,int>>&items,int n ,int k){
    vector<vector<int>>dp(n+1,vector<int>(k+1,0));
    for(int i=1;i<=n;i++){
        for(int j=1;j<=k;j++){
            int val=items[i-1].first;
            int wt=items[i-1].second;
            if(wt>j){
                dp[i][j]=dp[i-1][j];
            }
            else{
                dp[i][j]=max(dp[i-1][j], val+dp[i-1][j-wt]);
            }
        }
    }
    return dp[n][k]; //max profit
}
int main(){
    int N;
    cout<<"enter no of objects\n";
    cin>>N;
    vector<pair<int,int>>items;
    for(int i=0;i<N;i++){
        int wt,val;
        cin>>val >>wt ;
        items.push_back({val,wt});
    }
    int k;
    cout<<"enter capacity of the bag\n";
    cin>>k;
    cout<<knapsack(items,N,k);
}