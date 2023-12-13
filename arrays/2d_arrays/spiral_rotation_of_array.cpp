#include <bits/stdc++.h> 
using namespace std; 

class Solution
{   
    public: 
    
    bool checkCount(int count, int r, int c){
        return (count<=(r*c)?true:false);
    }
        
    vector<int> spirallyTraverse(vector<vector<int> > matrix, int r, int c) 
    {
        vector<int> ans;
        int top=0, left=0;
        int bottom=r-1, right=c-1, cnt=0;
        int total=r*c;
    
        while(top<=bottom and left<=right)
        {
         
        if(cnt==total)
            break;
            
        for(int j=left; j<=right; j++){
            ans.push_back(matrix[top][j]);
            cnt++;
        }
        top++;
        
        if(cnt==total)
            break;
        
        for(int i=top; i<=bottom; i++){
            ans.push_back(matrix[i][right]);
            cnt++;
        }
        right--;

        if(cnt==total)
            break; 
        
        for(int j=right; j>=left; j--){
            ans.push_back(matrix[bottom][j]);
            cnt++;
        }
            bottom--;

        if(cnt==total)
            break;

        for(int i=bottom; i>=top; i--){
            ans.push_back(matrix[i][left]);
            cnt++;
        }
        left++;
        }
    return ans;
    }
};

int main() {
    int t;
    cin>>t;
    
    while(t--) 
    {
        int r,c;
        cin>>r>>c;
        vector<vector<int> > matrix(r); 

        for(int i=0; i<r; i++)
        {
            matrix[i].assign(c, 0);
            for( int j=0; j<c; j++)
            {
                cin>>matrix[i][j];
            }
        }

        Solution ob;
        vector<int> result = ob.spirallyTraverse(matrix, r, c);
        for (int i = 0; i < result.size(); ++i)
                cout<<result[i]<<" ";
        cout<<endl;
    }
    return 0;
}
} 