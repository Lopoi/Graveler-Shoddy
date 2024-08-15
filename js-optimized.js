let start = Date.now()
let rounds = 231;
let rolls = 0;
let maxRolls = parseInt(process.argv[2] ?? 100)
console.log('Running for ' + maxRolls + ' rolls');
let ones = 0;
let maxOnes = 0;
let items = [1, 2, 3, 4];
while (ones < 177 && rolls < maxRolls) {
    ones = 0;
    for (let i = 0; i < rounds; i++) {
        let roll = items[Math.floor(Math.random() * 4)];
        if (roll == 1) {
            ones++;
            if (i > maxOnes && ones + (rounds - i) < maxOnes) {
                break;
            }
        }
    }
    rolls++;
    if (ones > maxOnes) {
        console.log(ones);
        maxOnes = ones;
    }
}
let end = Date.now();
console.log('Time: ' + (end - start) / 1000 + 's');
console.log('Max: ' + maxOnes);