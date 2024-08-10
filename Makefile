all: main.exe
	./main.exe

main.exe: main.o observer.o ignition.o horn.o headlights.o turnsignals.o windshield.o hazard.o cruise.o radio_volume.o radio_tuning.o display.o trunk.o steering.o sunroof.o traction.o pbrake.o menu.o interior.o drive.o fuel.o hseat.o cseat.o auto_hold.o hud_Adjust.o glove_box_release.o fog_lights.o emergency_brake.o trailer_control.o hands_free.o seat_heater.o seat_cooler.o RadioSource.o ClimateAirflow.o ClimateFan.o ClimateTemp.o Defrost.o DoorLock.o MirrorAdjust.o PowerWindows.o WindowLock.o SeatAdjust.o
	gcc -o main.exe main.o observer.o ignition.o horn.o headlights.o turnsignals.o windshield.o hazard.o cruise.o radio_volume.o radio_tuning.o display.o trunk.o steering.o sunroof.o traction.o pbrake.o menu.o interior.o drive.o fuel.o hseat.o cseat.o auto_hold.o hud_Adjust.o glove_box_release.o fog_lights.o emergency_brake.o trailer_control.o hands_free.o seat_heater.o seat_cooler.o RadioSource.o ClimateAirflow.o ClimateFan.o ClimateTemp.o Defrost.o DoorLock.o MirrorAdjust.o PowerWindows.o WindowLock.o SeatAdjust.o

main.o: main.c observer.h ignition.h horn.h headlights.h turnsignals.h windshield.h hazard.h cruise.h radio_volume.h radio_tuning.h display.h auto_hold.h hud_Adjust.h glove_box_release.h fog_lights.h emergency_brake.h trailer_control.h hands_free.h seat_heater.h seat_cooler.h
	gcc -c main.c

observer.o: observer.c observer.h
	gcc -c observer.c

display.o: display.c observer.h display.h
	gcc -c display.c

ignition.o: ignition.c observer.h ignition.h
	gcc -c ignition.c
	
horn.o: horn.c observer.h horn.h
	gcc -c horn.c

headlights.o: headlights.c observer.h headlights.h
	gcc -c headlights.c

turnsignals.o: turnsignals.c observer.h turnsignals.h
	gcc -c turnsignals.c

windshield.o: windshield.c observer.h windshield.h
	gcc -c windshield.c

hazard.o: hazard.c observer.h hazard.h
	gcc -c hazard.c

cruise.o: cruise.c observer.h cruise.h
	gcc -c cruise.c

radio_volume.o: radio_volume.c observer.h radio_volume.h
	gcc -c radio_volume.c

radio_tuning.o: radio_tuning.c observer.h radio_tuning.h
	gcc -c radio_tuning.c

sunroof.o: sunroof.c observer.h sunroof.h
	gcc -c sunroof.c

trunk.o: trunk.c observer.h trunk.h
	gcc -c trunk.c

fuel.o: fuel.c observer.h fuel.h
	gcc -c fuel.c

drive.o: drive.c observer.h drive.h
	gcc -c drive.c

pbrake.o: pbrake.c observer.h pbrake.h
	gcc -c pbrake.c

hseat.o: hseat.c observer.h hseat.h
	gcc -c hseat.c

cseat.o: cseat.c observer.h cseat.h
	gcc -c cseat.c

steering.o: steering.c observer.h steering.h
	gcc -c steering.c

interior.o: interior.c observer.h interior.h
	gcc -c interior.c

traction.o: traction.c observer.h traction.h
	gcc -c traction.c

auto_hold.o: auto_hold.c observer.h auto_hold.h
	gcc -c auto_hold.c

fog_lights.o: fog_lights.c observer.h fog_lights.h
	gcc -c fog_lights.c

seat_heater.o: seat_heater.c observer.h seat_heater.h
	gcc -c seat_heater.c

seat_cooler.o: seat_cooler.c observer.h seat_cooler.h
	gcc -c seat_cooler.c

trailer_control.o: trailer_control.c observer.h trailer_control.h
	gcc -c trailer_control.c

hands_free.o: hands_free.c observer.h hands_free.h
	gcc -c hands_free.c

hud_Adjust.o: hud_Adjust.c observer.h hud_Adjust.h
	gcc -c hud_Adjust.c

menu.o: menu.c observer.h menu.h
	gcc -c menu.c
RadioSource.o : RadioSource.c RadioSource.h observer.h
	gcc -c RadioSource.c

ClimateAirflow.o : ClimateAirflow.c ClimateAirflow.h observer.h
	gcc -c ClimateAirflow.c

ClimateFan.o : ClimateFan.c ClimateFan.h observer.h
	gcc -c ClimateFan.c

ClimateTemp.o : ClimateTemp.c ClimateTemp.h observer.h
	gcc -c ClimateTemp.c

Defrost.o : Defrost.c Defrost.h observer.h
	gcc -c Defrost.c

DoorLock.o : DoorLock.c DoorLock.h observer.h
	gcc -c DoorLock.c

MirrorAdjust.o : MirrorAdjust.c MirrorAdjust.h observer.h
	gcc -c MirrorAdjust.c

PowerWindows.o : PowerWindows.c PowerWindows.h observer.h
	gcc -c PowerWindows.c

WindowLock.o : WindowLock.c WindowLock.h observer.h
	gcc -c WindowLock.c

SeatAdjust.o : SeatAdjust.c SeatAdjust.h observer.h
	gcc -c SeatAdjust.c

glove_box_release.o: glove_box_release.c observer.h glove_box_release.h
	gcc -c glove_box_release.c

emergency_brake.o: emergency_brake.c observer.h emergency_brake.h
	gcc -c emergency_brake.c

clean:
	rm -f *.o main.exe