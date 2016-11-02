# SLAM Arduino autonomous robot

[Wiring](http://l2jujq.axshare.com/#g=1&c=1&p=mvu_marius_s__master_degree_work_diagram) <br />
[Project management](https://tree.taiga.io/project/marius-s-arduino-and-esp8266-project/backlog)

SLAM Arduino autonomous robot<br />
Vytautas Magnus University master's degree research work. <br /><br />

Project owner: Marius Š. <br />
Project stakeholder: T. Krilavičius <br />

# Gloval variables
__work__ - Main robot function variable (2 - go, 4 - print calculated data to serial monitor) <br />
__motor_speed__ - Speed of the robot motors <br />
__x__ - Map X axis coordinate <br />
__y__ - Map Y axis coordinate <br />
__Array__ -  Array with all map coordinates <br />
__compas__ - Compass value (1 - North, 2 - East, 3 - West, 4 - South) <br />

# Functions
__lcd_setup()__ - Initialize LCD keypad shield <br />
__lcds()__ - Read LCD keypad shield buttons press and show menu information in LCD screen <br />
__go_straight()__ - Drive the robot straight <br />
__turn_left()__ - Turn the robot left <br />
__turn_right()__ - Turn the robot right <br />
__stop_motors()__ - Stop the robot <br />
__calculate()__ - Write the robot traveled distance into coordinates array <br />
__Array_to_serial()__ - Print coordinates array into serial monitor <br />
__ultrasonic()__ - Read distance between ultrasonic sensor and object <br />
__microsecondsToCentimeters()__ - Convert ultrasonic sensor data into centimeters <br />
__compass()__ - Calcualte current robot position by compass <br />

# Libraries
__WiFiManager__<br />
https://github.com/tzapu/WiFiManager
