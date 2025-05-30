#include <iostream>
using namespace std;
// int main(){
//     cout << "Hello, World!" << endl;
//     return 0;
// }

// int main(){
//     int a = 65;
//     double b = a;
//     char c = a;
//     cout << "C:" << sizeof(a) << endl;
//     cout << "C:" << sizeof(b) << endl;
//     cout << "C:" << sizeof(c) << endl;
//     return 0;
// }

// int main(){
//     for(int i=5;i<10;i++){
//         cout << i << endl;
//     }   
// }

// int main(){
//     int n = 10;
//     do{
//         cout << n << endl;
//         n--;
//     } while(n == 8);
//     return 0;
// }

// int main(){
//     int n =5;
//     int fib[n];
//     fib[0]=0;
//     fib[1]=1;
//     for(int i=2;i<n;i++){
//         fib[i]=fib[i-1]+fib[i-2];
//     }
//     for(int i=0;i<n;i++){
//         cout << fib[i] << " ";
//     }
//     //OR
//     for(int num: fib){
//         cout << num << " ";
//     }
// }

// #include <vector>
// int main(){
//     vector<int> v;
//     v.push_back(25);
//     v.push_back(30);
//     v.push_back(35);
//     cout <<v.size() << endl;
//     for(int i=0;i<v.size();i++){
//         cout << v[i] << " ";
//     }

//     cout << endl;
//     cout<<v.front() << endl;
//     cout<<v.back() << endl;

//     int a[5];
//     a[0] =1;

//     cout<<sizeof(a)/sizeof(int) << endl;
//     //sizeof(int) = 4
//     //sizeof(a) = 20
//     //sizeof(a)/sizeof(int) = 20/4 = 5
// }

// #include <iostream>
// using namespace std;
// int main() {
//     int rows = 5;

//     for (int i = 1; i <= rows; i++) {
//         for (int j = 1; j <= i; j++) {
//             cout << "*";
//         }
//         cout << endl;
//     }
//     return 0;
// }

#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int main() {
    int num;
    cout << "enter number: ";
    cin >> num;
    int original = num;
    vector<int> digits;
    while (num != 0) {
        digits.push_back(num % 10);
        num /= 10;
    }
    int n = digits.size();
    int sum = 0;
    for (int digit : digits) {
        sum += pow(digit,n);
    }
    if (sum == original)
        cout << "armstrong number." << endl;
    else
        cout << "not an armstrong number." << endl;
    return 0;
}