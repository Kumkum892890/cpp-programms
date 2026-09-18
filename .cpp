#include<iostream>
#include<algorithm>
#include<string>

using namespace std;

int main() { //remove all the occrrences
string str=" pqrstuvwuvstuv";
string part ="uv";
while(str.find(part)!= string::npos)  {
  str.erase(str.find(part),part.length());
 
}
cout<< str;
return 0;


//string str="hi guys.";
 //reverse(str.begin(),str.end());
// cout<<str<<endl;
 //return 0;
 // int st=0 ;
 //int e= str.size()-1;
 // while(st<e){
  //  swap(str[st],str[e]);
 //   st++, e--;
//cout<<str<<endl;
//cout<<endl;
 // }
 // return 0;
  //string str=" good morning pineapple";
 // for(int i=0; i<str.length(); i++){
// cout<< str[i] <<endl;
  //  cout<<endl;
 // }
 
  //return 0;

// getline(cin, str);
 // cout<<" output: " << str<<endl;
 // return 0;
 // string str1 =" kumkum";
   //string str2 =" kumkupm";
   //cout<< str2.length() <<endl;
   //return 0;
// string str ="kumkum tiwari";
// cout<<str<<endl;
 //str= "hello guys";
 //cout<< str<< endl;
   //string literals 
//int len=0;
//for(int i=0; i<str[i] !='\0';i++){
 // len++;
//}


  //cout<<" length of string: "<< len <<endl;
 // return 0;
}


