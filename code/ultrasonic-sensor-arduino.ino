/*

📌 Pins Used

TRIG → D9
ECHO → D8
LED → D7

*/

#define TRIG 9
#define ECHO 8
#define LED  7

void setup()
{
    pinMode(TRIG, OUTPUT);
    pinMode(ECHO, INPUT);
    pinMode(LED, OUTPUT);
}

void loop()
{
    long duration;
    int distance;

    digitalWrite(TRIG, LOW);
    delayMicroseconds(2);
    digitalWrite(TRIG, HIGH);
    delayMicroseconds(10);
    digitalWrite(TRIG, LOW);

    duration = pulseIn(ECHO, HIGH);
    distance = duration / 58;

    if (distance > 30)
        digitalWrite(LED, LOW);
    else if (distance > 20)
        digitalWrite(LED, HIGH);
    else if (distance > 10)
    {
        digitalWrite(LED, HIGH);
        delay(300);
        digitalWrite(LED, LOW);
        delay(300);
    }
    else
    {
        digitalWrite(LED, HIGH);
        delay(100);
        digitalWrite(LED, LOW);
        delay(100);
    }

    delay(200);
}
