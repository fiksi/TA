#include "ta_uart.h"

/* USING ATMega128 UART-1 */

char var_str[CHAR_LONG];

static int uart_putchar(char ch,FILE*stream)
{
    if(ch=='\n'){uart_putchar('\r',stream);}
    while ((UCSR1A & (1 << UDRE1)) == 0) {};
    UDR1=ch;
    return 0;
}

static int uart_getchar(FILE*stream)
{
    (void) stream;
    char temp;

    while ((UCSR1A & (1 << RXC1)) == 0) {};
    temp=UDR1;
    return(temp);
}

static FILE uart_stdout=FDEV_SETUP_STREAM(uart_putchar,NULL,_FDEV_SETUP_WRITE);
static FILE uart_stdin=FDEV_SETUP_STREAM(NULL,uart_getchar,_FDEV_SETUP_READ);

void ta_uart_Init(void){
    UBRR1H=(((F_CPU / (BAUDRATE * 16UL))) - 1)>>8;
    UBRR1L=(((F_CPU / (BAUDRATE * 16UL))) - 1);

    UCSR1B |= 1<<RXEN1 | 1<<TXEN1 | 1<<RXCIE1;

    UCSR1C|=(1<<UCSZ11)|(1<<UCSZ10);

    stdin=&uart_stdin;
    stdout=&uart_stdout;
}

ISR(USART1_RX_vect){

    scanf("%s",var_str);
    if(strcmp(var_str,"test")==0){
        printf("serial OK \n\r");
    }
    else{
        printf("%s? \n\r",var_str);
    }

    return;
}
