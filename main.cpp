#include <iostream>
#include <numeric>
#include <vector>
#include <boost/multiprecision/cpp_int.hpp>

using boost::multiprecision::cpp_int;

struct private_key {
    unsigned numN;
    unsigned numD;
} privateKey;

struct public_key{
    unsigned numN;
    unsigned numE;
} publicKey;

unsigned primeNum1; //prime 1
unsigned primeNum2; //prime 2
unsigned numN;
unsigned numEul; //numEul = (primeNum1-1)*(primeNum2-1)
std::string text;
char ch;



bool checkPrime(unsigned num){
    if (num <= 1){
        return false;
    }
    // For cyklus, který projíždí všechny čísla od 2 do zadaného číslo a zkouší je dělit momentální hodnotou proměnné i.
    for (int i = 2; i < num; ++i) {
        if (num % i == 0){
            return false;
        }
    }
    if (num > 300){
        return false;
    }
    return true;
}

unsigned getPrime(){
    unsigned number;
    //Uživatel musí zadat prvočísla
    std::cout << "Enter a prime number between 2-300" << std::endl;
    std::cin>> number;
    std::cin.ignore();
    while (not checkPrime(number)){
        std::cout << "The number is not in the range 2-200, or it is not a prime number, enter again" << std::endl;
        std::cin >> number;
    }
    return number;
}

unsigned getN(unsigned num1, unsigned num2){
    unsigned numN;
    numN = num1 * num2;
    return numN;
}

unsigned getEul(unsigned num1, unsigned num2){
    unsigned eul;
    eul = (num1 - 1) * (num2 - 1);
    return eul;
}

unsigned getE(unsigned eul){
    unsigned i = 2;
    unsigned e;
    while (std::gcd(i, eul) != 1){
           i++;
    }
    e = i;
    if (e >= numEul){
        throw (std::runtime_error("numE is greater thar or equal to phi numN"));
    }
    return e;
}

unsigned getD(unsigned e, unsigned eul){
     unsigned k = 1;
     unsigned d;
     while (((k * eul) + 1) % e != 0) {
         k++;
     }
     d = ((k * eul) + 1) / e;

     return d;
}

boost::multiprecision::cpp_int encrypt(public_key pb, unsigned message){
    boost::multiprecision::cpp_int cipher;
    cipher = (boost::multiprecision::cpp_int(boost::multiprecision::pow(boost::multiprecision::cpp_int(message), pb.numE))) % pb.numN;
    return cipher;

}

boost::multiprecision::cpp_int decrypt(private_key pk, boost::multiprecision::cpp_int cipher){
    boost::multiprecision::cpp_int message_0;
    message_0 = (boost::multiprecision::cpp_int(boost::multiprecision::pow(boost::multiprecision::cpp_int(cipher), pk.numD))) % pk.numN;
    return message_0;
}





int main() {
    primeNum1 = getPrime();
    primeNum2 = getPrime();
    numN = getN(primeNum1, primeNum2);
    numEul = getEul(primeNum1, primeNum2);

    publicKey.numN = numN;
    publicKey.numE = getE(numEul);

    privateKey.numN = numN;
    privateKey.numD = getD(publicKey.numE, numEul);

    std::cout << "Enter text to encrypt " << std::endl;
    std::getline(std::cin, text);
    boost::multiprecision::cpp_int pole[text.length()];

    std::cout << "Encrypted message: " << std::endl;
    for (int i = 0; i < text.length(); ++i) {
            ch = text[i];
            int a = int(ch);

            std::cout << encrypt(publicKey, a) << " ";

            pole[i] = encrypt(publicKey, a);
    }

    std::cout << std::endl;
    std::cout << "Decrypted message " <<std::endl;
    for (int i = 0; i < text.length(); ++i) {
        std::cout << decrypt(privateKey, pole[i]) <<" ";
    }
    std::getchar();

    return 0;
}
