void setup() {
  Serial.begin(9600);
  long a = 419044;
  long b = 2369100;
  long p = 459829453;

  randomSeed(analogRead(A0));
  long x = random(0,459);

  long y = sqrt(pow(x,3)+a*x+b);

  while(y>=p){
    y-=p;
  }

  Serial.print("X = ");Serial.println(x);
  Serial.print("Y = ");Serial.println(y);
  Serial.println("------------------------");
}

void loop() {
  // put your main code here, to run repeatedly:

}
