type node struct {
    Char byte
    row int
    col int
}

func (n *node) checkChar(board [][]byte, word string) bool {
    if n.Char != word[0] {
        return false
    }
    if len(word) == 1 {
        return true
    }

    neibrs := [4]*node{}
    // Check boarders and filter already checked neighbours
    if n.row > 0 && board[n.row-1][n.col] != '$' {
        neibrs[0] = &node{Char: board[n.row-1][n.col], row: n.row-1, col: n.col}
    }
    if n.col > 0 && board[n.row][n.col-1] != '$' {
        neibrs[1] = &node{Char: board[n.row][n.col-1], row: n.row, col: n.col-1}
    }
    if n.row < len(board)-1 && board[n.row+1][n.col] != '$' {
        neibrs[2] = &node{Char: board[n.row+1][n.col], row: n.row+1, col: n.col}
    }
    if n.col < len(board[0])-1 && board[n.row][n.col+1] != '$' {
        neibrs[3] = &node{Char: board[n.row][n.col+1], row: n.row, col: n.col+1}
    }
    // Set a flag for already checked path
    board[n.row][n.col] = byte('$')
    for i := 0; i < len(neibrs); i++ {
        if neibrs[i] == nil {
            continue
        }
        // Check recursively for following part
        if neibrs[i].checkChar(board, word[1:]) {
            return true
        }
    }
    board[n.row][n.col] = n.Char
    return false
}

func exist(board [][]byte, word string) bool {
    for i := range board {
        for j := range board[i] {
            n := node{
                Char: board[i][j],
                row: i,
                col: j,
            }
            if n.checkChar(board, word) {
                return true
            }
        }
    }
    return false
}