#include <iostream>
#include <vector>
using namespace std;


/*
 * Write a function 'howSum(targetSum, numbers)' that takes in a
 * targertSum and an array of numbers as arguments.
 *
 * The function should return an array containing any combination of
 * elements that add up to exactly the targetSum.
 *
 * If there is non combination that add up to the targetSum,
 * then return null.
 *
 * If there are multiple combinations possible, you may return any
 * single one.
 */

/* Function that takes in array and print its elements */
void show(vector<int> tab){
    if(tab.empty()) return;
    for(auto& n: tab) cout << n << " "; cout << endl;
}

void howSum(int targetSum, vector<int> numbers, vector<int>& result){
    vector< vector<int>> tab(targetSum+1);
    tab[0] = {};
    for(int i{0}; i<targetSum+1; i++){
        if(tab[i].empty()==false || i==0){
            for(auto& num : numbers){
                if(i+num < targetSum+1){
                    vector<int> tmp = tab[i];
                    tmp.push_back(num);
                    tab[i+num] = tmp;
                }
            }
        }
    }
    result.resize(tab[targetSum].size());
    result = tab[targetSum];
    if(tab[targetSum].empty()==true) cout << "null" << endl;
}

int main()
{
    vector<int> result;
    howSum(7, {2,3}, result); show(result);  //[3, 2, 2]
    howSum(7, {5,3,4,7}, result); show(result); //[4,3]
    howSum(7, {2,4}, result);  show(result);  //null
    howSum(8, {2,3,4,5}, result);  show(result); // [2,2,2,2]
    howSum(300, {7,14}, result);  show(result); //null
    return 0;
}
