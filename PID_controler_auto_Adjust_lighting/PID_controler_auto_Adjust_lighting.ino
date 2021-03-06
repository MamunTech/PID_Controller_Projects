
/*in this code, using PID controller contorl the intensity or brightness in a place.
 * using thi code, in a place light will be automatic adjusted.
 * here we measure the light intensity or brightness using the LDR.the value of the LED is independent
 * our main gola is to using the value of LDR in the PID controller algorithom 
 * automatic adjust the light intensity or brightness.
*/

//int cumalativeError=0;
//int intregralActiveZone=450;

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
}

void loop() {
  LDR_sensor_value=analogRead(A0);
  analogWrite(6,150); 
PID();
//for debag
Serial.println("LDR_sensor_value");
Serial.println(LDR_sensor_value);

}

void PID(){
  while(1){

present_Sensor_value=LDR_sensor_value;

   /* int intregralActiveZone=450;
    *  int error=500- present_Sensor_valu
    *  if(error<intregralActiveZone && error!=0){
    *  cumalativeError+=error;
    *  }
    *  else{
    *  cumalativeError=0;
    *  }
    *  if(error!=0){
    *  int proportion=error * kp;
    int intergral=cumalativeError *ki;
    int derivative=(error-lastError)*kd;
    *  }
    

int lastError=error;

  */
  
  porportional=present_Sensor_value-500;//here 500 is the terget value where i want to keep my value or this is the my tergated weighted sum of the tergate value or this mean i want that my sensor value is always 500, this the desire value for which i will use PID algorithom
  derivative=porportional-last_proportional;
  last_proportional=porportional;
  kp=1;
  ki=0.005;
  kd=0.1;

  
 pid=porportional*kp + integral*ki + derivative*kd;

const int max=255;
  if(pid>max)
   {pid=max;
   analogWrite(6,pid);
   }
  if(pid<-max)
  { pid= (-1*max);
  analogWrite(6,pid);
   }
    
  if(pid<0)
  {
   analogWrite(6,max+pid);
  }
  else
  {
   analogWrite(6,max-pid); 
  }


LDR_sensor_value=analogRead(A0);
Serial.println(LDR_sensor_value);

//delay(100);

  if(present_Sensor_value==500)
    return; //break the while loop


  
  }
  
}
