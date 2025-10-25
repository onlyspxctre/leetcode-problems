# 289: Game of Life

The board is made up of an `m x n` grid of cells, where each cell has an initial state: live (represented by a `1`) or dead (represented by a `0`). Each cell interacts with its eight neighbors (horizontal, vertical, diagonal) using the following four rules (taken from the above Wikipedia article):

1. Any live cell with fewer than two live neighbors dies as if caused by under-population.
2. Any live cell with two or three live neighbors lives on to the next generation.
3. Any live cell with more than three live neighbors dies, as if by over-population.
4. Any dead cell with exactly three live neighbors becomes a live cell, as if by reproduction.

The next state of the board is determined by applying the above rules simultaneously to every cell in the current state of the `m x n` grid board. In this process, births and deaths occur simultaneously.

Given the current state of the board, update the board to reflect its next state.


In order to complete this challenge without the use of O(n + m) space, we must somehow simultaneously store the previous and next state into the cell. Since we are iterating through the board, if we update a previous cell we must still use its original value for the state of the next cell, as every cell in the board is determined simultaneusly. This means that in addition to storing the previous state into the cell, we must also store the amount of neighbors a cell has on the first pass and compute its next state on the second pass.

Luckily, the cells are of type `int`, but the state of the cell is represented as a bit. We must also store the number of alive neighbors a cell has, but since a cell can only have up to 8 neighbors, we can store the numeric value of the amount of alive neighbors in the int and an offset or extra bit for the original state.

In my example, I simply just incremented the cell by 100 if the original state was 0. This allowed me to, on the second pass, determine the original state by checking whether the cell was at least 100. In the end, the cells will have all the information needed to calculate the next state. Obviously, this is a naive approach and storing an extra bit would be a more optimized way of doing things.

The time complexity is O(m + n), where `m` and `n` are the rows and columns of the board, and the space complexity is O(1).
