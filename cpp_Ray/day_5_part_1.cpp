#include <bits/stdc++.h>
using namespace std;

//----------------------------------------Problem Description------------------------------------------------------------------
// store the initial seed numbers
// store every A-to-B map as a 2D array
// for each ith row of the array, 
// arr[0], arr[1], arr[2] are the destination start, source start and the range respectively 
// find the last destination, i.e., the location for each seed
// return the minimum value among those locations
//----------------------------------------------------------------------------------------------------------

void find_dest(vector<vector<long long>> info_map, vector<long long> &arr){
    long long src = 0;
    long long dest = 0; 
    for(int i=0; i<arr.size(); i++){
        src = arr[i]; dest = src;
        for(auto vec: info_map){
            if(src >= vec[1] && src < vec[1]+vec[2]){
                dest = vec[0] + (src-vec[1]);
                break;
            }
        }
        arr[i] = dest;
    }
}

int main(){    
    vector<long long> arr;
    string str; long long num = 0;
    getline(cin, str);
    stringstream ss(str);
    ss >> str;
    while(ss >> num) arr.push_back(num); // seed number stored
    getline(cin, str);

    long long dest=0; long long src=0; long long range=0;

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
        find_dest(info_map, arr);      
    }

    //find the minimum location value
    long long min_location = LONG_LONG_MAX;
    for(auto t: arr) min_location = min(min_location, t);

    cout << "The answer is: " << min_location << endl;
    return 0;
}