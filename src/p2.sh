#!/bin/bash

REMOTE_USER="so24p"
REMOTE_HOST="pacifico.izt.uam.mx"
SSH_KEY="~/.ssh/id_rsa_jlqf"
REMOTE_COMMAND="who"
OUTPUT_FILE="resultado.txt"

n=1
while [ $n -le 6 ]; do

ssh -i "${SSH_KEY}" "${REMOTE_USER}@${REMOTE_HOST}" "${REMOTE_COMMAND}" >> "${OUTPUT_FILE}"
sleep 1m
let n++
done


if [ $? -eq 0 ]; then
echo "Exito: ${OUTPUT_FILE}"
else 
echo "Error"
fi