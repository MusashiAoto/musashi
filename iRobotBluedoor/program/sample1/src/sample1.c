
#include<stdio.h>
#include<createoi.h>

int main(void)
{
  char s;
  int i;
  
  	while(1){
		begin();
		printf("scan key");
		scanf("%c", &s);
		
		printf("scan math");
		scanf("%d", &i);
		
		if(s=='w'){
			forwardDrive(300,i);
		}else if(s=='s'){	
			
			backwardDrive(300,i);
		}else if(s=='d'){
			forwardTurn(100,0,i);
		}else if(s=='a'){
		
			backwardTurn(100,0,i);
		}else{	
				printf("error");



		}

		end();
	}
  
  
  return 0;

}
