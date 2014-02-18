// motor A
int dir1PinA = 12;
int dir2PinA = 13;
int speedPinA = 10;
// motor B
int dir1PinB = 2;
int dir2PinB = 6;
int speedPinB = 3;
unsigned long time;
boolean forward = true;
int speed;
int lspeed;
int rspeed;
int interval = 5000;
int flip;
int maxforwardinterval = 7000;
int maxspininterval = 5000;
int trig = 4 ;
int echo = 7;

void setup() {
    Serial.begin (9600);
    pinMode(dir1PinA, OUTPUT);
    pinMode(dir2PinA, OUTPUT);
    pinMode(speedPinA, OUTPUT);
    pinMode(dir1PinB, OUTPUT);
    pinMode(dir2PinB, OUTPUT);
    pinMode(speedPinB, OUTPUT);
    pinMode(trig, OUTPUT);
    pinMode(echo, INPUT);
    time = millis();
    speed = 255;
    analogWrite(speedPinA, speed);
    analogWrite(speedPinB, speed);
    //Serial.begin(9600); // set up Serial library at 9600 bps
    moveForward();
}

void spin(){
    Serial.println("SPIN");
    digitalWrite(dir1PinA, HIGH); //for
    digitalWrite(dir1PinB, HIGH); //bac
    digitalWrite(dir2PinA, LOW); //bac
    digitalWrite(dir2PinB, LOW); //for
}

void moveForward(){
    digitalWrite(dir1PinA, HIGH); //for
    digitalWrite(dir1PinB, LOW); //bac
    digitalWrite(dir2PinA, LOW); //bac
    digitalWrite(dir2PinB, HIGH); //for
}

void moveBackward(){
}

void turnLeft(){
    lspeed = 0;
}

void turnRight(){
    rspeed = 0;
}

int getEchoDistance(){
    int duration, distance;
    digitalWrite(trig, HIGH);
    delayMicroseconds(1000);
    digitalWrite(trig, LOW);
    duration = pulseIn(echo, HIGH);
    Serial.println(duration);
    return duration;
}

boolean isTooClose(){
    int distance = getEchoDistance();
    if (distance < 1000)
        return true;
    return false;
}

void loop() {
    if(!isTooClose()){
        moveForward();
    }else{
        spin();
    }
}