/*
** EPITECH PROJECT, 2018
** OOP_arcade_2018
** File description:
** DLLoader.hpp
*/

#ifndef DLLOADER_HPP_
#define DLLOADER_HPP_

#include <dlfcn.h>

template<typename T>
class DLLoader {
    private:
        void *handler = nullptr;
        T *(*entryPointPtr)() = nullptr;
        std::string fileName;
    public:
    
        DLLoader(const std::string &filename);

        ~DLLoader();

        void init();
        void stop();
        T *getInstance();
        const std::string &getFileName();
};

#endif /* DLLOADER_HPP_ */