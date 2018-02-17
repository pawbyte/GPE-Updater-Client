// updater.hpp
#include <iostream>
#include <string>
#include <regex>
#include <map>
#include <curl/curl.h>
#include "updaterConfig.hpp"


namespace GPEUP {

class ServerCheck
{
private:
	int getVersion(CURL* servdata);
	static size_t read_data(void *ptr, size_t size, size_t nmemb, void *stream);
public:
    int check();

    std::string config;
	std::string serverVersion;
	bool md5LineParse(std::string input);
};

}