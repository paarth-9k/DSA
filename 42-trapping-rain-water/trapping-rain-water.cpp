class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        int left = 0;
        int right = n - 1;
        int leftmax = 0; // left limiting wall
        int rightmax = 0; // right limiting wall
        long water = 0;

        while(left < right)
        {
            if(height[left] <= height[right])
            {
                leftmax = max(leftmax, height[left]);
                water = water + (leftmax - height[left]);
                left++;
            }
            else
            {
                rightmax = max(rightmax, height[right]);
                water = water + (rightmax - height[right]);
                right--;
            }
        }

        return water;

    }
};