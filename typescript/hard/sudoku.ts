function validateNum(board: string[][], num: number, i: number,j: number): boolean{
    //check col
    for(let col: number = 0; col < 9; col++){
        if(board[i][col] === String(num)) return false
    }

    //check row
    for(let row: number = 0; row < 9; row++){
        if(board[row][j] === String(num)) return false;
    }

    //check 3 * 3
    let startCol: number = Math.floor(j / 3) * 3;
    let startRow: number = Math.floor(i / 3) * 3;
    for(let row: number = 0; row < 3; row++){
        for(let col: number = 0; col < 3; col++){
            if(board[startRow + row][startCol + col] === String(num)) return false;
        }
    }

    return true;
}

function solveSudoku(board: string[][]): boolean{
    for(let i: number = 0; i < 9; i++){
        for(let j: number = 0; j < 9; j++){
            if(board[i][j] === "."){
                for(let pos: number = 1; pos <= 9; pos++){
                    if(validateNum(board, pos, i, j)){
                        board[i][j] = String(pos);
                        if(solveSudoku(board)){
                            return true;
                        }else{
                            board[i][j] = ".";
                        }
                    }
                }
                return false;
            }
        }
    }

    return true;
};

export function sSudoku(){
    let board = [
        ["5","3",".",".","7",".",".",".","."],
        ["6",".",".","1","9","5",".",".","."],
        [".","9","8",".",".",".",".","6","."],
        ["8",".",".",".","6",".",".",".","3"],
        ["4",".",".","8",".","3",".",".","1"],
        ["7",".",".",".","2",".",".",".","6"],
        [".","6",".",".",".",".","2","8","."],
        [".",".",".","4","1","9",".",".","5"],
        [".",".",".",".","8",".",".","7","9"]
    ];

    solveSudoku(board);
}

