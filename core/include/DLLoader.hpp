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
    
        DLLoader(const std::string &filename)
        : fileName(filename)
        {}

        ~DLLoader()
        {
        }

        void init()
        {
            this->handler = dlopen(fileName.c_str(), RTLD_LAZY);
            if (!handler) {
                std::cerr << "ERROR: Invalid filename '" + fileName + "'. Can't dlopen. (maybe need to throw)" << std::endl;
            }
            entryPointPtr = (T *(*)())dlsym(handler, "entryPoint");
            if (!entryPointPtr) {
                std::cerr << "ERROR: '" + fileName + "' has no method 'entryPoint'. (maybe need to throw)" << std::endl;
            }
        }

        void stop()
        {
            if (this->handler)
                dlclose(this->handler);
            handler = nullptr;
            entryPointPtr = nullptr;
        }


        T *getInstance()
        {
            return this->entryPointPtr();
        }

        const std::string &getFileName()
        {
            return fileName;
        }
};

#endif /* DLLOADER_HPP_ */