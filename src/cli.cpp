#include <iostream>
#include "cli.hpp"
#include "updaterConfig.hpp"
#include "filecheck.hpp"

namespace GPEUP {

	CLI::CLI() {
		// Constructor
		std::cout << "CLI Created" << std::endl;
	}

	void CLI::version() {
		std::cout << GPEU_NAME_FULL << " - Version " << GPEU_VERSION_MAJOR << "." << GPEU_VERSION_MINOR << "." << GPEU_VERSION_STEP << std::endl;

	}

	void CLI::help(char* execname) {
		std::cout << "Usage: " << execname << " [OPTIONS]" << std::endl << std::endl;
		std::cout << "Example: " << execname << " -u  -- Update the program files, return a status code, and exit" << std::endl << std::endl;
		std::cout << "Options:" << std::endl << std::endl;
		std::cout << "-v\tVersion Information" << std::endl;
		std::cout << "-h\tDisplay this help menu" << std::endl;
		std::cout << "-s\tSilent, No GUI. Just return a return code" << std::endl;
		std::cout << "-u\tUpdate files in the project, return status code on success or failure" << std::endl;
		std::cout << "--nb\tNo Backups" << std::endl;
	}

	int CLI::prompt() {
		FileCheck fc;
		std::string location("test.txt");
		std::string result;
		fc.md5(location, result);
		std::cout << "Result of '" << location << "' is: " << result << std::endl;
		location = "something.txt";
		fc.md5(location, result);
		std::cout << "Result of '" << location << "' is: " << result << std::endl;
		return 0;
	}

}