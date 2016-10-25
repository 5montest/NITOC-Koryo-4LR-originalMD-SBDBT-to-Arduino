int i = 0;//速度
boolean flag = 0;

void setup()
{
  pinMode(4,OUTPUT);
  digitalWrite(4,HIGH);
}

void loop()
{
  
  if(flag == 0){
  //右回転(仮) 
    analogWrite(5,i);
    analogWrite(6,0);
    if(i<240){
      i++;
    }else{
      flag = 1;
      i = 0;
    }
    
  }else{
  //左回転(仮)
    analogWrite(5,0);
    analogWrite(6,i);
    if(i<240){
      i++;
    }else{
      flag = 0;
      i = 0;
    }
    
  }
  
  delay(50);
  
}
