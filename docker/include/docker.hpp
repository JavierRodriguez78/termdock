#ifndef Docker_H
#define Docker_H
#define RAPIDJSON_HAS_STDSTRING 1
#include "rapidjson/document.h"
using namespace std;
class Docker
{
    public:
        Docker();
        explicit Docker(std::string host);
        ~Docker();
};
#endif