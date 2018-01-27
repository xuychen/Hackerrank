# !/bin/bash

read
awk 'NR == 1 {for (i=1; i<NF; i++) a[$i]++}
    NR == 2 {for (i=1; i<NF; i++)
      if(--a[$i]+0 < 0)
      {
        print "No";
        exit;
      }

     print "Yes"}
'
