#!/bin/sh

echo Uploading in 5 seconds, ready up!
sleep 5 && avrdude -p atmega32u4 -P /dev/tty.usbmodem14141 -c avr109 -U flash:w:atreus62_default.hex
