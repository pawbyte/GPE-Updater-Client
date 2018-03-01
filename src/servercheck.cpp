//updater.cpp
#include "servercheck.hpp"

namespace GPEUP {
	
	int ServerCheck::getVersion(CURL* curl) {

		return 0;
	}

	size_t ServerCheck::read_data(void *ptr, size_t size, size_t nmemb, void *stream)
	{
		((std::string*)stream)->append((char*)ptr, size * nmemb);
		return size * nmemb;
	}

	int ServerCheck::check() {
		CURL *curl;
		CURLcode res;
		std::string manifest;

		curl_global_init(CURL_GLOBAL_DEFAULT);

		curl = curl_easy_init();
		if (curl) {
			curl_easy_setopt(curl, CURLOPT_URL, GPEU_RELEASE_URL);
			curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, read_data);
			curl_easy_setopt(curl, CURLOPT_WRITEDATA, &manifest);

			res = curl_easy_perform(curl);

			if (res != CURLE_OK) {
				std::cerr << "Unable to perform request" << curl_easy_strerror(res) << std::endl;
			}
			else {
				md5LineParse(manifest);
			}
			curl_easy_cleanup(curl);
		}

		curl_global_cleanup();

		return 0;
	}

	bool ServerCheck::md5LineParse(const std::string input) {
		std::regex md5Regex("([a-fA-F0-9]{32})(?: \*)(.*)", std::regex::ECMAScript | std::regex::icase);

		std::sregex_iterator md5Begin = std::sregex_iterator(input.begin(), input.end(), md5Regex);
		std::sregex_iterator md5End = std::sregex_iterator();

		//std::cout << "Found " << std::distance(md5Begin, md5End) << " words:\n";

		for (std::sregex_iterator i = md5Begin; i != md5End; ++i) {
			std::smatch match = *i;
			std::string match_md5 = match[1];
			std::string match_file = match[2];
			match_file.erase(0, 1);
			servData.insert(std::make_pair(match_file, match_md5));
			//std::cout << match_md5 << " : " << match_file << '\n';
		}
		

		return false;
	}

	std::unordered_map<std::string, std::string> ServerCheck::getServerData() {
		if (servData.size() < 1) {
			check();
		}
		return servData;
	}

}
