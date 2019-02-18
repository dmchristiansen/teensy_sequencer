EESchema Schematic File Version 4
EELAYER 26 0
EELAYER END
$Descr A4 11693 8268
encoding utf-8
Sheet 1 3
Title ""
Date ""
Rev ""
Comp ""
Comment1 ""
Comment2 ""
Comment3 ""
Comment4 ""
$EndDescr
$Comp
L teensy:Teensy-LC U1
U 1 1 5C65E53A
P 4200 2450
F 0 "U1" H 4225 3687 60  0000 C CNN
F 1 "Teensy-LC" H 4225 3581 60  0000 C CNN
F 2 "" H 4200 1900 60  0000 C CNN
F 3 "" H 4200 1900 60  0000 C CNN
	1    4200 2450
	1    0    0    -1  
$EndComp
$Sheet
S 1300 1100 550  450 
U 5C65E8D1
F0 "power" 59
F1 "power.sch" 59
$EndSheet
$Sheet
S 7000 1950 800  700 
U 5C6618A1
F0 "input" 50
F1 "input.sch" 50
$EndSheet
$Comp
L power:+3.3V #PWR0101
U 1 1 5C661C1B
P 2900 2950
F 0 "#PWR0101" H 2900 2800 50  0001 C CNN
F 1 "+3.3V" H 2915 3123 50  0000 C CNN
F 2 "" H 2900 2950 50  0001 C CNN
F 3 "" H 2900 2950 50  0001 C CNN
	1    2900 2950
	1    0    0    -1  
$EndComp
Wire Wire Line
	2900 2950 2900 3000
Wire Wire Line
	2900 3000 3150 3000
$EndSCHEMATC
