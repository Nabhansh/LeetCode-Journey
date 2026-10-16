class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        int n = arr2.size();
        
        vector<int>ans;
        
        map<int, int>mpp;
        for(int i=0;i<n;i++){
            mpp[arr2[i]] = i;
        }
        
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>>pq;
        
        for(int i=0;i<arr1.size();i++){
            if(mpp.find(arr1[i])!=mpp.end()){
                pq.push({mpp[arr1[i]], arr1[i]});
            }
            else{
                pq.push({n, arr1[i]});
            }
        }
        
        while(!pq.empty()){
            ans.push_back(pq.top().second);
            pq.pop();
        }
        
        return ans;
    }
};