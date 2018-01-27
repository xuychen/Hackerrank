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

function main() {
    var s = readLine();
    var n = parseInt(readLine());
    var map = {};
    var count = 0;
    var prev = s[0];
    
    for (var i in s) {
       if (prev !== s[i]) {
           prev = s[i];
           count = 1;
       }
       else
           count++;
        
       map[(s[i].charCodeAt()-96) * count] = 1;
    }
    
    for(var a0 = 0; a0 < n; a0++){
        var x = parseInt(readLine());
        
        if (map[x] == 1)
            process.stdout.write("Yes\n");
        else
            process.stdout.write("No\n");
    }
}

