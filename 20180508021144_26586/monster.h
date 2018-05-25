#ifndef MONSTER_H
#define MONSTER_H
#include <rpgobj.h>


class Monster: public RPGObj
{
public:
    Monster(){}
    ~Monster(){}
    void move1(int direction1, int stepss=1);
};

#endif // MONSTER_H
