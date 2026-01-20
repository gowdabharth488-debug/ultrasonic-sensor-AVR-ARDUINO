/*
📌 Pins Used

TRIG → PA0
ECHO → PA1
LED → PA2

*/

#define F_CPU 8000000UL
#include <avr/io.h>
#include <util/delay.h>

#define TRIG PA0
#define ECHO PA1
#define LED  PA2

void io_init(void)
{
    DDRA |= (1 << TRIG) | (1 << LED);
    DDRA &= ~(1 << ECHO);
}

void send_trigger(void)
{
    PORTA |= (1 << TRIG);
    _delay_us(10);
    PORTA &= ~(1 << TRIG);
}

uint16_t get_echo_time(void)
{
    while (!(PINA & (1 << ECHO)));

    TCNT1 = 0;
    TCCR1B = (1 << CS11);

    while (PINA & (1 << ECHO));

    TCCR1B = 0;
    return TCNT1;
}

int main(void)
{
    uint16_t time_us, distance_cm;
    io_init();

    while (1)
    {
        send_trigger();
        time_us = get_echo_time();
        distance_cm = time_us / 58;

        if (distance_cm > 30)
            PORTA &= ~(1 << LED);
        else if (distance_cm > 20)
            PORTA |= (1 << LED);
        else if (distance_cm > 10)
        {
            PORTA |= (1 << LED);
            _delay_ms(300);
            PORTA &= ~(1 << LED);
            _delay_ms(300);
        }
        else
        {
            PORTA |= (1 << LED);
            _delay_ms(100);
            PORTA &= ~(1 << LED);
            _delay_ms(100);
        }

        _delay_ms(200);
    }
}
