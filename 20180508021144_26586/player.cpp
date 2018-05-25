#include "player.h"
//#include "world.h"

//direction =1,2,3,4 for 上下左右
void Player::move(int direction, RPGObj obj11, int steps){
    switch (direction){
        case 1:
            if(((this->getPosY()==3)&&(this->getPosX()==4))||((this->getPosY()==5)&&(this->getPosX()==6))||((this->getPosY()==8)&&(this->getPosX()==6))||((this->getPosY()==8)&&(this->getPosX()==7))||((this->getPosY()==13)&&(this->getPosX()==10))||((this->getPosY()==13)&&(this->getPosX()==11))||((this->getPosY()==8)&&(this->getPosX()==18))||((this->getPosY()==10)&&(this->getPosX()==17)))
            {
                    return;
            }
            else
            {
                this->_pos_y -= steps;
                break;
            }
        case 2:
            if(((this->getPosY()+2==3)&&(this->getPosX()==4))||((this->getPosY()+2==5)&&(this->getPosX()==6))||((this->getPosY()+2==8)&&(this->getPosX()==6))||((this->getPosY()+2==8)&&(this->getPosX()==7))||((this->getPosY()+2==13)&&(this->getPosX()==10))||((this->getPosY()+2==13)&&(this->getPosX()==11))||((this->getPosY()+2==8)&&(this->getPosX()==18))||((this->getPosY()+2==10)&&(this->getPosX()==17)))
            {

                    return;

            }
            else
            {
                this->_pos_y += steps;
                break;
            }
        case 3:
            if(((this->getPosY()+1==3)&&(this->getPosX()-1==4))||((this->getPosY()+1==5)&&(this->getPosX()-1==6))||((this->getPosY()+1==8)&&(this->getPosX()-1==6))||((this->getPosY()+1==8)&&(this->getPosX()-1==7))||((this->getPosY()+1==13)&&(this->getPosX()-1==10))||((this->getPosY()+1==13)&&(this->getPosX()-1==11))||((this->getPosY()+1==8)&&(this->getPosX()-1==18))||((this->getPosY()+1==10)&&(this->getPosX()-1==17)))
            {
                    return;

            }
            else
            {
                this->_pos_x -= steps;
                break;
            }
        case 4:
            if(((this->getPosY()+1==3)&&(this->getPosX()+1==4))||((this->getPosY()+1==5)&&(this->getPosX()+1==6))||((this->getPosY()+1==8)&&(this->getPosX()+1==6))||((this->getPosY()+1==8)&&(this->getPosX()+1==7))||((this->getPosY()+1==13)&&(this->getPosX()+1==10))||((this->getPosY()+1==13)&&(this->getPosX()+1==11))||((this->getPosY()+1==8)&&(this->getPosX()+1==18))||((this->getPosY()+1==10)&&(this->getPosX()+1==17)))
            {

                    return;

            }
            else
            {
                this->_pos_x += steps;
                break;
            }
    }
}
/*void Player::handleCollisions(){
    QList collisions = collidingItems();
}*/
