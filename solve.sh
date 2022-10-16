#!/bin/sh
while read in; do openssl enc -aes256 -d -k "$in" -in secret.bin 2>/dev/null;echo ""; done < passwords > output