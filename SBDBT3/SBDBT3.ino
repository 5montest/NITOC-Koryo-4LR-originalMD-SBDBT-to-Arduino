#define DATA_CNT 8

byte data[DATA_CNT] = {0};

void setup()
{
  pinMode(4,OUTPUT);
  pinMode(8,OUTPUT);
  digitalWrite(4,HIGH);
  digitalWrite(8,HIGH);
  
  Serial.begin(2400);
}

void get_ps3()
{
  int i;
  
  do{
    if(Serial.available() > 0){ 
      data[7] = Serial.read();
    }
  }while(data[7] != 0x80);

  for(i=6;i>=0;i--){
    if(Serial.available() > 0){ 
      data[i] = Serial.read();
    }else{
      i++;
    }
  }
}

void drive(byte left_stick,byte right_stick)
{
 //左スティックの処理
 if(left_stick == 64){
  analogWrite(9,0);
  analogWrite(10,0);
 }else if(left_stick > 64){
   analogWrite(9,(left_stick-64)*3);
   analogWrite(10,0);
 }else{
   analogWrite(9,0);
   analogWrite(10,(64-left_stick)*3);
 }
 //右スティックの処理
 if(left_stick == 64){
  analogWrite(5,0);
  analogWrite(6,0);
 }else if(left_stick > 64){
   analogWrite(5,(right_stick-64)*3);
   analogWrite(6,0);
 }else{
   analogWrite(5,0);
   analogWrite(6,(64-right_stick)*3);
 }
}

void loop()
{
  get_ps3();
  drive(data[3],data[1]);
}
