/*
** EPITECH PROJECT, 2019
** OOP_arcade_2018
** File description:
** ScoreBoard
*/

#include <algorithm>
#include "ScoreBoard.hpp"

static Sprite scoreBoardSprite {
    {}
};

static Sprite none;

static const std::pair<float, float> scorePositions[10]
{
    {}
};

ScoreBoard::ScoreBoard(const std::map<std::string, std::map<std::string, int> > &highScores, std::pair<float, float> pos)
: Object("ScoreBoard", scoreBoardSprite, pos)
{
    scores.reserve(highScores.size());
    // size_t i = 0;

    // std::cout << "size = " << highScores.size() << std::endl;
    // for (auto &e : highScores) {
    //     games.push_back(new Text("gameScore", e.first, 64, RED, none, std::pair<float, float>{5, 5}));
    //     std::vector<std::pair<std::string, int> >sortedScores(e.second.begin(), e.second.end());
    //     std::sort(sortedScores.begin(), sortedScores.end(),
    //         [](const std::pair<std::string, int> &a, const std::pair<std::string, int> &b)
    //         {
    //             return a.second > b.second;
    //         });
    //     int j = 0;
    //     std::cout << e.first << " i = " << i << std::endl;
    //     for (auto &score : sortedScores) {
    //         std::cout << "j = " << j << std::endl;
    //         scores[i].push_back(new Text("score" + std::to_string(i), score.first + " - " + std::to_string(score.second), 64, RED, none, std::pair<float, float>{8, 8 + j * 2}));
    //         j++;
    //     }
    //     std::cout << std::endl;
    //     i++;
    // }
}

ScoreBoard::~ScoreBoard()
{
}

void ScoreBoard::eventHit(Object *other)
{
    (void)other;
    actualGame++;
    if (actualGame == games.size())
        actualGame = 0;
    updateScores();
}

void ScoreBoard::display(IDisplayModule *display)
{
    Object::display(display);
    for (size_t i = actualScore; i != scores.size() && i != actualScore + 10; i++)
        scores[actualGame][i]->display(display);
}

void ScoreBoard::nextScore()
{
    if (actualScore + 1 == scores[actualGame].size())
        return;
    actualScore++;
    updateScores();
}

void ScoreBoard::prevScore()
{
    if (actualScore == 0)
        return;
    actualScore--;
    updateScores();
}

void ScoreBoard::updateScores()
{
    for (size_t i = actualScore; i != scores.size() && i != actualScore + 10; i++)
        scores[actualGame][i]->getMovement().setPosition(scorePositions[i - actualScore].first, scorePositions[i - actualScore].second);
}
