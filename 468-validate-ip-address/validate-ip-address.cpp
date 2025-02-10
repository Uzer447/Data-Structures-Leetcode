class Solution {
public:
    string validIPAddress(string IP) {
        if (isIPv4(IP)) {
            return "IPv4";
        } 
        if (isIPv6(IP)) {
            return "IPv6";
        }
        return "Neither";
    }

private:
    bool isIPv4(string IP) {
        if (count(IP.begin(), IP.end(), '.') != 3) {
            return false;
        }
        auto segments = splitByDot(IP);
        if (segments.size() != 4) {
            return false;
        }
        for (auto& seg : segments) {
            if (seg.empty() || seg.size() > 3 || (seg.size() > 1 && seg[0] == '0')) {
                return false;
            }
            for (char ch : seg) {
                if (!isdigit(ch)) {
                    return false;
                }
            }
            if (stoi(seg) > 255) {
                return false;
            }
        }
        return true;
    }

    bool isIPv6(string IP) {
        if (count(IP.begin(), IP.end(), ':') != 7) {
            return false;
        }
        auto segments = splitByColon(IP);
        if (segments.size() != 8) {
            return false;
        }
        for (auto& seg : segments) {
            if (seg.empty() || seg.size() > 4) {
                return false;
            }
            for (char ch : seg) {
                if (!isxdigit(ch)) {
                    return false;
                }
            }
        }
        return true;
    }

    vector<string> splitByDot(const string& s) {
        vector<string> parts;
        string part;
        istringstream stream(s);
        while (getline(stream, part, '.')) {
            parts.push_back(part);
        }
        return parts;
    }

    vector<string> splitByColon(const string& s) {
        vector<string> parts;
        string part;
        istringstream stream(s);
        while (getline(stream, part, ':')) {
            parts.push_back(part);
        }
        return parts;
    }
};