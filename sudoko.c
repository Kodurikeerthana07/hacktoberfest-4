#include <stdbool.h>

bool isValidSudoku(char** board, int boardSize, int* boardColSize) {
    bool row[9][9] = {false};
    bool col[9][9] = {false};
    bool box[9][9] = {false};

    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            char c = board[i][j];
            if (c == '.') continue;

            int num = c - '1';  // Convert '1'-'9' → 0-8
            int boxIndex = (i / 3) * 3 + (j / 3);  // Identify which 3x3 box

            // Check if number already seen in row, column, or box
            if (row[i][num] || col[j][num] || box[boxIndex][num])
                return false;

            // Mark number as seen
            row[i][num] = col[j][num] = box[boxIndex][num] = true;
        }
    }

    return true;
}
