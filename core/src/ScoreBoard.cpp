/*
** EPITECH PROJECT, 2019
** OOP_arcade_2018
** File description:
** ScoreBoard
*/

#include <algorithm>
#include "ScoreBoard.hpp"

static Sprite scoreBoardSprite {
    {  RED,   RED,   RED,   RED,   RED,   RED,   RED,   RED,   RED,   RED,   RED,   RED,   RED,   RED,   RED,   RED,   RED,   RED,   RED,   RED,   RED,   RED,   RED,   RED,   RED,   RED,   RED,   RED,   RED},
    {  RED, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE,   RED},
    {  RED, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE,   RED},
    {  RED, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE,   RED},
    {  RED, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE,   RED},
    {  RED, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE,   RED},
    {  RED, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE,   RED},
    {  RED, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE,   RED},
    {  RED,   RED,   RED,   RED,   RED,   RED,   RED,   RED,   RED,   RED,   RED,   RED,   RED,   RED,   RED,   RED,   RED,   RED,   RED,   RED,   RED,   RED,   RED,   RED,   RED,   RED,   RED,   RED,   RED},
    {  RED, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE,   RED},
    {  RED, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE,   RED},
    {  RED, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE,   RED},
    {  RED, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE,   RED},
    {  RED, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE,   RED},
    {  RED, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE,   RED},
    {  RED, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE,   RED},
    {  RED, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE,   RED},
    {  RED, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE,   RED},
    {  RED, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE,   RED},
    {  RED, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE,   RED},
    {  RED, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE,   RED},
    {  RED, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE,   RED},
    {  RED, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE,   RED},
    {  RED, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE,   RED},
    {  RED, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE,   RED},
    {  RED, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE,   RED},
    {  RED, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE,   RED},
    {  RED, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE,   RED},
    {  RED, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE,   RED},
    {  RED, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE,   RED},
    {  RED, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE,   RED},
    {  RED, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE,   RED},
    {  RED, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE,   RED},
    {  RED, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE,   RED},
    {  RED, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE,   RED},
    {  RED, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE,   RED},
    {  RED, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE,   RED},
    {  RED, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE,   RED},
    {  RED, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE,   RED},
    {  RED, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE,   RED},
    {  RED, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE,   RED},
    {  RED, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE,   RED},
    {  RED, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE,   RED},
    {  RED, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE,   RED},
    {  RED, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE,   RED},
    {  RED, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE,   RED},
    {  RED, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE,   RED},
    {  RED, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE,   RED},
    {  RED, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE,   RED},
    {  RED, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE,   RED},
    {  RED, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE,   RED},
    {  RED, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE,   RED},
    {  RED,   RED,   RED,   RED,   RED,   RED,   RED,   RED,   RED,   RED,   RED,   RED,   RED,   RED,   RED,   RED,   RED,   RED,   RED,   RED,   RED,   RED,   RED,   RED,   RED,   RED,   RED,   RED,   RED},
};

static Sprite none;

static Sprite buttonGameSprite {
    { NONE,   RED,   RED,   RED,   RED,   RED,   RED,   RED, NONE},
    {  RED,   RED, WHITE, WHITE, WHITE, WHITE, WHITE,   RED,  RED},
    {  RED, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE,  RED},
    {  RED, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE,  RED},
    {  RED, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE,  RED},
    {  RED, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE,  RED},
    {  RED, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE,  RED},
    {  RED, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE,  RED},
    {  RED, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE,  RED},
    {  RED,   RED, WHITE, WHITE, WHITE, WHITE, WHITE,   RED,  RED},
    { NONE,   RED,   RED,   RED, WHITE,   RED,   RED,   RED, NONE},
    { NONE,  NONE,  NONE,   RED, WHITE,   RED,  NONE,  NONE, NONE},
    { NONE,  NONE,   RED,   RED, WHITE,   RED,   RED,  NONE, NONE},
    { NONE,   RED, WHITE, WHITE, WHITE, WHITE, WHITE,   RED, NONE},
    { NONE,   RED, WHITE, WHITE,   RED, WHITE, WHITE,   RED, NONE},
    { NONE,   RED, WHITE,   RED,  NONE,   RED, WHITE,   RED, NONE},
    { NONE,  NONE,   RED,  NONE,  NONE,  NONE,   RED,  NONE, NONE},
};

