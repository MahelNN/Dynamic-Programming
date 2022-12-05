#include <iostream>
#include <bits/stdc++.h>

using namespace std;

/*
 * Write a funciton 'canConstruct(target, wordBank)' that accepts a
 * target string and an array of strings
 *
 * The function should return a boolean indicating whether or not the
 * target can be constructed by concatenating elements of the
 * wordBank array.
 *
 * You may reuse elements of wordBank as many times as needed
 */


bool canConstruct(string target, vector<string> wordBank){
    int n = target.size();
    vector<bool> tab(n+1, false);
    tab[0] = true;

    for(int i{0}; i<n+1; i++)
        if(tab[i])
            for(auto& word : wordBank)
                if(target.substr(i,word.size())==word)
                    tab[i+word.size()] = true;
    return tab[n];
}


int main()
{
    cout << canConstruct("abcdef", {"ab", "abc", "cd", "def", "abcd"}) << endl;  //true
    cout << canConstruct("skateboard", {"bo", "rd", "ate", "t", "ska", "sk", "boar"}) << endl; //false
    cout << canConstruct("enterapotentpot", {"a", "p", "ent", "enter", "ot", "o", "t"}) << endl; //true
    cout << canConstruct("eeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeef", {
                             "e",
                             "ee",
                             "eee",
                             "eeee",
                             "eeeee",
                             "eeeeee"
                         }) << endl; //false

    return 0;
}
