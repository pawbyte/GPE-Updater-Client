#include <iostream>
#include "cli.hpp"
#include "updaterConfig.hpp"

 

	 CLI::CLI() {
		 // Constructor
		 std::cout << "CLI Created" << std::endl;
	 }

	 void CLI::version() {
		 std::cout << GPEU_NAME_FULL << " - Version " << GPEU_VERSION_MAJOR << "." << GPEU_VERSION_MINOR << "." << GPEU_VERSION_STEP << std::endl;

	 }

