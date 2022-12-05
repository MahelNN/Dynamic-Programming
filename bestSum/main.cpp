#include <iostream>
#include <vector>
#include <bits/stdc++.h>

using namespace std;

/*
 * Write a function 'bestSum(targetSum, numbers)' that takes in a
 * targertSum and an array of numbers as arguments.
 *
 * The function should return an array containing the shortest
 * combination of numbers that add up to exactly the targetSum.
 *
 * If there is a tie for the shortest combination, you may return
 * any one of the shortest.
 */


/* Function that takes in an array an print its elements */

void show(vector<int> tab){
    if(tab.empty()) return;
    for(auto& n: tab) cout << n << " "; cout << endl;
}


void bestSum(int targetSum, vector<int> numbers, vector<int>& result){
    vector<vector<int>> tab(targetSum+1); tab[0] = {};
    int maxNum = *max_element(numbers.begin(), numbers.end());
    int m = targetSum/maxNum-1;
    if(m>0) targetSum -= m*maxNum;

    for(int i{0}; i<targetSum+1; i++)
        if(tab[i].empty()==false || i==0)
            for(auto& num : numbers)
                if(i+num < targetSum+1){
                    vector<int> tmp = tab[i];
                    tmp.push_back(num);
                    if(tmp.size() < tab[i+num].size() || tab[i+num].empty())
                        tab[i+num] = tmp;
                }

    result.resize(tab[targetSum].size());
    result=tab[targetSum];

    if(tab[targetSum].empty()) cout << "null" << endl;
    else if(m>0)
        for(int i{0}; i<m; i++) result.push_back(maxNum);
}

int main()
{
    vector<int> result;

    bestSum(7, {2,3}, result); show(result);  //[3, 2, 2]
    bestSum(7, {5,3,4,7}, result); show(result); //[7]
    bestSum(7, {2,4}, result);  show(result);  //null
    bestSum(8, {2,3,4,5}, result);  show(result); // [3,5]
    bestSum(300, {7,14}, result);  show(result); //null
    bestSum(21, {2,5,10}, result);  show(result); //
    bestSum(100, {2,5,10, 25}, result);  show(result); //

    return 0;
}
