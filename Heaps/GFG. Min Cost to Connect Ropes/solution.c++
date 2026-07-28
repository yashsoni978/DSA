/* Brute
Idea:
- Repeatedly find the two smallest ropes by scanning the array.
- Remove them and insert their sum back into the array.
- Add the sum to the total cost.
- Repeat until only one rope remains.

TC:
- Finding two smallest ropes: O(n)
- Done (n-1) times
Overall: O(n²)

SC: O(1) (Ignoring the input modifications)
*/

class Solution {
  public:
    int minCost(vector<int>& arr) {
        // code here
        int cost = 0;
        while(arr.size() > 1){
            int first = 0, second = 1;
            if(arr[first] > arr[second]) swap(first, second);
            for(int i=2; i<arr.size(); i++){
                if(arr[i] < arr[first]){
                    second = first;
                    first = i;
                }
                else if(arr[i] < arr[second]) second = i;
            }
            int sum = arr[first] + arr[second];
            cost += sum;
            if(first > second) swap(first, second);
            arr.erase(arr.begin() + second);
            arr.erase(arr.begin() + first);
            arr.push_back(sum);
        }
        return cost;
    }
};

/* Optimal (Min Heap)
Idea:
- Insert all ropes into a min heap.
- Repeatedly remove the two smallest ropes.
- Connect them and add the cost.
- Push the new rope back into the heap.
- Repeat until one rope remains.

Why Min Heap?
- To minimize the total cost, always connect the two smallest ropes first.
- Min heap gives the two smallest ropes in O(log n).

TC:
- Build Heap : O(n)
- (n-1) merge operations : O(n log n)

Overall: O(n log n)

SC: O(n)
*/

class Solution {
public:
    int minCost(vector<int>& arr) {

        priority_queue<int, vector<int>, greater<int>> minH;

        for (int rope : arr)
            minH.push(rope);

        int cost = 0;

        while (minH.size() > 1) {

            int first = minH.top();
            minH.pop();

            int second = minH.top();
            minH.pop();

            int sum = first + second;

            cost += sum;

            minH.push(sum);
        }

        return cost;
    }
};