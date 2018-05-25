#include "world.h"
#include "icon.h"

 RPGObj obj1, obj2, obj3, obj4, obj5, obj6, obj7, obj8, obj9, obj10;

void World::initWorld(string mapFile){
    //TODO 下面这部分逻辑应该是读入地图文件，生成地图上的对象
    //player 5 5
    this->_player.initObj("player");
    this->_player.setPosX(5);
    this->_player.setPosY(5);

    this->_monster.initObj("monster");
    this->_monster.setPosX(13);
    this->_monster.setPosY(11);



    //stone 4 5
   // RPGObj obj1, obj2, obj3, obj4, obj5, obj6, obj7, obj8, obj9, obj10;
    obj1.initObj("stone");
    obj1.setPosX(4);
    obj1.setPosY(3);

    obj2.initObj("stone");
    obj2.setPosX(6);
    obj2.setPosY(5);

    obj3.initObj("fruit");
    obj3.setPosX(6);
    obj3.setPosY(8);

    obj4.initObj("fruit");
    obj4.setPosX(7);
    obj4.setPosY(8);

    obj5.initObj("fruit");
    obj5.setPosX(10);
    obj5.setPosY(13);

    obj6.initObj("stone");
    obj6.setPosX(11);
    obj6.setPosY(13);

    obj7.initObj("stone");
    obj7.setPosX(17);
    obj7.setPosY(10);

    obj8.initObj("fruit");
    obj8.setPosX(18);
    obj8.setPosY(8);

    obj9.initObj("well");
    obj9.setPosX(15);
    obj9.setPosY(15);

    obj10.initObj("banana");
    obj10.setPosX(13);
    obj10.setPosY(9);


    this->_objs.push_back(obj1);
    this->_objs.push_back(obj2);
    this->_objs.push_back(obj3);
    this->_objs.push_back(obj4);
    this->_objs.push_back(obj5);
    this->_objs.push_back(obj6);
    this->_objs.push_back(obj7);
    this->_objs.push_back(obj8);
    this->_objs.push_back(obj9);
    this->_objs.push_back(obj10);


}


void World::show(QPainter * painter){
    vector<RPGObj>::iterator it;
    for(it=this->_objs.begin();it!=this->_objs.end();it++){
        (*it).show(painter);
    }
    /*if((_player.getPosX()==13)&&(_player.getPosY()==9))
    {
        this->_objs.erase(_objs.begin()+9);
    }*/
    for(it=this->_objs.begin();it!=this->_objs.end();it++){
        if((this->_player.getPosX() == 13)&&(_player.getPosY() == 9)&&(it == _objs.begin()+9))
        {
            it = this->_objs.erase(it);
            break;
        }
    }


    this->_player.show(painter);
    this->_monster.show(painter);
}

void World::handlePlayerMove (int direction,int steps){
    //vector<RPGObj>::iterator it;
    //for(int i = 0; i < 10; i++){
        //if((_player.getPosX()== it.getPosX())&&(_player.getPosY()== it.getPosY())&&(it.canCover == false))
        //{
            this->_player.move(direction,obj1, steps);
        //}
    //}


    //this->_player.move(direction, obj1, steps);
}

void World::handleMonsterMove(int direction1, int stepss){
    this->_monster.move1(direction1,stepss);
}

