/* Example 1:
Input Format:
 N = 6, k = 4, arr[] = {0,3,4,7,10,9}
Result:
 3
Explanation:
 The maximum possible minimum distance between any two cows will be 3 when 4 cows are placed at positions {0, 3, 7, 10}. Here the distances between cows are 3, 4, and 3 respectively. We cannot make the minimum distance greater than 3 in any ways.

Example 2:
Input Format:
 N = 5, k = 2, arr[] = {4,2,1,3,6}
Result:
 5
Explanation:
 The maximum possible minimum distance between any two cows will be 5 when 2 cows are placed at positions {1, 6}.  */

 int Aggressive_cows(vector<int>&nums,int k){
    int n = nums.size();
    int low =0;
    int high =n-1;
    while(low<=high){
        int mid = (low+high)/2;
    }
 }

 int main(){
    int n , k;
    cin>>n>>k;
    vector<int>nums(n);
    for(int i =0;i<n;i++){
        cin>>nums[i];
    }
    cout<<Aggressive_cows(nums,k)<<" ";
    return 0;
 }