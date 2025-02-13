function solution(board, skill) {
    let answer = 0;
    
    const d = Array.from({length:(board.length+1)},()=>Array(board[0].length+1).fill(0));
    
    // 누적합 마킹
    for (let i=0; i<skill.length; i++) {
        const [type, r1, c1, r2, c2, degree] = skill[i];
        const value = type == 2 ? degree : -degree;
        d[r1][c1] += value;
        d[r2+1][c1] += -value;
        d[r1][c2+1] += -value;
        d[r2+1][c2+1] += value;
    }
    
    // 열 처리
    for (let i=1; i<d.length; i++) {
        for (let j=0; j<d[i].length; j++) {
            d[i][j] += d[i-1][j]
        }
    }
    
    // 행 처리
    for (let i=0; i<d.length; i++) {
        for (let j=1; j<d[i].length; j++) {
            d[i][j] += d[i][j-1]
        }
    }
    
    // 적용
    for (let i=0; i<board.length; i++) {
        for (let j=0; j<board[i].length; j++) {
            if (board[i][j] + d[i][j] >= 1) answer++;
        }
    }
    
    return answer;
}
