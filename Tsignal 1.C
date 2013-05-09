/*                          D64  智能交通灯   v1.9.6               */
/*      第十届大学生电子设计竞赛 D组 64号参赛队伍作品               */
/*             @杨杰        @刘智琳         @王雨彬                 */
//                       东北电力大学 
//						    2013.05
// 程序设计 	@王雨彬
// 硬件设计		@杨杰        @刘智琳 
#include<reg51.h>							  
											  
sbit nsMiku = P1^0	;			
sbit nsRin = P1^1  ;			
sbit nsMeiko = P1^2  ;		
sbit ewMiku = P1^3	 ;
sbit ewRin = P1^4	 ;
sbit ewMeiko = P1^5	  ;
sbit buttonNight = P2^4	  ;
sbit buttonEmergency = P2^5	;
sbit buttonAdd = P2^6	   ;
sbit buttonDecrease = P2^7	 ;
sbit led1 = P2^0 ;
sbit led2 = P2^1 ;
sbit led3 = P2^2 ;
sbit led4 = P2^3 ;


unsigned char led[10]={0xc0,0xf9,0xa4,0xb0,0x99,0x92,0x82,0xf8,0x80,0x90};	  
unsigned char ledPrivilegeArray[3]={0xB6,0x9C,0xA3};


int Back = 0 ;

void Delay10msEmergency(int count ){
	int i,j,k ;
	for(i = 0 ; i < count ; i++){
		for(j = 0 ; j <10 ; j++){
			for(k = 0 ; k < 10 ; k++) ;
				
			
		}
	}
 }


void LedClassics(int i){
	led3 = 0 ;
	P0 = led[i % 10] ;
	
	led3 = 1 ;
	led4 = 0 ;
	P0 = led[i / 10] ;
	
	led4 = 1 ;	
}	


void LedPrivilege(int i){
	
	
	   led1 = 0 ;
	   P0 = ledPrivilegeArray[i] ;
	   led1 = 1 ;
	   led2 = 0 ;
	   P0 = ledPrivilegeArray[i] ;
	   led2 = 1 ;
	   led3 = 0 ;
	   P0 = ledPrivilegeArray[i] ;
	   led3 = 1 ;
	   led4 = 0 ;
	   P0 = ledPrivilegeArray[i] ;
	   led4 = 1 ;
	
}

void Delay10msPrivilege(int count ){
	int i,j,k ;
	for(i = 0 ; i < count ; i++){
		for(j = 0 ; j <10 ; j++){
			for(k = 0 ; k < 10 ; k++) {
				LedPrivilege(0) ;
			}
		}
	}
 }


 void EmergencyPrivilege() {
	nsMiku = 1 ; nsRin = 1 ; nsMeiko = 0 ;
	ewMiku = 1 ; ewRin = 1 ; ewMeiko = 0 ;
	
	while(1){
	    int i = 90 ;
		
		
		led1 = 0 ; 
		P0 = ledPrivilegeArray[1]	;
		Delay10msEmergency(i);
		led1= 1 ;

		led2 = 0 ; 
		 P0 = ledPrivilegeArray[1]	;
		Delay10msEmergency(i);
		led2= 1 ;

		led3 = 0 ; 
		P0 = ledPrivilegeArray[1]	;
		Delay10msEmergency(i);
		led3= 1 ;

		led4 = 0 ; 
		P0 = ledPrivilegeArray[1]	;
		Delay10msEmergency(i);
		led4= 1 ;

 	    led4 = 0 ; 
		P0 = ledPrivilegeArray[2]	;
		Delay10msEmergency(i);
		led4= 1 ;

		 led3 = 0 ; 
		P0 = ledPrivilegeArray[2]	;
		Delay10msEmergency(i);
		led3= 1 ;

		  led2 = 0 ; 
		P0 = ledPrivilegeArray[2]	;
		Delay10msEmergency(i);
		led2= 1 ;

		   led1 = 0 ; 
		P0 = ledPrivilegeArray[2]	;
		Delay10msEmergency(i);
		led1= 1 ;

		   
		
	}
}

void NightPrivilege() {
	nsMiku = 1 ;nsMeiko = 1 ;
	ewMiku = 1 ; ewMeiko = 1 ;
	while(1){
		nsRin = 1 ; ewRin = 1 ;
		Delay10msPrivilege(100);
		nsRin = 0 ; ewRin = 0 ;
		Delay10msPrivilege(100);
		if(buttonEmergency == 0){
		
			while(!buttonEmergency){
		
			}
		EmergencyPrivilege();
	 	}
	}
}



void key(){
	if(buttonNight == 0){
	 	
		while(!buttonNight){
		
		}
		NightPrivilege();
	}
	
	if(buttonEmergency == 0){
		
		while(!buttonEmergency){
		
		}
		EmergencyPrivilege();
	 }
}

int keyTime(){
	int ExCount = 0 ;
	if(buttonAdd == 0){
		while(!buttonAdd){
		
		}
		ExCount = 1 ;
	}
	
	if(buttonDecrease == 0){
		while(!buttonDecrease){
		
		}
		ExCount = - 1 ;
	}
	return(ExCount);
}








void Delay10msLed(int count , int l){
	int i,j,k ;
	for(i = 0 ; i < count ; i++){
		for(j = 0 ; j < 4 ; j++){
			for(k = 0 ; k < 17 ; k++) {
				LedClassics(l) ;
				  key();
			    l = l + keyTime() ;
				Back = l ;
			}
		}
	}
 }




void main(){
	led1 = 1 ;
	led2 = 1 ;
	led3 = 1 ;
	led4 = 1 ;
	while(1){
		
		int i = 30 ;
		int k = 30 ;
		int j  ;	
		nsMiku = 0 ; nsRin = 1 ; nsMeiko = 1 ;
		ewMiku = 1 ; ewRin = 1 ; ewMeiko = 0 ;
		for( ; i > 0 ; i--){
			Delay10msLed(100 , i);
			i = Back ;
			
			
			
		}
		nsMiku = 1 ;  
		for(j = 3 ; j > 0 ; j--){
			nsRin = 1 ; 
			Delay10msLed(50 , j);
			nsRin = 0 ; 
			Delay10msLed(50 , j);
		}
		
		nsMiku = 1 ; nsRin = 1 ; nsMeiko = 0 ;
		ewMiku = 0 ; ewRin = 1 ; ewMeiko = 1 ;
		for( ; k > 0 ; k--){
			Delay10msLed(100 , k);
			k = Back ;
		}

		ewMiku = 1 ;
		for( j = 3; j > 0 ; j--){
			ewRin = 1 ;
			Delay10msLed(50 , j);
			ewRin = 0 ;
			Delay10msLed(50 , j);
		}
		
	}
}






