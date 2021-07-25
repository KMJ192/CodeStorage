"use strict";
exports.__esModule = true;
exports.sSudoku = void 0;
function validateNum(board, num, i, j) {
    //check col
    for (var col = 0; col < 9; col++) {
        if (board[i][col] === String(num))
            return false;
    }
    //check row
    for (var row = 0; row < 9; row++) {
        if (board[row][j] === String(num))
            return false;
    }
    //check 3 * 3
    var startCol = Math.floor(j / 3) * 3;
    var startRow = Math.floor(i / 3) * 3;
    for (var row = 0; row < 3; row++) {
        for (var col = 0; col < 3; col++) {
            if (board[startRow + row][startCol + col] === String(num))
                return false;
        }
    }
    return true;
}
function solveSudoku(board) {
    for (var i = 0; i < 9; i++) {
        for (var j = 0; j < 9; j++) {
            if (board[i][j] === ".") {
                for (var pos = 1; pos <= 9; pos++) {
                    if (validateNum(board, pos, i, j)) {
                        board[i][j] = String(pos);
                        if (solveSudoku(board)) {
                            return true;
                        }
                        else {
                            board[i][j] = ".";
                        }
                    }
                }
                //backtraking
                return false;
            }
        }
    }
    console.log(board);
    return true;
}
;
function sSudoku() {
    var board = [
        ["5", "3", ".", ".", "7", ".", ".", ".", "."],
        ["6", ".", ".", "1", "9", "5", ".", ".", "."],
        [".", "9", "8", ".", ".", ".", ".", "6", "."],
        ["8", ".", ".", ".", "6", ".", ".", ".", "3"],
        ["4", ".", ".", "8", ".", "3", ".", ".", "1"],
        ["7", ".", ".", ".", "2", ".", ".", ".", "6"],
        [".", "6", ".", ".", ".", ".", "2", "8", "."],
        [".", ".", ".", "4", "1", "9", ".", ".", "5"],
        [".", ".", ".", ".", "8", ".", ".", "7", "9"]
    ];
    solveSudoku(board);
}
exports.sSudoku = sSudoku;
