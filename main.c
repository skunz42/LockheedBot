#pragma config(Motor,  motor1,          leftMotorA,    tmotorVexIQ, PIDControl, encoder)
#pragma config(Motor,  motor2,          leftMotorB,    tmotorVexIQ, PIDControl, encoder)
#pragma config(Motor,  motor3,          upperArm,      tmotorVexIQ, PIDControl, encoder)
#pragma config(Motor,  motor4,          lowerArm,      tmotorVexIQ, PIDControl, encoder)
#pragma config(Motor,  motor5,          rightMotorB,   tmotorVexIQ, PIDControl, reversed, encoder)
#pragma config(Motor,  motor6,          rightMotorA,   tmotorVexIQ, PIDControl, reversed, encoder)
#pragma config(Motor,	 motor8,					yuhMotor,			 tmotorVexIQ,	PIDControl,	reversed, encoder)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

void playTheme() {
	playNote(noteE, octave1, 20);
	playNote(noteE, octave1, 20);
	playNote(noteG, octave2, 20);
	playNote(noteC, octave3, 20);
	playNote(noteE, octave3, 20);
	sleep(20);
	playNote(noteE, octave3, 20);
	sleep(20);
	playNote(noteC, octave3, 20);
	sleep(40);
	playNote(noteC, octave1, 20);
	playNote(noteA, octave1, 20);
	playNote(noteA, octave1, 20);
}

task main()
{
	playTheme();
	while (true) {
		setMotorSpeed(leftMotorA,  (getJoystickValue(ChA) + getJoystickValue(ChB))/2);  	// (y - x)/2
		setMotorSpeed(leftMotorB,  (getJoystickValue(ChA) + getJoystickValue(ChB))/2);  	// (y - x)/2
		setMotorSpeed(rightMotorA, (getJoystickValue(ChA) - getJoystickValue(ChB))/2);  	// (y + x)/2
		setMotorSpeed(rightMotorB, (getJoystickValue(ChA) - getJoystickValue(ChB))/2);  	// (y + x)/2

		if(getJoystickValue(BtnRUp) == 1)
		{
			setMotorSpeed(lowerArm, -127);
			setMotorSpeed(yuhMotor, -127);
		}
		//If the "L-Up" isn't pressed, but "L-Down" is, we'll set the motor to run forward.
		else if(getJoystickValue(BtnRDown) == 1)
		{
			setMotorSpeed(lowerArm, 127);
			setMotorSpeed(yuhMotor, 127);
		}
		else	//If neither button is pressed, we'll set the motor off.
		{
			setMotorSpeed(lowerArm, 0);
			setMotorSpeed(yuhMotor, 0);
		}

		if(getJoystickValue(BtnLUp) == 1)
		{
			setMotorSpeed(upperArm, -127);
		}
		//If the "L-Up" isn't pressed, but "L-Down" is, we'll set the motor to run forward.
		else if(getJoystickValue(BtnLDown) == 1)
		{
			setMotorSpeed(upperArm, 127);
		}
		else	//If neither button is pressed, we'll set the motor off.
		{
			setMotorSpeed(upperArm, 0);
		}
	}
}
