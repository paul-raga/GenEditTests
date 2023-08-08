//
// Created by paul on 2/23/23.
//

#ifndef CLION_PROJECTS__MYCHAIN_H
#define CLION_PROJECTS__MYCHAIN_H

#include <string>
#include "read_write.h"
#include <bits/stdc++.h>
#include <memory>

class MyChain{
private:
    std::string chain; //input of the user

public:
    explicit MyChain(); //constructor
    ~MyChain();
    void printSequence();
    void modSequence();
    void compare();

};

#endif //CLION_PROJECTS__MYCHAIN_H
