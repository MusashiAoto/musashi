#include <stdio.h>
#include <createoi.h>
#include <time.h>
void func08(void);
void func09(void);
void func10(void);
void func11(void);
void func12(void);
void func13(void);
int main()
{
 begin();

	time_t ii;
	ii = time(NULL);
	int t = time(&ii);

	while(1){
		int tt = time(&ii);
		int s = tt - t;
		printf("%d\n", s);
		if(s == 2){
			func08();
		}else if( s == 13 ){
			func10();
		}else if( s == 18 ){
			func11();
		}else if( s == 31 ){
			func12();
		}else if( s == 42 ){
			func13();
		}else if( s == 55 ){
			func10();
		}else if( s == 60 ){
			func10();
		}else if( s == 67 ){
			func08();
		}
	}



 // 	func08();
 // 	int a;
	// while(1){
	// 	scanf("%d",&a);
	// 	if(a == 1){
	// 		func10();
	// 		a = 0;
	// 	}
	// }



	// func08();
	// func09();
	// func10();
	// func11();
	// func12();
	// func13();
end();
return 0;
}
