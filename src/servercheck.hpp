// updater.hpp
#include <iostream>
#include <string>
#include <curl/curl.h>
#include "updaterConfig.hpp"


namespace GPEUP {

class ServerCheck
{
private:
	int getVersion(CURL* servdata);
public:
    int check();

    std::string config;
	std::string serverVersion;
};

}