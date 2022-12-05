#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/*
 * Count the number of differenct ways to move through a 6x9 grid.
 * Say that you are a traveller on a 2D grid. You begin int the
 * top-left corner and your goal is to travel to the bottom-right
 * corner. You may only move down or right.
 *
 * In how many ways can you travel to the goal on a grid with
 * dimension m * n ?
 *
 * Write a function 'gridTraveler(m, n)' that calculates this.
 */

int64_t gridTraveler(int64_t n, int64_t m){
    vector< vector<int64_t> > v(
                n+1,
                vector<int64_t> (m+1, 0));
    v[1][1] = 1;
    for(int64_t i{0}; i<n+1; i++)
        for(int64_t j{0}; j<m+1; j++){
            if(j < m) v[i][j+1] += v[i][j];
            if(i < n) v[i+1][j] += v[i][j];
        }
    return v[n][m];
}

int main()
{
    cout << gridTraveler(1,1) << endl; //1
    cout << gridTraveler(2,3) << endl; //3
    cout << gridTraveler(3,2) << endl; //3
    cout << gridTraveler(3,3) << endl; //6
    cout << gridTraveler(18,18) << endl; // 2333606220
    return 0;
}
