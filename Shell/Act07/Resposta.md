# Resposta Act07
La variable que es pasa com a parametre, sera el numero de ids, és a dir, de procesos que es crearan en el programa, que sera la variable 'N'.
Per a cada N es cridara el executable p.sh.
## p.sh
```sh
#!/bin/bash
echo "RUN - time: $(date) Process id:$$"

sleep $((RANDOM % 21))

echo "END - time:$(date) Process id:$$"
```

El qual fa un echo de cuan comença amb un txt + data + id del proces, despreés fa un sleep, i un altre echo de cuan acaba, en el que també imprimeix un tx + data + id, però aquest id pot ser diferent ja que en la execució, algun proces pot acabar abans que un altre.

Al final del programa, comprova quins s'han executat correctament i quins no fent serivr el seguent script

```sh
for p in $pids; do
if wait $p; then
(( complete++ ))
else
(( fail++ ))
fi
done
echo "$complete processes completed successfully."
echo "$fail processes failed to completed."
echo "Done."
```
