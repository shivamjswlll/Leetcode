class Solution {
public:
    int numberOfPairs(vector<vector<int>>& points) {
        int cnt = 0;
        int n = points.size();

        for(int i = 0;i<n;i++){
            int Ax = points[i][0];
            int Ay = points[i][1];

            for(int j = 0;j<n;j++){
                if(i != j){
                    int Bx = points[j][0];
                    int By = points[j][1];
                    if(Bx <= Ax && By >= Ay){
                        bool flag = true;
                        for(int k = 0;k<n;k++){
                            if(k!= i && k != j){
                                int Cx = points[k][0];
                                int Cy = points[k][1];
                                if(Cx <= Ax && Cx >= Bx && Cy >= Ay && Cy <= By){
                                    flag = false;
                                    break;
                                }
                            }
                        }
                        if(flag) cnt++;
                    }
                }
            }
        }

        return cnt;

    }
};