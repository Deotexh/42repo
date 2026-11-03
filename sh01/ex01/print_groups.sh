#!/bin/bash

if [ '' = "$FT_USER" ]
then 
    # echo "Bla bla"
    exit
else
    id -Gn $FT_USER | tr [:blank:] , | cat
fi
