#include <bits/stdc++.h>
using namespace std;

//----------------------------------------Problem Description------------------------------------------------------------------
// Read 2 lines of input, ne having the time allowed for each race, second giving the max distance recorded
// for each race, find the number of ways u can beat the record
// if t is the time, d is the max distance recorder, then:
// any value of h satisfying [h*(t-h) > d] will account for 1 way to win that race.
// Count all such h for that race. Return product of counts from all the races.
//----------------------------------------------------------------------------------------------------------

long long countWaystoWin(long long time_allowed, long long dist_recorded){
    long long count = 0;
    long long t = time_allowed;
    long long d = dist_recorded;
    for(long long h=1; h<=t/2; h++){
        if(h*(t-h) > d){
            count = t - 2*h + 1;
            break;
        }
    }
    return count;
}

int main(){    
    long long result = 0;
    long long time_allowed = 0;
    long long dist_recorded = 0;
    string str;  char ch;;

    getline(cin, str);
    stringstream ss(str);
    while(ss >> ch){
        if(isdigit(ch)){
            time_allowed = time_allowed*10 + (ch - '0');
        }
    }

    getline(cin,str);
    stringstream ss_(str);
    while(ss_ >> ch){
        if(isdigit(ch)){
            dist_recorded = dist_recorded*10 + (ch - '0');
        }
    }

    result = countWaystoWin(time_allowed, dist_recorded);
    cout << "The answer is: " << result << endl;
    return 0;
}
