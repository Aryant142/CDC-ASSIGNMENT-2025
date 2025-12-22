class Solution {
public:
    int maxVowels(string s, int k) {
        int maxVowel = 0, currVowel = 0;
        unordered_set<char> vowels = {'a', 'e', 'i', 'o', 'u'};

        for (int i = 0; i < s.size(); i++) {
            // Add right end
            if (vowels.count(s[i]))
                currVowel++;

            // Remove left end if window > k
            if (i >= k && vowels.count(s[i - k]))
                currVowel--;

            // Update max
            maxVowel = max(maxVowel, currVowel);
        }

        return maxVowel;
    }
};
