#ifndef CURLOBJ_H
#define CURLOBJ_H

#include <iostream>
#include <curl/curl.h>
#include <vector>
#include <map>
#include <algorithm>
#include <string>

using namespace std;


class CurlObj {

public:
    static int curlWriter(char *data, int size, int nmemb, string *buffer);

    string getData();

    void setUrl(string URL);

    void DoRequest();

protected:
    CURL * curl;
    string curlBuffer;
    string url;
};

#endif // CURLOBJ_H
