#!/bin/sh

echo Uploading in 5 seconds, ready up!

sleep 5

# Get name of object
MODEM=$(ls /dev | grep 'tty\.usbmodem')
if [ -z "$MODEM" ]; then
  echo Could not find device, aborting.
  exit 1
fi

avrdude -p atmega32u4 -P /dev/$MODEM -c avr109 -U flash:w:atreus62_default.hex
