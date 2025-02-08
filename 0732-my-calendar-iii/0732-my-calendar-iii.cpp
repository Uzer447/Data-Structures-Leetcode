class MyCalendarThree {
public:
    map<int, int> events;
    MyCalendarThree() {}

    int book(int startTime, int endTime) {
        events[startTime]++;
        events[endTime]--;
        int max_k = 0, ongoing = 0;
        for (auto it = events.begin(); it != events.end(); ++it) {
            ongoing += it->second;
            if (ongoing > max_k) max_k = ongoing;
        }
        return max_k;
    }
};

/**
 * Your MyCalendarThree object will be instantiated and called as such:
 * MyCalendarThree* obj = new MyCalendarThree();
 * int param_1 = obj->book(startTime,endTime);
 */