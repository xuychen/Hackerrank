process.stdin.resume();
process.stdin.setEncoding('ascii');

var input_stdin = "";
var input_stdin_array = "";
var input_currentline = 0;

process.stdin.on('data', function (data) {
    input_stdin += data;
});

process.stdin.on('end', function () {
    input_stdin_array = input_stdin.split("\n");
    main();    
});

function readLine() {
    return input_stdin_array[input_currentline++];
}

/////////////// ignore above this line ////////////////////

function funnyString(s){
    var i, len = s.length;
    var arr = [];
    for (i = 0; i < len - 1; i++)
        arr[i] = Math.abs(s[i].charCodeAt() - s[i+1].charCodeAt());
    
    for (i = 0; i < (len - 1) / 2; i++)
        if (arr[i] !== arr[len-2-i])
            break;
    
    if (i >= (len-1)/2)
        return "Funny";
    else
        return "Not Funny";
}

function main() {
    var q = parseInt(readLine());
    for(var a0 = 0; a0 < q; a0++){
        var s = readLine();
        var result = funnyString(s);
        process.stdout.write("" + result + "\n");
    }

}

