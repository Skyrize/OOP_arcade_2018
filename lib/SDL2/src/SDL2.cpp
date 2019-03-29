/*
** EPITECH PROJECT, 2018
** OOP_arcade_2018
** File description:
** SFML.cpp
*/

#include "SDL2.hpp"

DisplayModule::DisplayModule()
{
    auto start = std::chrono::steady_clock::now();

    _clock = start;
    _isOpen = true;
    SDL_Init(SDL_INIT_VIDEO);
    TTF_Init();
}

DisplayModule::~DisplayModule()
{
    SDL_Quit();
    TTF_Quit();
}

void DisplayModule::init()
{
    restartTime();
    _win = SDL_CreateWindow("SDL2", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED,
        1600, 912, SDL_WINDOW_SHOWN);
    _render = SDL_CreateRenderer(_win, -1, SDL_RENDERER_ACCELERATED);
    _font = TTF_OpenFont("./resources/font.ttf", 100);
}

void DisplayModule::stop()
{
    _isOpen = false;
    TTF_CloseFont(_font);
    SDL_DestroyWindow(_win);
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
    SDL_Color colorSdl;
    SDL_Rect rec;
    int w, h = 0;

    if (!_isOpen)
        return;
    colorSdl = {(uint8_t)RGB[color][0], (uint8_t)RGB[color][1], (uint8_t)RGB[color][2], 255};
    _surface = TTF_RenderText_Solid(_font, str.c_str(), colorSdl);
    _texture = SDL_CreateTextureFromSurface(_render, _surface);
    SDL_QueryTexture(_texture, NULL, NULL, &w, &h);
    rec.x = x * 16;
    rec.y = y * 16;
    rec.w = w * fontSize / 100;
    rec.h = h * fontSize / 100;
    SDL_RenderCopy(_render, _texture, NULL, &rec);
    SDL_FreeSurface(_surface);
    SDL_DestroyTexture(_texture);
}

void DisplayModule::drawShape(int x, int y, std::vector<std::vector<Color> > pixels)
{
    SDL_Rect rec;
    int tmp = x * 16;

    y *= 16;
    x *= 16;
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
            SDL_SetRenderDrawColor(_render, RGB[j][0], RGB[j][1], RGB[j][2], 255);
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
    } else if (event.type != SDL_KEYDOWN)
        return map;
    for (auto &i: SDL_Key) {
        if (event.key.keysym.sym == i.second)
            map[i.first] = true;
    }
    return map;
}

void DisplayModule::playMusic(std::string musicName)
{
    (void)musicName;
}

void DisplayModule::stopCurrentMusic()
{
}