class KthLargest {
public:
    priority_queue<int, vector<int>, greater<int>> pq; // min-heap
    int k;

    KthLargest(int k, vector<int>& nums) {
        this->k = k;
        for (int num : nums) {
            pq.push(num);
            if (pq.size() > k)
                pq.pop(); // keep only k largest
        }
    }

    int add(int val) {
        pq.push(val);
        if (pq.size() > k)
            pq.pop();
        return pq.top(); // kth largest
    }
};
