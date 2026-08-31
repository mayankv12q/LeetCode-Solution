class Solution {
public:
    string predictPartyVictory(string senate) {
        int n = senate.length();
        queue<int> radiant;
        queue<int> dire;

        // Step 1: Populate queues with initial indices
        for (int i = 0; i < n; ++i) {
            if (senate[i] == 'R') {
                radiant.push(i);
            } else {
                dire.push(i);
            }
        }

        // Step 2: Simulate rounds
        while (!radiant.empty() && !dire.empty()) {
            int rIndex = radiant.front();
            radiant.pop();
            int dIndex = dire.front();
            dire.pop();

            // The senator with the earlier turn bans the opponent
            if (rIndex < dIndex) {
                // Radiant wins this match, goes to the next round
                radiant.push(rIndex + n);
            } else {
                // Dire wins this match, goes to the next round
                dire.push(dIndex + n);
            }
        }

        // Step 3: Return the party whose queue is not empty
        return radiant.empty() ? "Dire" : "Radiant";
    }
};