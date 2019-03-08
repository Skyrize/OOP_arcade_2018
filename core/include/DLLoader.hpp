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
        void *(*trick)(const char *file, int mode) = dlopen;
        T *module = nullptr;
    public:
    
        DLLoader(const std::string &filename)
        {
            this->handler = trick(filename.c_str(), RTLD_LAZY);
            if (!handler) {
                std::cerr << "ERROR: Invalid filename '" + filename + "'. Can't dlopen. (maybe need to throw)" << std::endl;
            }
            entryPointPtr = (T *(*)())dlsym(handler, "entryPoint");
            if (!entryPointPtr) {
                std::cerr << "ERROR: '" + filename + "' has no method 'entryPoint'. (maybe need to throw)" << std::endl;
            } else
                module = entryPointPtr();
        }

        ~DLLoader()
        {
            delete(module);
            dlclose(this->handler);
            module = nullptr;
            handler = nullptr;
            entryPointPtr = nullptr;
        }

        T *getInstance()
        {
            return module;
        }
};

#endif /* DLLOADER_HPP_ */