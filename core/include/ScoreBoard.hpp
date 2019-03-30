/*
** EPITECH PROJECT, 2019
** OOP_arcade_2018
** File description:
** ScoreBoard
*/

#ifndef SCOREBOARD_HPP_
    #define SCOREBOARD_HPP_

#include "Text.hpp"

class ScoreBoard : public Object {
	public:
		ScoreBoard(const std::map<std::string, std::map<std::string, int> > &highScores, std::pair<float, float> pos = {0, 0});
		~ScoreBoard();

		virtual void display(IDisplayModule *display);
		virtual void eventHit(Object *other);

        void nextScore();
        void prevScore();
        void updateScores();

	protected:
        std::vector<Text *> highscores;
        std::vector<Text *> games;
        std::vector<std::vector<Text *>> scores;
        size_t actualGame = 0;
        size_t actualScore = 0;
	private:
};

#endif /* !SCOREBOARD_HPP_ */
