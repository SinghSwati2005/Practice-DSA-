#include<iostream>
#include<vector>
using namespace std;


void helper(const string &num , int target, int index, string path, long value,long prev, vector<string>&res){
    if(index==num.size()){
        if(value==target){
            res.push_back(path);
        }
        return;
    }

    long curr =0;
    for(int i =index;i<num.size();i++){
        if(i>index &&num[index]=='0') break;

        curr = curr*10+(num[i]-'0');
        string currstr = num.substr(index,i-index+1);

        if(index==0){
            helper(num, target, i+1, currstr,curr,curr,res);
        }
        else{
            helper(num , target,i+1,path+"+"+currstr, value+curr, curr,res);
            helper(num , target,i+1,path+"-"+currstr, value-curr, -curr,res);
            helper(num , target,i+1,path+"*"+currstr, value-prev+prev*curr, prev*curr,res);
        }
    }
}



vector<string>addOperators(string num , int target){
    vector<string>res;
    helper(num , target, 0, "",0,0,res);
    return res;


}

int main(){
    string num;
    int target;
    cin>>num>>target;

    auto ans = addOperators(num,target);
    for(auto &s: ans) cout<<s<<"\n";
    return 0;
}

