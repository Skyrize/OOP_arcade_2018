/*
** EPITECH PROJECT, 2019
** OOP_arcade_2018
** File description:
** ScoreBoard
*/

#ifndef SCOREBOARD_HPP_
    #define SCOREBOARD_HPP_

#include "Text.hpp"
#include "ScoreButton.hpp"
#include "Scene.hpp"

class ScoreButton;
class ScoreBoard : public Object {
	public:
		ScoreBoard(Scene &parent, const std::vector< std::pair< std::string, std::vector< std::pair< std::string, int > > > > &highScores, std::pair<float, float> pos = {0, 0});
		~ScoreBoard();

		virtual void display(IDisplayModule *display);

        void nextScore();
        void nextGame();
        void updateScores();

	protected:
        Scene &parent;
        std::vector<Text *> highscores;
        std::vector<Text *> games;
        std::vector<std::vector<Text *>> scores;
        size_t actualGame = 0;
        size_t actualScore = 0;

        ScoreButton *gameButton;
        ScoreButton *scoreButton;
	private:
};

#endif /* !SCOREBOARD_HPP_ */
