#define F_CPU 9600000UL
#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>

#define TRIG PB0
#define ECHO PB1
#define LED  PB2

volatile uint16_t ovf_count = 0;

/* Timer0 Overflow ISR */
ISR(TIM0_OVF_vect)
{
    ovf_count++;
}

/* IO Init */
void io_init(void)
{
    DDRB |= (1 << TRIG) | (1 << LED);   // Outputs
    DDRB &= ~(1 << ECHO);               // Input
}

/* Send ultrasonic trigger */
void send_trigger(void)
{
    PORTB |= (1 << TRIG);
    _delay_us(10);
    PORTB &= ~(1 << TRIG);
}

/* Measure echo pulse width (us) */
uint16_t get_echo_time(void)
{
    ovf_count = 0;
    TCNT0 = 0;

    // Wait for ECHO HIGH
    while (!(PINB & (1 << ECHO)));

    // Start Timer0 (prescaler 8 → ~0.83µs per tick)
    TCCR0B = (1 << CS01);
    TIMSK0 = (1 << TOIE0);
    sei();

    // Wait for ECHO LOW
    while (PINB & (1 << ECHO));

    // Stop timer
    cli();
    TCCR0B = 0;

    return (ovf_count * 256) + TCNT0;
}

int main(void)
{
    uint16_t time_us;
    uint16_t distance_cm;

    io_init();

    while (1)
    {
        send_trigger();
        time_us = get_echo_time();

        /* Integer distance calculation */
        distance_cm = (time_us * 48UL) / 5800UL;

        if (distance_cm > 30)
        {
            PORTB &= ~(1 << LED);
        }
        else if (distance_cm > 20)
        {
            PORTB |= (1 << LED);
        }
        else if (distance_cm > 10)
        {
            PORTB |= (1 << LED);
            _delay_ms(300);
            PORTB &= ~(1 << LED);
            _delay_ms(300);
        }
        else
        {
            PORTB |= (1 << LED);
            _delay_ms(100);
            PORTB &= ~(1 << LED);
            _delay_ms(100);
        }

        _delay_ms(200);
    }
}
