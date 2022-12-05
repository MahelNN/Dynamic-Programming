#include <iostream>
#include <bits/stdc++.h>

using namespace std;

/*
 * Write a funciton 'countConstruct(target, wordBank)' that accepts a
 * target string and an array of strings
 *
 * The function should return the numbers of ways that the 'target' can
 * be constructed by concatenating elements of the 'wordBank' array.
 *
 * You may reuse elements of wordBank as many times as needed
 */


int countConstruct(string target, vector<string> wordBank){
    int n = target.size();
    vector<int> tab(n+1, 0); tab[0] = 1;

    for(int i{0}; i<n+1; i++)
        for(auto& word : wordBank)
            if(target.substr(i,word.size())==word)
                tab[i+word.size()] += tab[i];
    return tab[n];
}


int main()
{
    cout << countConstruct("purple", {"purp", "p", "ur", "le", "purpl"}) << endl; //2
    cout << countConstruct("abcdef", {"ab", "abc", "cd", "def", "abcd"}) << endl;  //1
    cout << countConstruct("skateboard", {"bo", "rd", "ate", "t", "ska", "sk", "boar"}) << endl; //0
    cout << countConstruct("enterapotentpot", {"a", "p", "ent", "enter", "ot", "o", "t"}) << endl; //4
    cout << countConstruct("eeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeef", {
                               "e",
                               "ee",
                               "eee",
                               "eeee",
                               "eeeee",
                               "eeeeee"
                           }) << endl; //0


    return 0;
}
