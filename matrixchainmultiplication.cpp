
#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include<climits>
using namespace std;

//RECURSION tc:O(2^n)
// long long matrixmultiplication(vector<int> &mat,int i,int j){
//     if(i>=j)  return 0;
//     long long final=LLONG_MAX;
//     for(int k=i;k<j;k++){
//         long long temp=matrixmultiplication(mat,i,k)
//                       + matrixmultiplication(mat,k+1,j)
//                       + mat[i-1]* mat[k]* mat[j];
//         final=min(temp,final);
//     }
//     return final;
// }
// int main(){
//     int n;
//     cout << "Enter number of Matrix: ";
//     cin >> n;
//     vector<int> mat(n+1);
//     cout << "Enter matrix Data: ";
//     for(int i=0;i<=n;i++){
//         cin>>mat[i];
//     }
//     long long result=matrixmultiplication(mat,1,n);
//     cout << result;
//     return 0;
// }

//MEMORIZATION tc:O(n3) sc:O(n2) for emorization table
long long matrixMultiplication(vector<int> &mat, int i, int j, vector<vector<long long>> &dp,vector<vector<int>>&bracket) {
    if (i >= j) return 0;
    if (dp[i][j] != -1) return dp[i][j];
    long long final = LLONG_MAX;
    for (int k = i; k < j; k++) {
        long long cost = matrixMultiplication(mat, i, k, dp, bracket)
                       + matrixMultiplication(mat, k + 1, j, dp, bracket)
                       + mat[i - 1] * mat[k] * mat[j];
        if(cost<final){
            final=cost;
            bracket[i][j]=k;
        }
    }
    return dp[i][j] = final;
}
void printParenthesis(int i, int j, vector<vector<int>>& bracket, char& name) {
    if (i == j) {
        cout << name++;
        return;
    }
    cout << "(";
    printParenthesis(i, bracket[i][j], bracket, name);
    printParenthesis(bracket[i][j] + 1, j, bracket, name);
    cout << ")";
}
int main() {
    int n;
    cout << "Enter number of matrices: ";
    cin >> n;
    vector<int> mat(n + 1);
    cout << "Enter matrix Data: ";
    for (int i = 0; i <= n; i++) {
        cin >> mat[i];
    }
    // Initialize dp with -1
    vector<vector<long long>> dp(n + 1, vector<long long>(n + 1, -1));
    vector<vector<int>> bracket(n + 1, vector<int>(n + 1, 0));
    long long result = matrixMultiplication(mat, 1, n, dp,bracket);
    cout << "Minimum number of multiplications: " << result << endl;
    
    //for printing the optimial solution
    cout << "Optimal Parenthesization: ";
    char name = 'A';  // Starting matrix name
    printParenthesis(1, n, bracket, name);
    cout << endl;
    return 0;
}

