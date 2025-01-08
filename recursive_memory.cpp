#include <iostream>
#include <chrono>
using namespace std;

long int fib(long int n, long int* arr)
{    
   if (n == 0 || n == 1) {
        return arr[n]; 
    }
    if (arr[n] == 0) { // 確保只計算一次
        arr[n] = fib(n - 1, arr) + fib(n - 2, arr);
    }
    return arr[n];
}

long int fib2(long int n, long int* arr)
{    
    if(n==0 || n==1)
    {
        return 1; 
    }
    return fib2(n-1,arr)+fib2(n-2,arr);
    
}

int main()
{
long int a[100]={0};
a[0]=1;
a[1]=1;
auto start = std::chrono::high_resolution_clock::now();
cout<<fib(40,a);
auto end = std::chrono::high_resolution_clock::now();
auto duration = std::chrono::duration_cast<std::chrono::nanoseconds>(end - start);
cout<<"總共花了"<<duration.count() <<"奈秒"<<endl;

auto start2 = std::chrono::high_resolution_clock::now();
cout<<fib2(40,a);
auto end2 = std::chrono::high_resolution_clock::now();
auto duration2 = std::chrono::duration_cast<std::chrono::nanoseconds>(end2 - start2);
cout<<"總共花了"<<duration2.count() <<"奈秒"<<endl;

return 0;    
}
