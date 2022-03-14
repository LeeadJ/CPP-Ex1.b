#include "mat.hpp"
#include <vector>

namespace ariel{
    string mat(int col, int row, char c1, char c2){
        //Checking for Errors:
        //  Need to implement error check here:

        //////////////////////////////////////////////////////////////////////////////
        //Printing correct matrix:
        char matrix[row][col];
        int top = 0;
        int bottom = row - 1;
        int left = 0;
        int right = col - 1;

        int counter = 0;
        int matrix_size = row * col;
        char curr = c2;
        while(counter < matrix_size){
            // deciding which symbol to loop"
            if(curr==c2)
                curr = c1;
            else
                curr = c1;
                
            //adding the top row of the current loop:
            for(int i=left; i<=right; i++){
                matrix[top][i] = curr;
            }
            top++; // updating the top pointer for the next loop.

            //adding right column of the current loop:
            for(int i=top; i<= bottom; i++){
                matrix[i][right] = curr;
            }
            right--; // updating the right pointer for the next loop.

            //adding the bottom row of the current loop:
            for(int i=right; i>=left; i++){
                matrix[bottom][i] = curr;
            }
            bottom--; //updating the bottom pointer for the next loop.

            //adding the left column of the current loop.
            for(int i=bottom; i>=top; i++){
                matrix[left][i] = curr;
            }
            left++; //updating the left pointer for the next loop.
        }

        return "";
    }
}