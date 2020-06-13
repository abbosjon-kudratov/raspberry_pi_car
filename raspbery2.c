#include <stdio.h>
#include <wiringPi.h>
#include <softPwm.h>



#define IN1_PIN     1
#define IN2_PIN     4
#define IN3_PIN     5
#define IN4_PIN     6

#define MAX_SPEED 100
#define MIN_SPEED 0

#define LEFT_IR_PIN 27
#define RIGHT_IR_PIN 26

#define TRIG_PIN 28
#define ECHO_PIN 29






void initDCMotor(); 
void goForward(); 
void goBackward(); 
void goLeft();

void goForwardSmooth(float s);
void goBackwardSmooth(int s);
void initDCMotorForSmooth();

void goRight();
void stopDCMotor();
void mission1();
void mission2();
void mission3();
void mission4();
void mission5();
void mission6();
void mission7();
void mission8();


void initIR();
int getDistance();








int main(void)
{
    
    int cntr = 1;
    if(wiringPiSetup() == -1) return 0;

    pinMode(TRIG_PIN, OUTPUT);
    pinMode(ECHO_PIN, INPUT);
    
    // pinMode(IN1_PIN, OUTPUT);
    // pinMode(IN2_PIN, OUTPUT);
    // pinMode(IN3_PIN, OUTPUT);
    // pinMode(IN4_PIN, OUTPUT);
     initDCMotorForSmooth();

    while(cntr>0)
{
          // mission1();
	 // mission2();
	   	   
           //mission3();
	   // mission4();
	    mission5();
	    //mission6();
	    //mission7();
	   // mission8();

	//initDCMotor();

	//int LValue, RValue;
	//initIR();

	//LValue=digitalRead(LEFT_IR_PIN);
	//RValue=digitalRead(RIGHT_IR_PIN);
	//if(LValue==1 && RValue==0){printf("Right\n"); goLeft(); delay(500);}
	//else if(LValue==0 && RValue==1){printf("Left\n");goRight(); delay(500); }
	//else if(LValue==0 && RValue==0){printf("Both\n");goBackward(); delay(500); /*stopDCMotor();*/}
	//else if(LValue==1 && RValue==1){printf("No\n"); goForward(); delay(1000);}

	stopDCMotor();

            cntr --;
    }

    return 0;

}



void initIR()
{
 pinMode(LEFT_IR_PIN, INPUT);
 pinMode(RIGHT_IR_PIN, INPUT);
}


void initDCMotor(){



	pinMode(IN1_PIN, OUTPUT);
	pinMode(IN2_PIN, OUTPUT);
	pinMode(IN3_PIN, OUTPUT);
	pinMode(IN4_PIN, OUTPUT);
	
	digitalWrite(IN1_PIN, HIGH); 
	digitalWrite(IN2_PIN, HIGH); 
	digitalWrite(IN3_PIN, HIGH); 
	digitalWrite(IN4_PIN, HIGH);
}


void initDCMotorForSmooth(){


	pinMode(IN1_PIN, SOFT_PWM_OUTPUT);
	pinMode(IN2_PIN, SOFT_PWM_OUTPUT);
	pinMode(IN3_PIN, SOFT_PWM_OUTPUT);
	pinMode(IN4_PIN, SOFT_PWM_OUTPUT);

  softPwmCreate(IN1_PIN, MIN_SPEED, MAX_SPEED); 
  softPwmCreate(IN2_PIN, MIN_SPEED, MAX_SPEED); 
  softPwmCreate(IN3_PIN, MIN_SPEED, MAX_SPEED); 
  softPwmCreate(IN4_PIN, MIN_SPEED, MAX_SPEED); 
  
}



void goForward(){ 
	digitalWrite(IN1_PIN, HIGH); 
	digitalWrite(IN2_PIN, LOW); 
	digitalWrite(IN3_PIN, HIGH); 
	digitalWrite(IN4_PIN, LOW); 
	printf("Forward\n");
}



void goForwardSmooth(float s){ 
	softPwmWrite(IN1_PIN, MAX_SPEED/s); 
	softPwmWrite(IN2_PIN, MIN_SPEED/s); 
	softPwmWrite(IN3_PIN, MAX_SPEED/s); 
	softPwmWrite(IN4_PIN, MIN_SPEED/s); 
	printf("Forward Smooth\n");
}


