void setup() {
  Serial.begin(9600);
  randomSeed(analogRead(A0));
  
  long clave = 1;
  int i=0;

  for (i; i<random(20,40);i++){
    clave *= 2; 
  }

  int vecesExtra = random(20,40);
  clave += vecesExtra;

  
  Serial.print("i = ");Serial.println(i);
  Serial.print("vecesExtra ");Serial.println(vecesExtra);
  Serial.print("clave ");Serial.println(clave);
  Serial.println("------------------");

}

void loop() {
  // put your main code here, to run repeatedly:

}
