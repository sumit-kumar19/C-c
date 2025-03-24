class Solution {
public:
    int countDays(int days, vector<vector<int>>& meetings) {
        if (meetings.empty())
            return days;
        sort(meetings.begin(), meetings.end());

        int n = meetings.size();
        int ans = meetings[0][0] - 1;
        int maxmeeting = meetings[0][1];

        for (int i = 1; i < n; i++) {
            if (maxmeeting < meetings[i][0])
                ans += meetings[i][0] - maxmeeting - 1;
            maxmeeting = max(meetings[i][1], maxmeeting);
        }

        if (maxmeeting < days)
            ans += days - maxmeeting;
        return ans;
    }
};