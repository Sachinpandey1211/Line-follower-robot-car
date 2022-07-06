// Done final code by "TEAM ROBOMAZE" using object oriented programming language for line follower car :

//This porsion from global veriables to creating class and defining public and constructor is done by:" JAGVEER SINGH BHAKAR(Captain)"  

class robot {

  private:
    int m1,m2,m3,m4,ir1,ir2;
  public:

  robot(int a,int b,int c,int d,int e,int f)
    :m1(a),m2(b),m3(c),m4(d),ir1(e),ir2(f){}

// This porsion creating void Begin and void sensors function is done by :"SACHIN PANDEY" 


    void sensors(int e,int f)
    {
      ir1 = digitalRead(e);
      ir2 = digitalRead(f);
    }
    
    void Begin() {
      Serial.begin(9600);
      // Defining pinmode of devices connected to arduino
      pinMode(m1, OUTPUT);
      pinMode(m2, OUTPUT);
      pinMode(m3, OUTPUT);
      pinMode(m4, OUTPUT);
      pinMode(ir1, INPUT);
      pinMode(ir2, INPUT);
      Serial.print("POSSITION OF SENSORS ");
      Serial.print("         |           ");

      Serial.print("STATUS OF CAR\n");

    }


// This porsion creating void Forward and rest both the  function is done by :"YOUGAL ATTRI"  
    void Forward() {

  //When both the sensors are on white surface:
      if (ir1 == 0 && ir2 == 0)
      {
        digitalWrite(m1, LOW);  //left backword motor is OFF
        digitalWrite(m2, HIGH); //left forword motor is ON
        digitalWrite(m3, HIGH);  //right backword motor is OFF
        digitalWrite(m4, LOW); //right forward  motor is ON
        Serial.print("Both on white               ");
        Serial.print("                   Forward\n");
        
      }
    }
    //When both the sensors are on black surface:
    void rest() {
      if (ir1 == 1 && ir2 == 1)
      {
        digitalWrite(m1, LOW); // left backword motor is OFF
        digitalWrite(m2, LOW); // left forword motor is OFF
        digitalWrite(m3, LOW); // right backword motor is OFF
        digitalWrite(m4, LOW); // right  forword motor is OFF
        Serial.print("Both on black              ");
        Serial.print("                    Stop\n");
        
      }
    }

  // This porsion creating void left and right both the functions are done by : "BHAJANPREET SINGH" 

  //When left sensor on black and right sensor white surface:
    void left() {


      if (ir1 == 1 && ir2 == 0)
      {
        digitalWrite(m1, LOW);  //left backword motor is ON
        digitalWrite(m2, HIGH);  //left forword motor is OFF
        digitalWrite(m3, LOW);  //right backword motor is OFF
        digitalWrite(m4, HIGH); //right forword motor is ON
        Serial.print("Left sensor on black surface             ");
        Serial.print("      Moving to left\n");
        
      }
    }
    //When right sensor on black and left sensor white surface:                    
    void right() {
      if (ir1 == 0 && ir2 == 1)
      {
        digitalWrite(m1, HIGH); //left backword motor is OFF
        digitalWrite(m2, LOW); //left forword motor is ON
        digitalWrite(m3, HIGH); //right backword motor is ON
        digitalWrite(m4,LOW);  //right forword motor is OFF
        Serial.print("Right sensor on black surface             ");
        Serial.print("     Moving to right\n");
        
      }

    }
};
//This porsion creating object for class and void setup and void loop is done by  : "SURBHITRAJ SINGH"
// creating object of class:

robot   red(2,3,4,5,9,10);

void setup() {
  red.Begin();

}
void loop() { 
  red.sensors(9,10);
  red.Forward();
  red.rest();
  red.left();
  red.right();}
