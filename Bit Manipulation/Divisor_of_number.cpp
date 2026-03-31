#include<iostream>
#include<vector>
#include <algorithm>
using namespace std;

vector<int>getDivisor(int n ){
    vector<int>res;
    for(int i =1;i*i<=n;i++){
        if(n%i==0)
        res.push_back(i);

        if(i!=n/i){
            res.push_back(n/i);
        }
    }
    sort(res.begin(), res.end());
    return res;
}

int main(){
    int n;
    cin>>n;
    vector<int>res = getDivisor(n);
    cout<<"[";
    for(int i =0;i<res.size();i++){
        cout<<res[i]<<" ";
        if(i<res.size()-1) cout<<",";
    }
    cout<<"]";
    return 0;
}