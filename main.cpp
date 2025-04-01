#include <iostream>
#include <fstream>
#include <vector>
#include <iomanip>  

double mapValue(double val) {
    //return -1 + (val - 1) * (2 - (-1)) / (5 - 1);
    return (3.0/4.0)*val - (7.0/4.0);
    
}

int main() {
    std::ifstream file("data.txt");
    if (!file) {
        std::cerr << "Non si apre il file" << std::endl;
        return 1;
    }

    std::vector<double> dati;
    double valore;
    while (file >> valore) {
        dati.push_back(valore);
    }

    file.close();

    
    std::vector<double> valori_mappati;
    for (double val : dati) {
        valori_mappati.push_back(mapValue(val));
    }


    double somma = 0.0;
    std::ofstream risultato("result.txt");
    risultato << "# N Mean" << std::endl; 

    for (size_t i = 0; i < valori_mappati.size(); ++i) {
        somma += valori_mappati[i];
        double media = somma / (i + 1);  
        risultato << std::scientific << std::setprecision(16) << (i + 1) << " " << media << std::endl;
    }

    risultato.close();

    std::cout << "I risultati sono scritti in result.txt" << std::endl;
    return 0;
}