//
// Created by MinseokK on 24. 8. 8.
//

#ifndef CLIMATEAIRFLOW_H
#define CLIMATEAIRFLOW_H
typedef void(*ClimateAirflowControlFunction)();

void AirflowFace();
void AirflowFoot();
void AirflowDefrost();
void handleClimateAirflow(ClimateAirflowControlFunction);
#endif //CLIMATEAIRFLOW_H
