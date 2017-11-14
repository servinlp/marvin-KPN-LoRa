int	set_port = 1;

// Some standard ports that depend on the layout of the Marvin
long defaultBaudRate = 57600;
int	reset_port = 5;
int	RN2483_power_port = 6;
int	led_port = 13;

//*** Set parameters here BEGIN ---->
String set_devaddr = "14203395";
String set_nwkskey = "91b0857a38ced10c8641571b6053684b";
String set_appskey = "7122f303e0bff2102570c811bd22e22e";
//*** <---- END Set parameters here

const int buttonPin = 4;
int buttonState = 0;
int wasPressed = 0;

// What you want tot send
int message = 1;

void setup() {

	Serial.begin( defaultBaudRate );
	Serial1.begin( defaultBaudRate );
	InitializeSerials( defaultBaudRate );
	initializeRN2483( RN2483_power_port, reset_port );
	pinMode( led_port, OUTPUT );
	pinMode( buttonPin, INPUT );
	blinky();

}

void loop() {

	buttonState = digitalRead( buttonPin );

	if ( buttonState == LOW && wasPressed == 0 ) { // If LOW it's pressed

		send_LoRa_data( set_port, String( message, HEX ) );
		blinky();
		delay( 1000 );
		read_data_from_LoRa_Mod();
		delay( 30000 );

		wasPressed = 1;

	} else {

		wasPressed = 0;

	}

	delay( 20 );

}

void InitializeSerials( int baudrate ) {

	delay( 1000 );
	print_to_console( "Serial ports initialised" );

}

void initializeRN2483( int pwr_port, int rst_port ) {

	//Enable power to the RN2483
	pinMode( pwr_port, OUTPUT );
	digitalWrite( pwr_port, HIGH );
	print_to_console( "RN2483 Powered up" );
	delay( 1000 );

	//Disable reset pin
	pinMode( rst_port, OUTPUT );
	digitalWrite( rst_port, HIGH );

	//Configure LoRa module
	send_LoRa_Command( "sys reset" );
	read_data_from_LoRa_Mod();

	send_LoRa_Command( "radio set crc off" );
	delay( 1000 );
	read_data_from_LoRa_Mod();

	send_LoRa_Command( "mac set nwkskey " + set_nwkskey );
	read_data_from_LoRa_Mod();

	send_LoRa_Command( "mac set appskey " + set_appskey );
	read_data_from_LoRa_Mod();

	send_LoRa_Command( "mac set devaddr " + set_devaddr );
	read_data_from_LoRa_Mod();

	//For this commands some extra delay is needed.
	send_LoRa_Command( "mac set adr on" );
	delay( 1000 );
	read_data_from_LoRa_Mod();

	send_LoRa_Command( "mac save" );
	delay( 1000 );
	read_data_from_LoRa_Mod();

	send_LoRa_Command( "mac join abp" );
	delay( 1000 );
	read_data_from_LoRa_Mod();

}

void print_to_console( String message ) {

	Serial.println( message );

}

void read_data_from_LoRa_Mod() {

	if ( Serial1.available() ) {

		String inByte = Serial1.readString();
		Serial.println( inByte );

	}

}

void send_LoRa_Command( String cmd ) {

	print_to_console( "Now sending: " + cmd );
	Serial1.println( cmd );
	delay( 500 );

}

void send_LoRa_data( int tx_port, String rawdata ) {

	send_LoRa_Command( "mac tx uncnf " + String( tx_port ) + String(" ") + rawdata );

}


void blinky() {

	digitalWrite( led_port, HIGH );
	delay( 500 );
	digitalWrite( led_port, LOW );
	delay( 500 );
	digitalWrite( led_port, HIGH );
	delay( 500 );
	digitalWrite( led_port, LOW );
	delay( 500 );

}
