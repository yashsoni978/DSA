/*Brute Force Approach (Simulation)
Idea

Simulate the CPU execution one unit of time at a time.

Count the frequency of each task.
At every time unit, execute the available task with the highest remaining frequency.
If no task is available because of the cooldown, CPU stays idle.
Repeat until all tasks are completed.

This approach is straightforward but inefficient because we simulate every time slot.

Algorithm
Count frequency of each task.
Maintain cooldown information for each task.
At every unit of time:
Choose the available task with maximum remaining frequency.
Execute it.
Put it into cooldown.
If no task is available, insert an idle slot.
Continue until all tasks finish.
Time Complexity
In the worst case, every time slot scans all 26 tasks.
O(T × 26) ≈ O(T)

where T is the total schedule length (including idle slots).

Space Complexity
O(26)*/

class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        vector<int>freq(26,0);
        for(char ch : tasks) freq[ch - 'A']++;
        priority_queue<int>maxH;
        for(int f : freq){
            if(f > 0) maxH.push(f);
        }
        queue<pair<int,int>>q;
        int time = 0;
        while(!maxH.empty() || !q.empty()){
            time++;
            if(!maxH.empty()){
                int cnt = maxH.top();
                maxH.pop();
                cnt--;
                if(cnt > 0) q.push({cnt, time + n});
            }
            if(!q.empty() && q.front().second == time){
                maxH.push(q.front().first);
                q.pop();
            }
        }
        return time;
    }
};

/*Optimal Approach (Greedy Formula)
Observation

The task with the maximum frequency determines the minimum possible schedule length.

Example

Tasks = A A A B B C
n = 2

Since A occurs the most, place them first.

A _ _ A _ _ A

There are

maxFreq - 1

gaps.

Each gap has size

n

We try to fill these gaps using other tasks.

Formula

Let

maxFreq = maximum frequency
countMax = number of tasks having maximum frequency

Then

Minimum intervals

=
(maxFreq - 1) * (n + 1)
+ countMax

However,

if total tasks are larger than this value, answer becomes

tasks.size()

Hence

Answer = max(tasks.size(),
             (maxFreq-1)*(n+1)+countMax)*/

class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        vector<int>freq(26,0);
        for(char ch : tasks) freq[ch - 'A']++;
        int maxFreq = *max_element(freq.begin(), freq.end());
        int cntMax = 0;
        for(int f : freq){
            if(f == maxFreq) cntMax++;
        }
        return max((int)tasks.size(), (maxFreq - 1) * (n + 1) + cntMax);
    }
};

/*Time Complexity
Count frequency = O(n)
Traverse frequency array (26 letters) = O(26)

Overall:

O(n)

Space Complexity
Frequency array of size 26

O(1)*/

/*Why does the formula work?

Suppose the most frequent task appears maxFreq times.

We first place these tasks:

A _ _ A _ _ A

There are:

maxFreq - 1 gaps
Each gap must contain at least n intervals before another A can be executed.

So the minimum framework needed is:

(maxFreq - 1) × (n + 1)

The +1 accounts for the task itself plus its following cooldown block.

If multiple tasks share the same maximum frequency, they occupy the last positions together, so we add:

countMax

Finally:

If other tasks completely fill (or exceed) the idle slots, no idle time is needed, and the answer is simply the total number of tasks.
Otherwise, the formula gives the minimum required schedule length.*/