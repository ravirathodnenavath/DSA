class Solution {
public:
    void findcombinationSum2(int ind, vector<int>& candidates, int target, vector<vector<int>> &ans, vector<int> &ds){ 
        if(target == 0){
            ans.push_back(ds) ;
            return ;
        }

        for(int i=ind; i<candidates.size(); i++){
            // Continue means, basically skip...
            // skip the duplicate
            if(i>ind && candidates[i] == candidates[i-1]) continue ;
            if(candidates[i] > target) break ;
            ds.push_back(candidates[i]) ;
            findcombinationSum2(i+1, candidates, target-candidates[i], ans, ds) ;
            ds.pop_back() ;
        }
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        // we shouldn't have to do (i == n) for duplicates
        // there is no Not-Picking line of code
        // sorting is Mandatory before 1st call for duplicates prob
        sort(candidates.begin(), candidates.end()) ;
        vector<vector<int>> ans ;
        vector<int> ds ;
        findcombinationSum2(0, candidates, target, ans, ds) ; 
        return ans ;
    }
};