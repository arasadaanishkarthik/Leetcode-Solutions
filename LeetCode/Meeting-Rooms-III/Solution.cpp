1class Solution {
2public:
3    int mostBooked(int n, vector<vector<int>>& meetings) {
4        sort(meetings.begin(), meetings.end());
5        
6        priority_queue<int, vector<int>, greater<int>> freeRooms;
7        for(int i = 0; i < n; i++) freeRooms.push(i);
8        
9        priority_queue<pair<long long,int>, vector<pair<long long,int>>, greater<pair<long long,int>>> busy;
10        vector<int> count(n, 0);
11        
12        for(auto &m : meetings){
13            long long start = m[0], end = m[1];
14            long long duration = end - start;
15            
16            while(!busy.empty() && busy.top().first <= start){
17                freeRooms.push(busy.top().second);
18                busy.pop();
19            }
20            
21            if(!freeRooms.empty()){
22                int room = freeRooms.top();
23                freeRooms.pop();
24                count[room]++;
25                busy.push({end, room});
26            } else {
27                auto top = busy.top();
28                busy.pop();
29                long long newEnd = top.first + duration;
30                int room = top.second;
31                count[room]++;
32                busy.push({newEnd, room});
33            }
34        }
35        
36        int ans = 0;
37        for(int i = 1; i < n; i++){
38            if(count[i] > count[ans]) ans = i;
39        }
40        return ans;
41    }
42};