#include <mbed.h>
#include <rtos.h>
#include <mbed_events.h>

Serial pc(USBTX, USBRX);
Thread worker;
EventQueue queue ;

DigitalOut red(LED_RED,1); /* initial state 1 led is off */
DigitalOut green(LED_GREEN,0);
DigitalOut blue(LED_BLUE,1);
void flash_red(void) {
    while(1){
        red.write(1);
        wait(0.6);
        red.write(0);
        wait(0.3);
    }
}
void flash_green(void){
  while(1){
    green.write(0);
    wait(0.3);
    green.write(1);
    wait(0.6);
  }
}
void flash_blue(void){
  while(1){
    wait(0.3);
    blue.write(1);
    wait(0.3);
    blue.write(0);
    wait(0.3);
    blue.write(1);
  }
}


int main() {

    // put your setup code here, to run once:
    worker.start( flash_red );
    worker.start( flash_green );
    worker.start( flash_blue );
    while(1) {
        // put your main code here, to run repeatedly:



    }
}
