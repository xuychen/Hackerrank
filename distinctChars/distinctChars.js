var map = {};

function one(lhs, rhs)
{
    var diff = lhs - rhs;
    if (diff === 0 || diff === 1)
        return true;
    
    return false;
}

function compare (lhs, rhs)
{
    return map[rhs] - map[lhs];
}

function alter (s, a, b)
{
    var pat;
    
    for (var i in s)
        if (s[i] === a && pat !== a)
            pat = a;
        else if (s[i] === b && pat !== b)
            pat = b;
        else if (s[i] !== a && s[i] !== b)
            continue;
        else 
            return false;
    
    return true;
}

function maxLen(n, s){
    var index = 0;
    var max = 0, limit = 1;
    var arr = [];
    
    for (var i in s)
      if (map[s[i]] === undefined)
      {
        map[s[i]] = 1;
        arr[index++] = s[i];
      }
      else
        map[s[i]]++;
        
    arr.sort(compare);
    for (var i = 0; i < arr.length - 1 && map[arr[i]] >= limit; i++)
      for (var j = i+1; one(map[arr[i]], map[arr[j]]); j++)
        if (alter(s, arr[i], arr[j]))
        {
           max = max > map[arr[i]] + map[arr[j]]? max : map[arr[i]] + map[arr[j]];   
           limit = map[arr[i]];
        }
           
    return max;
}

function main() {
    var n = parseInt(readLine());
    var s = readLine();
    var result = maxLen(n, s);
    process.stdout.write(""+result+"\n");

}
