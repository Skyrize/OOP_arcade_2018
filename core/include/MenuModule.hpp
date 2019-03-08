/*
** EPITECH PROJECT, 2019
** OOP_arcade_2018
** File description:
** MenuModule
*/

#ifndef MENUMODULE_HPP_
    #define MENUMODULE_HPP_

#include "IGameModule.hpp"

class MenuModule : public IGameModule {
	private:
        std::string _name = "MainMenu";
	public:
		MenuModule();
		~MenuModule();

        virtual void init();
        virtual void stop();
        virtual const std::string &getName() const;

        virtual void eventHandler(IDisplayModule *library, std::map<Input, bool> &inputs);

        virtual void run(IDisplayModule *library);

	protected:
};

#endif /* !MENUMODULE_HPP_ */

