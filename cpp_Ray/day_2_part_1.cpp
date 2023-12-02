#include <bits/stdc++.h>
using namespace std;

//----------------------------------------Problem Description----------------------------------------------
// take n lines of input
// input line format: Game 3: 8 green, 6 blue, 20 red; 5 blue, 4 red, 13 green; 5 green, 1 red
// find which games are possible with the bag having:
// only 12 red cubes, 13 green cubes, and 14 blue cubes
// sum up the IDs of those games, return the ans
//----------------------------------------------------------------------------------------------------------

bool isValidSet(string setString){
    int num;
    string color;
    stringstream ss(setString);
    string str;

    while(getline(ss, str, ',')){
        stringstream ss_(str);
        ss_ >> num >> color;
        if(color == "red" && num > 12) return false;
        if(color == "blue" && num > 14) return false;
        if(color == "green" && num > 13) return false;
    }
    return true;
}

void processLine(int &result, string line){
    string temp; string setString;
    int gameID = 0;
    char ch;
    stringstream ss(line);
    ss >> temp >> gameID >> ch;

    while(getline(ss, setString, ';')){
        // process the set
        if(!isValidSet(setString)) return;
    }
    
    result += gameID;
    return;
}

int main(){    
    string line;    
    int result = 0;

    while(getline(cin, line)){
        if(line.empty()) break;
        // process the line
        processLine(result, line);
    }

    cout << "The answer is: " << result << endl;
    return 0;
}