#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/*
 * Write a function 'canSum(targetSum, numbers)' that takes in a
 * targetSum and an array of numbers as arguments.
 *
 * The function should return a boolenan indicating whether or not it
 * is possible to generate the targetSum using numbers from the array.
 *
 * You may use an element of the array as many times as needed.
 * You may assume that all input numbers are nonnegative.
 */

bool canSum(int targetSum, vector<int> numbers){
    vector<bool> tab(targetSum+1, false); tab[0] = true;

    for(int i{0}; i<targetSum+1; i++){
        if(tab[i])
            for(auto& num : numbers){
                if(i+num < targetSum+1) tab[i+num] = true;
            }
    }
    return tab[targetSum];
}

int main()
{
    cout << canSum(7, {2,3}) << endl; //1
    cout << canSum(7, {5,3,4,7}) << endl; //1
    cout << canSum(7, {2,4}) << endl;  //0
    cout << canSum(8, {2,3,4,5}) << endl;  //1
    cout << canSum(300000, {7,14}) << endl;  //0
    return 0;
}
