#define echoPin 10
#define trigPin 11

int IN1 = 3;  //IRA CONECTADO EL MOTOR A
int IN2 = 5;  //IRA CONECTADO EL MOTOR A
int IN3 = 6;  //IRA CONECTADO EL MOTOR B
int IN4 = 9;   //IRA CONECTADO EL MOTOR B

int pwma;
int cont;
void setup() {

  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);

  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);
  cont =0;
 pwma = 120; //Valor de voltaje inyectado para control de velocidad
  delay(2000);
}

void loop() {
  int distancia, duracion;

  digitalWrite(trigPin, HIGH);
  delay(200);
  digitalWrite(trigPin, LOW);

  duracion = pulseIn(echoPin, HIGH);
  distancia = (duracion / 2) / 29.1;

  if (distancia < 15) {
    if(cont==0){
    //Avanzamos hacia atras y despues giramos
    analogWrite(IN1, 0); analogWrite(IN2, pwma);
    analogWrite(IN3, 0); analogWrite(IN4, 0);
    delay(500);
    analogWrite(IN1, 0); analogWrite(IN2, pwma+30);
    analogWrite(IN3, 255); analogWrite(IN4, 0);
    delay(500);
    //Se encontro obstaculo
    cont=1;
    }
    else{
       analogWrite(IN1, 0); analogWrite(IN2, pwma);
    analogWrite(IN3, 0); analogWrite(IN4, 0);
    delay(500);
    analogWrite(IN1, 0); analogWrite(IN2, pwma+30);
    analogWrite(IN3, 0); analogWrite(IN4, 255);
    delay(500);
    //Se encontro obstaculo
    cont=0;
      }
  } else {
    //Avanzamos
    analogWrite(IN1, pwma); analogWrite(IN2, 0);
    analogWrite(IN3, 0); analogWrite(IN4, 0);

    
  }
}
