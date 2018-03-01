#ifndef CLI_HPP
#define CLI_HPP
#include <iostream>
#include <unordered_map>
#include "updaterConfig.hpp"
#include "filecheck.hpp"
#include "servercheck.hpp"

namespace GPEUP {

	class CLI
	{
	public:
		CLI();
		void version();
		void help(char* execname);
		int prompt();
	};

}

#endif // !CLI_HPP
