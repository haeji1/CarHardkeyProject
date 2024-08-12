//
// Created by MinseokK on 24. 8. 8.
//

#ifndef CLIMATEFAN_H
#define CLIMATEFAN_H
typedef void(*ClimateFanControlFunction)();
void Level_One();
void Level_Two();
void Level_Three();
void Level_Four();
void Level_Five();
void handleClimateFan(ClimateFanControlFunction);
#endif //CLIMATEFAN_H
