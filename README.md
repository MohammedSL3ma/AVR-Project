# AVR-Project

<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Project README</title>
</head>
<body>

<h1>Sending Data to Control Machines with an Encryption System</h1>

<p>
    At Information Technology Institute (ITI) I managed to create the following project:
</p>

<h2>Project Description</h2>
<p>
    This project involves three ATMEGA32 microcontrollers where the first sends encrypted data to the other two. The second ATMEGA32 decrypts the data and performs the correct command, while the third does not decrypt and thus understands the wrong data. The system includes functionalities such as rotating a motor at different speeds and controlling an LED with a delay.
</p>

<h2>Technologies Used</h2>
<ul>
    <li>C programming language</li>
    <li>3 AVR microcontrollers (ATMEGA 32)</li>
    <li>UART Communication Protocol</li>
    <li>Keypad & LCD</li>
    <li>PWM</li>
    <li>Timer0</li>
    <li>Timer2</li>
</ul>

<h2>Functionality</h2>
<p>
    - When the first button on the keypad is pressed, the motor rotates at the first level. There are three levels of speed.<br>
    - Another button makes the LED stay on for ten seconds without stopping the delay moving the program.
</p>

</body>
</html>