void goBackward(){
	digitalWrite(IN1_PIN, LOW); 
	digitalWrite(IN2_PIN, HIGH); 
	digitalWrite(IN3_PIN, LOW); 
	digitalWrite(IN4_PIN, HIGH); 
	printf("Backward\n");
}


void goBackwardSmooth(int s){
	softPwmWrite(IN1_PIN, MIN_SPEED/s); 
	softPwmWrite(IN2_PIN, MAX_SPEED/s); 
	softPwmWrite(IN3_PIN, MIN_SPEED/s); 
	softPwmWrite(IN4_PIN, MAX_SPEED/s); 
	printf("Backward Smooth\n");
}


void goLeft(){
	digitalWrite(IN1_PIN, LOW); 
	digitalWrite(IN2_PIN, HIGH); 
	digitalWrite(IN3_PIN, HIGH); 
	digitalWrite(IN4_PIN, LOW); 
	printf("Left\n");
}


void goRight(){
	digitalWrite(IN1_PIN, HIGH); 
	digitalWrite(IN2_PIN, LOW); 
	digitalWrite(IN3_PIN, LOW); 
	digitalWrite(IN4_PIN, HIGH); 
	printf("Right\n");
}


void goRightSmooth(int s){
	softPwmWrite(IN1_PIN, MAX_SPEED); 
	softPwmWrite(IN2_PIN, MIN_SPEED); 
	softPwmWrite(IN3_PIN, MAX_SPEED/s); 
	softPwmWrite(IN4_PIN, MIN_SPEED); 
	printf("Right Smooth\n");
    
    }


    
void goLeftSmooth(int s){
	softPwmWrite(IN1_PIN, MAX_SPEED/s); 
	softPwmWrite(IN2_PIN, MIN_SPEED); 
	softPwmWrite(IN3_PIN, MAX_SPEED); 
	softPwmWrite(IN4_PIN, MIN_SPEED); 
	printf("Left Smooth\n");
    
    }


  void goRightSmoothBack(int s){
	softPwmWrite(IN1_PIN, MIN_SPEED); 
	softPwmWrite(IN2_PIN, MAX_SPEED); 
	softPwmWrite(IN3_PIN, MIN_SPEED); 
	softPwmWrite(IN4_PIN, MAX_SPEED/s); 
	printf("Right Smooth Back\n");
    
    }
  

    void goLeftSmoothBack(int s){
	softPwmWrite(IN1_PIN, MIN_SPEED); 
	softPwmWrite(IN2_PIN, MAX_SPEED/s); 
	softPwmWrite(IN3_PIN, MIN_SPEED); 
	softPwmWrite(IN4_PIN, MAX_SPEED); 
	printf("Left Smooth Back\n");
    
    }



void stopDCMotor(){
	digitalWrite(IN1_PIN, LOW); 
	digitalWrite(IN2_PIN, LOW); 
	digitalWrite(IN3_PIN, LOW); 
	digitalWrite(IN4_PIN, LOW); 
	printf("Stop\n");
}

void stopDCMotorSmooth(){
	softPwmWrite(IN1_PIN, MIN_SPEED); 
	softPwmWrite(IN2_PIN, MIN_SPEED); 
	softPwmWrite(IN3_PIN, MIN_SPEED); 
	softPwmWrite(IN4_PIN, MIN_SPEED); 
	
	printf("Stop\n");
}

int getDistance(){

	int start_time=0, end_time=0;
	float distance=0;

	digitalWrite(TRIG_PIN, LOW);
	delay(100);
	digitalWrite(TRIG_PIN, HIGH);
	delayMicroseconds(10);
	digitalWrite(TRIG_PIN, LOW);

	while(digitalRead(ECHO_PIN)==0);
	start_time = micros();

	while(digitalRead(ECHO_PIN)==1);
	end_time = micros();

	distance = (end_time - start_time) /29. /2. ;

	return (int)distance;



}




void mission1(){

			
	    initDCMotor();



	    goForward();
            delay(2000);
            stopDCMotor();
            delay(1000);
            goRight();
            delay(400);
            goBackward();
            delay(2000);
            stopDCMotor();
            delay(1000);
            goLeft();
            delay(400);
            stopDCMotor();

}


