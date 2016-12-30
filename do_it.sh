#!/bin/sh

sudo dfu-programmer atmega32u4 erase --force && sudo dfu-programmer atmega32u4 flash satan_default.hex && sudo dfu-programmer atmega32u4 reset
