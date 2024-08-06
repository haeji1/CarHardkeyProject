//
// Created by MinseokK on 24. 8. 5.
//


typedef void (*CarHandlerStrategy)(void *context, void *data);

typedef struct {
    CarHandlerStrategy strategy;
    void *data;
} CarHandlerContext;

void executeHandler(CarHandlerContext *context);



void handleMirrorAdjust();
void initializeMirrorAdjustHandlers();