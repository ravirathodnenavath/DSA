class Solution {
public:
    void findsubsets(int ind, vector<int>& arr, vector<vector<int>> &ans, vector<int>& ds){
        // Base Case
        ans.push_back(ds) ;

        for(int i=ind; i<arr.size();i++){
            if(i>ind && arr[i] == arr[i-1]) continue ;
            ds.push_back(arr[i]) ;
            findsubsets(i+1, arr, ans, ds) ;
            ds.pop_back() ;
        }
    }

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        // we shouldn't have to do (i == n) for duplicates
        // there is no Not-Picking line of code
        // sorting is Mandatory before 1st call for duplicates prob
        vector<vector<int>> ans ;
        vector<int> ds ;
        sort(nums.begin(), nums.end()) ;
        findsubsets(0, nums, ans, ds) ;
        return ans ;
    }
};