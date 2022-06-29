#ifndef VALIDSUDOKU_H    // To make sure you don't declare the function more than once by including the header multiple times.
#define VALIDSUDOKU_H

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <bits/stdc++.h>
#include <utility> 
 
bool isValidSudoku(std::vector<std::vector<int>>& board) {
        
        std::vector<std::vector<int>> row = std::vector<std::vector<int>> (9,std::vector<int> (9,0));
        std::vector<std::vector<int>> column = std::vector<std::vector<int>> (9,std::vector<int> (9,0));
        std::vector<std::vector<int>> block = std::vector<std::vector<int>> (9,std::vector<int> (9,0));
        
        int i=0;int j=0;int number;
        
        for(i=0;i<9;i++){
            for(j=0;j<9;j++){
                if(board[i][j] == 0)
                    continue;
                number = board[i][j];
               // cout << number << endl;
                if(row[i][number] || 
                   column[j][number] ||
                   block[i / 3 * 3 + j / 3][number])
                    return false;
                
                row[i][number] = 1; 
                column[j][number] = 1;
                block[i / 3 * 3 + j / 3][number] = 1;
            }
        }
        
        return true;
}

#endif