void mission2(){

			
	    initDCMotor();
			
            goRight();
            delay(1500);
            
            stopDCMotor();
            delay(1000);
            
            goLeft();
            delay(1500);
            
            stopDCMotor();

}


void mission3(){
			
          //something

	    initDCMotorForSmooth();
			
            goForwardSmooth(4);
            delay(1000);

           	goForwardSmooth(3);
            delay(1000);

            goForwardSmooth(2);
            delay(1000);

            goForwardSmooth(1);
            delay(2000);
	    
	   
	    
            
            stopDCMotor();
            

}


void mission4(){
			
          //something

		initDCMotorForSmooth();

	    goRightSmooth(5);
	    delay(1000);
	    goForwardSmooth(1);
	    delay(1000);
	    
	     
	    goLeftSmooth(5);
	    delay(1900);
	    
	    goForwardSmooth(1);
	    delay(1000);
	    
	    
	   




        //goLeftSmooth(3);
	  //  delay(700);

        //goRightSmooth(3);
	    //delay(700);
	    
	    //goForwardSmooth(1);
        //delay(1000);

        stopDCMotor();


}





void mission5(){
			
   	initDCMotorForSmooth();

	    goRightSmoothBack(5);
	    delay(1000);
	    
	    goBackwardSmooth(1);
	    delay(1000);
	    
	    
	    goLeftSmoothBack(5);
	    delay(1700);
	    
	    goBackwardSmooth(1);
	    delay(1000);
	    
	    stopDCMotor();
	    
	     
	    
	    
	    //goForwardSmooth(1);
	   // delay(1000);




    

	    
            

}


void mission6() {
    int count;
    int distance;
    
    initDCMotorForSmooth();
    
    for (;;) {
	distance = getDistance();
	
	printf("distance %dcm\n", distance);
	
	if (distance < 30) {
	    stopDCMotor();
	   // goRightSmooth(5);
	    //delay(2000);
	    goBackwardSmooth(3);
	    delay(200);
	    //goForwardSmooth(3);
	    //delay(200);
	    
	    
	    count++;
	} 
	
	else if (distance==30){
	    stopDCMotor();
	    break;}
	
	//else if ((count % 3) == 0) {
	  //  stopDCMotor();
	    //break;
	//} 
	else {
	    goForwardSmooth(2);
	    delay(50);
	}
	
	printf("count %d\n", count);
    }

    stopDCMotor();
}


void mission7() {
    int count;
    int distance;
    
    initDCMotorForSmooth();
    
    for (;;) {
	distance = getDistance();
	
	printf("distance %dcm\n", distance);
	
	if (distance < 30) {
	    stopDCMotor();
	   
	    goBackwardSmooth(2);
	    delay(500);
	     goRightSmooth(5);
	    delay(700);
	    goLeftSmooth(5);
	    delay(1500);
	    goForwardSmooth(3);
	    delay(1000);
	    
	    
	    goLeftSmooth(5);
	    delay(600);
	    goRightSmooth(5);
	    delay(800);
	    goForwardSmooth(3);
	    delay(2000);
	    stopDCMotor();
	    break;
	    
	    
	    count++;
	} 
	
	//else if (distance==30){
	  //  stopDCMotor();
	    //break;}
	
	else if ((count % 3) == 0) {
	    stopDCMotor();
	    break;
	} 
	else {
	    goForwardSmooth(2);
	    delay(100);
	}
	
	printf("count %d\n", count);
    }

    stopDCMotor();
}


void mission8() {
    int count;
    int distance;
    
    initDCMotorForSmooth();
    
    for (;;) {
	distance = getDistance();
	
	printf("distance %dcm\n", distance);
	
	if (distance <= 100) {
	    //stopDCMotor();
	    if(distance > 20) {
		printf("distance is less than 100cm go SmoothForward");
		goForwardSmooth(2);
		delay(100);
	    }
	    else{
		printf("distance is less than 20cm");
		stopDCMotorSmooth();
		delay(1000);
	    } 
	
	//else if ((count % 3) == 0) {
	 //   stopDCMotor();
	//    break;
	} 
	else {
	    goForwardSmooth(1);
	    delay(100);
	}
	
	//printf("count %d\n", count);
    }

    stopDCMotor();
}

