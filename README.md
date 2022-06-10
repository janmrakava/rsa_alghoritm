# README #

Toto README slou�� jako n�vod k tomu, jak zapnout program. D�le pak pro pochopen� funkc�, kter� se vyskytuj� v programu. 

### Z�kladn� informace ###

* RSA je �ifra s ve�ejn�m kl��em, jedn� se o prvn� algoritmus, kter� je vhodn� jak pro podepisov�n�, tak �ifrov�n�. Pou��v� se i dnes, p�i�em� p�i dostate�n� d�lce kl��e je pova�ov�n za bezpe�n�.
* Program vyv�jen v jazyce C++, v IDE Clion 2022.1 na opera�n�m syst�mu Windows 10.

### Jak spustit program ###

* Pro spu�t�n� programu sta�� spustit .exe soubor s n�zvem krypto_rsa.exe, kter� se nach�z� ve slo�ce cmake-build-debug. Otev�e se v p��kazov�m ��dku. 
* Po t� se objev� instrukce, co je pot�eba d�le d�lat. Hodnota prvo��sel je omezena kv�li rychlosti algoritmu maxim�ln� hodnotou 300. Ale v p��pad� mal� �pravy k�du, lze toto omezen� zru�it.
* Po zad�n� prvo��sel je t�eba zadat text, kter� chcete za�ifrovat. Po t� lze vid�t, jak program zpr�vu za�ifroval a pot� i de�ifroval. 
* Program se ukon�� zm��knut�m jak�koli kl�vesy. 

### Popis funkc� ###

* checkPrime()
  * Funkce kontroluje, zda-li je zadan� ��slo od u�ivatele prvo��slo. Z�rove� hl�d� jestli je ��slo men�� ne� 300. D�ky knihovn� boost by nebyl probl�m zvl�dat v�t�� ��sla, ale algortimus by pak byl pomal�.
* getPrime()
  * �kolem funkce je z�skat od u�ivatele prvo��slo. Pro kontrolu pou��v� funkci checkPrime().
* getN()
  * Funkce m� 2 atributy, ty jsou zadan� prvo��sla. Vrac� jej�ch sou�in
* getEul()
  * Funkce vrac� hodnotu v�po�tu Eulerovy funkce.
* getE()
  * Funkce m� za �kol vr�t�t vypo��tanou hodnotu e. K tomu pou��v� funkci jazyka c++ gcd(), ta se sna�� naj�t nejv�t��ho spole�n�ho d�litele dvou ��sel.
* getD()
  * Funkce vrac� vypo��tanou hodnotu d. Pomoc� vzorce d = ((k * eul) + 1) / e. Koeficient k zjist� dle vzorce ((k * eul) + 1) % e != 0)
* encrypt()
  * �kolem funkce je za�ifrovat zadanou zpr�vu. Pro pot�eby RSA algoritmu bylo nutn� pou��t knihovnu boost, p�esn�ji jej� datov� int. B�h�m po��t�n� s v�t��mi prim�rn�mi ��sly datov� typy zabudovan� v jazyce c++ nesta��. Jinak je v�po�et dle vzorce.
* decrypt()
  * �kolem funkce je de�ifrovat zadanou cifru. Stejn� p��pad jako v p��pad� encrypt(), nutn� pou��t extern� knihovny. 
* main()
  * V t�to ��sti se volaj� jednotliv� metody, pro obslou�en� programu. 
### Kdo je autorem? ###

* Autor: Bc. Jan Mr�kava
