#include "mat.hpp"
#include <vector>

namespace ariel{
    string mat(int col, int row, char c1, char c2){
        //Checking for Errors:
        //  Need to implement error check here:

        //////////////////////////////////////////////////////////////////////////////
        // Creating the 2D vector representing the carpet:
        vector<vector<char>> carpet(row, vector<char>(col, '0'));
        int max_size = row*col;

        // Creating the relevent boundry pointers:
        int top = 0;
        int bottom = row - 1;
        int left = 0;
        int right = col - 1;
        char symbol = c2;

        // implementing the carpet vector:
        while(carpet.size() < max_size){
            // deciding which symbol to implement"
            if(symbol==c2){
                symbol = c1;
            }
            else{
                symbol = c2;
            }

            //adding the top row of the current loop:
            for(int i=left; i<=right && carpet.size() < max_size; i++){
                carpet[top][i] = symbol;
            }
            top++; // updating the top pointer for the next loop.

            //adding right column of the current loop:
            for(int i=top; i<=bottom && carpet.size() < max_size; i++){
                carpet[i][right] = symbol;
            }
            right--; // updating the right pointer for the next loop.

            //adding the bottom row of the current loop:
            for(int i=right; i>=left && carpet.size() < max_size; i--){
                carpet[bottom][i];
            }
            bottom--; // updating the bottom pointer for the next loop.

             //adding the left column of the current loop.
            for(int i=bottom; i>=top && carpet.size() < max_size; i--){
                carpet[i][left] = symbol;
            }
            left++; // updating the left pointer for the next loop.
        }

        // implementing a string of the vector:
        string str;
        for(int i=0; i<row; i++){
            for(int j=0; j<col; j++){
                str += carpet[i][j];
            }
            str += '\n';
        }
        return str;
    }
}