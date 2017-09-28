class Solution {
public:
    int calPoints(vector <string> &ops) {
        vector<int> history;
        for (auto &op : ops) {
            if (op == "+") {
                history.push_back(history.back() + history[history.size() - 2]);
            } else if (op == "D") {

                history.push_back(history.back() * 2);
            } else if (op == "C") {
                history.pop_back();
            } else {
                history.push_back(stoi(op));
            }
        }
        int result = 0;
        for (auto item : history) {
            result += item;
        }
        return result;
    }
};