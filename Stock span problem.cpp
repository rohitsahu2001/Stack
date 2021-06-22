class Solution
{
    public:
    //Function to calculate the span of stockâ€™s price for all n days.
    vector <int> calculateSpan(int price[], int n)
    {
       // Your code here
       vector<int> ans;
       ans.push_back(1);
       stack<pair<int,int>> s;
       s.push({price[0],0});
       for(int i=1;i<n;i++){
           while(!s.empty() && price[i]>=s.top().first)
             s.pop();
           int x=s.empty()?-1:s.top().second;
           ans.push_back(i-x);
           s.push({price[i],i});
       }
       return ans;
    }
};
