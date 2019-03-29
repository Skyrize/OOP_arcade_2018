/*
** EPITECH PROJECT, 2019
** OOP_arcade_2018
** File description:
** DLLoader
*/

#include <iostream>
#include "IGameModule.hpp"
#include "IDisplayModule.hpp"
#include "DLLoader.hpp"

template <>
DLLoader<IGameModule>::DLLoader(const std::string &filename)
: fileName(filename)
{
}

template <>
void DLLoader<IGameModule>::init()
{
    this->handler = dlopen(fileName.c_str(), RTLD_LAZY);
    if (!handler) {
        std::cerr << std::string(dlerror()) << std::endl;
        exit (84);
    }
    entryPointPtr = (IGameModule *(*)())dlsym(handler, "entryPointGame");
    if (!entryPointPtr) {
        std::cerr <<  std::string(dlerror()) << std::endl;
        exit (84);
    }
}

template <>
void DLLoader<IGameModule>::stop()
{
    if (this->handler) {
        if (dlclose(this->handler) != 0) {
            std::cerr <<  std::string(dlerror()) << std::endl;
            exit (84);
        }
    }
    handler = nullptr;
    entryPointPtr = nullptr;
}

template <>
DLLoader<IGameModule>::~DLLoader()
{
    stop();
}

template <>
IGameModule *DLLoader<IGameModule>::getInstance()
{
    if (!entryPointPtr)
    std::cout << fileName << std::endl;
    return this->entryPointPtr();
}

template <>
const std::string &DLLoader<IGameModule>::getFileName()
{
    return fileName;
}


template <>
DLLoader<IDisplayModule>::DLLoader(const std::string &filename)
: fileName(filename)
{
}

template <>
void DLLoader<IDisplayModule>::init()
{
    this->handler = dlopen(fileName.c_str(), RTLD_LAZY);
    if (!handler) {
        std::cerr << std::string(dlerror()) << std::endl;
        exit (84);
    }
    entryPointPtr = (IDisplayModule *(*)())dlsym(handler, "entryPointDisplay");
    if (!entryPointPtr) {
        std::cerr <<  std::string(dlerror()) << std::endl;
        exit (84);
    }
}

template <>
void DLLoader<IDisplayModule>::stop()
{
    if (this->handler) {
        if (dlclose(this->handler) != 0) {
            std::cerr <<  std::string(dlerror()) << std::endl;
            exit (84);
        }
    }
    handler = nullptr;
    entryPointPtr = nullptr;
}

template <>
DLLoader<IDisplayModule>::~DLLoader()
{
    stop();
}

template <>
IDisplayModule *DLLoader<IDisplayModule>::getInstance()
{
    if (!entryPointPtr)
    std::cout << fileName << std::endl;
    return this->entryPointPtr();
}

template <>
const std::string &DLLoader<IDisplayModule>::getFileName()
{
    return fileName;
}