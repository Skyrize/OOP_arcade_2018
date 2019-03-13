/*
** EPITECH PROJECT, 2018
** OOP_arcade_2018
** File description:
** SFML.cpp
*/

#include "SDL2.hpp"

void DisplayModule::init()
{
    auto start = std::chrono::steady_clock::now();

    _clock = start;
    _isOpen = true;
    SDL_Init(SDL_INIT_VIDEO);
    _win = SDL_CreateWindow("SDL2", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED,
        1632, 880, SDL_WINDOW_SHOWN);
    _render = SDL_CreateRenderer(_win, -1, SDL_RENDERER_ACCELERATED);
}

void DisplayModule::stop()
{
    _isOpen = false;
    SDL_DestroyWindow(_win);
    SDL_Quit();
}

void DisplayModule::display()
{
    if (!_isOpen)
        return;
    SDL_RenderPresent(_render);
}

void DisplayModule::clear()
{
    if (!_isOpen)
        return;
    SDL_SetRenderDrawColor(_render, 0, 0, 0, 255);
    SDL_RenderClear(_render);
}

void DisplayModule::drawText(int x, int y, const std::string &str, int fontSize, Color color)
{
    (void)x;
    (void)y;
    (void)str;
    (void)fontSize;
    (void)color;
    if (!_isOpen)
        return;
}

void DisplayModule::drawShape(int x, int y, std::vector<std::vector<Color> > pixels)
{
    SDL_Rect rec;
    int tmp = x;

    if (!_isOpen)
        return;
    for (auto &i: pixels) {
        for (auto &j: i) {
            if (j == -1) {
                x += 16;
                continue;
            }
            rec.x = x;
            rec.y = y;
            rec.h = 16;
            rec.w = 16;
            SDL_SetRenderDrawColor(_render, RGBA[j][0], RGBA[j][1], RGBA[j][2], 255);
            SDL_RenderFillRect(_render, &rec);
            x += 16;
        }
        x = tmp;
        y += 16;
    }
}

float DisplayModule::getTime()
{
    auto end = std::chrono::steady_clock::now();
    auto start = _clock;

    if (!_isOpen)
        return 0;
    return double(double(std::chrono::duration_cast<std::chrono::microseconds>(end - start).count()) / 1000000);
}

void DisplayModule::restartTime()
{
    _clock = std::chrono::steady_clock::now();
}

std::map<Input, bool> DisplayModule::catchInput()
{
    SDL_Event event;
    std::map<Input, bool> map;

    if (!_isOpen)
        return map;
    SDL_PollEvent(&event);
    if (event.type == SDL_QUIT) {
        this->stop();
        return map;
    } else if (event.type == SDL_KEYDOWN)
        return map;
    for (auto &i: SDL_Key) {
        if (event.key.keysym.sym == i.second)
            map[i.first] = true;
    }
    return map;
}