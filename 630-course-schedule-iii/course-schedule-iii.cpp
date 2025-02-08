class Solution {
public:
    int scheduleCourse(vector<vector<int>>& courses) {
        sort(courses.begin(), courses.end(), [](vector<int>& a, vector<int>& b){ return a[1] < b[1]; });
        priority_queue<int> maxHeap;
        int totalTime = 0;
        for (auto& course : courses) {
            totalTime += course[0];
            maxHeap.push(course[0]);
            if (totalTime > course[1]) {
                totalTime -= maxHeap.top();
                maxHeap.pop();
            }
        }
        return maxHeap.size();
    }
};