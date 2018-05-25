#include "monster.h"

void Monster::move1(int direction1, int stepss){
    switch(direction1){
        case 1:
            this->_pos_y -= stepss;
            break;
        case 2:
            this->_pos_y += stepss;
            break;
        case 3:
            this->_pos_x -= stepss;
            break;
        case 4:
            this->_pos_x += stepss;
            break;
    }
}
