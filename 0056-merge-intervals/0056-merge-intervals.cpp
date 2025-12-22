class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> merged;
        
        if (intervals.empty()) return merged;

        // Step 1: Sort intervals based on start time
        sort(intervals.begin(), intervals.end());

        // Step 2: Start with the first interval
        vector<int> current = intervals[0];

        for (int i = 1; i < intervals.size(); i++) {
            // If overlapping: current.end >= next.start
            if (current[1] >= intervals[i][0]) {
                // Merge by taking max end
                current[1] = max(current[1], intervals[i][1]);
            } else {
                // No overlap → save current and move on
                merged.push_back(current);
                current = intervals[i];
            }
        }

        // Add the last interval
        merged.push_back(current);
        return merged;
    }
};
