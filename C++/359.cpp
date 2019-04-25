__________________________________________________________________________________________________
class Logger {
public:
    Logger() {}
    
    bool shouldPrintMessage(int timestamp, string message) {
        if (!m.count(message)) {
            m[message] = timestamp;
            return true;
        } 
        if (timestamp - m[message] >= 10) {
            m[message] = timestamp;
            return true;
        }
        return false;
    }

private:
    unordered_map<string, int> m;
};
__________________________________________________________________________________________________
class Logger {
public:
    Logger() {}
    
    bool shouldPrintMessage(int timestamp, string message) {
        if (timestamp < m[message]) return false;
        m[message] = timestamp + 10;
        return true;
    }

private:
    unordered_map<string, int> m;
};
__________________________________________________________________________________________________
