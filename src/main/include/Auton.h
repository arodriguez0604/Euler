// some of this should be in the DalekDrive class, but whatever
#pragma once

#include "Euler.h"

// literally every single #define is a guess, so test one at a time
#define START_DIST				1.524
#define pixelOffsetCoefficient	0.025
#define angleOffsetCoefficient	0.01
#define distanceCoefficient		0.3
#define turningErrorThreshold	0.05
#define distanceErrorThreshold	0.2
#define pTurn					2 // this number depends on the speed of the robot (weight and handicap)
#define iTurn					0 // probably unnecessary and won't be used
#define dTurn					0 // probably unnecessary and won't be used
#define maxTurnSpeed			0.5

using namespace std;
using namespace frc;

// all angles are in radians
// all measurements are in meters
class Auton {
	public:
	Auton(DalekDrive *drive, AHRS * ahrs, RaspberryPi *pi, BallIntake *ballIntake);
	
	void AutonCase(int begin, int end); // this must be called before AutonDrive()
	void AutonDrive();

	private:
	DalekDrive *m_drive;
	RaspberryPi *m_pi;
	AHRS *m_ahrs;
	BallIntake *m_ballIntake;
	// eventually will need delivery mechanism

	int auton_phase;
	double exit_target_x, exit_target_y, exit_target_ang, enter_target_x, enter_target_y, enter_target_ang;
	bool pickupBalls;

	bool driveToCoordinates(double x, double y, double angle);

};