#include <stdio.h>
#include <createoi.h>
void func10(void)
{

	begin();
	directDrive(300,-300);
	waitTime(0.4);
	drive(0,0);
	end();
	sleep(0.8);
	begin();
	directDrive(300,-300);
	waitTime(0.4);
	drive(0,0);
	end();
	sleep(0.8);
	begin();
	directDrive(-300,300);
	waitTime(0.4);
	drive(0,0);
	end();
	sleep(0.8);
	begin();
	directDrive(-300,300);
	waitTime(0.4);
	drive(0,0);
	end();
	sleep(0.8);


	begin();
	drive(300,0);
	waitTime(0.4);
	end();
	sleep(0.8);
	begin();
	drive(-300,0);
	waitTime(0.4);
	end();
	sleep(0.8);
	begin();
	drive(500,0);
	waitTime(0.1);
	end();
	begin();
	drive(500,0);
	waitTime(0.1);
	end();
	begin();
	drive(500,0);
	waitTime(0.1);
	end();
	begin();
  }