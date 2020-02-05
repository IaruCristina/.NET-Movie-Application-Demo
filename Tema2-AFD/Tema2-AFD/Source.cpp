#include "Header.h"

int main() {

	AFD *afd = new AFD();
	afd->showQ();
	std::cout << " \n";
	afd->showSigma();
	afd->showFinale();
	afd->showStari();
	std::cout << " \n";
	int nrOfWords;

	std::cout << " Introduceti cuvinte pana la intalnirea cuvantului : STOP \n";

	std::string word;
	std::ifstream f("words.txt");

	f >> nrOfWords;
	for(unsigned index = 0; index < nrOfWords; ++ index) {
		f >> word;
		afd->wordVerificationNedeed(word);
		std::cout << std::endl;
		
	}
	return 0;
}