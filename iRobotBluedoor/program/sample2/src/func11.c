#include<stdio.h>
#include<createoi.h>

void func11(void){
  int i; double x = 0.10;
  
  for( i = 0; i < 2; ++i ) {
    forwardDrive(500,0);   
    setLEDState(1,255,255);
    waitTime(0.6);
    waitTime(0.10+x);

    backwardDrive(500,0);
    setLEDState(1,0,255);  
    waitTime(0.50+x);
    
    setLEDState(1,255,255);
    forwardTurn(250, 0, 180);
  }//4,4,8tempo
  
  for ( i = 100;i<500;i+=100 ){
  forwardDrive(i,0);
  waitTime(0.3);
  }
  forwardTurn(500, 0, 270);

  for ( i = 500; i>=0;i-=100 ) {
  forwardDrive(i,0); waitTime(0.3);
  }
  waitTime(2.0);
}
