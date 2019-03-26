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

        virtual void init(const std::string &playerName, const int &highScore);
        virtual void stop();
        virtual const std::string &getName() const;
        virtual int getHighScore() const;
        
        virtual void run(IDisplayModule *library, std::map<Input, bool> &inputs);
};

#endif /* !MENUMODULE_HPP_ */

