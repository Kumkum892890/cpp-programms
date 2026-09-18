#include<iostream>
#include<math.h>
#include<vector>
using namespace std;


//prime no.
// string isPrime(int n){
// for(int i=2; i*i<=n; i++){
//     if(n%2 ==0){
//         return "non prime";
//     }
//     else {
//         return "prime";
//     }
// }
// return 0;
// }
// int main(){
// int n;
// cin >>n;
// cout<<isPrime(n)<<endl;
// return 0;
// }

//sieve of eratosthenes


//digits in a number
// void printDigits(int n){// o(log n)
//     int sum=0;

//     int count =0;
//     while(n !=0){
// int digit =n % 10;
// sum += digit;
// count++;
// cout<<digit<<endl;
// cout<<sum<<endl;
// n =n/10;
//     }
//     cout<<count<<endl;
// }
// int main() {
//     int n=3568;
//     printDigits(n);
//     cout<<(int)(log10(n)+1)<<endl;//equal to the count of the digits
//     return 0;
// }


//armstrong number
// bool isArmstrong(int n){
//     int copyN =n;
//     int Sumofcubes =0;

//     while(n != 0){
//         int dig = n%10;
//         Sumofcubes += (dig*dig*dig);

//         n=n/10;

//     }
// return Sumofcubes == copyN;
// }

// int main(){
//     int n=89;
//    if (isArmstrong(n)) {
// cout<<" is an armtrong number\n";
//    }
//    return 0;
// }

//greatest common factor
// int gcd(int a,int b){
//     while(a>0 && b>0){
//         if(a >b){
//             a= a%b;
//         }else{
//             b=b%a;
//         }
//     }
//     if(a ==0) return b;
//     return a;
// }

// int gcdrec(int a, int b){
//     if(b==0) return a;

//     return gcdrec(b ,a%b);
// }

// //lcm
//  int lcm(int a ,int b){
//     int gcd = gcdrec( a ,b);
//     return(a*b)/gcd;
//  }


int main(){
    cout<<lcm(20 ,28)<<endl;
    return 0;
}