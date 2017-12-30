//connecting motors
int mot1=;
int mot2=;
int mot3=;
int mot4=;

//sensor
int left=;
int right=;

int Lread=0;
int Rread=0;

void LEFT (void);
void RIGHT (void);
void STOP (void);

void setup()
{
  pinMode(mot1,OUTPUT);
  pinMode(mot2,OUTPUT);
  pinMode(mot3,OUTPUT);
  pinMode(mot4,OUTPUT);

  pinMode(left,INPUT);
  pinMode(right,INPUT);

  digitalWrite(left,HIGH);
  digitalWrite(right,HIGH);
  
  
}

void loop() 
{
 
analogWrite(mot1,255);
analogWrite(mot2,0);
analogWrite(mot3,255);
analogWrite(mot4,0);

while(1)
{
  Lread=digitalRead(left);
  Rread=digitalRead(right);
  
  if((Lread==0 && Rread==1)==1)
  LEFT();
  else if((Rread==0 && Lread==1)==1)
  RIGHT();
}
}

void LEFT (void)
{
   analogWrite(mot3,0);
   analogWrite(mot4,30);
   
   
   while(Left==0)
   {
    Lread=digitalRead(left);
    Rread=digitalRead(right);
    if(Right==0)
    {
      int lprev=Lread;
      int rprev=Rread;
      STOP();
      while(((lprev==Lread)&&(rprev==Rread))==1)
      {
         Lread=digitalRead(left);
         Rread=digitalRead(right);
      }
    }
    analogWrite(mot1,255);
    analogWrite(mot2,0); 
   }
   analogWrite(mot3,255);
   analogWrite(mot4,0);
}

void RIGHT (void)
{
   analogWrite(mot1,0);
   analogWrite(mot2,30);

   while(Rread==0)
   {
    Lread=digitalRead(left);
    Rread=digitalRead(right);
    if(Lread==0)
    {
      int lprev=Lread;
      int rprev=Rread;
     STOP();
      while(((lprev==Lread)&&(rprev==Rread))==1)
      {
         Lread=digitalRead(left);
         Rread=digitalRead(right);
      }
    }
    analogWrite(mot3,255);
    analogWrite(mot4,0);
    }
   analogWrite(mot1,255);
   analogWrite(mot2,0);
}
void STOP (void)
{
analogWrite(mot1,0);
analogWrite(mot2,0);
analogWrite(mot3,0);
analogWrite(mot4,0);
  
}
