class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
       if (nums.size() < 2) 
           return nums.size();
	    int j = 0;
	    for (int i = 1; i < nums.size(); i++)
		    if (nums[j] != nums[i]) {
                // nums[++j] == j+=1; nums[j];
                nums[++j] = nums[i];
            }
        // return ++j == j+=1; return j;
	    return ++j;
    }
};