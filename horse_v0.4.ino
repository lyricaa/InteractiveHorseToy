
int analogPin = A0;     //정도를 측정할 센서의 핀 번호 analog pin 0
                        // outside leads to ground and +5V
int motA = 2;          
int motB = 3;
int motC = 4;          
int motD = 5;
int ledA = 6;
int ledB = 7;

int val = 0;              // 진동 정도의 값
int time = 0;             // when it doesn't operate. 시간을 가게할 때 쓸 인티저
int count = 0;            // count val number over '100'




void setup() {
  
  pinMode(motA, OUTPUT);
  pinMode(motB, OUTPUT);
  pinMode(motC, OUTPUT);
  pinMode(motD, OUTPUT);
  pinMode(ledA, OUTPUT);
  pinMode(ledB, OUTPUT);
  Serial.begin(9600);               //  setup serial
}

void loop() {
 
  val = analogRead(analogPin);
  Serial.println(val);              //  debug value
  time ++;                          //시간을 가게한다
 
  
      if(time > 20)                 //진동이 시간 20동안만큼 없으면
      {
        Serial.println("reset");
        time = 0;                   //시간 초기화
        count = 0;                  //count 초기화
      }

      if (count == 0)               // time이 0이면 mot, led가 모두 멈추게 한다.
      {
        analogWrite(motA, 0);
        analogWrite(motB, 0);
        analogWrite(motC, 0);
        analogWrite(motD, 0);
        digitalWrite(ledA, LOW);    // 처음엔 LED 꺼짐
        digitalWrite(ledB, LOW);
      }
  
      //사운드 발생시
      if (val > 30)
      {
        Serial.println("val값이 40이상");
        count++;
        time = 0;
      }

      delay(100);

      //작동범위
      int moveRange1 = 3;
      int moveRange2 = 15;
      
      if ((count >= moveRange1) && (count < moveRange2))
      {
        Serial.println("모터작동");
        analogWrite(motA, 200);
        analogWrite(motB, 0);
        analogWrite(motC, 200);
        analogWrite(motD, 0);
        digitalWrite(ledA, LOW);
        digitalWrite(ledB, LOW);
      }
     else if (count >= moveRange2)
      {
        Serial.println("눈에 LED");
        analogWrite(motA, 200);
        analogWrite(motB, 0);
        analogWrite(motC, 200);
        analogWrite(motD, 0);
        digitalWrite(ledA, HIGH);
        digitalWrite(ledB, HIGH);
      }
}
