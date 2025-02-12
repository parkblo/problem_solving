function solve(M, N, input) {
	const land = Array.from(input, (a) => a.split(" ").map(Number));
	const dp = Array.from({ length: M }, () => Array(N).fill(0));

	let ans = 0;

	for (let i = 0; i < M; i++) {
		for (let j = 0; j < N; j++) {
			if (land[i][j] === 0) {
				dp[i][j] = 1;
				ans = 1;
			}
		}
	}

	for (let i = 1; i < M; i++) {
		for (let j = 1; j < N; j++) {
			if (land[i][j] > 0) {
				dp[i][j] = 0;
			} else {
				dp[i][j] =
					Math.min(dp[i - 1][j], dp[i][j - 1], dp[i - 1][j - 1]) + 1;
				ans = Math.max(ans, dp[i][j]);
			}
		}
	}

	return ans;
}

const input = [];
let cnt = (mm = nn = 0);
const readline = require("readline");
let rl = readline.createInterface({
	input: process.stdin,
	output: process.stdout,
});

rl.on("line", (line) => {
	if (cnt === 0) {
		const [M, N] = line.split(" ").map(Number);
		mm = M;
		nn = N;
		cnt++;
	} else {
		input.push(line);
		cnt++;
		if (cnt > mm) rl.close();
	}
});

rl.on("close", () => {
	console.log(solve(mm, nn, input));
	process.exit();
});
