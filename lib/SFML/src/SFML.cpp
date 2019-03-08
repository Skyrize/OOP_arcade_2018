/*
** EPITECH PROJECT, 2018
** OOP_arcade_2018
** File description:
** SFML.cpp
*/

#include "SFML.hpp"

std::map<Color, sf::Color> sfColors = {
    {NONE, sf::Color::Transparent},
    {BLACK, sf::Color::Black},
    {RED, sf::Color::Red},
    {GREEN, sf::Color::Green},
    {YELLOW, sf::Color::Yellow},
    {BLUE, sf::Color::Blue},
    {MAGENTA, sf::Color::Magenta},
    {CYAN, sf::Color::Cyan},
    {WHITE, sf::Color::White}
};

const std::map<Input, sf::Keyboard::Key> sfInputs = {
    {LEFT_ARROW_KEY, sf::Keyboard::Key::Left},
    {RIGHT_ARROW_KEY, sf::Keyboard::Key::Right},
    {UP_ARROW_KEY, sf::Keyboard::Key::Up},
    {DOWN_ARROW_KEY, sf::Keyboard::Key::Down},
    {SPACE_KEY, sf::Keyboard::Key::Space},
    {ESCAPE_KEY, sf::Keyboard::Key::Escape},
    {A_KEY, sf::Keyboard::Key::A},
    {B_KEY, sf::Keyboard::Key::B},
    {C_KEY, sf::Keyboard::Key::C},
    {D_KEY, sf::Keyboard::Key::D},
    {E_KEY, sf::Keyboard::Key::E},
    {F_KEY, sf::Keyboard::Key::F},
    {G_KEY, sf::Keyboard::Key::G},
    {H_KEY, sf::Keyboard::Key::H},
    {I_KEY, sf::Keyboard::Key::I},
    {J_KEY, sf::Keyboard::Key::J},
    {K_KEY, sf::Keyboard::Key::K},
    {L_KEY, sf::Keyboard::Key::L},
    {M_KEY, sf::Keyboard::Key::M},
    {N_KEY, sf::Keyboard::Key::N},
    {O_KEY, sf::Keyboard::Key::O},
    {P_KEY, sf::Keyboard::Key::P},
    {Q_KEY, sf::Keyboard::Key::Q},
    {R_KEY, sf::Keyboard::Key::R},
    {S_KEY, sf::Keyboard::Key::S},
    {T_KEY, sf::Keyboard::Key::T},
    {U_KEY, sf::Keyboard::Key::U},
    {V_KEY, sf::Keyboard::Key::V},
    {W_KEY, sf::Keyboard::Key::W},
    {X_KEY, sf::Keyboard::Key::X},
    {Y_KEY, sf::Keyboard::Key::Y},
    {Z_KEY, sf::Keyboard::Key::Z},
    {ONE_KEY, sf::Keyboard::Key::Num1},
    {TWO_KEY, sf::Keyboard::Key::Num2},
    {THREE_KEY, sf::Keyboard::Key::Num3},
    {FOUR_KEY, sf::Keyboard::Key::Num4},
    {FIVE_KEY, sf::Keyboard::Key::Num5},
    {SIX_KEY, sf::Keyboard::Key::Num6},
    {SEVEN_KEY, sf::Keyboard::Key::Num7},
    {EIGHT_KEY, sf::Keyboard::Key::Num8},
    {NINE_KEY, sf::Keyboard::Key::Num9},
    {ZERO_KEY, sf::Keyboard::Key::Num0},
};

DisplayModule::DisplayModule()
{
    this->window = new sf::RenderWindow();
}

DisplayModule::~DisplayModule()
{
    delete(this->window);
}

void DisplayModule::init()
{
    this->window->create(sf::VideoMode(1920, 1080), "SFML", sf::Style::Resize | sf::Style::Fullscreen);
}

void DisplayModule::stop()
{
    this->window->close();
}

bool DisplayModule::isOpen()
{
    return this->window->isOpen();
}

void DisplayModule::display()
{
    this->window->display();
}

void DisplayModule::clear()
{
    this->window->clear();
}

void DisplayModule::drawText(int x, int y, const std::string &name) const
{
    (void)x;
    (void)y;
    (void)name;
}

void DisplayModule::drawShape(int x, int y, std::vector<std::vector<int> > pixels)
{
    for (size_t i = 0; i != pixels.size(); i++) {
        for (size_t j = 0; j != pixels[i].size(); j++) {
            this->baseSquare.setPosition((j + 1) * 16 * x, (i + 1) * 16 * y);
            const sf::Color color = sfColors[(Color)pixels[i][j]];
            this->baseSquare.setFillColor(color);
            this->window->draw(this->baseSquare);
        }
    }
}

std::map<Input, bool> DisplayModule::catchInput()
{
    sf::Event event;
    std::map<Input, bool> inputs = {
    {LEFT_ARROW_KEY, false},
    {RIGHT_ARROW_KEY, false},
    {UP_ARROW_KEY, false},
    {DOWN_ARROW_KEY, false},
    {SPACE_KEY, false},
    {ESCAPE_KEY, false},
    {A_KEY, false},
    {B_KEY, false},
    {C_KEY, false},
    {D_KEY, false},
    {E_KEY, false},
    {F_KEY, false},
    {G_KEY, false},
    {H_KEY, false},
    {I_KEY, false},
    {J_KEY, false},
    {K_KEY, false},
    {L_KEY, false},
    {M_KEY, false},
    {N_KEY, false},
    {O_KEY, false},
    {P_KEY, false},
    {Q_KEY, false},
    {R_KEY, false},
    {S_KEY, false},
    {T_KEY, false},
    {U_KEY, false},
    {V_KEY, false},
    {W_KEY, false},
    {X_KEY, false},
    {Y_KEY, false},
    {Z_KEY, false},
    {ONE_KEY, false},
    {TWO_KEY, false},
    {THREE_KEY, false},
    {FOUR_KEY, false},
    {FIVE_KEY, false},
    {SIX_KEY, false},
    {SEVEN_KEY, false},
    {EIGHT_KEY, false},
    {NINE_KEY, false},
    {ZERO_KEY, false},};
    
    while (this->window->pollEvent(event)) {
        if (event.type == sf::Event::Closed)
            window->close();
        for (auto e : sfInputs)
            if (sf::Keyboard::isKeyPressed(e.second))
                inputs[e.first] = true;
    }
    return inputs;
}