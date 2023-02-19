const readline = require('readline').createInterface({
    input: process.stdin,
    output: process.stdout,
});

readline.question(`What is your name? `, name => {
    console.log(`hello, ${name}`);
    readline.close();
});