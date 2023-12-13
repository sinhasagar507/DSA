class Solution
{
    public:

    int findMinOpeartion(vector<vector<int> > matrix, int n)
    {   
        int sumMax=0, countOps=0;;
        for(int i=0; i<n; i++)
        {   
            int sumRow=0, sumCol=0;
            for(int j=0; j<n; j++){
                sumRow+=matrix[i][j];
                sumCol+=matrix[j][i];
            }
            sumMax=max(sumMax, max(sumRow, sumCol));
        }
        
        for(int i=0; i<n; i++)
        {   
            int sumCalc=0;
            for(int j=0; j<n; j++)
                sumCalc+=matrix[i][j];
            countOps += (sumMax-sumCalc);         
        }
        
        return countOps;
    } 
};
