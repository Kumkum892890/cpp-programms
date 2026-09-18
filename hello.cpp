#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
 int partition(vector<int> &arr ,int st , int end){
    int Idx = st-1,pivot= arr[end];
    for(int j= st; j<end ; j++){
        if(arr[j]>= pivot){
            Idx++;
            swap(arr[j] , arr[Idx]);
        }
    }
    Idx++;
    swap(arr[end], arr[Idx]);
    return Idx;
 }
 void Quickss(vector<int> &arr ,int st , int end){
    if(st <end){
          int pivIndx = partition(arr , st, end);
           Quickss(arr , st, pivIndx-1);
              Quickss(arr , pivIndx+1, end);
    }
 }
 int main(){
    vector<int> arr ={3,5,4,3,1};
    Quickss(arr ,0 ,arr.size()-1);
    for(int val: arr){
    cout<<val<<" ";
    }
    cout<<endl; 
    return 0;
}

