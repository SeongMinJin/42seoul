/*
	This program will print its own source when run.
*/
const main = () => {
	/*
		This program will print its own source when run.
	*/
	print();
}

const print = () => {
	const backTick = '`';
	const s = `/*
	This program will print its own source when run.
*/
const main = () => {
	/*
		This program will print its own source when run.
	*/
	print();
}

const print = () => {
	const backTick = '%s';
	const s = %s%s%s;
	console.log(s, backTick, backTick, s, backTick);
}

main();`;
	console.log(s, backTick, backTick, s, backTick);
}

main();
