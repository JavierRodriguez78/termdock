#ifndef Container_H
#define Container_H
#include <string.h> 
#include "docker.hpp"

class Container : protected Docker {

    public:
        Container();
        int getContainers();
        void sendRequest();

};
#endif