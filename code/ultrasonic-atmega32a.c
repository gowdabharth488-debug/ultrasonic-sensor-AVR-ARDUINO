/*
📌 Pins Used

TRIG → PC0
ECHO → PC1
LED → PC2
*/

#define F_CPU 8000000UL
#include <avr/io.h>
#include <util/delay.h>

#define TRIG PC0
#define ECHO PC1
#define LED  PC2

void io_init(void)
{
    DDRC |= (1 << TRIG) | (1 << LED);
    DDRC &= ~(1 << ECHO);
}

void send_trigger(void)
{
    PORTC |= (1 << TRIG);
    _delay_us(10);
    PORTC &= ~(1 << TRIG);
}

uint16_t get_echo_time(void)
{
    // Wait for ECHO HIGH
    while (!(PINC & (1 << ECHO)));

    TCNT1 = 0;
    TCCR1B = (1 << CS11);   // Prescaler 8 → 1µs/tick @ 8MHz

    // Wait for ECHO LOW
    while (PINC & (1 << ECHO));

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

        // Integer distance calculation
        distance_cm = time_us / 58;

        if (distance_cm > 30)
            PORTC &= ~(1 << LED);
        else if (distance_cm > 20)
            PORTC |= (1 << LED);
        else if (distance_cm > 10)
        {
            PORTC |= (1 << LED);
            _delay_ms(300);
            PORTC &= ~(1 << LED);
            _delay_ms(300);
        }
        else
        {
            PORTC |= (1 << LED);
            _delay_ms(100);
            PORTC &= ~(1 << LED);
            _delay_ms(100);
        }

        _delay_ms(200);
    }
}
