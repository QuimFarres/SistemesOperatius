Us recomano utilitzar aquest tipus de document per comentar les preguntes de text. Així ho teniu tot organitzat al repositori. 


## Q1: Repetir els passos amb l'ordre yes > /dev/null. Què fa aquesta ordre? Quines diferències trobeu amb l'execució de l'ordre anterior? (0,5 punts)

L'ordre ```yes``` simplement escriu repetidament una cadena a stdout, el caràcter *y* per defecte. Redirigint-lo (>) a **/dev/null**. La principal diferència és l'estat (S) a (R). Aquesta ordre executa de forma permanent (R) mentre l'ordre ```sleep``` executa en el mode (S). Amb ctrl+z aturem el procés en els dos casos (S) i (R) i bg el torna a reanudar als estat (S) i (R).


## Q2: Modificar aquest procés per obtenir una sortida indicant Hola sóc el procés pare i Hola sóc el procés fill. (0,5 punts)

Aquest apartat s'ha solucionat al fitxer **act2.c**

## Q3: Modificar aquest exemple fent anar la funció execv(). (0,5 punts)
 
Per tal de fer servir la funció ```execv()``s'ha de modificar la línia següent:

```c
// Original:
// execvp( "find", argv );
// Solució:
execv( "/usr/bin/find", argv );
```

En resum ```execv``` requereix tot el path fins la comanda i ```execvp``` no. Per obtenir més informació ```man exec```.

## Q4: Explica el funcionament del programa. Indicant quants senyals s'envien, quin procés envia el senyal, i on l'envia. (2,5 punts)


## Q5: Programeu un programa pare, fill net que tingui la següent sortida (mantenint l’ordre). A més a més els fills, hauran de generar un enter aleatori entre els valors 0,1 i 2. El 0=apunyalat, 1=decapitat.  (4 punts)

Aquest apartat s'ha solucionat al fitxer **act5.c**

Us falta comentar que el programa genera 5 senyals. Els canvis d'estat del fill generats per *SIGCON* i *SIGSTOP* generen el senyal *SIGCHL* que notifica el pare d'aquests esdeveniments en el fill i ens obliga a haver d'esperar per 2 senylas adicionals (es veu amb els 2 primers **waits**). L'ordre **exit()** també la genera i per tant necessitem un últim **wait()** per esperar el *SIGCHLD* generat per l'exit.
