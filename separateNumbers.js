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

var _TRILLION = 1000000000000000; 
var TRILLION = "000000000000000";

function addone (str) {
    var len, lower, upper, res;
    len = str.length > 15 ? 15 : str.length;
    lower = parseInt(str.substr(-len)) + 1;
    
    if (lower / _TRILLION < 1) {
       if (str.length > 15) {
         lower = (TRILLION + lower.toString()).substr(-len);
         res = str.substr(0, str.length-len) + lower;
       }
       else
         res = lower.toString();
    }
    else {
        if (str.length === len)
            upper = 1;
        else
            upper = parseInt(str.substr(0, str.length-len)) + 1;
        res = upper.toString() + TRILLION; 
    }
        
    return res;
}

function main() {
    var q = parseInt(readLine());
    var copy, index, str, i, j, flag;
    for(var a0 = 0; a0 < q; a0++){
        var s = readLine();
        flag = false;
        for (i = 0; i < (s.length-1)/2; i++) {
            str = copy = s.substr(0, i+1);
            index = 0;
            for (j = 0; j < s.length; j++) {   
                if (str[index++] !== s[j])
                    break;
                
                if(index === str.length) {
                    str = addone(str);
                    index = 0;
                }
            }
            
            if(j === s.length && index === 0) {
                process.stdout.write("YES " + copy + "\n");
                flag = true;
                break;
            }
            if(s[0] === "0")
               break;
        }
        
        if (flag === false)
           process.stdout.write("NO\n"); 
    }
}

