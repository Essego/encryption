void setup() {
  Serial.begin(9600);

  long a;
  long b;
  long e;

  randomSeed(analogRead(A0));
  a = random(50000,4000000);

  do{
    b = random(50000,4000000);
  }while( ((4*a*a*a)+(27*b*b)) == 0 );

  e = GenerarPrimo();

  Serial.print("a = ");Serial.println(a);
  Serial.print("b = ");Serial.println(b);
  Serial.print("e = ");Serial.println(e);

  Serial.println("-------------------------");

}

void loop() {
  // put your main code here, to run repeatedly:

}


bool EsPrimo(unsigned long numero) {
    // Los números menores o iguales a 1 no son primos
    if (numero <= 1) {
        return false;
    }
    // 2 y 3 son primos
    if (numero <= 3) {
        return true;
    }
    // Eliminar los múltiplos de 2 y 3
    if (numero % 2 == 0 || numero % 3 == 0) {
        return false;
    }
    // Solo comprobar hasta la raíz cuadrada del número
    for (unsigned long i = 5; i * i <= numero; i += 6) {
        if (numero % i == 0 || numero % (i + 2) == 0) {
            return false;
        }
    }
    return true;
}


long NumeroRandom(){
  randomSeed(analogRead((A0)+analogRead(A1)+analogRead(A2))*4); //Semilla aleatoria basade en medida de señales analógicas
  long r = random(327675,2147483647);
  int r2 = r % 32767;//Escalado a la longitud de un int
  randomSeed(r2);
  unsigned long random2 = random(1000,2147483647) + random(100,2147483647);
  return random2;
}

long GenerarPrimo(){
  unsigned long numRandom;
  do{
    numRandom = NumeroRandom();
  }while(!EsPrimo(numRandom));
  return numRandom;
}
