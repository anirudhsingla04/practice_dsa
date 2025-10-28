class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        vector<int> ans;

        for (int i = 0; i < nums1.size(); i++) {
            int num = nums1[i];
            int indexInNums2 = -1; // ✅ Correct: to store position of nums1[i] in nums2

            // ✅ Step 1: Find where nums1[i] occurs in nums2
            for (int j = 0; j < nums2.size(); j++) {
                if (nums2[j] == num) {
                    indexInNums2 = j;
                    break; // stop once found
                }
            }

            int nextGreater = -1; // default if none found

            // ✅ Step 2: Look for a number greater than nums1[i] after its position
            for (int k = indexInNums2 + 1; k < nums2.size(); k++) {
                if (nums2[k] > num) {
                    nextGreater = nums2[k];
                    break; // stop at first greater element
                }
            }

            ans.push_back(nextGreater); // ✅ Add correct answer for nums1[i]
        }

        return ans;
    }
};
