const readline = require('readline').createInterface({
    input: process.stdin,
    output: process.stdout,
});

readline.question(`What is your name? `, yourname => {
    if(yourname.length === 0){
        // console.log(`please enter your name`);
    }
    console.log(`hello ` + yourname);
    readline.close();
});


// name = readline.question('What is your name?');
// console.log('Hello, ' + name);
// readline.close();