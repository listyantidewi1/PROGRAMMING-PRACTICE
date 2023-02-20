const readline = require('readline').createInterface({
    input: process.stdin,
    output: process.stdout,
});

readline.question(`What is your name? `, yourname => {
    console.log(`hello ` + yourname);
    readline.close();
});


// name = readline.question('What is your name?');
// console.log('Hello, ' + name);
// readline.close();