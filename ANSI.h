#ifndef ANSI_H
#define ANSI_H

#include <string>



namespace ANSI{
    const std::string ANSI_CHAR = "\u001b[";
    const std::string ANSI_CLOSE = "m";
    const std::string ANSI_256_PREFIX = "8;5;";
    const std::string ANSI_BRIGHT = ";1";


    enum class Color{
        BLACK=0,
        RED=1,
        GREEN=2,
        YELLOW=3,
        BLUE=4,
        MAGENTA=5,
        CYAN=6,
        WHITHE=7,
        RESET=-1   
    };
    
    enum class Position{
        FOREGROUND=3,
        BACKGROUND=4
    };
    
    enum class Decoration{
        BOLD=1,
        ITALIC=3,
        UNDERLINE=4,
        REVERSED=7
    };
    
    enum class Navigation{
        UP='A',
        DOWN='B',
        RIGHT='C',
        LEFT='D',
        NEXT_LINE='E',
        PREV_LINE='F',
        SET_COLUMN='G'
        //SET_POS='H'     
    };

    enum class FromTo{
        CURSOR_TO_END = 0,
        CURSOR_TO_BEGIN = 1,
        ALL=2
    };
}

class AnsiUtility{

public:
    //static constexpr std::string ZERO = get_set_position(0,0);
    //static constexpr std::string CLEAR_ALL_SCREEN = get_clear_screen(ANSI::FromTo::ALL);

    static AnsiUtility& get_instance(){
        static AnsiUtility instance;

        return instance;
    }

    AnsiUtility(AnsiUtility const&)     = delete;
    void operator=(AnsiUtility const&)  = delete;

    std::string get_color(const ANSI::Color  color, const ANSI::Position  pos) const;
    std::string get_brtight_color(const ANSI::Color & color, const ANSI::Position & pos) const;
    std::string get_256color(const unsigned char range /*0->255*/, const ANSI::Position & pos) const;
    std::string get_decoration(const ANSI::Decoration & decoration)const;
    std::string get_mouve_cursor(const ANSI::Navigation & navigation, const  int spostamento) const;
    std::string get_set_position(const  int row, const  int col) const;
    
    std::string get_clear_screen(const ANSI::FromTo & where)const;
    std::string get_clear_row(const ANSI::FromTo & where)const; 
    
    std::string reset() const;

private:
    AnsiUtility(){}
};


#endif 