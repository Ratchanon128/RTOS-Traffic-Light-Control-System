#define GREEN_1_SET_TIME 2000

#define GREEN_2_SET_TIME 2000

#define GREEN_3_SET_TIME 2000

#define GREEN_4_SET_TIME 2000

#define YELLOW_SET_TIME 1000


#define LIGHT_1_RED 2
#define LIGHT_1_YELLOW 3
#define LIGHT_1_GREEN 4

#define LIGHT_2_RED 5
#define LIGHT_2_YELLOW 6
#define LIGHT_2_GREEN 7

#define LIGHT_3_RED 8
#define LIGHT_3_YELLOW 9
#define LIGHT_3_GREEN 10

#define LIGHT_4_RED 11
#define LIGHT_4_YELLOW 12
#define LIGHT_4_GREEN 13

#define GREEN_LIGHT_1 0
#define YELLOW_LIGHT_1 1

#define GREEN_LIGHT_2 2
#define YELLOW_LIGHT_2 3

#define GREEN_LIGHT_3 4
#define YELLOW_LIGHT_3 5

#define GREEN_LIGHT_4 6
#define YELLOW_LIGHT_4 7

//switch
#define SW5 A0
#define SW6 A1
#define SW7 A2
#define SW8 A3

unsigned long Timer_1 = 0;

unsigned short Set_Time[8] = {GREEN_1_SET_TIME, YELLOW_SET_TIME,
                              GREEN_2_SET_TIME, YELLOW_SET_TIME, 
                              GREEN_3_SET_TIME, YELLOW_SET_TIME,
                              GREEN_4_SET_TIME, YELLOW_SET_TIME};

short Light_Index = GREEN_LIGHT_1;

void setup() 
{
  Serial.begin(9600);

  pinMode(LIGHT_1_GREEN, OUTPUT);
  pinMode(LIGHT_1_YELLOW, OUTPUT);
  pinMode(LIGHT_1_RED, OUTPUT);

  pinMode(LIGHT_2_GREEN, OUTPUT);
  pinMode(LIGHT_2_YELLOW, OUTPUT);
  pinMode(LIGHT_2_RED, OUTPUT);

  pinMode(LIGHT_3_GREEN, OUTPUT);
  pinMode(LIGHT_3_YELLOW, OUTPUT);
  pinMode(LIGHT_3_RED, OUTPUT);

  pinMode(LIGHT_4_GREEN, OUTPUT);
  pinMode(LIGHT_4_YELLOW, OUTPUT);
  pinMode(LIGHT_4_RED, OUTPUT);

  //แก้
  pinMode(SW5,INPUT_PULLUP);
  pinMode(SW6,INPUT_PULLUP);
  pinMode(SW7,INPUT_PULLUP);
  pinMode(SW8,INPUT_PULLUP);

  Serial.println("Tx");

  Traffic_GREEN_1();
  //delay(2000);

  Timer_1 = millis();
}

