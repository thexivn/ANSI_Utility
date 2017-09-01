#include "ANSI.h"
#include <iostream>

std::string AnsiUtility::get_color(const ANSI::Color  color, const ANSI::Position  pos)const{
    if(color == ANSI::Color::RESET)
        return this->reset();
    
    return ANSI::ANSI_CHAR + std::to_string((int)pos) + std::to_string((int)color)  + ANSI::ANSI_CLOSE;
}

std::string AnsiUtility::get_brtight_color(const ANSI::Color & color, const ANSI::Position & pos) const{
    if(color == ANSI::Color::RESET)
        return this->reset();

    return ANSI::ANSI_CHAR + std::to_string((int)pos) + std::to_string((int)color) + ANSI::ANSI_BRIGHT + ANSI::ANSI_CLOSE;
}

std::string AnsiUtility::get_256color(const unsigned char range /*0->255*/, const ANSI::Position & pos) const{
    return ANSI::ANSI_CHAR + std::to_string((int)pos) + ANSI::ANSI_256_PREFIX + std::to_string((int)range) + ANSI::ANSI_CLOSE;
}

std::string AnsiUtility::get_decoration(const ANSI::Decoration & decoration)const{
    return ANSI::ANSI_CHAR + std::to_string((int)decoration) + ANSI::ANSI_CLOSE;
}

std::string AnsiUtility::get_mouve_cursor(const ANSI::Navigation & navigation, const  int spostamento) const{
    return ANSI::ANSI_CHAR + std::to_string(spostamento) + (char)navigation;
}

std::string AnsiUtility::get_set_position(const  int row, const  int col) const{
    return ANSI::ANSI_CHAR + std::to_string(row) + ";" + std::to_string(col);
}

std::string AnsiUtility::get_clear_screen(const ANSI::FromTo & where) const{
    return ANSI::ANSI_CHAR + std::to_string((int)where) + "J";
}
std::string AnsiUtility::get_clear_row(const ANSI::FromTo & where) const{
    return ANSI::ANSI_CHAR + std::to_string((int)where) + "K";
}

std::string AnsiUtility::reset() const{
    return ANSI::ANSI_CHAR  +"0" + ANSI::ANSI_CLOSE;
}
