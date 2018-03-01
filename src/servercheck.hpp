// updater.hpp
#ifndef SERVERCHECK_HPP
#define SERVERCHECK_HPP
#include <iostream>
#include <string>
#include <regex>
#include <utility>
#include <unordered_map>
#include <curl/curl.h>
#include "updaterConfig.hpp"


namespace GPEUP {


class ServerCheck
{
private:
	int getVersion(CURL* servdata);
	std::unordered_map<std::string, std::string> servData;
	static size_t read_data(void *ptr, size_t size, size_t nmemb, void *stream);
public:
    int check();
	std::string getCurrentVersion();
	std::vector<std::string> getAvailableVersions();
	bool md5LineParse(std::string input);
	std::unordered_map<std::string, std::string> getServerData();
};

}

#endif