// the loop function runs over and over again forever
void loop() 
{
  //int randomGreenSetTime = random(1000, 2000);
  //int randomRedSetTime = random(1000, 2000);
  //Serial.println(String(GREEN_1_SET_TIME)+","+String(GREEN_2_SET_TIME)+","+String(GREEN_3_SET_TIME)+","+String(YELLOW_SET_TIME));
  //delay(2000);

  if((millis()-Timer_1) >= Set_Time[Light_Index])
  {
    Light_Index++;

    if(Light_Index > 7)
    {
      Light_Index = GREEN_LIGHT_1;
    }

    Timer_1 = millis();

    if(Light_Index == GREEN_LIGHT_1)
    {
      Traffic_GREEN_1();
    }
    else if(Light_Index == YELLOW_LIGHT_1)
    {
      Traffic_YELLOW_1();
    }
    
    else if(Light_Index == GREEN_LIGHT_2)
    {
      Traffic_GREEN_2();
    }
    else if(Light_Index == YELLOW_LIGHT_2)
    {
      Traffic_YELLOW_2();
    }
    
    else if(Light_Index == GREEN_LIGHT_3)
    {
      Traffic_GREEN_3();
    }
    else if(Light_Index == YELLOW_LIGHT_3)
    {
      Traffic_YELLOW_3();
    }

    else if(Light_Index == GREEN_LIGHT_4)
    {
      Traffic_GREEN_4();
    }
    else if(Light_Index == YELLOW_LIGHT_4)
    {
      Traffic_YELLOW_4();
      int TIME_GREEN_NEXT = GREEN_1_SET_TIME + GREEN_2_SET_TIME + GREEN_3_SET_TIME + + GREEN_3_SET_TIME + (YELLOW_SET_TIME * 4);
      Serial.println(String(TIME_GREEN_NEXT));
    }
  }

  //switch
  if(digitalRead(SW5) == LOW)
  {
     digitalWrite(LIGHT_1_RED,LOW);
     digitalWrite(LIGHT_1_YELLOW,LOW);
     digitalWrite(LIGHT_1_GREEN,HIGH);
     digitalWrite(LIGHT_2_RED,HIGH);
     digitalWrite(LIGHT_2_YELLOW,LOW);
     digitalWrite(LIGHT_2_GREEN,LOW);
     digitalWrite(LIGHT_3_RED,HIGH);
     digitalWrite(LIGHT_3_YELLOW,LOW);
     digitalWrite(LIGHT_3_GREEN,LOW);
     digitalWrite(LIGHT_4_RED,HIGH);
     digitalWrite(LIGHT_4_YELLOW,LOW);
     digitalWrite(LIGHT_4_GREEN,LOW);
  }
  if(digitalRead(SW6) == LOW)
  {
     digitalWrite(LIGHT_1_RED,HIGH);
     digitalWrite(LIGHT_1_YELLOW,LOW);
     digitalWrite(LIGHT_1_GREEN,LOW);
     digitalWrite(LIGHT_2_RED,LOW);
     digitalWrite(LIGHT_2_YELLOW,LOW);
     digitalWrite(LIGHT_2_GREEN,HIGH);
     digitalWrite(LIGHT_3_RED,HIGH);
     digitalWrite(LIGHT_3_YELLOW,LOW);
     digitalWrite(LIGHT_3_GREEN,LOW);
     digitalWrite(LIGHT_4_RED,HIGH);
     digitalWrite(LIGHT_4_YELLOW,LOW);
     digitalWrite(LIGHT_4_GREEN,LOW);
  }
  if(digitalRead(SW7) == LOW)
  {
     digitalWrite(LIGHT_1_RED,HIGH);
     digitalWrite(LIGHT_1_YELLOW,LOW);
     digitalWrite(LIGHT_1_GREEN,LOW);
     digitalWrite(LIGHT_2_RED,HIGH);
     digitalWrite(LIGHT_2_YELLOW,LOW);
     digitalWrite(LIGHT_2_GREEN,LOW);
     digitalWrite(LIGHT_3_RED,LOW);
     digitalWrite(LIGHT_3_YELLOW,LOW);
     digitalWrite(LIGHT_3_GREEN,HIGH);
     digitalWrite(LIGHT_4_RED,HIGH);
     digitalWrite(LIGHT_4_YELLOW,LOW);
     digitalWrite(LIGHT_4_GREEN,LOW);
  }
  if(digitalRead(SW8) == LOW)
  {
     digitalWrite(LIGHT_1_RED,HIGH);
     digitalWrite(LIGHT_1_YELLOW,LOW);
     digitalWrite(LIGHT_1_GREEN,LOW);
     digitalWrite(LIGHT_2_RED,HIGH);
     digitalWrite(LIGHT_2_YELLOW,LOW);
     digitalWrite(LIGHT_2_GREEN,LOW);
     digitalWrite(LIGHT_3_RED,HIGH);
     digitalWrite(LIGHT_3_YELLOW,LOW);
     digitalWrite(LIGHT_3_GREEN,LOW);
     digitalWrite(LIGHT_4_RED,LOW);
     digitalWrite(LIGHT_4_YELLOW,LOW);
     digitalWrite(LIGHT_4_GREEN,HIGH);
  }
}

void Traffic_GREEN_1(){
  digitalWrite(LIGHT_1_GREEN, HIGH);
  digitalWrite(LIGHT_1_YELLOW, LOW);
  digitalWrite(LIGHT_1_RED, LOW);   

  digitalWrite(LIGHT_2_GREEN, LOW);
  digitalWrite(LIGHT_2_YELLOW, LOW);
  digitalWrite(LIGHT_2_RED, HIGH);

  digitalWrite(LIGHT_3_GREEN, LOW);
  digitalWrite(LIGHT_3_YELLOW, LOW);
  digitalWrite(LIGHT_3_RED, HIGH);

  digitalWrite(LIGHT_4_GREEN, LOW);
  digitalWrite(LIGHT_4_YELLOW, LOW);
  digitalWrite(LIGHT_4_RED, HIGH);
}

void Traffic_GREEN_2(){
  digitalWrite(LIGHT_1_GREEN, LOW);
  digitalWrite(LIGHT_1_YELLOW, LOW);
  digitalWrite(LIGHT_1_RED, HIGH);   

  digitalWrite(LIGHT_2_GREEN, HIGH);
  digitalWrite(LIGHT_2_YELLOW, LOW);
  digitalWrite(LIGHT_2_RED, LOW);

  digitalWrite(LIGHT_3_GREEN, LOW);
  digitalWrite(LIGHT_3_YELLOW, LOW);
  digitalWrite(LIGHT_3_RED, HIGH);

  digitalWrite(LIGHT_4_GREEN, LOW);
  digitalWrite(LIGHT_4_YELLOW, LOW);
  digitalWrite(LIGHT_4_RED, HIGH);
}

