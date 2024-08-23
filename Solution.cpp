class Solution{
  public:
    int maxHist(int row[],int m){
        int tp, curr_area=0;
        int max_area=0;
        stack<int>s;
        
        int i=0;
        while(i<m){
            if(s.empty()|| row[s.top()]<=row[i]){
                s.push(i++);
            }
            else{
                tp=s.top();
                s.pop();
                
                curr_area= row[tp] * (s.empty()?
                i
                :
                i-s.top()-1
                );
                if(curr_area>max_area) max_area=curr_area;
            }
        }
        while(!s.empty()){
            tp=s.top();
            s.pop();
            curr_area= row[tp] * (s.empty() ?
            i
            :
            i-s.top()-1
            );
            if(curr_area>max_area) max_area=curr_area;
        }
        return max_area;
    }
    
    int maxArea(int M[MAX][MAX], int n, int m) {
        int res= maxHist(M[0],m);
        for(int i=1;i<n;i++){
            for(int j=0;j<m;j++){
                if(M[i][j]){
                    M[i][j] += M[i-1][j];
                }
            }
            res=max(res, maxHist(M[i],m));
        }
        return res;
    }
};
