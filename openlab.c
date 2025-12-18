#define leds (char*) 0x00002020 
#define hex0 (char*) 0x00002010 
#define gpio_0 (char*) 0x00002000 
#define switches (volatile char*) 0x00002030 

volatile int delay_count; 
int SW_value; 

int main(void) 
{ 
    while(1) 
    { 
        SW_value = *switches; 
        
        // Check for pedestrian crossing request (switch 2 = 0x00000002)
        if (SW_value & 0x00000002) 
        { 
            // Immediate pedestrian crossing mode
            // Vehicle red, pedestrian green immediately
            *gpio_0 = 0x02; // vehicle red, pedestrian green 
            
            // Show countdown on 7-segment: 9 to 0
            *hex0 = 0x0000006F; // 9
            for (delay_count = 1000000; delay_count != 0; --delay_count);
            
            *hex0 = 0x0000007F; // 8
            for (delay_count = 1000000; delay_count != 0; --delay_count);
            
            *hex0 = 0x00000007; // 7
            for (delay_count = 1000000; delay_count != 0; --delay_count);
            
            *hex0 = 0x0000007D; // 6
            for (delay_count = 1000000; delay_count != 0; --delay_count);
            
            *hex0 = 0x0000006D; // 5
            for (delay_count = 1000000; delay_count != 0; --delay_count);
            
            *hex0 = 0x00000066; // 4
            for (delay_count = 1000000; delay_count != 0; --delay_count);
            
            *hex0 = 0x0000004F; // 3
            for (delay_count = 1000000; delay_count != 0; --delay_count);
            
            *hex0 = 0x0000005B; // 2
            for (delay_count = 1000000; delay_count != 0; --delay_count);
            
            *hex0 = 0x00000006; // 1
            for (delay_count = 1000000; delay_count != 0; --delay_count);
            
            *hex0 = 0x0000003F; // 0
            for (delay_count = 1000000; delay_count != 0; --delay_count);
            
            // Blink pedestrian green before switching back
            for (int i = 0; i < 5; i++) {
                *gpio_0 = 0x02; // Green on
                for (delay_count = 200000; delay_count != 0; --delay_count);
                *gpio_0 = 0x00; // All off
                for (delay_count = 200000; delay_count != 0; --delay_count);
            }
            
            // Return to normal operation
            continue; // Skip the rest of the loop and start over
        }
        
        // Normal traffic light operation (when switch 1 is on)
        if (SW_value == 0x00000001) 
        { 
            *gpio_0 = 0x01; // vehicle green, pedestrian red 
            for (delay_count = 1000000; delay_count != 0; --delay_count); 
            *hex0 = 0x00000010; 
            for (delay_count = 1000000; delay_count != 0; --delay_count); 
            *hex0 = 0x00000000; 
            for (delay_count = 1000000; delay_count != 0; --delay_count); 
            *hex0 = 0x00000078; 
            for (delay_count = 1000000; delay_count != 0; --delay_count); 
            *hex0 = 0x00000002; 
            for (delay_count = 1000000; delay_count != 0; --delay_count); 
            *hex0 = 0x00000012; 
            for (delay_count = 1000000; delay_count != 0; --delay_count); 
            *hex0 = 0x00000019; 
            for (delay_count = 1000000; delay_count != 0; --delay_count); 
            *hex0 = 0x00000030; 
            for (delay_count = 1000000; delay_count != 0; --delay_count); 
            *hex0 = 0x00000024; 
            for (delay_count = 1000000; delay_count != 0; --delay_count); 
            *hex0 = 0x00000079; 
            for (delay_count = 1000000; delay_count != 0; --delay_count); 
            *hex0 = 0x000000FF; 
            *gpio_0 = 0x04; // vehicle yellow 
            for (delay_count = 1000000; delay_count != 0; --delay_count); 
            *hex0 = 0x000000FF; 
            for (delay_count = 1000000; delay_count != 0; --delay_count); 
            *hex0 = 0x000000FF; 
            for (delay_count = 1000000; delay_count != 0; --delay_count); 
            *hex0 = 0x000000FF; 
            *gpio_0 = 0x02; // vehicle red, pedestrian green 
            for (delay_count = 1000000; delay_count != 0; --delay_count); 
            *hex0 = 0x00000010; 
            for (delay_count = 1000000; delay_count != 0; --delay_count); 
            *hex0 = 0x00000000; 
            for (delay_count = 1000000; delay_count != 0; --delay_count); 
            *hex0 = 0x00000078; 
            for (delay_count = 1000000; delay_count != 0; --delay_count); 
            *hex0 = 0x00000002; 
            for (delay_count = 1000000; delay_count != 0; --delay_count); 
            *hex0 = 0x00000012; 
            for (delay_count = 1000000; delay_count != 0; --delay_count); 
            *hex0 = 0x00000019; 
            for (delay_count = 1000000; delay_count != 0; --delay_count); 
            *hex0 = 0x00000030; 
            for (delay_count = 1000000; delay_count != 0; --delay_count); 
            *hex0 = 0x00000024; 
            for (delay_count = 1000000; delay_count != 0; --delay_count); 
            *hex0 = 0x00000079; 
            for (delay_count = 1000000; delay_count != 0; --delay_count); 
            *hex0 = 0x000000FF; 
        } 
        else 
        { 
            *hex0 = 0x0000007F; 
            *gpio_0 = 0x01; 
            for (delay_count = 500000; delay_count != 0; --delay_count); 
        } 
    }
    
    return 0;
}