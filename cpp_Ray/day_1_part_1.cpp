#include <bits/stdc++.h>
using namespace std;

//----------------------------------------------------------------------------------------------------------
// read n lines
// each line contain a string with alpha-num characters
// create an int using the first and last numerical digit u find in the string
// sum up all those integers and return the result
//----------------------------------------------------------------------------------------------------------


// method to create the required integer from given string
int createNum(string str){
    int tens_dig = 0; 
    int ones_dig = 0;
    int len = str.size();

    // find the tens digit
    for(int i=0; i<len; i++){
        if(isdigit(str[i])){
            tens_dig = str[i] - '0';
            break;
        }
    }
    // find the ones digit
    for(int i=len-1; i>=0; i--){
        if(isdigit(str[i])){
            ones_dig = str[i] - '0';
            break;
        }
    }

    return 10*tens_dig + ones_dig;
}

int main(){    
    string str;
    int num = 0;
    int sum = 0;

    while(true){
        cin >> str;
        if(str == "-1") break;
        // process the string
        num = createNum(str);
        // cout << num << endl;
        sum += num;
    }
    cout << "The answer is: " << sum << endl;
    return 0;
}
