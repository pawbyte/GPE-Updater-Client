//updater.cpp
#include "servercheck.hpp"

namespace GPEUP {
	
	int ServerCheck::check() {
		CURL *curl;
		CURLcode res;

		curl_global_init(CURL_GLOBAL_DEFAULT);

		curl = curl_easy_init();
		if (curl) {
			curl_easy_setopt(curl, CURLOPT_URL, GPEU_RELEASE_URL);

			res = curl_easy_perform(curl);

			if (res != CURLE_OK) {
				std::cerr << "Unable to perform request" << curl_easy_strerror(res) << std::endl;
			}
			else {
				std::cout << curl << std::endl;
			}
			curl_easy_cleanup(curl);
		}

		curl_global_cleanup();

		return 0;
	}

}
