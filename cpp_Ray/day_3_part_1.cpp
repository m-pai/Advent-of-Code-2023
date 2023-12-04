#include <bits/stdc++.h>
using namespace std;

//----------------------------------------Problem Description------------------------------------------------------------------
// read the input lines, sum up all the numbers that are appearnig adjacent
// to a symbol other than the period. 
//----------------------------------------------------------------------------------------------------------

bool isValidNum(vector<string> grid, int row, vector<int> pos, int n, int m){
    // check is there's a symbol in the neighbour
    for(int col: pos){
        for(int i=-1; i<2; i++){
            for(int j=-1; j<2; j++){
                if(row+i < 0 || col+j < 0 || row+i >= n || col+j >= m) continue;
                char c = grid[row+i][col+j];
                if(c != '.' && !isdigit(c))
                return true;
            }
        }
    }
    return false;
}

int partSum(vector<string> grid, int n, int m){
    // sum up all the valid numbers in the line    
    int sum = 0;
    for(int row=0; row<n; row++){
        for(int i=0; i<m; i++){
            string numStr = "";
            vector<int> pos;

            while(isdigit(grid[row][i])){
                pos.push_back(i);
                numStr += grid[row][i];
                i++;
            }            
            if(isValidNum(grid, row, pos, n, m)) sum += stoi(numStr);
        }
    }
    return sum;
}

int main(){    
    string str;
    vector<string> grid;

    while(getline(cin, str)){
        if(str.empty()) break;
        grid.push_back(str);
    }

    int n = grid.size(); int m = grid[0].size();

    cout << "The answer is: " << partSum(grid, n, m) << endl;
    return 0;
}