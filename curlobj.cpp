#include "curlobj.h"


int CurlObj::curlWriter(char *data, int size, int nmemb, string *buffer) {
    int result = 0;
    if (buffer != NULL) {
        buffer->append(data, size * nmemb);
        result = size * nmemb;
    }

    return result;
}

string CurlObj::getData() {
    return curlBuffer;
}

void CurlObj::setUrl(string URL)
{
    url = URL;
}

void CurlObj::DoRequest(){
    curl = curl_easy_init();
    if (!curl) {
        throw string ("Curl did not initialize.");
    }

    curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, &CurlObj::curlWriter);
    curl_easy_setopt(curl, CURLOPT_WRITEDATA, &curlBuffer);
    curl_easy_setopt(curl, CURLOPT_URL, url.c_str());
    curl_easy_setopt(curl, CURLOPT_FOLLOWLOCATION, 1);
    curl_easy_perform(curl);
    curl_easy_cleanup(curl);
}
