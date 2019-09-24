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
    CurlObj (string url);

    static int curlWriter(char *data, int size, int nmemb, string *buffer);

    string getData();

protected:
    CURL * curl;
    string curlBuffer;
};

#endif // CURLOBJ_H
