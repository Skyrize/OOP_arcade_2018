/*
** EPITECH PROJECT, 2019
** OOP_arcade_2018
** File description:
** SDL2
*/

#ifndef SDL2_HPP_
#define SDL2_HPP_

#include <SDL2/SDL.h>
#include "IDisplayModule.hpp"
#include <iostream>
#include <chrono>

class DisplayModule : public IDisplayModule {
	public:
		DisplayModule() = default;
		virtual ~DisplayModule() = default;

        void init();
        void stop();
        const std::string &getName() const { return _name; };

        bool isOpen() { return _isOpen; };
        void clear();
        void display();

        void drawText(int x, int y, const std::string &name, int fontSize, Color color);
        void drawShape(int x, int y, std::vector<std::vector<Color> >);
        
        float getTime();
        void restartTime();
        std::map<Input, bool> catchInput();

    private:
        std::string _name = "SDL2";
        std::chrono::steady_clock::time_point _clock;
        bool _isOpen = false;
        SDL_Window *_win = nullptr;
        SDL_Renderer *_render = nullptr;
};

const int RGBA[8][3] = {
    {0, 0, 0},         //BLACK
    {230, 25, 75},     //RED
    {60, 180, 75},     //GREEN
    {255, 225, 25},    //YELLOW
    {0, 130, 200},     //BLUE
    {240, 50, 230},    //MAGENTA
    {70, 240, 240},    //CYAN
    {255, 255, 255},   //WHITE
};

const std::map<Input, SDL_Keycode> SDL_Key = {
    {LEFT_ARROW_KEY,    SDLK_LEFT},
    {RIGHT_ARROW_KEY,   SDLK_RIGHT},
    {UP_ARROW_KEY,      SDLK_UP},
    {DOWN_ARROW_KEY,    SDLK_DOWN},
    {SPACE_KEY,         SDLK_SPACE},
    {RETURN_KEY,        SDLK_RETURN},
    {ERASE_KEY,         SDLK_BACKSPACE},
    {ESCAPE_KEY,        SDLK_ESCAPE},
    {A_KEY,             SDLK_a},
    {B_KEY,             SDLK_b},
    {C_KEY,             SDLK_c},
    {D_KEY,             SDLK_d},
    {E_KEY,             SDLK_e},
    {F_KEY,             SDLK_f},
    {G_KEY,             SDLK_g},
    {H_KEY,             SDLK_h},
    {I_KEY,             SDLK_i},
    {J_KEY,             SDLK_j},
    {K_KEY,             SDLK_k},
    {L_KEY,             SDLK_l},
    {M_KEY,             SDLK_m},
    {N_KEY,             SDLK_n},
    {O_KEY,             SDLK_o},
    {P_KEY,             SDLK_p},
    {Q_KEY,             SDLK_q},
    {R_KEY,             SDLK_r},
    {S_KEY,             SDLK_s},
    {T_KEY,             SDLK_t},
    {U_KEY,             SDLK_u},
    {V_KEY,             SDLK_v},
    {W_KEY,             SDLK_w},
    {X_KEY,             SDLK_x},
    {Y_KEY,             SDLK_y},
    {Z_KEY,             SDLK_z},
    {ONE_KEY,           SDLK_1},
    {TWO_KEY,           SDLK_2},
    {THREE_KEY,         SDLK_3},
    {FOUR_KEY,          SDLK_4},
    {FIVE_KEY,          SDLK_5},
    {SIX_KEY,           SDLK_6},
    {SEVEN_KEY,         SDLK_7},
    {EIGHT_KEY,         SDLK_8},
    {NINE_KEY,          SDLK_9},
    {ZERO_KEY,          SDLK_0}
};


#endif /* !SDL2_HPP_ */
