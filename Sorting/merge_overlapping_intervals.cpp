class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
    	
    	int n = intervals.size();  
        sort(intervals.begin(), intervals.end());
        vector<int> aux;
        vector<vector<int>> updatedIntervals;
        
        if(n == 1)
            return intervals;
     
            
        int a = 0, b = 0, c = 0;
        int key = intervals[0][1];
        aux.push_back(intervals[0][0]);
            
            for(int i = 1; i < n; i++)
            {
                if(key >= intervals[i][0] and key <= intervals[i][1])
                    key = intervals[i][1];
                
                else if(key >= intervals[i][0] and key >= intervals[i][1])
                    continue; // DO nothing
                
                else
                {   
                    aux.push_back(key);
                    updatedIntervals.push_back(aux);
                    aux.clear();
                    key = intervals[i][1];
                    aux.push_back(intervals[i][0]);
                    
                }
            }
        
        aux.push_back(key);
        updatedIntervals.push_back(aux);
        
        return updatedIntervals;
    }
};