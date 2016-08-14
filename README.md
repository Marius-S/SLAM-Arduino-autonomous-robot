# SLAM Arduino autonomous robot

[Wiring](http://l2jujq.axshare.com/#g=1&c=1&p=mvu_marius_s__master_degree_work_diagram) <br />
[Project management](https://tree.taiga.io/project/marius-s-arduino-and-esp8266-project/backlog)

SLAM Arduino autonomous robot<br />
Vytautas Magnus University master's degree research work. <br /><br />

Project owner: Marius Š. <br />
Project stakeholder: T. Krilavičius <br />

# Gloval variables
work - Main robot function variable (2 - go, 4 - print calculated data to serial monitor) <br />
motor_speed - Speed of the robot motors <br />
x - Map X axis coordinate <br />
y - Map Y axis coordinate <br />
Array -  Array with all map coordinates <br />
compas - Compass value (1 - North, 2 - East, 3 - West, 4 - South) <br />

# Functions
lcd_setup() - Initialize LCD keypad shield <br />
lcds() - Read LCD keypad shield buttons press and show menu information in LCD screen <br />
go_straight() - Drive the robot straight <br />
turn_left() - Turn the robot left <br />
turn_right() - Turn the robot right <br />
stop_motors() - Stop the robot <br />
calculate() - Write the robot traveled distance into coordinates array <br />
Array_to_serial() - Print coordinates array into serial monitor <br />
ultrasonic() - Read distance between ultrasonic sensor and object <br />
microsecondsToCentimeters() - Convert ultrasonic sensor data into centimeters <br />
compass() - Calcualte current robot position by compass <br />

# Libraries
__WiFiManager__<br />
https://github.com/tzapu/WiFiManager
