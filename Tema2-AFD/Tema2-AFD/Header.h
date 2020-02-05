#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <fstream>

 class AFD {

 private:
	std::vector<char> Q; // 1 ,2, 3, 4 - noduri
	std::vector<char> Sigma; //alfabet - a,b
	char stareInit;
	std::vector<std::string> stari;
	std::vector<char> finale; 

 public:

	AFD() {
		std::ifstream fin("Text.txt");
		char c;
		int aux, aux1;
		std::string d;


		/*for (unsigned index = 0; index < 4; ++index) {
			Q.push_back(index+48+1);
		}*/

		fin >> aux1;
		for (int index = 0; index < aux1; ++index) {
			fin >> c;
			Q.push_back(c);
		}

		fin >> aux;
		for (int index = 0; index < aux; ++index) {
			fin >> c;
			Sigma.push_back(c);
		}


		/*std::cout << "Introduceti elementele din alfabet: *Sigma* \n";
		for (unsigned index = 0; index < 3; ++index) {
			char c;
			std::cin >> c;
			Sigma.push_back(c);
		}*/

		fin >> stareInit;

		for (unsigned index = 0; index < aux1; ++index) {
			fin >> d;
			stari.push_back(d);
		}

		fin >> aux;
		for (unsigned index = 0; index < aux; ++index) {
			fin >> c;
			finale.push_back(c);
		}
	}

	bool stareInitincludedinQ() {

		int okei = 0;
		for (unsigned index = 0; index < Q.size(); ++index) {
			if (Q[index] == stareInit) okei = 1;
		}
		return okei;
	}

	void showSigma() {

		std::cout << "Sigma={ ";
		for (unsigned index = 0; index < Sigma.size()-1; index++) {
			std::cout << Sigma.at(index)<<" , ";
		}
		std::cout << Sigma.at(Sigma.size() - 1) << " }; \n";
	}

	void showQ() {

		std::cout << "Q = { ";
		for (unsigned index = 0; index < Q.size() - 1; index++) {
			std::cout << Q.at(index) << " , ";
		}
		std::cout << Q.at(Q.size() - 1) << " }; \n";

	}

	void showFinale() {

		std::cout << "F = { ";
		for (unsigned index = 0; index < finale.size() - 1; index++) {
			std::cout << finale.at(index) << " , ";
		}
		std::cout << finale.at(finale.size() - 1) << " }; \n";
	}

	void showStartSymbol() {
		std::cout << stareInit << "\n";
	}

	void showStari() {

		std::cout << "Stari = { ";
		for (unsigned index = 0; index < stari.size() - 1; index++) {
			std::cout << stari.at(index) << " , ";
		}
		std::cout << stari.at(stari.size() - 1) << " }; \n";
	}
	void wordVerificationNedeed(std::string newWord) {

		int indexSaved = 0;
		int ok = 0;
		std::string aux = newWord;
			std::string aux1 = newWord;
		while(aux.length()!=0){
			//parcurg fiecare litera a cuvantului
			for (unsigned index = 0; index < newWord.length(); index++) {

				std::cout << "delta(" << stareInit -48 << " , " << aux1 << ") |-- ";
				char actualWord = newWord.at(index);

				std::cout << "actualWorrd=" << actualWord << " ,";

				//parcurg vectorul alfabet si caut pozitia pentru care sigma[poz]=actualWord
				for (unsigned index1 = 0; index1 < Sigma.size(); index1++) {

					if (Sigma.at(index1) == actualWord) {
						indexSaved = index1;
						std::cout << " IndexSaved = " << indexSaved << " ";
					}
				}

				//noua stare se va afla la vechea pozitie in vectorul de stari,la pozitia corespunzatoare actualei litere din vectorul Alfabet
				stareInit = stari.at(stareInit - 48-1).at(indexSaved) ;
				std::cout << "stareInit=" << stareInit -48 << " , ";

				aux1 = { "" };

				//reconstruiesc noul cuvant eliminand la fiecare iteratie prima litera din cuvant
				for (unsigned index1 = index+1; index1 < newWord.length(); index1++)
				{
					aux1 = aux1 + newWord.at(index1);
				}

				//verific daca am ajuns la finalul cuvantului
				if (index != newWord.length() - 1)
					std::cout << "Aux1= " << aux1 << " ";
				else
					std::cout << "Aux1= lambda" << " ";

				std::cout << "\n";

				if (index == newWord.length() - 1) {
					std::cout << "delta(" << stareInit - 48 << " , lambda" << ") |-- \n";
				}
			}

			//verific daca ultima stare=una dintre starile finale
			for (unsigned index = 0; index < finale.size(); index++) {

				if (stareInit == finale.at(index))
					ok = 1;
			}
			
			//cand am ajuns la final,opresc ciclul
			aux = "";
		}

			if (ok == 1) std::cout << " DA! \n";
			else
				std::cout << "NU! \n";
	}
};









