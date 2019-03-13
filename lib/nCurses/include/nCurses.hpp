/*
** EPITECH PROJECT, 2019
** OOP_arcade_2018
** File description:
** nCurses
*/

#ifndef NCURSES_HPP_
#define NCURSES_HPP_

#include "IDisplayModule.hpp"
#include <ncurses.h>
#include <ctime>
#include <iostream>
#include <unistd.h>
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
        std::string _name = "nCurses";
        bool _isOpen = false;
        std::chrono::steady_clock::time_point _clock;
        WINDOW *_win = nullptr;
};

const std::map<Input, int> nCursesKeys = {
    {LEFT_ARROW_KEY,    260},
    {RIGHT_ARROW_KEY,   261},
    {UP_ARROW_KEY,      259},
    {DOWN_ARROW_KEY,    258},
    {SPACE_KEY,         32},
    {RETURN_KEY,        10},
    {ESCAPE_KEY,        27},
    {A_KEY,             97},
    {B_KEY,             98},
    {C_KEY,             99},
    {D_KEY,             100},
    {E_KEY,             101},
    {F_KEY,             102},
    {G_KEY,             103},
    {H_KEY,             104},
    {I_KEY,             105},
    {J_KEY,             106},
    {K_KEY,             107},
    {L_KEY,             108},
    {M_KEY,             109},
    {N_KEY,             110},
    {O_KEY,             111},
    {P_KEY,             112},
    {Q_KEY,             113},
    {R_KEY,             114},
    {S_KEY,             115},
    {T_KEY,             116},
    {U_KEY,             117},
    {V_KEY,             118},
    {W_KEY,             119},
    {X_KEY,             120},
    {Y_KEY,             121},
    {Z_KEY,             122},
    {ONE_KEY,           38},
    {TWO_KEY,           169},
    {THREE_KEY,         34},
    {FOUR_KEY,          39},
    {FIVE_KEY,          40},
    {SIX_KEY,           45},
    {SEVEN_KEY,         168},
    {EIGHT_KEY,         95},
    {NINE_KEY,          167},
    {ZERO_KEY,          160}
};

#endif /* !NCURSES_HPP_ */
