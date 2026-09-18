#include<iostream>
#include<algorithm>
using namespace std;
int main(){
    int arr[] ={5,8,11,7,15};
int n =5 ;
int tar =9;
int st =0, end =n-1;

sort(arr , arr+n);

bool found =false;
while(st<end){
int Sum = arr[st]+arr[end];
 if(Sum ==tar){
    cout<<"ans is found";
    found ="true";
    break;
 }

 else if(Sum > tar) {end--;
 }
else { st++;
}
}
if(!found)
cout<<"ans is not found ";


return 0;
}
