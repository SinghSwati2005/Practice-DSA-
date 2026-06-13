#include <iostream>
#include <vector>
#include <climits>
using namespace std;
vector<int> majority(vector<int> nums)
{
    int n = nums.size();
    int cnt1 =0, cnt2=0, el1= INT_MIN, el2=INT_MIN;

vector<int>ans;

    for(int i =0;i<n;i++){
        if(cnt1 ==0 && nums[i]!=el2){
            cnt1 = 1;
            el1 = nums[i];
        }
     else if(cnt2 ==0 && nums[i]!=el1){
            cnt2 = 1;
            el2= nums[i];
        }
      else  if(nums[i]==el1){
            cnt1++;
        }
        else{
            cnt1-- , cnt2--;
        }
    }
     cnt1 = 0, cnt2 = 0;
        for (int i = 0; i < n; i++) {
            if (nums[i] == el1)
                cnt1++;
            if (nums[i] == el2)
                cnt2++;
        }
        int mini = int(n / 3) + 1;
        if (cnt1 >= mini)
            ans.push_back(el1);
        if (cnt2 >= mini)
            ans.push_back(el2);
        return ans;


}

int main(){
    int n ;
    cin>>n;
    vector<int>nums(n);
    for(int i=0;i<n;i++){
        cin>>nums[i];
    }

 vector<int>res = majority(nums);
    for(int i =0;i<res.size();i++){
        cout<<res[i]<<" ";
    }
    return 0;
}