function super_reduced_string(s){
  return s.replace(/(.)\1/g, "");
}

function main() {
    var s = readLine();
    var ques;
    var result = s;
    do {
        ques = result;
        result = super_reduced_string(ques);
    } while (result !== ques);
    
    if (result === "")
        process.stdout.write("Empty String\n");
    else
        process.stdout.write("" + result + "\n");
}
