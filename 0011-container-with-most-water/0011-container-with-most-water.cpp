class Solution {
public:
    int maxArea(vector<int>& height) {
        int start = 0 , end = height.size()-1;
        int width, h , maxwater = 0 ;
        while (start < end ){
            h = min (height[start],height[end]);
            width = end-start;
            maxwater = max(maxwater , width*h);
            height[start] < height[end]? start++ : end--;

        }
        return maxwater;
    }
};