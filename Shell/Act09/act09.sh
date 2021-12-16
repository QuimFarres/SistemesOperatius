#!/bin/bash


x=$(pidof -x act09.sh)
array=()
if [ $x = $$ ]; then
    echo "El fitxer es unic"
    if [ $1 -gt 0 ]; then
        
        if [ -e $2 ]; then
            echo "El fitxer existeix"
            chmod +x $2
            echo "El fitxer te permisos de execusció"

            echo "---------------------------------------------------------------"
            echo "Tria una de les seguents 3 opcions: "
            echo "1 - Executar la fàbrica de processos amb els arguments rebuts."
            echo "2 - Eliminar l’executable passat com a paràmetre."
            echo "3 - Traure els permisos d’execució de l’argument 2."
            echo "---------------------------------------------------------------"
            read opcion

                if [ $opcion = 1 ]; then
                    for ((i=0;i<$1;i++))
                        do
                        ( ./p.sh ) &
                        sleep 3
                        array[i]+=" $!"
                        echo "Hi, the factory creates:  ${array[*]} ..."
                        done
                    for ((i=0;i<${#array[*]};i++))
                        do
                        wait ${array[i]};                           
                        done
                    fi
                if [ $opcion = 2 ]; then
                    $(rm $2)

                    fi
                if [ $opcion = 3 ]; then
                    chmod -x $2
                    fi
            fi
        fi
    fi