#include <bits/stdc++.h>
using namespace std;

//----------------------------------------Problem Description------------------------------------------------------------------
// read the input lines fin '*' with two numbers adjacent to it - gear.
// gear ratio is multiplication of the 2 nums
// sum up and return all gear ratio
//----------------------------------------------------------------------------------------------------------

int gearRatio(vector<string> grid, int row, int col, int n, int m){
    set<pair<int,int>> coords; int ratio = 1;
    for(int i=-1; i<=1; i++){
        for(int j=-1; j<=1; j++){
            if(row+i < 0 || col+j < 0 || row+i >= n || col+j >= m) continue;
            if(isdigit(grid[row+i][col+j])){
                //find the coordinates of the leading digit in that number
                int c = col+j;
                while(c-1>=0 && isdigit(grid[row+i][c-1])) c--;
                coords.insert({row+i,c});
            }
        }
    }
    if(coords.size() != 2) return 0;
    for(auto p: coords){
        // form the number and find ratio
        int x = p.first; int y = p.second; string num = "";
        while(y < n && isdigit(grid[x][y])) num += grid[x][y++];  
        ratio = ratio*stoi(num);
    }    
    return ratio;
}

int ratioSum(vector<string> grid, int n, int m){
    int ratioSum = 0;
    for(int row=0; row<n; row++){
        for(int col=0; col<m; col++){
            if(grid[row][col] == '*'){
                //find and add up gearRatio, if not a gear, ratio is 0
                ratioSum += gearRatio(grid, row, col, n, m);
            }
        }
    }
    return ratioSum;
}

int main(){    
    string str;
    vector<string> grid;

    while(getline(cin, str)){
        if(str.empty()) break;
        grid.push_back(str);
    }

    int n = grid.size(); int m = grid[0].size();
    cout << "The answer is: " << ratioSum(grid, n, m) << endl;
    return 0;
}