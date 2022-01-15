int duration;
int distance;


void setup()
{
	pinMode(10, OUTPUT);// piezo
	pinMode(9, OUTPUT);// vibrator
	pinMode(2, OUTPUT); // ultra-sonic sensor
	pinMode(3, INPUT);
	
	Serial.begin(9600);
}

void loop()
{
	digitalWrite(2, HIGH);
	delayMicroseconds(10);
	digitalWrite(2,LOW);
	
	duration= pulseIn(3, HIGH);
	distance = (duration/2)/29;
	
	Serial.print("Distance :");
	Serial.print(distance);
	Serial.print("cm");
	Serial.print(" ");
	
	if(distance>150){
		digitalWrite(10, LOW);
		digitalWrite(9, LOW);
		Serial.println("Safe");
	}
	else {
	}
	
	if(distance>=100 && distance<150){
		digitalWrite(10, HIGH);
		digitalWrite(9, HIGH);
		Serial.println("Mid range");
		delay(2000);
		digitalWrite(10, LOW);
		digitalWrite(9, LOW);
	}
	else {
	}
		if(distance<100){
		digitalWrite(10, HIGH);
		digitalWrite(9, HIGH);
		Serial.println("Unsafe");
		delay(50);
		digitalWrite(10, LOW);
		digitalWrite(9, LOW);
	}
	else {
	}
}
