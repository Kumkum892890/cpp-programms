#include<iostream>
#include<vector>
using namespace std;
// int getmaxSum(int mat[][3], int rows ,int cols){
//  int maxrowsum =INT_MIN;
//  for(int i=0;i<rows; i++){
//   int  rowSum=0;
//   for(int j=0; j<cols; j++){
//     rowSum +=mat[i][j];
//   }
//   maxrowsum = max(maxrowsum ,rowSum);

 
//  }
//  return maxrowsum;
// }


//maximum colum sum
// int getmaxSum(int mat[][3], int rows ,int cols){
//   int maxColSum =INT_MIN;
//   for(int i=0; i<rows ; i++){
//     int colsum =0;
//     for(int j=0; j<cols ;j++){
//       colsum +=mat[j][i];
//     }
//     maxColSum =max(maxColSum , colsum);
//   }
//   return maxColSum;
// }

int diagonalSum(int mat[][3] , int n){
  int sum =0; 
  for(int i=0; i<n; i++){
    for(int j=0; j<n; j++){
      if( i==j){
        sum += mat[i][j];
      } else if( j =n-i-1){
         sum += mat[i][j];
      }
    }
  }
return sum;
}

int main(){
  int sum=0;
  int n=3;
int rows= 3;
int cols =3;
int matrix[3][3]={{1,2,3},{4,5,6},{7,8,9}};
cout<<diagonalSum(matrix , n) <<endl;

}

 



 







