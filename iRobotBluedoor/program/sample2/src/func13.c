/* AL18013 井口拓海 */
/* 前に動き、後ろに動き、回転して、光る。 */
#include <stdio.h>
#include <createoi.h>
void func13(){

  forwardDrive( 300, 0); 
  waitTime(4); //前に進む

  backwardDrive( 300, 0);
  waitTime(4); //後ろに進む

int i;
 for(i=0;i<2;++i){
  backwardDrive(100,0);
  waitTime(0.5);// 後退 //
  forwardTurn(500,0,180);// 半回転 //
  }
  forwardDrive(100,0);
  waitTime(0.5);// 前進 //
  backwardDrive(100,0);
  waitTime(0.5);// 後退 //
  forwardTurn(500,0,0);
  waitTime(1); //２秒//

  forwardTurn( 500, 0, 0);
  waitTime(4); //回る

  
}
