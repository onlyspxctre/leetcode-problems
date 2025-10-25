#include <stdbool.h>
#include <stdio.h>

void gameOfLife(int** board, int boardSize, int* boardColSize) {
    for (int r = 0; r < boardSize; ++r) {
        for (int c = 0; c < *boardColSize; ++c) {
            int* cell = &board[r][c];

            if (*cell == 0) {
                *cell = 100;
            }

            int r_offset;
            int c_offset;

            int neighbor;
            for (r_offset = -1; r_offset <= 1; ++r_offset) {

                if (r + r_offset < 0 || r + r_offset >= boardSize) {
                    continue;
                }

                for (c_offset = -1; c_offset <= 1; ++c_offset) {
                    if (r_offset == 0 && c_offset == 0) {
                        continue;
                    }
                    if (c + c_offset < 0 || c + c_offset >= *boardColSize) {
                        continue;
                    }

                    neighbor = board[r + r_offset][c + c_offset];

                    if (neighbor > 0 && neighbor < 100) {
                        *cell += 1;
                    }
                }
            }
        }
    }

    for (int r = 0; r < boardSize; ++r) {
        for (int c = 0; c < *boardColSize; ++c) {
            int* cell = &board[r][c];

            if (*cell >= 100) {
                *cell -= 100;

                *cell = *cell == 3 ? 1 : 0;
            }
            else {
                *cell -= 1;

                switch (*cell) {
                    case 2:
                    case 3:
                        *cell = 1;
                        break;
                    default:
                        *cell = 0;
                        break;
                }
            }
        }
    }
}
