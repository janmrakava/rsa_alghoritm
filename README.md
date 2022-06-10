# README #

Toto README slouží jako návod k tomu, jak zapnout program. Dále pak pro pochopení funkcí, které se vyskytují v programu. 

### Základní informace ###

* RSA je šifra s veøejným klíèem, jedná se o první algoritmus, který je vhodný jak pro podepisování, tak šifrování. Používá se i dnes, pøièemž pøi dostateèné délce klíèe je považován za bezpeèný.
* Program vyvíjen v jazyce C++, v IDE Clion 2022.1 na operaèním systému Windows 10.

### Jak spustit program ###

* Pro spuštìní programu staèí spustit .exe soubor s názvem krypto_rsa.exe, který se nachází ve složce cmake-build-debug. Otevøe se v pøíkazovém øádku. 
* Po té se objeví instrukce, co je potøeba dále dìlat. Hodnota prvoèísel je omezena kvùli rychlosti algoritmu maximální hodnotou 300. Ale v pøípadì malé úpravy kódu, lze toto omezení zrušit.
* Po zadání prvoèísel je tøeba zadat text, který chcete zašifrovat. Po té lze vidìt, jak program zprávu zašifroval a poté i dešifroval. 
* Program se ukonèí zmáèknutím jakékoli klávesy. 

### Popis funkcí ###

* checkPrime()
  * Funkce kontroluje, zda-li je zadané èíslo od uživatele prvoèíslo. Zároveò hlídá jestli je èíslo menší než 300. Díky knihovnì boost by nebyl problém zvládat vìtší èísla, ale algortimus by pak byl pomalý.
* getPrime()
  * Úkolem funkce je získat od uživatele prvoèíslo. Pro kontrolu používá funkci checkPrime().
* getN()
  * Funkce má 2 atributy, ty jsou zadané prvoèísla. Vrací jejích souèin
* getEul()
  * Funkce vrací hodnotu výpoètu Eulerovy funkce.
* getE()
  * Funkce má za úkol vrátít vypoèítanou hodnotu e. K tomu používá funkci jazyka c++ gcd(), ta se snaží najít nejvìtšího spoleèného dìlitele dvou èísel.
* getD()
  * Funkce vrací vypoèítanou hodnotu d. Pomocí vzorce d = ((k * eul) + 1) / e. Koeficient k zjistí dle vzorce ((k * eul) + 1) % e != 0)
* encrypt()
  * Úkolem funkce je zašifrovat zadanou zprávu. Pro potøeby RSA algoritmu bylo nutné použít knihovnu boost, pøesnìji její datový int. Bìhìm poèítání s vìtšími primárními èísly datové typy zabudované v jazyce c++ nestaèí. Jinak je výpoèet dle vzorce.
* decrypt()
  * Úkolem funkce je dešifrovat zadanou cifru. Stejný pøípad jako v pøípadì encrypt(), nutné použít externí knihovny. 
* main()
  * V této èásti se volají jednotlivé metody, pro obsloužení programu. 
### Kdo je autorem? ###

* Autor: Bc. Jan Mrákava
