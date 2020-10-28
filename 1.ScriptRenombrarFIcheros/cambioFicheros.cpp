#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <string.h>


int main() {

    std::string lista;

    system("ls TEXTURAS_AES_IB/ > ficheros.txt");

    std::ifstream file("ficheros.txt");
    std::vector<std::string> v;
    std::string linea;
 

    while(file >> linea) {
        linea.erase(std::remove(linea.begin(), linea.end(), '\n'), linea.end());
        v.push_back(linea);
    }


    std::cout << "\n\n La lista es: \n\n";

    for (int i = 0; i<v.size(); i++) {
        std::cout << v[i] << "\n";
    }

    for (int i = 0; i<v.size(); i++) {
        std::string fic;
        fic = v[i];
        const char *entrada = v[i].c_str();
        if (fic.find("LEVC") != std::string::npos) {
            fic.replace(13,4,"LEAL");
            //std::cout <<  << "\n";
            const char *salida = fic.c_str();
            std::cout << "\n Entrada: " << entrada << "\n";
            std::cout << "\n Salida:  " << salida << "\n";
            if (std::rename("TEXTURAS_AES_IB/"entrada, "TEXTURAS_AES_IB/"salida) != 0)
		        perror("Error renaming file");
	        else
		        std::cout << "File renamed successfully";
        }
    }

    //system("rm ficheros.txt");
    return 0;
}