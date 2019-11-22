/* AL18013 井口拓海 */
/* 前に動き、後ろに動き、回転して、光る。 */
#include <stdio.h>
#include <createoi.h>
int main(){
begin();
forwardDrive( 300, 0); 

//  forwardTurn( 500, 1, 300);
  //waitTime(2); //回る

  //setLEDState(1, 0, 120); //光る


  end();
  return 0;
}
