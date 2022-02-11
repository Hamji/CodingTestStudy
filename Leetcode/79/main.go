//https://leetcode.com/problems/word-search/

func exist(board [][]byte, word string) bool {
    // 내부함수 쓰려면 원형 선언해야한단다
    var dfs func(row, col, now int) bool
    dfs = func(row, col, now int) bool {
        // 범위 벗어날 때 검사
        if row < 0 || col < 0 || row >= len(board) || col >= len(board[0]) {
            return false
        }
        // 길이가 word 길이라면 맞는지
        if now == len(word) - 1 {
            return word[now] == board[row][col]
        }    
        // 다르다면 가지치기
        if word[now] != board[row][col]{
            return false
        }
        
        // 재귀 불렀을 때 왔던 방향으로 또 오면 안되니깐 잠깐 공백으로 비운다
        var temp = board[row][col]
        board[row][col] = ' '
        
        // 상하좌우
        var result = dfs(row + 1, col, now+1) || dfs(row - 1, col, now+1) || dfs(row, col + 1, now+1) || dfs(row, col - 1, now+1) 
        
        board[row][col] = temp        
        return result
    }
    
    for i := 0; i < len(board); i++{
        for j := 0; j < len(board[0]); j++{
            if dfs(i, j, 0){
                return true
            }
        }
    }
    
    
    return false
}
