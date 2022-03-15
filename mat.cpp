#include "mat.hpp" ////(mat.hpp includes: <iostream>,<string>, namespace std) 
#include <vector>

namespace ariel{
    string mat(int col, int row, char c1, char c2){
        // Using const because of error.
        const int min = 33;
        const int max = 126;

        //Checking for Errors:
        if(col < 0 || row < 0){
            throw runtime_error("Negative Row/Column Error!");
        }   
        if(col==0 || row==0){
            throw runtime_error("Zero Row/Column Error!");
        }
        if(col%2==0 || row%2==0){
            throw runtime_error("Even Row/Column Error!");
        }
        if(c1 < min || c2 < min || c1 > max || c2 > max){
            throw out_of_range("c1/c2 Not in Range [33,126] Error!");
        }
        

        //////////////////////////////////////////////////////////////////////////////
        // Creating the Carpet:

        string str;

        // If row or column are 1 (shortening the code):
        if(col==1 || row==1){
            for(int i=0; i<row; i++){
                for(int j=0; j<col; j++){
                    str += c1;
                }
                str += '\n';
            }
            str.pop_back();   
        }
        
        else{
            // Creating the 2D vector representing the carpet (Vector of Vectors):
            // Inititializing the inner vectors with '0' because it makes it easier to spot printing errors.
            vector<vector<char>> carpet(row, vector<char>(col, '0'));
            int max_size = row * col; // The maximum amount of elements the main vector can hold.

            // Creating the relevent boundry pointers:
            //These pointers will help point to the correct place int vector.
            int top = 0;
            int bottom = row - 1;
            int left = 0;
            int right = col - 1;
            char symbol = c2;
            int counter = 0;

            // implementing the carpet vector:
            // Using a while loop to fill the main Vector.
            // Stops when the counter reaches the max size.
            // This while loop was ispired by a video I found online: https://www.youtube.com/watch?v=BdQ2AkaTgOA
            while(counter < max_size){

                // deciding which symbol to implement"
                if(symbol==c2){
                    symbol = c1;
                }
                else{
                    symbol = c2;
                }

                //adding the top row of the current loop:
                for(int i=left; i<=right; i++){
                    carpet[top][i] = symbol;
                    counter++;
                }
                top++; // updating the top pointer for the next loop.

                //adding right column of the current loop:
                for(int i=top; i<=bottom; i++){
                    carpet[i][right] = symbol;
                    counter++;
                }
                right--; // updating the right pointer for the next loop.

                //adding the bottom row of the current loop:
                for(int i=right; i>=left; i--){
                    carpet[bottom][i] = symbol;
                    counter++;
                }
                bottom--; // updating the bottom pointer for the next loop.

                //adding the left column of the current loop.
                for(int i=bottom; i>=top; i--){
                    carpet[i][left] = symbol;
                    counter++;
                }
                left++; // updating the left pointer for the next loop.
            }

            // implementing a string of the vector:
            // looping through the carpet vector and coping the elements into string str.
            // using pop_back() to get rid of the last '\n' in str.
            for(int i=0; i<row; i++){
                for(int j=0; j<col; j++){
                    str += carpet[i][j];
                }
                str += '\n';
            }
            str.pop_back();
            
        }
        return str;
    }
}