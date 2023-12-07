#include <bits/stdc++.h>
using namespace std;

//----------------------------------------Problem Description------------------------------------------------------------------
// Read 2 lines of input, ne having the time allowed for each race, second giving the max distance recorded
// for each race, find the number of ways u can beat the record
// if t is the time, d is the max distance recorder, then:
// any value of h satisfying [h*(t-h) > d] will account for 1 way to win that race.
// Count all such h for that race. Return product of counts from all the races.
//----------------------------------------------------------------------------------------------------------

int countWaystoWin(vector<int> &time_allowed, vector<int> &dist_recorded, int size){
    int total = 1;
    for(int i=0; i<size; i++){
        int count = 0;
        int t = time_allowed[i];
        int d = dist_recorded[i];
        for(int h=1; h<=t/2; h++){
            if(h*(t-h) > d){
                count = t - 2*h + 1;
                break;
            }
        }
        total = total * count;
    }
    return total;
}

int main(){    
    int result = 0;
    vector<int> time_allowed;
    vector<int> dist_recorded;
    string str; int num=0; int size=0;

    getline(cin, str);
    stringstream ss(str);
    ss >> str;
    while(ss >> num){
        time_allowed.push_back(num);
        size++;
    }

    getline(cin,str);
    stringstream ss_(str);
    ss_ >> str;
    while(ss_ >> num){
        dist_recorded.push_back(num);
    }

    result = countWaystoWin(time_allowed, dist_recorded, size);
    cout << "The answer is: " << result << endl;
    return 0;
}
