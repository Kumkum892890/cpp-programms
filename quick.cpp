#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int partition(vector<int> &arr ,int st, int end){
    int idx =st-1, pivot = arr[end];

    for(int j =st; j<end; j++){
        if(arr[j] >= pivot){//by here changing we can get acssending and descending on comparisons
            idx++;
            swap(arr[j] , arr[idx]);
        }
    }
    idx++;
     swap(arr[end] , arr[idx]);
     return idx;
}
void quickSort(vector<int> &arr, int st, int end){
    if(st<end){
        int pivIndx = partition(arr , st, end);
         quickSort(arr, st, pivIndx-1); //left half
             quickSort(arr,pivIndx+1 , end);//right half

    }
}

int main(){
    vector<int> arr ={9,8,7,6,5,4,3,2};
    quickSort(arr, 0, arr.size()-1);
    for(int val : arr){
        cout<<val<< " " ;
    }
    cout<<endl;
    return 0;
}
