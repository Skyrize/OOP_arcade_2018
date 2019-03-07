/*
** EPITECH PROJECT, 2018
** OOP_arcade_2018
** File description:
** DLLoader.hpp
*/

#ifndef DLLOADER_HPP_
#define DLLOADER_HPP_

#include <string>
#include <dlfcn.h>

template<typename T>
class DLLoader {
    private:
        void *handler = nullptr;
        T *(*entryPointPtr)() = nullptr;
        T *module = nullptr;
    public:
        DLLoader(const std::string &filename)
        {
            handler = dlopen(filename.c_str, RTLD_LAZY);

            if (!handler) {
                std::cerr << "ERROR: Invalid filename '" + filename + "'. Can't dlopen. (maybe need to throw)" << std::endl;
            }
            entryPointPtr = (T *(*)())dlsym(handler, "entry_point");
            if (!entryPointPtr) {
                std::cerr << "ERROR: '" + filename + "' has no method 'entry_point'. (maybe need to throw)" << std::endl;
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