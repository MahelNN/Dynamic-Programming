#include <iostream>
#include <bits/stdc++.h>

using namespace std;


/*
 * Write a function 'allConstruct(target, wordBank)' that accepts a
 * target string and an array of strings.
 *
 * The function should return a 2D array containing all the ways
 * that the target can be constructed by concatenating elements of
 * the wordBank array. Each element of the 2D array should represent
 * one combination that constructs the target
 *
 * You may reuse elements of wordBank as many time as needed.
 */


/* Function that takes a 2D array and print its elements */
void show(vector< vector<string>> allconstruct){
    if(allconstruct.empty()){
        cout << "[]" << endl;
        return;
    }
    cout << "[" << endl;
    for(int i{0}, n=allconstruct.size(); i<n; i++){
        cout << "  [";
        for(int j{0}, m=allconstruct[0].size(); j<m; j++){
            cout <<allconstruct[i][j];
            if(j!=m-1) cout << ", ";
        }
        if(i!=n-1) cout << "];" << endl;
        else cout << "]" << endl;
    } cout << "]" << endl;
}

vector< vector<string>>  allConstruct(string target, vector<string> wordBank){
    int n = target.size();
    vector<vector<string>> tmp;
    vector<vector<vector<string>>> tab(n+1, tmp);
    tab[0] = {{}};
    for(int i{0}; i<n+1; i++){
        for(auto& word : wordBank){
            if(target.substr(i, word.size())==word){
                vector<vector<string>> tmp1 = tab[i];
                for(auto& t : tmp1){
                    t.push_back(word);
                    tab[i+word.size()].push_back(t);
                }
            }
        }
    }
    return  tab[n];
}

int main()
{

    show(allConstruct("purple", {"purp", "p", "ur", "le", "purpl"})); cout << endl; //2 words
    show(allConstruct("abcdef", {"ab", "abc", "cd", "def", "abcd"}));  cout << endl; //1 word
    show(allConstruct("skateboard", {"bo", "rd", "ate", "t", "ska", "sk", "boar"})); cout << endl; //0 word
    show(allConstruct("enterapotentpot", {"a", "p", "ent", "enter", "ot", "o", "t"})); cout << endl; //4 words
    show(allConstruct("eeeeeeeeeeeeef", {
                          "e",
                          "ee",
                          "eee",
                          "eeee",
                          "eeeee",
                          "eeeeee"
                      })); //0 word

    return 0;
}
