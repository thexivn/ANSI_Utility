#include <iostream>
#include <chrono>
#include <thread>
#include "ANSI.h"
#define TOP_LIMIT(in, limit) ((in>limit)? limit : in)

void print_pb_bar(const ANSI::Color & color,const int percent, const int width);


int main(){
    AnsiUtility & color_utility = AnsiUtility::get_instance();
    const std::string font_rosso 
        = color_utility.get_color(ANSI::Color::RED, ANSI::Position::FOREGROUND);
    const std::string bg_blu 
        = color_utility.get_color(ANSI::Color::CYAN, ANSI::Position::BACKGROUND);

    for(char y = 0; y<16; ++y){
        for(char x = 0; x<16; ++x){
            std::cout << color_utility.get_256color((16*y)+(x), ANSI::Position::BACKGROUND) << "   ";
        }
        std::cout << std::endl;
    }

    std::cout << font_rosso << bg_blu << "Hello World ANSI!!" << color_utility.reset() << std::endl;

    for(int i = 0; i<=100; ++i){
        print_pb_bar(ANSI::Color::BLUE, i, 25); 
        print_pb_bar(ANSI::Color::CYAN, i, 35);
        print_pb_bar(ANSI::Color::GREEN, i*2, 35);
        print_pb_bar(ANSI::Color::MAGENTA, i, 55);
        print_pb_bar(ANSI::Color::RED, i*3, 75);
        std::this_thread::sleep_for(std::chrono::milliseconds(100));
        if(i<100)
            std::cout << color_utility.get_mouve_cursor(ANSI::Navigation::LEFT, 1000) << color_utility.get_mouve_cursor(ANSI::Navigation::UP, 5); 
    }

    std::cout << color_utility.get_mouve_cursor(ANSI::Navigation::DOWN, 12) << "############";

    return 0;
}

void print_pb_bar(const ANSI::Color & color,const int percent, const int width){
    
    std::string bar = "[" + AnsiUtility::get_instance().get_brtight_color(color, ANSI::Position::BACKGROUND) ;
    int colored = 0;
    colored = (width * TOP_LIMIT(percent, 100)) / 100;
   
    int c;
    for(c=0; c<colored; ++c) bar += " ";
    bar +=   AnsiUtility::get_instance().reset();
    for(;c<width; ++c) bar +=  " ";

    
    bar+="] ";
    std::cout << bar << TOP_LIMIT(percent, 100) << "%"  << std::endl;
}