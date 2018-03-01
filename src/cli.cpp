#include "cli.hpp"


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
		std::cout << "-i\tIntegrity Check. Verifies that the current set of files are the same as the current version" << std::endl;
		std::cout << "-u\tUpdate files in the project, return status code on success or failure" << std::endl;
		std::cout << "--nb\tNo Backups" << std::endl << std::endl;
	}

	int CLI::prompt() {
		FileCheck fc;
		ServerCheck sc;
		std::unordered_map<std::string, std::string> sdata;
		sdata = sc.getServerData();
		fc.checkbatch(sdata);

		return 0;
	}

}