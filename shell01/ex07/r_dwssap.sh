#!/bin/env bash

names=$(cat /etc/passwd | grep -v '^#' | sed -n '2~2p' | cut -d: -f1 | rev | sort -r | sed -n "$FT_LINE1,$FT_LINE2 p" | xargs | sed 's/ /, /g' | tr -d '\n')
if [ -n "$names" ]; then
    echo -n "$names."
fi
