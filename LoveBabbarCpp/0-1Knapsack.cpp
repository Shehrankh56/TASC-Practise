#include<bits/stdc++.h>
using namespace std;

int solveUsingRecursion(int capacity, int wt[],int profit[],int index,int n){
    if(index >= n ){
        return 0;
    }

    int include=0;
    if(wt[index] <= capacity){
        include=profit[index]+solveUsingRecursion(capacity-wt[index] , wt , profit , index+1 , n);
    }
    int exclude=0+solveUsingRecursion(capacity, wt,profit,index+1,n);

    int ans=max(include,exclude);
    return ans;
}

int solveUsingMem(int capacity, int wt[],int profit[],int index,int n,vector<vector<int>>& dp){
    if(index >= n ){
        return 0;
    }

    if(dp[capacity][index]!=-1)
    return dp[capacity][index];



    int include=0;
    if(wt[index] <= capacity){
        include=profit[index]+solveUsingMem(capacity-wt[index] , wt , profit , index+1 , n,dp);
    }
    int exclude=0+solveUsingMem(capacity, wt,profit,index+1,n,dp);

    dp[capacity][index]=max(include,exclude);
    return dp[capacity][index];

}

int solveUsingTabulation(int capacity, int wt[],int profit[],int index,int n){

    vector<vector<int>>dp(capacity+1,vector<int>(n+1,-1));

    //base case : har row ke nth index pr zero rkhna h because index>=n return 0
    for(int row=0; row<=capacity; row++){
        dp[row][n]=0;
    }

    for(int i=0; i<=capacity ; i++){
        for(int j=n-1; j >= 0 ; j--){
            int include=0;
            if(wt[j] <= i){
                include=profit[j]+dp[i-wt[j]][j+1];
            }
            int exclude=0+dp[i][j+1];

            dp[i][j]=max(include,exclude);
        }
    }
    return dp[capacity][0];
}
int main(){
    int capacity=50;
    int wt[]={10,20,30};
    int profit[]={60,100,120};
    int index=0;
    int n=3;
    //vector<vector<int>>dp(capacity+1, vector<int>(n+1,-1));
    //int ans=solveUsingRecursion(capacity,wt,profit,index,n);
    //int ans=solveUsingMem(capacity,wt,profit,index,n,dp);
    int ans=solveUsingTabulation(capacity,wt,profit,index,n);
    cout<<"Max Profit:"<< ans <<" ";
    return 0;
}