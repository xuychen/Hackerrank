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

function gemstones(arr){
    var i, j, index;
    var map = {};
    var str = "";
    
    index = 0;
    for (i = 0; i < arr[0].length; i++)
        if (map[arr[0][i]] === undefined) {
            map[arr[0][i]] = 1;
            str = str + arr[0][i];
        }
    
    arr[0] = str;
    
    for (i = 1; i < arr.length; i++) {
       str = arr[0];
       for (j = 0; j < arr[0].length; j++)
          if (arr[i].indexOf(arr[0][j]) === -1)
             str = str.replace(new RegExp(arr[0][j], "g"), "");
        
       arr[0] = str;
    }
    
    return arr[0].length;
}

function main() {
    var n = parseInt(readLine());
    var arr = [];
    for(var arr_i = 0; arr_i < n; arr_i++){
       arr[arr_i] = readLine();
    }
    var result = gemstones(arr);
    process.stdout.write("" + result + "\n");

}

