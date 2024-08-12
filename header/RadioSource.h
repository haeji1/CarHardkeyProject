//
// Created by MinseokK on 24. 8. 8.
//

#ifndef RADIOSOURCE_H
#define RADIOSOURCE_H
typedef void(*RadioSouceControlFunction)();

void AM();
void FM();
void BT();
void radioSouceControl(RadioSouceControlFunction);
#endif //RADIOSOURCE_H
