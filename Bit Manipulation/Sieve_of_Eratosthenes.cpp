// #include<iostream>
// #include<vector>
// using namespace std;

// bool isPrime(int n){
//     if(n<=1) return false;
//     if(n==2) return true;
//     if(n%2==0) return false;
//     for(int i = 3;i*i<=n;i++){
//         if(n%i==0) return false;
//     }
//     return true;
// }

// int main(){

//     int n ;
//     cin>>n;

//     vector<vector<int>>q (n,vector<int>(2));
//     for(int i =0;i<n;i++){
//         cin>>q[i][0]>>q[i][1];

//     }
//     vector<int>res;
//     for(int i =0;i<n;i++){
//         int L = q[i][0];
//         int R = q[i][1];
//         int count =0;
//         for(int num= L;num<=R;num++){
//             if(isPrime(num)){
//                 count++;
//             }
//         }
//         res.push_back(count);
//     }
//     for(int i =0;i<res.size();i++){
//         cout<<res[i]<<" ";
//     }
//     return 0;
// }

#include <iostream>
#include <vector>
using namespace std;

// Function to check if a number is prime
bool isPrime(int n) {
    if (n <= 1) return false;
    if (n == 2) return true;
    if (n % 2 == 0) return false;
    for (int i = 3; i * i <= n; i += 2) {
        if (n % i == 0) return false;
    }
    return true;
}

int main() {
    int n;
    cout << "Enter number of queries: ";
    cin >> n;

    vector<vector<int>> queries(n, vector<int>(2));
    cout << "Enter each query as two numbers (L R):\n";
    for (int i = 0; i < n; i++) {
        cin >> queries[i][0] >> queries[i][1];
    }

    // Process each query
    for (int i = 0; i < n; i++) {
        int L = queries[i][0];
        int R = queries[i][1];

        cout << "Primes between " << L << " and " << R << " (excluding boundaries): ";

        bool found = false;
        for (int num = L + 1; num < R; num++) {  // exclude boundaries
            if (isPrime(num)) {
                cout << num << " ";
                found = true;
            }
        }
        if (!found) cout << "None";  // if no primes found
        cout << endl;
    }

    return 0;
}
