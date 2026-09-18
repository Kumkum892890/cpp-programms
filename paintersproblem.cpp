#include<iostream>
#include<vector>
using namespace std;
bool isPossible(vector<int>& arr, int n, int m ,int maxAllowedTime){
    int painter=1, time =0;

    for(int i=0; i<n; i++){
        if(time+arr[i]<= maxAllowedTime){
            time+=arr[i];

        }
        else{
            painter++;
            time=arr[i];
        }
    }
    return painter <= m;
}

int minTimetopaint(vector<int> &arr, int n, int m){
    int sum=0, maxVal=0;
    for( int i=0; i<n; i++) {//o(n)
        sum+= arr[i];
        maxVal= max(maxVal, arr[i]);
    }
    int st=maxVal, end=sum , ans=-1;

    while(st<=end){//log(sum)
        int mid= st+(end-st)/2;

        if(isPossible(arr, n,m, mid)) {//left
          ans=mid;
            end=mid-1;
        }
        else{//right
            //right 
            st=mid+1;
        }
    }
    return ans;
}
int main(){
    vector<int> arr={40,30,10,20};
    int n=4; int m=2;

    cout << minTimetopaint(arr, n, m)<< endl;
    return 0;
}