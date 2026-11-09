class Solution {
public:
    vector<int> busiestServers(int k, vector<int>& arrival, vector<int>& load) {
        // Min-heap: (free_time, server_id)
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<>> pq;
        // Set of currently available server IDs
        set<int> avail;
        for (int i = 0; i < k; i++) avail.insert(i);
        vector<int> cnt(k, 0);

        for (int i = 0; i < arrival.size(); i++) {
            // Free up servers whose tasks are done
            while (!pq.empty() && pq.top().first <= arrival[i]) {
                avail.insert(pq.top().second);
                pq.pop();
            }

            // No free server → drop the request
            if (avail.empty()) continue;

            // Target server is i % k
            int target = i % k;
            auto it = avail.lower_bound(target);
            if (it == avail.end()) it = avail.begin(); // wrap around

            int s = *it;
            avail.erase(it);
            cnt[s]++;
            pq.push({arrival[i] + load[i], s});
        }

        int mx = *max_element(cnt.begin(), cnt.end());
        vector<int> res;
        for (int i = 0; i < k; i++)
            if (cnt[i] == mx) res.push_back(i);
        return res;
    }
};