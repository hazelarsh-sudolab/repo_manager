    module openlab (CLOCK_50,SW,KEY,LEDR,HEX0,GPIO_0);
	 
	 input CLOCK_50;
	 input [7:0] SW;
	 input [0:0] KEY;
	 output[7:0] LEDR;
	 output[6:0] HEX0;
	 output[7:0] GPIO_0;
	 
	 nios_system u0 (
        .clk_clk         (CLOCK_50),         //      clk.clk
        .reset_reset_n   (KEY),   //    reset.reset_n
        .gpio0_export    (GPIO_0),    //    gpio0.export
        .hex0_export     (HEX0),     //     hex0.export
        .leds_export     (LEDR),     //     leds.export
        .switches_export (SW)  // switches.export
    );
endmodule