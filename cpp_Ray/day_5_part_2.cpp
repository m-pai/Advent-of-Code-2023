#include <iostream>
#include <sstream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

//----------------------------------------Problem Description------------------------------------------------------------------
// store the initial seed numbers, this time in the form of pairs: (start, range)
// store every A-to-B map as a 2D array
// for each ith row of the array, 
// arr[0], arr[1], arr[2] are the destination start, source start and the range respectively 
// find the last destination, i.e., the location for each seed
// return the minimum value among those locations
//----------------------------------------------------------------------------------------------------------

queue<pair<long long, long long>> find_dest(vector<vector<long long>> &info_map, 
    queue<pair<long long, long long>> &end_points){
    queue<pair<long long, long long>> result;
    while(!end_points.empty()){
        auto p = end_points.front();
        end_points.pop();
        long long dest1=p.first, dest2=p.second;
        for(auto vec: info_map){
            //check if first endpoint is in range
            if(p.first >= vec[1] && p.first < vec[1]+vec[2]){
                //check if second endpoint is in range
                if(!(p.second < vec[1]+vec[2])){
                    //when not in range, split the pair, add the new pair to Q
                    end_points.push({vec[1]+vec[2], p.second});
                    p.second = vec[1] + vec[2] - 1;
                }
                //add the first pair to result
                dest1 = p.first - vec[1] + vec[0];
                dest2 = p.second - vec[1] + vec[0];
                break;
            }
        }
        result.push({dest1, dest2});
    }
    return result;
}

int main(){    
    long long result = LONG_LONG_MAX;
    string str; 
    long long num = 0; 
    long long range = 0; 
    queue<pair<long long, long long>> end_points;

    getline(cin, str);
    stringstream ss(str);
    ss >> str;
    //store seed values in terms of endpoint pairs
    while(ss >> num >> range) end_points.push({num, num+range-1});
    getline(cin, str);

    long long dest=0; long long src=0; range=0;

    //keep updating end_points with new destination values
    while(true){
        vector<vector<long long>> info_map;
        getline(cin, str);
        if(str.empty()) break;
        while(true){
            getline(cin,str);
            if(str.empty()) break;
            stringstream ss(str);
            ss >> dest >> src >> range;
            info_map.push_back({dest, src, range});
        }
        end_points = find_dest(info_map, end_points);   
    }

    //find the minimum location value
    while(!end_points.empty()){
        result = min(result, end_points.front().first);
        end_points.pop();
    }

    cout << "The answer is: " << result << endl;
    return 0;
}