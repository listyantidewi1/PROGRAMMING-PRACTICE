var readlineSync = require('readline-sync');

//ask the user how many changes owed
get_cents = () => {
    var cents = -1;
    while (cents < 0) {
        cents = readlineSync.question("Change owed: ");
    }
    return cents;
}

///calculate the number of quarters
calculate_quarters = (cents) => {
    var quarters = Math.floor(cents / 25);
    return quarters;
}

//calculate the number of dimes
calculate_dimes = (cents) => {
    var dimes = Math.floor(cents / 10);
    return dimes;
}

//calculate the number of nickels
calculate_nickels = (cents) => {
    var nickels = Math.floor(cents / 5);
    return nickels;
}

//calculate the number of pennies
calculate_pennies = (cents) => {
    return cents;
}

var cents = get_cents();

var quarters = calculate_quarters(cents);
cents = cents - quarters * 25;

var dimes = calculate_dimes(cents);
cents = cents - dimes * 10;

var nickels = calculate_nickels(cents);
cents = cents - nickels * 5;

var pennies = calculate_pennies(cents);
cents = cents - pennies * 1;

var coins = quarters + dimes + nickels + pennies;

console.log(coins);