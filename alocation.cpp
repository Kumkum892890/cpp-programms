#include<iostream>
#include<vector> 
using namespace std;
bool isvalid(vector<int>& arr, int n, int m, int maxAllowedpages){ //o(n)
    //o(n*logn)
    int stu=0 ,pages=0;

    for(int i=0; i<n; i++){
        if(arr[i]> maxAllowedpages){
            return false;
        }
        if(pages +arr[i]<= maxAllowedpages){
            pages+=arr[i];
        }
        else{stu ++;
        pages =arr[i];
    }
    }
    return  stu >m ? false: true;
}
int allocateBooks(vector<int>& arr, int n, int m){
    if(m>n){
        return -1;
    }
    int sum=0;
    int ans=-1;
    for( int i=0; i<n; i++){
        sum+= arr[i];
    }
    int st=0, end=sum; //range of possible ans
    while(st<=end){ //o(logn)
        int mid= st+(end-st)/2;
        if(isvalid(arr,n,m,mid)){
        //left
        ans= mid;
        end=mid-1;
    } else {
        //right
         st=mid+1;
        
    }

}
return ans;

}
int main(){
    vector<int> arr={9,8,9,0};
    int n=4, m=2;
    cout<< allocateBooks(arr,n,m) <<endl;
    return 0;
}