#include <bits/stdc++.h>
using namespace std;

int activitySelection(vector<pair<int,int>>& intervals) {
    sort(intervals.begin(), intervals.end(), [](auto& a, auto& b){ return a.second < b.second; });
    int count = 1, lastEnd = intervals[0].second;
    for (int i = 1; i < (int)intervals.size(); i++) {
        if (intervals[i].first >= lastEnd) { count++; lastEnd = intervals[i].second; }
    }
    return count;
}

int minMeetingRooms(vector<pair<int,int>>& intervals) {
    vector<int> starts, ends;
    for (const auto& p : intervals) { starts.push_back(p.first); ends.push_back(p.second); }
    sort(starts.begin(), starts.end());
    sort(ends.begin(), ends.end());
    int rooms = 0, endPtr = 0;
    for (int start : starts) {
        if (start < ends[endPtr]) rooms++;
        else endPtr++;
    }
    return rooms;
}

vector<pair<int,int>> mergeIntervals(vector<pair<int,int>> intervals) {
    sort(intervals.begin(), intervals.end());
    vector<pair<int,int>> merged;
    for (const auto& p : intervals) {
        int s = p.first, e = p.second;
        if (merged.empty() || s > merged.back().second) merged.push_back({s, e});
        else merged.back().second = max(merged.back().second, e);
    }
    return merged;
}

int jumpGame(const vector<int>& nums) {
    int maxReach = 0, jumps = 0, currentEnd = 0;
    for (int i = 0; i < (int)nums.size() - 1; i++) {
        maxReach = max(maxReach, i + nums[i]);
        if (i == currentEnd) { jumps++; currentEnd = maxReach; }
    }
    return jumps;
}

int main() {
    vector<pair<int,int>> acts = {{1,4},{3,5},{0,6},{5,7},{3,9},{5,9},{6,10},{8,11},{8,12},{2,14},{12,16}};
    cout << activitySelection(acts) << "\n";
    vector<pair<int,int>> meetings = {{0,30},{5,10},{15,20}};
    cout << minMeetingRooms(meetings) << "\n";
    vector<pair<int,int>> ivs = {{1,3},{2,6},{8,10},{15,18}};
    for (auto& interval : mergeIntervals(ivs)) cout << "[" << interval.first << "," << interval.second << "] ";
    cout << "\n";
    vector<int> nums = {2,3,1,1,4};
    cout << jumpGame(nums) << "\n";
    return 0;
}