#!/bin/bash

if [[ -z $1 ]]; #Check if '$1' argument is null 
then 
    echo "No Path has been passed."
else 
    tr ':' '\n' <<< $1 | xargs -I $PATH find $PATH -type f -executable
fi
