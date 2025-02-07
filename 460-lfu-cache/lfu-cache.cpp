class LFUCache {
public:
    LFUCache(int capacity) {
        cap = capacity;
        min_freq = 0;
    }
    
    int get(int key) {
        if (key_to_val_freq.find(key) == key_to_val_freq.end()) return -1;
        int val = key_to_val_freq[key].first;
        int freq = key_to_val_freq[key].second;
        freq_to_keys[freq].erase(key_to_iter[key]);
        key_to_val_freq[key].second = freq + 1;
        freq_to_keys[freq + 1].push_back(key);
        key_to_iter[key] = --freq_to_keys[freq + 1].end();
        if (freq_to_keys[freq].empty()) {
            freq_to_keys.erase(freq);
            if (min_freq == freq) min_freq++;
        }
        return val;
    }
    
    void put(int key, int value) {
        if (cap <= 0) return;
        if (key_to_val_freq.find(key) != key_to_val_freq.end()) {
            key_to_val_freq[key].first = value;
            get(key);
        } else {
            if (key_to_val_freq.size() >= cap) {
                int key_to_remove = freq_to_keys[min_freq].front();
                freq_to_keys[min_freq].pop_front();
                if (freq_to_keys[min_freq].empty()) freq_to_keys.erase(min_freq);
                key_to_val_freq.erase(key_to_remove);
                key_to_iter.erase(key_to_remove);
            }
            key_to_val_freq[key] = {value, 1};
            freq_to_keys[1].push_back(key);
            key_to_iter[key] = --freq_to_keys[1].end();
            min_freq = 1;
        }
    }
private:
    int cap;
    int min_freq;
    unordered_map<int, pair<int, int>> key_to_val_freq;
    unordered_map<int, list<int>> freq_to_keys;
    unordered_map<int, list<int>::iterator> key_to_iter;
};