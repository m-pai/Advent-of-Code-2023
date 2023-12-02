#include <bits/stdc++.h>
using namespace std;

//----------------------------------------Problem Description----------------------------------------------
// take n lines of input
// input line format: Game 3: 8 green, 6 blue, 20 red; 5 blue, 4 red, 13 green; 5 green, 1 red
// find min num of cubes of each color to make that possible
// power is the product of those numbers for each color
// sum up the powers of all games, return the ans
//----------------------------------------------------------------------------------------------------------

void processSet(string setString, map<string,int> &maxNumOfCubes){
    int num;
    string color;
    stringstream ss(setString);
    string str;

    while(getline(ss, str, ',')){
        stringstream ss_(str);
        ss_ >> num >> color;
        if(num > maxNumOfCubes[color]) maxNumOfCubes[color] = num;
    }
    return;
}

int powerOfCubes(string line){
    string temp; string setString;
    int gameID = 0;
    char ch;
    map<string,int> maxNumOfCubes = {{"red",0}, {"blue",0}, {"green",0}};
    stringstream ss(line);

    ss >> temp >> gameID >> ch;
    while(getline(ss, setString, ';')){
        // process the set
        processSet(setString, maxNumOfCubes);
    }
    
    int power = maxNumOfCubes["red"] * maxNumOfCubes["blue"] * maxNumOfCubes["green"];
    return power;
}

int main(){    
    string line;    
    int result = 0;

    while(getline(cin, line)){
        if(line.empty()) break;
        // process the line
        result += powerOfCubes(line);
    }

    cout << "The answer is: " << result << endl;
    return 0;
}