function solve(input, sum) {
	const ar = input.sort((a, b) => a[0] - b[0]);
	const mid = sum / 2;
	for (let i = (curr = 0); i < ar.length; i++) {
		curr += ar[i][1];
		if (curr >= mid) return ar[i][0];
	}
	return ar[ar.length - 1][0];
}

const input = [];
let N = (sum = cnt = 0);
const readline = require("readline");
let rl = readline.createInterface({
	input: process.stdin,
	output: process.stdout,
});

rl.on("line", (line) => {
	if (cnt === 0) N = Number(line);
	else {
		const [X, A] = line.split(" ").map(Number);
		input.push([X,A]);
		sum += A;
	}
	cnt++;
	if (cnt > N) rl.close();
});

rl.on("close", () => {
	console.log(solve(input, sum));
	process.exit();
});
