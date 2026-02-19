#include <iostream>
#include <vector>
using namespace std;
vector<int> majority(vector<int> nums)
{
    int n = nums.size();
    vector<int> result;

    for (int i = 0; i < n; i++)
    {

        if (result.size() == 0 || result[0] != nums[i])
        {
            int cnt = 0;

            for (int j = 0; j < n; j++)
            {
                if (nums[j] == nums[i])
                {
                    cnt++;
                }
            }
            if (cnt > n / 3)
            {
                result.push_back(nums[i]);
            }
        }
        if (result.size() == 2)
            break;
    }
    return result;
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