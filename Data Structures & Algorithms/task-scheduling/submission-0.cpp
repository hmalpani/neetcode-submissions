class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        vector<int> count(26, 0);
        for (int task: tasks) {
            count[task - 'A'] += 1;
        }

        priority_queue<int> pq;
        for (int cnt: count) {
            if (cnt > 0) {
                pq.push(cnt);
            }
        }

        int time = 0;
        queue<pair<int, int>> q;
        while (!pq.empty() || !q.empty()) {
            time += 1;

            if (pq.empty()) {
                time = q.front().second;
            } else {
                int cnt = pq.top() - 1;
                pq.pop();
                if (cnt > 0) {
                    q.push({cnt, time + n});
                }
            }
            if (!q.empty() && q.front().second == time) {
                pq.push(q.front().first);
                q.pop();
            }
        }
        return time;
    }
};
