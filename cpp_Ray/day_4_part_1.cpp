#include <bits/stdc++.h>
using namespace std;

//----------------------------------------Problem Description------------------------------------------------------------------
// read multiple lines of input
// sample input: Card 1: 41 48 83 86 17 | 83 86  6 31 17  9 48 53
// for each card, card points = 2^(k-1) 
// where k is the num of ints in RHS that are also in LHS
// sum up all the card points and return the ans
//----------------------------------------------------------------------------------------------------------

int cardPoints(string card){
    int points = 0; string temp; int num; char c;
    int count = 0; //stores the no. of matches in a card
    set<int> winningNums;
    stringstream ss(card);
    ss >> temp >> num >> c;
    getline(ss, temp, '|');
    stringstream ss_(temp);
    // assemble the winning numbers
    while(ss_ >> num){
        winningNums.insert(num);
    }
    // check for each num u have if it is a winning num
    while(ss >> num){
        if(winningNums.find(num) != winningNums.end()) count++;
    }
    points = pow(2, count-1);
    return points;
}

int main(){    
    int result = 0;
    string card;
    while(getline(cin, card)){
        if(card.empty()) break;
        // process card
        result += cardPoints(card);
    }

    cout << "The answer is: " << result << endl;
    return 0;
}
