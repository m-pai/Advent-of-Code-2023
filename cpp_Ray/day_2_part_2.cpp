#include <bits/stdc++.h>
using namespace std;

//----------------------------------------------------------------------------------------------------------
// read n lines
// each line contain a string with alpha-num characters
// create an int using the first and last numerical digit u find in the string
// string can also have subtrings which spell out a number that needs to be taken into account while creating the int
// sum up all those integers and return the result
//----------------------------------------------------------------------------------------------------------

// method to find digit (without map --> more optimised)
int findNum(string str, int i, int n){
    if(str[i] == 'z' && i+4 <= n && str.substr(i,4) == "zero")
    return 0;
    if(str[i] == 'o' && i+3 <= n && str.substr(i,3) == "one") 
    return 1;
    if(str[i] == 't'){
        if(i+3 <= n && str.substr(i,3) == "two")
        return 2;
        if(i+5 <= n && str.substr(i,5) == "three")
        return 3;
    }   
    if(str[i] == 'f' && i+4 <= n){
        if(str.substr(i,4) == "four")
        return 4;
        if(str.substr(i,4) == "five")
        return 5;
    } 
    if(str[i] == 's'){
        if(i+3 <= n && str.substr(i,3) == "six")
        return 6;
        if(i+5 <= n && str.substr(i,5) == "seven")
        return 7;
    }    
    if(str[i] == 'e' && i+5 <= n && str.substr(i,5) == "eight")
    return 8;
    if(str[i] == 'n' && i+4 <= n && str.substr(i,4) == "nine")
    return 9;

    return -1;
}

// method to create the required integer from given string
int createNum(string str){
    int tensDig = -1; 
    int onesDig = -1;
    int len = str.size();

    // find the tens digit
    for(int i=0; i<len; i++){
        if(isdigit(str[i])){
            tensDig = str[i] - '0';
            break;
        }
        tensDig = findNum(str, i, len);
        if(tensDig != -1) break;
    }
    // find the ones digit
    for(int i=len-1; i>=0; i--){
        if(isdigit(str[i])){
            onesDig = str[i] - '0';
            break;
        }
        onesDig = findNum(str, i, len);
        if(onesDig != -1) break;
    }

    return 10*tensDig + onesDig;
}

int main(){    
    string str;
    int num = 0;
    int sum = 0;

    // map<string,int> nums = {
    //     {"zero_", 0}, {"one__", 1}, {"two__", 2}, {"three", 3}, {"four_", 4},
    //     {"five_", 5}, {"six__", 6}, {"seven", 7}, {"eight", 8}, {"nine_", 9}
    // };

    while(true){
        cin >> str;
        if(str == "-1") break;
        // process the string
        num = createNum(str);
        cout << num << endl;
        sum += num;
    }
    cout << "The answer is: " << sum << endl;
    return 0;
}
