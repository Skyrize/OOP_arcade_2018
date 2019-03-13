/*
** EPITECH PROJECT, 2019
** OOP_arcade_2018
** File description:
** MenuModule
*/

#ifndef MENUMODULE_HPP_
    #define MENUMODULE_HPP_

#include "IGameModule.hpp"
#include "MainMenuScene.hpp"

class MenuModule : public IGameModule {
	private:
        std::string _name = "MainMenu";
        MainMenuScene scene;
	public:
		MenuModule();
		~MenuModule();

        virtual void init();
        virtual void stop();
        virtual const std::string &getName() const;

        virtual void run(IDisplayModule *library, std::map<Input, bool> &inputs);

	protected:
};

#endif /* !MENUMODULE_HPP_ */

