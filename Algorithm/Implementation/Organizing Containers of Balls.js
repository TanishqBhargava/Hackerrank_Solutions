'use strict';

const fs = require('fs');

process.stdin.resume();
process.stdin.setEncoding('utf-8');

let inputString = '';
let currentLine = 0;

process.stdin.on('data', inputStdin => {
    inputString += inputStdin;
});

process.stdin.on('end', _ => {
    inputString = inputString.replace(/\s*$/, '')
        .split('\n')
        .map(str => str.replace(/\s*$/, ''));

    main();
});

function readLine() {
    return inputString[currentLine++];
}

// Complete the organizingContainers function below.
function organizingContainers(container) {
    let capacity = [];
    let count = [];

    for(let i = 0; i < container.length; i++){
        capacity.push(container[i].reduce((a, x) => a+x));
        count.push(container.map(x => x[i]).reduce((a, x) => a+x));
    }

    let capacityString = JSON.stringify(capacity.sort((a, b) => a-b));
    let countString = JSON.stringify(count.sort((a, b) => a-b));

    return capacityString == countString ? "Possible" : "Impossible";
}

function main() {
    const ws = fs.createWriteStream(process.env.OUTPUT_PATH);

    const q = parseInt(readLine(), 10);

    for (let qItr = 0; qItr < q; qItr++) {
        const n = parseInt(readLine(), 10);

        let container = Array(n);

        for (let i = 0; i < n; i++) {
            container[i] = readLine().split(' ').map(containerTemp => parseInt(containerTemp, 10));
        }

        let result = organizingContainers(container);

        ws.write(result + "\n");
    }

    ws.end();
}
