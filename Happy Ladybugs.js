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

// Complete the happyLadybugs function below.
function happyLadybugs(b) {
let space = false;
    let beside = true;

    for(let i = 0; i < b.length; i++){
        if(b.charAt(i) === `_`){ space = true; }

        else if(b.indexOf(b.charAt(i)) === i){
            let count = 0;
            let j = i + 1;
            let k = i;

            while(j !== 0){
                j = b.indexOf(b.charAt(i), j);

                if(j-k > 1) { beside = false; }
                
                k = j;
                count++;
                j++;
            }
            if(count === 1){ return `NO`; }
        }
    }
    return (space || beside) ? `YES` : `NO`;

}

function main() {
    const ws = fs.createWriteStream(process.env.OUTPUT_PATH);

    const g = parseInt(readLine(), 10);

    for (let gItr = 0; gItr < g; gItr++) {
        const n = parseInt(readLine(), 10);

        const b = readLine();

        let result = happyLadybugs(b);

        ws.write(result + "\n");
    }

    ws.end();
}
