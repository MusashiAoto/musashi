
void func08(void)
{
  int i; 
  forwardTurn(500,0,200);
  //waitTime(2); //２秒//
  forwardDrive(100,0);
  waitTime(0.5);// 前進 //
  backwardDrive(100,0);
  waitTime(0.5);// 後退 //
  for(i=0;i<3;++i){
    forwardDrive(300,0);
    waitTime(0.3);// 3回前進　//
  }
  forwardTurn(500,0,360);// ピーで一回転 //
  
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
  end();
}
