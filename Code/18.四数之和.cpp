/*
 * @lc app=leetcode.cn id=18 lang=cpp
 *
 * [18] 四数之和
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        vector <vector<int>> res;
        for(int i = 0; i + 3 < nums.size(); ++i)
        {
            if(i > 0 && nums[i] == nums[i-1])   continue;
            for(int j = i+1; j + 2 < nums.size(); ++j)
            {
                if(j > i+1 && nums[j] == nums[j-1])   continue; 
                //此处不能为j>0，循环至少进行一轮后才能continue，确保当前情况的数字组合已经判断过
                int ttarget = target - nums[i] - nums[j] ;
                int l = j+1, r = nums.size()-1;
                while(l < r)
                {
                    int sum = nums[l] + nums[r];        //注意-号
                    if(ttarget == sum)
                    {
                        res.push_back({nums[i],nums[j],nums[l],nums[r]});
                        l++;
                        r--;
                        while(l < r && nums[l] == nums[l-1])    l++;
                        while(l < r && nums[r] == nums[r+1])    r--;
                    }
                    if(ttarget > sum)    l++;
                    if(ttarget < sum)    r--;
                } 
            }
        }
        return res;
    }
};
// @lc code=end

