var partOne = true; //changed in read function

//print answers in the HTML document
function printAnswer(stackList) {
    var answer = "";
    stackList.forEach(stack => {
        answer += stack.pop();
    });
    if (partOne) {
        document.getElementById("answerOne").innerText = answer;
    } else {
        document.getElementById("answerTwo").innerText = answer;
    }

}

//the meat of the coding challenge
function runCommand(stackList, command) {
    var quantityToMove = command[0];
    var from = command[1] - 1;
    var to = command[2] - 1;

    //part one of coding challenge
    if (partOne) {
        for (var i = 0; i < quantityToMove; i++) {
            let container = stackList[from].pop();
            stackList[to].push(container);
        }
    //part two of coding challenge
    } else {
        let group = [];
        for (var i = 0; i < quantityToMove; i++) {
            let container = stackList[from].pop();
            group.unshift(container);
        }
        for (var i = 0; i < quantityToMove; i++) {
            container = group.shift();
            stackList[to].push(container);
        }
    }
}

//reading this file was tedious! 
function readStartingValues(inputText, stackList, commandList) {
    let row = 0, col = 0;
    var numOfStacks;

    //determine number of stacks by getting the second last character in a line not containing '['
    var i = 0, j = 0;
    while ((j = inputText.indexOf('\n', i)) !== -1) {
        var line = inputText.substring(i, j);
        if (line.indexOf("[") === -1) {
            numOfStacks = line[line.length - 2];
            break;
        }
        i = j + 1;
    }

    //create a 2d array of stacks from the input
    //each stack is calculated by finding the arithmetic sequences at which characters are written in the input
    for (i = 0; i < numOfStacks; i++) {
        stackList.push([]);
    }
    while (inputText[(numOfStacks*4) * row + 1] != '1') {
        for (col = 0; col < numOfStacks; col++) {
            let character = inputText[(col*4 + 1) + ((numOfStacks*4) * row)];
            if (character != ' ') {
                stackList[col].unshift(character);
            }
        }
        row++;
    }

    //loop through each line and add commands to a 2d array using substring finding
    i = 0; j = 0;
    var cmd = 0;
    while ((j = inputText.indexOf('\n', i)) !== -1) {
        var line = inputText.substring(i, j);

        if (line.indexOf("move") !== -1) {
            commandList.push([]);
            commandList[cmd].push(
                line.substring(line.indexOf("move") + 5, line.indexOf("from")-1));
            commandList[cmd].push(
                line.substring(line.indexOf("from") + 5, line.indexOf("to")-1));
            commandList[cmd].push(
                line.substring(line.indexOf("to") + 5, line.length-1));
            cmd++;
        }
        i = j + 1;
    }
}

//read values, run the commands with them, print the answer
function main(inputText) {
    var stackList = [];
    var commandList = [];

    readStartingValues(inputText, stackList, commandList);
    console.log("Before: "); console.log(stackList);
    
    commandList.forEach(command => {
        runCommand(stackList, command);
    });
    console.log("After: "); console.log(stackList);

    printAnswer(stackList);
}

//runs main() twice
function fileReader() {
    document.getElementById("readfile").addEventListener("change", function () {
        var reader = new FileReader();
        reader.onload = function (progressEvent) {
            main(this.result);
            partOne = false;
            main(this.result);
        };
        reader.readAsText(this.files[0]);
    });
}

fileReader();