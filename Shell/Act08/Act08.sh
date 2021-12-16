#!/bin/bash

N=$1

complete=0

fail=0

array=()

echo "Hi, I am the factory [$$]..."

for ((i=0;i<N;i++))

do

# Donar a p.sh permissos d'execució abans d'executar.

( ./p.sh ) &

sleep 3

array[i]+=" $!"

echo "Hi, the factory creates:  ${array[*]} ..."

done 

for ((i=0;i<${#array[*]};i++))
do

if wait ${array[i]}; then

(( complete++ ))

else

(( fail++ ))

fi

done



echo "$complete processes completed successfully."

echo "$fail processes failed to completed."

echo "Done."