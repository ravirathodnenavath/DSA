class Solution {
public:
    void findcombinationSum(int i, int target, vector<int> &candidates, vector<vector<int>> &ans, vector<int> &ds){
        // Base Case
        if(i == candidates.size()){
            if(target == 0) ans.push_back(ds) ;
            return ;
        }

        // Pick up the element
        // We stay at the same index because
        // we can use the same element multiple times.
        if(candidates[i] <= target){
            ds.push_back(candidates[i]) ;
            findcombinationSum(i, target-candidates[i], candidates, ans, ds) ;
            ds.pop_back() ;     // Backtrack
        }

        // Not Pick up the element
        // Move to the next candidate.
        findcombinationSum(i+1, target, candidates, ans, ds) ;
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        // int minElem = *min_element(candidates.begin(), candidates.end()) ;
        // if(target < minElem) return {} ;
        
        vector<vector<int>> ans ;
        vector<int> ds ;
        findcombinationSum(0, target, candidates, ans, ds) ;
        return ans ;
    }
};