class Solution
{
    public:
    
    void nsl(long long *arr,int n,vector<long long> &left){
        stack<pair<long long,int>> s;
        for(int i=n-1;i>=0;i--){
            while(!s.empty() && arr[i]<=s.top().first)
              s.pop();
            int x=s.empty()?n:s.top().second;
            left.push_back(x);
            s.push({arr[i],i});
        }
        reverse(left.begin(),left.end());
    }
    
    void nsr(long long *arr,int n,vector<long long> &right){
        stack<pair<long long,int>> s;
        for(int i=0;i<n;i++){
            while(!s.empty() && arr[i]<=s.top().first)
              s.pop();
            int x=s.empty()?-1:s.top().second;
            right.push_back(x);
            s.push({arr[i],i});
        }
    }
    //Function to find largest rectangular area possible in a given histogram.
    long long getMaxArea(long long arr[], int n)
    {
        // Your code here
        vector<long long> left,right;
        nsl(arr,n,left);
        nsr(arr,n,right);
        long long mx=0;
        for(int i=0;i<n;i++){
            mx=max(mx,(left[i]-right[i]-1)*arr[i]);
        }
        return mx;
    }
