#include<iostream>
#include<vector>
using namespace std;

bool isSafe(vector<vector<int>>&mat,int row,int col){
    int n=mat.size();
    //checks the above rows in same col
    //if some other queen is already placed there or not
    for(int i=0;i<row;i++){
        if(mat[i][col]==1) return false;
    }
    //checks diagonals
    for(int i=row-1,j=col-1;i>=0 && j>=0 ; i--,j--){
        if(mat[i][j]==1) return false;
    }
    for(int i=row-1,j=col+1;i>=0 && j<n ; i--,j++){
        if(mat[i][j]==1) return false;
    }
    return true;
}
//checks solution exists or not
bool placeQueens(int row, vector<vector<int>>&mat){
    int n=mat.size();
    if(row==n){
        return true;
    }
    for(int i=0;i<n;i++){
        if(isSafe(mat,row,i)){
            mat[row][i]=1;
            if(placeQueens(row+1,mat)){
                return true;
            }
            mat[row][i]=0;
        }
    }
    return false;
}
vector<int>nQueens(int n){
    vector<vector<int>>mat(n,vector<int>(n,0));
    if(placeQueens(0,mat)){ 
        vector<int>sol;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(mat[i][j]){
                    sol.push_back(j);
                }
            }
        }
        return sol;
    }
    else{
        return {-1};
    }
}
int main(){
    int n;
    cin>>n;
    vector<int> sol=nQueens(n);
    for(int i=0;i<sol.size();i++){
        cout<<sol[i]<<" ";
    }
    cout<<"\n";
}