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

// Complete the countingSort function below.
function countingSort(arr) {
let cArr = new Array(100);
    let final = [];

    for(let i = 0; i < cArr.length; i++){
        cArr[i] = 0;
    }
    for(let i = 0; i < arr.length; i++){
        cArr[arr[i]] += 1;
    }
    for(let i = 0; i < cArr.length; i++){
        for(let j = 0; j < cArr[i]; j++){
            final.push(i);
        }
    }
    return final;

}

function main() {
    const ws = fs.createWriteStream(process.env.OUTPUT_PATH);

    const n = parseInt(readLine(), 10);

    const arr = readLine().split(' ').map(arrTemp => parseInt(arrTemp, 10));

    let result = countingSort(arr);

    ws.write(result.join(" ") + "\n");

    ws.end();
}
