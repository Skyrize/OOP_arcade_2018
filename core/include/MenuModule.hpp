/*
** EPITECH PROJECT, 2019
** OOP_arcade_2018
** File description:
** MenuModule
*/

#ifndef MENUMODULE_HPP_
    #define MENUMODULE_HPP_

#include "IGameModule.hpp"
#include "Scene.hpp"
#include "Arcade.hpp"

class Arcade;
class MenuModule : public IGameModule, public Scene {
	private:
        std::string _name = "MainMenu";
        Arcade &arcade;
		std::string &playerName;

        /* Scene */

		float starSpawnTimer = 0;
		int nbStars = 0;
		size_t actualPannel = 0;
		std::vector<Scene *> pannels;
		bool exiting = false;
		bool changer = false;

	public:
		MenuModule(Arcade &arcade);
		~MenuModule();

        /* Module */

        virtual void init(const std::string &playerName, const int &highScore);
        virtual void stop();
        virtual const std::string &getName() const;
        virtual int getHighScore() const;
        virtual void restart() const;
        virtual void run(IDisplayModule *library, std::map<Input, bool> &inputs);

        /* Scene */

		virtual void manageEvents(std::map<Input, bool> &inputs);
		void goToPannel(const int &index);
		Scene *getActualPannel();

		virtual void display(IDisplayModule *display);
		virtual float update(IDisplayModule *display);
		void eventButtonTriggered();
		void exitModule();
		void changeLib();
};

#endif /* !MENUMODULE_HPP_ */

