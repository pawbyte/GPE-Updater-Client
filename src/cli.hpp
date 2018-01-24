#ifndef CLI_HPP
#define CLI_HPP

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
