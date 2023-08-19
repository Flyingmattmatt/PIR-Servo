
#include "pico/stdlib.h"
#include "hardware/gpio.h"
#include "hardware/pwm.h"
#include "hardware/clocks.h"

const uint servoPin = 15;
const uint servoPinRed = 14;
const uint PIN_PIR = 13;

int main(void) {
    
    stdio_init_all();
    
    gpio_init(servoPinRed);
    gpio_set_dir(servoPinRed, GPIO_OUT);
    gpio_init(PIN_PIR);
    gpio_set_dir(PIN_PIR, GPIO_IN);
    gpio_pull_up(PIN_PIR);
    
    //sleep_ms(2000);
    gpio_set_function(servoPin, GPIO_FUNC_PWM);
    
    uint slice_num = pwm_gpio_to_slice_num(servoPin);
    uint channel = pwm_gpio_to_channel(servoPin);
    
    pwm_set_clkdiv(slice_num, 256.0f);
    pwm_set_wrap(slice_num, 9804);
    pwm_set_enabled(slice_num, true);
    
    while (1) {
        if (gpio_get(PIN_PIR)) {//movement
            gpio_put(servoPinRed, 0);
            //gpio_put(servoPin, 0);
            pwm_set_chan_level(slice_num, channel, 270);
            sleep_ms(900);
            pwm_set_chan_level(slice_num, channel, 332);
            sleep_ms(900);
            pwm_set_chan_level(slice_num, channel, 432);
            sleep_ms(900);
            pwm_set_chan_level(slice_num, channel, 532);
            sleep_ms(900);
            pwm_set_chan_level(slice_num, channel, 632);
            sleep_ms(900);
            pwm_set_chan_level(slice_num, channel, 732);
            sleep_ms(900);
            //pwm_set_chan_level(slice_num, channel, 832);
            //sleep_ms(900);
            //pwm_set_chan_level(slice_num, channel, 932);
            //sleep_ms(900);
           // pwm_set_chan_level(slice_num, channel, 1250);
            //sleep_ms(900);
            pwm_set_chan_level(slice_num, channel, 270);
            sleep_ms(900);
            
        } else {
            gpio_put(servoPin, 0);
            gpio_put(servoPinRed, 1);
            sleep_ms(900);
            
        }
        
    }
}
