
/*in this code, using PID controller contorl the intensity or brightness in a place.
 * using thi code, in a place light will be automatic adjusted.
 * here we measure the light intensity or brightness using the LDR.the value of the LED is independent
 * our main gola is to using the value of LDR in the PID controller algorithom 
 * automatic adjust the light intensity or brightness.
*/

int cumalativeError=0;
int intregralActiveZone=780;
int error;
int lastError;
float a=0;
float implementPID=0;

int 
  derivative=0,
  porportional=0,
  integral=0;
float kp,ki,kd;
int last_proportional=0;
int LDR_sensor_value=0,present_Sensor_value=0;
float pid;

void setup() {
  pinMode(A0,INPUT);//LDR sensor at A0
  pinMode(6,OUTPUT);//LED at 6
  Serial.begin(9600);
  analogWrite(6,0);
}

void loop() {
  LDR_sensor_value=analogRead(A0);
 
PID();

//analogWrite(6,1);
//for debag

Serial.print(800);


//Serial.println("LDR_sensor_value");
Serial.print(" ");
Serial.print(LDR_sensor_value);

Serial.print(" ");
Serial.print(255);


Serial.print(" ");
Serial.print(implementPID);

//Serial.print(" ");
//Serial.println(pid);


//delay(100);

}

void PID(){


present_Sensor_value=LDR_sensor_value;

 
       error=800- present_Sensor_value;
       Serial.print(" ");
Serial.println(error);
      if(error<200 && error!=0) ////integral intregralActiveZone
      {
      cumalativeError+=error;
      }
      else{
      cumalativeError=0;
      }

      
      porportional=error * kp;
    integral=cumalativeError *ki;
    derivative=(error-lastError)*kd;
      if(error==0){
        derivative=0;
        }
    

 lastError=error;

 
  kp=.9;
  ki=0.1;
  kd=0.6;

  
 pid=porportional*kp + integral*ki + derivative*kd;

 if(error=!0){

if(pid>0){
  
  implementPID+=a+0.1;
  analogWrite(6,implementPID);
  }
  
if(pid<0){
  
  implementPID+=a-0.1;
  analogWrite(6,implementPID);
  }
  
  delay(40);
//if(pid>255){
//  float modifiedPID=pid*0.1;
//  implementPID=a+modifiedPID;
//  analogWrite(6,implementPID);
//  }
//  
//if(pid<0){
//   float modifiedPID=pid*0.1;
//   implementPID=a-modifiedPID;
//analogWrite(6,implementPID);
//}
//else{
//  float modifiedPID=pid*0.3;
//  implementPID=a+modifiedPID;
//  analogWrite(6,implementPID);
//  }

 }

//const int max=255;
//  if(pid>max)
//   {pid=max;
//   analogWrite(6,pid);
//   }
//  if(pid<-max)
//  { pid= (-1*max);
//  analogWrite(6,pid);
//   }
//    
//  if(pid<0)
//  {
//   analogWrite(6,max+pid);
//  }
//  else
//  {
//   analogWrite(6,max-pid); 
//  }


LDR_sensor_value=analogRead(A0);
//Serial.println(LDR_sensor_value);

//delay(4);

  
  
}
