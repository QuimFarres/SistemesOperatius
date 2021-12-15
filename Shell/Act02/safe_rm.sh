#!/bin/bash

if [ -e $1 ]; then
    if [ ! -e safe_rm_recycle ]; then
        mkdir safe_rm_recycle
    fi
    mv $1 safe_rm_recycle
    
else
    echo "ERROR"
fi
