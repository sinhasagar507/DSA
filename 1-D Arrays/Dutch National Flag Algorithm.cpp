/* Dutch National Flag Algorithm. Works on the idea ki u push the zeroes to left and 2's to right, and the 1's will take care of themselves */
/* Objects of the same color - Sort them inplace */
class Solution {
public:
    void sortColors(vector<int> &nums) 
    {
        int n=nums.size();
        int low=0, mid=0, high=n-1;
        
        while(mid<=high)
        {
            if(nums[mid]==0)
                swap(nums[low++], nums[mid++]);
            
            else if(nums[mid]==1)
                mid++;
        
            else if(nums[mid]==2)
                swap(nums[mid], nums[high--]);     
        }
    }
};