class Solution
{
    public:
    //Function to find the next greater element for each element of the array.
    vector<long long> nextLargerElement(vector<long long> nums, int n){
        // Your code here
        vector<long long> ans;
        stack<long long> stack;
        for(int i=n-1;i>=0;i--){
            while(!stack.empty() && nums[i]>=stack.top()){
                stack.pop();
            }
            long long x=stack.empty()?-1:stack.top();
            ans.push_back(x);
            stack.push(nums[i]);
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};
