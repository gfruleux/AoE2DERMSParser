** Age Of Empires 2 : Definitive Edition Random Map Script Parser **

Lets you generate the clean version of GeneratingObjects for specified RMS !
All the constants will be used to get what the game use to generate the map objects :)

The program will ask you to
1) Select the Random Map Script files you want to parse
2) Select the Output directory for the parsed files


Limitations:
* Doesn't work with `conditional RMS` (like MegaRandom) because of the Random Percents used to define constants on the fly.
Thus, the program would need to iterate over all and every possible arrangements and generate equivalent files


Evolutions:
* Select Map Size (Tiny, Medium, Huge ...)
* Select Resource mod (Infinite)
* Select Map Type (KotH, Regicide, Random ...)