static Sprite buttonScoreSprite {
    { NONE,  BLUE,  BLUE,  BLUE,  BLUE,  BLUE,  BLUE,  BLUE, NONE},
    { BLUE,  BLUE, WHITE, WHITE, WHITE, WHITE, WHITE,  BLUE, BLUE},
    { BLUE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, BLUE},
    { BLUE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, BLUE},
    { BLUE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, BLUE},
    { BLUE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, BLUE},
    { BLUE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, BLUE},
    { BLUE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, BLUE},
    { BLUE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, BLUE},
    { BLUE,  BLUE, WHITE, WHITE, WHITE, WHITE, WHITE,  BLUE, BLUE},
    { NONE,  BLUE,  BLUE,  BLUE, WHITE,  BLUE,  BLUE,  BLUE, NONE},
    { NONE,  NONE,  NONE,  BLUE, WHITE,  BLUE,  NONE,  NONE, NONE},
    { NONE,  NONE,  BLUE,  BLUE, WHITE,  BLUE,  BLUE,  NONE, NONE},
    { NONE,  BLUE, WHITE, WHITE, WHITE, WHITE, WHITE,  BLUE, NONE},
    { NONE,  BLUE, WHITE, WHITE,  BLUE, WHITE, WHITE,  BLUE, NONE},
    { NONE,  BLUE, WHITE,  BLUE,  NONE,  BLUE, WHITE,  BLUE, NONE},
    { NONE,  NONE,  BLUE,  NONE,  NONE,  NONE,  BLUE,  NONE, NONE},
};


ScoreBoard::ScoreBoard(Scene &parent, const std::vector< std::pair< std::string, std::vector< std::pair< std::string, int > > > > &highScores, std::pair<float, float> pos)
: Object("ScoreBoard", scoreBoardSprite, pos),
parent(parent)
{
    scores.reserve(highScores.size());
    for (auto it = highScores.begin(); it != highScores.end(); it++) {
        games.push_back(new Text("game", it->first, 64, RED, none, std::pair<float, float>{6, 4}));

        std::vector<std::pair<std::string, int> >sortedScores(it->second.begin(), it->second.end());
        std::sort(sortedScores.begin(), sortedScores.end(),
            [](const std::pair<std::string, int> &a, const std::pair<std::string, int> &b)
            {
                return a.second > b.second;
            });
        scores.push_back(std::vector<Text *>());
        for (auto iter = sortedScores.begin(); iter != sortedScores.end(); iter++) {
            scores[std::distance(highScores.begin(), it)].push_back(new Text("text", std::to_string(std::distance(sortedScores.begin(), iter) + 1) + " - " + iter->first + " - " + std::to_string(iter->second), 32, BLUE, none, std::pair<float, float>{5, std::distance(sortedScores.begin(), iter) * 4 + 13}));
        }
        sortedScores.clear();
    }
    this->gameButton = new ScoreButton(*this, &ScoreBoard::nextGame, buttonGameSprite, std::pair<float, float>{62, 15});
    this->scoreButton = new ScoreButton(*this, &ScoreBoard::nextScore, buttonScoreSprite, std::pair<float, float>{45, 15});
    parent.addObject(gameButton);
    parent.addObject(scoreButton);
}

ScoreBoard::~ScoreBoard()
{
    for (size_t i = 0; i != highscores.size(); i++)
        delete(highscores[i]);
    highscores.clear();
    for (size_t i = 0; i != games.size(); i++)
        delete(games[i]);
    games.clear();
    for (size_t i = 0; i != scores.size(); i++) {
        for (size_t j = 0; j != scores[i].size(); j++) {
            delete(scores[i][j]);
        }
        scores[i].clear();
    }
    scores.clear();
}

void ScoreBoard::nextGame()
{
    actualGame++;
    if (actualGame == games.size())
        actualGame = 0;
    updateScores();
}

void ScoreBoard::display(IDisplayModule *display)
{
    Object::display(display);
    games[actualGame]->display(display);
    for (size_t i = actualScore; i != scores[actualGame].size() && i != actualScore + 10; i++)
        scores[actualGame][i]->display(display);
}

void ScoreBoard::nextScore()
{
    actualScore++;
    if (actualScore == scores[actualGame].size())
        actualScore = 0;
    updateScores();
}

void ScoreBoard::updateScores()
{
    for (size_t i = actualScore; i != scores[actualGame].size() && i != actualScore + 10; i++)
        scores[actualGame][i]->getMovement().setPosition(5, (i - actualScore) * 4 + 13);
}
