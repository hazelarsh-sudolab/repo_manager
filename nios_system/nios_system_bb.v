
module nios_system (
	clk_clk,
	reset_reset_n,
	gpio0_export,
	hex0_export,
	leds_export,
	switches_export);	

	input		clk_clk;
	input		reset_reset_n;
	output	[7:0]	gpio0_export;
	output	[7:0]	hex0_export;
	output	[7:0]	leds_export;
	input	[7:0]	switches_export;
endmodule
