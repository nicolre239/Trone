#include "step.h"

Step::Step(int id)
{
    this ->id = id;
    switch (id) {
    case 1:
        setPixmap(QPixmap(":/images/Player1.png"));
        break;
    case 2:
        setPixmap(QPixmap(":/images/Player2.png"));
        break;
    default:
        setPixmap(QPixmap(":/images/Field.png"));
        break;
    }
}