void Traffic_GREEN_3(){
  digitalWrite(LIGHT_1_GREEN, LOW);
  digitalWrite(LIGHT_1_YELLOW, LOW);
  digitalWrite(LIGHT_1_RED, HIGH);   

  digitalWrite(LIGHT_2_GREEN, LOW);
  digitalWrite(LIGHT_2_YELLOW, LOW);
  digitalWrite(LIGHT_2_RED, HIGH);

  digitalWrite(LIGHT_3_GREEN, HIGH);
  digitalWrite(LIGHT_3_YELLOW, LOW);
  digitalWrite(LIGHT_3_RED, LOW);

  digitalWrite(LIGHT_4_GREEN, LOW);
  digitalWrite(LIGHT_4_YELLOW, LOW);
  digitalWrite(LIGHT_4_RED, HIGH);
}

void Traffic_GREEN_4(){
  digitalWrite(LIGHT_1_GREEN, LOW);
  digitalWrite(LIGHT_1_YELLOW, LOW);
  digitalWrite(LIGHT_1_RED, HIGH);   

  digitalWrite(LIGHT_2_GREEN, LOW);
  digitalWrite(LIGHT_2_YELLOW, LOW);
  digitalWrite(LIGHT_2_RED, HIGH);

  digitalWrite(LIGHT_3_GREEN, LOW);
  digitalWrite(LIGHT_3_YELLOW, LOW);
  digitalWrite(LIGHT_3_RED, HIGH);

  digitalWrite(LIGHT_4_GREEN, HIGH);
  digitalWrite(LIGHT_4_YELLOW, LOW);
  digitalWrite(LIGHT_4_RED, LOW);
}

void Traffic_YELLOW_1(){
  digitalWrite(LIGHT_1_GREEN, LOW);
  digitalWrite(LIGHT_1_YELLOW, HIGH);
  digitalWrite(LIGHT_1_RED, LOW);   

  digitalWrite(LIGHT_2_GREEN, LOW);
  digitalWrite(LIGHT_2_YELLOW, LOW);
  digitalWrite(LIGHT_2_RED, HIGH);

  digitalWrite(LIGHT_3_GREEN, LOW);
  digitalWrite(LIGHT_3_YELLOW, LOW);
  digitalWrite(LIGHT_3_RED, HIGH);

  digitalWrite(LIGHT_4_GREEN, LOW);
  digitalWrite(LIGHT_4_YELLOW, LOW);
  digitalWrite(LIGHT_4_RED, HIGH);
}

void Traffic_YELLOW_2(){
  digitalWrite(LIGHT_1_GREEN, LOW);
  digitalWrite(LIGHT_1_YELLOW, LOW);
  digitalWrite(LIGHT_1_RED, HIGH);   

  digitalWrite(LIGHT_2_GREEN, LOW);
  digitalWrite(LIGHT_2_YELLOW, HIGH);
  digitalWrite(LIGHT_2_RED, LOW);

  digitalWrite(LIGHT_3_GREEN, LOW);
  digitalWrite(LIGHT_3_YELLOW, LOW);
  digitalWrite(LIGHT_3_RED, HIGH);

  digitalWrite(LIGHT_4_GREEN, LOW);
  digitalWrite(LIGHT_4_YELLOW, LOW);
  digitalWrite(LIGHT_4_RED, HIGH);
}

void Traffic_YELLOW_3(){
  digitalWrite(LIGHT_1_GREEN, LOW);
  digitalWrite(LIGHT_1_YELLOW, LOW);
  digitalWrite(LIGHT_1_RED, HIGH);   

  digitalWrite(LIGHT_2_GREEN, LOW);
  digitalWrite(LIGHT_2_YELLOW, LOW);
  digitalWrite(LIGHT_2_RED, HIGH);

  digitalWrite(LIGHT_3_GREEN, LOW);
  digitalWrite(LIGHT_3_YELLOW, HIGH);
  digitalWrite(LIGHT_3_RED, LOW);

  digitalWrite(LIGHT_4_GREEN, LOW);
  digitalWrite(LIGHT_4_YELLOW, LOW);
  digitalWrite(LIGHT_4_RED, HIGH);
}

void Traffic_YELLOW_4(){
  digitalWrite(LIGHT_1_GREEN, LOW);
  digitalWrite(LIGHT_1_YELLOW, LOW);
  digitalWrite(LIGHT_1_RED, HIGH);   

  digitalWrite(LIGHT_2_GREEN, LOW);
  digitalWrite(LIGHT_2_YELLOW, LOW);
  digitalWrite(LIGHT_2_RED, HIGH);

  digitalWrite(LIGHT_3_GREEN, LOW);
  digitalWrite(LIGHT_3_YELLOW, LOW);
  digitalWrite(LIGHT_3_RED, HIGH);

  digitalWrite(LIGHT_4_GREEN, LOW);
  digitalWrite(LIGHT_4_YELLOW, HIGH);
  digitalWrite(LIGHT_4_RED, LOW);
}

