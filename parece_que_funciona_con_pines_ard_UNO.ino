// --- PINES ---
#define X_STEP_PIN 2 
#define X_DIR_PIN  5
#define Y_STEP_PIN 3 
#define Y_DIR_PIN  6
#define Z_STEP_PIN 4 
#define Z_DIR_PIN  7
#define A_STEP_PIN 12
#define A_DIR_PIN  13
#define EN_PIN     8 

// --- CONFIGURACIÓN ---
// DRV8825 con 1/16 microstep (MS1=LOW, MS2=LOW, MS3=HIGH)
// Vref = I_motor / 2 → para 0.5A: Vref = 0.25V
const int pasosPorVuelta = 3200;  // 200 pasos * 16 microsteps
const int velocidad      = 100;   // µs entre pasos — baja para más velocidad, sube para más torque

void setup() {
  pinMode(X_STEP_PIN, OUTPUT); pinMode(X_DIR_PIN, OUTPUT);
  pinMode(Y_STEP_PIN, OUTPUT); pinMode(Y_DIR_PIN, OUTPUT);
  pinMode(Z_STEP_PIN, OUTPUT); pinMode(Z_DIR_PIN, OUTPUT);
  pinMode(A_STEP_PIN, OUTPUT); pinMode(A_DIR_PIN, OUTPUT);
  pinMode(EN_PIN, OUTPUT);

  digitalWrite(EN_PIN, LOW); // motores habilitados desde el inicio

  // Fijar dirección una sola vez
  digitalWrite(X_DIR_PIN, HIGH);
  digitalWrite(Y_DIR_PIN, HIGH);
  digitalWrite(Z_DIR_PIN, HIGH);
  digitalWrite(A_DIR_PIN, HIGH);
}

void loop() {
  // Un paso, velocidad constante, sin rampas
  digitalWrite(X_STEP_PIN, HIGH);
  digitalWrite(Y_STEP_PIN, HIGH);
  digitalWrite(Z_STEP_PIN, HIGH);
  digitalWrite(A_STEP_PIN, HIGH);
  delayMicroseconds(5);
  digitalWrite(X_STEP_PIN, LOW);
  digitalWrite(Y_STEP_PIN, LOW);
  digitalWrite(Z_STEP_PIN, LOW);
  digitalWrite(A_STEP_PIN, LOW);
  delayMicroseconds(velocidad);
}