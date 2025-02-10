function solve(input) {
	const N = Number(input[0]);
	const drink = input[1].split(" ").map(Number);

	const sorted = drink.sort((a,b)=>a-b);

	let sum = sorted[sorted.length-1];
	for (let i=0; i<sorted.length-1; i++) {
		sum += (sorted[i]/2);
	}

	return sum;
}


const input = [];
let cnt = 0;
const readline = require("readline");
let rl = readline.createInterface({
	input: process.stdin,
	output: process.stdout,
});

rl.on("line", (line) => {
	input.push(line)
	cnt++;
	if (cnt > 1) rl.close();
});

rl.on("close", () => {
	console.log(solve(input));
	process.exit();
});
