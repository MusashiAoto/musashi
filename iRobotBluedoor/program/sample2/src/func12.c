/* AL18012 XXX */
#include <stdio.h>
#include <createoi.h>

void turn2pi(int);

int func12(void)
{
  begin();

  forwardDrive(300,0); //前進
  waitTime(3);
  turn(300,50,90,1);//右に
  forwardDrive(300,0);//進む
  waitTime(2);
  turn(300,50,180,1);//左に
  forwardDrive(300,0);//進む
  waitTime(2);
  turn(300,50,450,1);//回転して向きを戻す
  forwardDrive(300,0);//前進
  waitTime(1);
  backwardDrive(300,0);//後退
  waitTime(1);
  forwardDrive(300,0);//前進
  waitTime(2);


  backwardDrive( 300, 0);
  waitTime(2); //後ろに進む

  forwardTurn( 500, 0, 0);
  waitTime(2); //回る

 
    end();
return 0;
}
