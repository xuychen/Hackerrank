# !/bin/bash

cd $1
for file in *
do
   if [[ $file == *.txt || -d $file ]]; then
       continue
   fi

   DIR=${file%%.*}
   SHORT=${DIR%%-*}

   if [[ -d $SHORT || -e $SHORT.* ]]; then
       DIR=$SHORT
   elif [ ! -d $DIR ]; then
       mkdir $DIR
   fi

   mv $file $DIR
   echo FILE \"$file\" is putting in Directory \"$DIR\"
done
