#ifndef HANDS_FREE_H
#define HANDS_FREE_H

typedef void (*handsFreeFunction)();

void activateHandsFree(void);
void setHandsFree(handsFreeFunction hff);

#endif // HANDS_FREE_H
