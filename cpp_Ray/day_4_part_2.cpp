#include <bits/stdc++.h>
using namespace std;

//----------------------------------------Problem Description------------------------------------------------------------------
// read multiple lines of input, sample input: Card 1: 41 48 83 86 17 | 83 86  6 31 17  9 48 53
// each card will win one copy each of cards with n susequent card number, n being the number of matches of that card.
// each copy will be processed similar to the original card with that card number.
// find the total number of cards collected, including the originals
//----------------------------------------------------------------------------------------------------------------------------

int num_matches(string card){
    string temp; int num; char c;
    int matches = 0;
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
        if(winningNums.find(num) != winningNums.end()) matches++;
    }
    return matches;
}



int main(){    
    int result = 0;
    unordered_map<int,int> num_cards;
    string card; int i=1; int matches;

    while(getline(cin, card)){
        if(card.empty()) break;
        // process the card
        matches = num_matches(card);
        num_cards[i]++; 
        for(int k=i+1; k<=i+matches; k++) num_cards[k] += num_cards[i];        
        result += num_cards[i];
        i++;
    }

    cout << "The answer is: " << result << endl;
    return 0;
}
