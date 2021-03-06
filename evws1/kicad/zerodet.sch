EESchema Schematic File Version 4
LIBS:evws1-cache
EELAYER 26 0
EELAYER END
$Descr A4 11693 8268
encoding utf-8
Sheet 7 6
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
L Device:R R?
U 1 1 5E2B6F70
P 4350 2000
AR Path="/5E0A3961/5F6ED0C4/5E2B6F70" Ref="R?"  Part="1" 
AR Path="/5E2B680B/5E2B6F70" Ref="R50"  Part="1" 
F 0 "R50" H 4475 2025 50  0000 C CNN
F 1 "820K" H 4525 1925 50  0000 C CNN
F 2 "Project:r-1206-hand-soldering" V 4280 2000 50  0001 C CNN
F 3 "" H 4350 2000 50  0001 C CNN
	1    4350 2000
	1    0    0    -1  
$EndComp
$Comp
L Device:D_Small D?
U 1 1 5E2B6F78
P 4350 2700
AR Path="/5E0A3961/5F6ED0C4/5E2B6F78" Ref="D?"  Part="1" 
AR Path="/5E2B680B/5E2B6F78" Ref="D9"  Part="1" 
F 0 "D9" V 4275 2475 50  0000 L CNN
F 1 "1N4007" V 4375 2350 50  0000 L CNN
F 2 "Project:sma_hand-soldering" V 4350 2700 50  0001 C CNN
F 3 "~" V 4350 2700 50  0001 C CNN
F 4 "1000V/1A/SMA" V 4475 2050 50  0000 L CNN "type"
	1    4350 2700
	0    1    1    0   
$EndComp
Wire Wire Line
	4350 2600 4350 2550
Wire Wire Line
	4350 2550 4550 2550
Wire Wire Line
	4550 2550 4550 2600
Wire Wire Line
	4550 2600 4650 2600
Connection ~ 4350 2550
Wire Wire Line
	4350 2550 4350 2450
Wire Wire Line
	4350 2800 4350 2900
Wire Wire Line
	4350 3050 3950 3050
Wire Wire Line
	4350 1850 4350 1750
Wire Wire Line
	4350 1750 3950 1750
Text Label 4050 1750 0    50   ~ 0
L
Text Label 4075 3050 0    50   ~ 0
N
$Comp
L Device:C_Small C?
U 1 1 5E2B6F8C
P 4350 2350
AR Path="/5E0A3961/5F6ED0C4/5E2B6F8C" Ref="C?"  Part="1" 
AR Path="/5E2B680B/5E2B6F8C" Ref="C25"  Part="1" 
F 0 "C25" H 4442 2441 50  0000 L CNN
F 1 "2.2n" H 4442 2350 50  0000 L CNN
F 2 "Capacitors_THT:C_Disc_D3.8mm_W2.6mm_P2.50mm" H 4350 2350 50  0001 C CNN
F 3 "~" H 4350 2350 50  0001 C CNN
F 4 "1000V" H 4442 2259 50  0000 L CNN "type"
	1    4350 2350
	1    0    0    -1  
$EndComp
Wire Wire Line
	4650 2800 4550 2800
Wire Wire Line
	4550 2800 4550 2900
Wire Wire Line
	4550 2900 4350 2900
Connection ~ 4350 2900
Wire Wire Line
	4350 2900 4350 3050
$Comp
L Device:C_Small C?
U 1 1 5E2B6F98
P 5900 1850
AR Path="/5E0A3961/5F6ED0C4/5E2B6F98" Ref="C?"  Part="1" 
AR Path="/5E2B680B/5E2B6F98" Ref="C27"  Part="1" 
F 0 "C27" H 5992 1896 50  0000 L CNN
F 1 "1u" H 5992 1805 50  0000 L CNN
F 2 "Project:c-1206-hand-soldering" H 5900 1850 50  0001 C CNN
F 3 "~" H 5900 1850 50  0001 C CNN
	1    5900 1850
	1    0    0    -1  
$EndComp
$Comp
L Device:R R?
U 1 1 5E2B6F9F
P 5650 2100
AR Path="/5E0A3961/5F6ED0C4/5E2B6F9F" Ref="R?"  Part="1" 
AR Path="/5E2B680B/5E2B6F9F" Ref="R60"  Part="1" 
F 0 "R60" H 5525 2150 50  0000 C CNN
F 1 "39K" H 5500 2050 50  0000 C CNN
F 2 "Project:r-0805-hand-soldering" V 5580 2100 50  0001 C CNN
F 3 "" H 5650 2100 50  0001 C CNN
	1    5650 2100
	1    0    0    -1  
$EndComp
$Comp
L power:+3V3 #PWR?
U 1 1 5E2B6FA6
P 5200 1600
AR Path="/5E2B6FA6" Ref="#PWR?"  Part="1" 
AR Path="/5E13857A/5E2B6FA6" Ref="#PWR?"  Part="1" 
AR Path="/5E0A3961/5F6ED0C4/5E2B6FA6" Ref="#PWR?"  Part="1" 
AR Path="/5E2B680B/5E2B6FA6" Ref="#PWR0194"  Part="1" 
F 0 "#PWR0194" H 5200 1450 50  0001 C CNN
F 1 "+3V3" H 5215 1773 50  0000 C CNN
F 2 "" H 5200 1600 50  0001 C CNN
F 3 "" H 5200 1600 50  0001 C CNN
	1    5200 1600
	1    0    0    -1  
$EndComp
$Comp
L Device:C_Small C?
U 1 1 5E2B6FAC
P 5650 2700
AR Path="/5E0A3961/5F6ED0C4/5E2B6FAC" Ref="C?"  Part="1" 
AR Path="/5E2B680B/5E2B6FAC" Ref="C26"  Part="1" 
F 0 "C26" H 5742 2746 50  0000 L CNN
F 1 "220n" H 5742 2655 50  0000 L CNN
F 2 "Project:c-1206-hand-soldering" H 5650 2700 50  0001 C CNN
F 3 "~" H 5650 2700 50  0001 C CNN
	1    5650 2700
	1    0    0    -1  
$EndComp
$Comp
L Device:C_Small C?
U 1 1 5E2B6FB3
P 6150 2450
AR Path="/5E0A3961/5F6ED0C4/5E2B6FB3" Ref="C?"  Part="1" 
AR Path="/5E2B680B/5E2B6FB3" Ref="C28"  Part="1" 
F 0 "C28" V 6075 2325 50  0000 C CNN
F 1 "1n" V 6075 2550 50  0000 C CNN
F 2 "Project:c-1206-hand-soldering" H 6150 2450 50  0001 C CNN
F 3 "~" H 6150 2450 50  0001 C CNN
	1    6150 2450
	0    1    1    0   
$EndComp
$Comp
L power:GND #PWR?
U 1 1 5E2B6FBA
P 5650 2900
AR Path="/5E0A3961/5F6ED0C4/5E2B6FBA" Ref="#PWR?"  Part="1" 
AR Path="/5E2B680B/5E2B6FBA" Ref="#PWR0195"  Part="1" 
F 0 "#PWR0195" H 5650 2650 50  0001 C CNN
F 1 "GND" H 5650 2750 50  0000 C CNN
F 2 "" H 5650 2900 50  0001 C CNN
F 3 "" H 5650 2900 50  0001 C CNN
	1    5650 2900
	1    0    0    -1  
$EndComp
$Comp
L Device:R R?
U 1 1 5E2B6FC0
P 5450 1700
AR Path="/5E0A3961/5F6ED0C4/5E2B6FC0" Ref="R?"  Part="1" 
AR Path="/5E2B680B/5E2B6FC0" Ref="R58"  Part="1" 
F 0 "R58" V 5530 1700 50  0000 C CNN
F 1 "100R" V 5350 1700 50  0000 C CNN
F 2 "Project:r-0805-hand-soldering" V 5380 1700 50  0001 C CNN
F 3 "" H 5450 1700 50  0001 C CNN
	1    5450 1700
	0    -1   -1   0   
$EndComp
Wire Wire Line
	5200 1600 5200 1700
Wire Wire Line
	5200 1700 5300 1700
Wire Wire Line
	5600 1700 5650 1700
Wire Wire Line
	5650 1700 5650 1950
Wire Wire Line
	5650 1700 5900 1700
Wire Wire Line
	5900 1700 5900 1750
Connection ~ 5650 1700
$Comp
L power:GND #PWR?
U 1 1 5E2B6FCE
P 5900 2050
AR Path="/5E0A3961/5F6ED0C4/5E2B6FCE" Ref="#PWR?"  Part="1" 
AR Path="/5E2B680B/5E2B6FCE" Ref="#PWR0196"  Part="1" 
F 0 "#PWR0196" H 5900 1800 50  0001 C CNN
F 1 "GND" H 5900 1900 50  0000 C CNN
F 2 "" H 5900 2050 50  0001 C CNN
F 3 "" H 5900 2050 50  0001 C CNN
	1    5900 2050
	1    0    0    -1  
$EndComp
Wire Wire Line
	5900 2050 5900 1950
Wire Wire Line
	5250 2600 5350 2600
Wire Wire Line
	5350 2600 5350 2550
Wire Wire Line
	5350 2550 5650 2550
Wire Wire Line
	5650 2550 5650 2450
Wire Wire Line
	5650 2550 5650 2600
Connection ~ 5650 2550
Wire Wire Line
	5250 2800 5350 2800
Wire Wire Line
	5350 2800 5350 2850
Wire Wire Line
	5350 2850 5650 2850
Wire Wire Line
	5650 2850 5650 2800
Wire Wire Line
	5650 2850 5650 2900
Connection ~ 5650 2850
Wire Wire Line
	5650 2450 6050 2450
Connection ~ 5650 2450
Wire Wire Line
	5650 2450 5650 2250
Text HLabel 6775 2450 2    50   Output ~ 0
ZERODET
$Comp
L _project:PC817C U?
U 1 1 5E2B6FE5
P 4950 2700
AR Path="/5E0A3961/5F6ED0C4/5E2B6FE5" Ref="U?"  Part="1" 
AR Path="/5E2B680B/5E2B6FE5" Ref="U12"  Part="1" 
F 0 "U12" H 4775 2900 50  0000 C CNN
F 1 "PC817C" H 5075 2900 50  0000 C CNN
F 2 "Project:sop-4-pc817" H 4750 2500 50  0001 L CIN
F 3 "" H 4950 2700 50  0001 L CNN
	1    4950 2700
	1    0    0    -1  
$EndComp
Wire Wire Line
	4350 2250 4350 2150
$Comp
L Device:Jumper_NO_Small JP?
U 1 1 5E2B6FED
P 6450 2450
AR Path="/5E2B6FED" Ref="JP?"  Part="1" 
AR Path="/5E13857A/5E2B6FED" Ref="JP?"  Part="1" 
AR Path="/5E0A3961/5F6ED0C4/5E2B6FED" Ref="JP?"  Part="1" 
AR Path="/5E2B680B/5E2B6FED" Ref="JP4"  Part="1" 
F 0 "JP4" H 6400 2525 50  0000 L CNN
F 1 "Jumper_NO_Small" V 6495 2498 50  0001 L CNN
F 2 "Project:idc-header-1x02-p2.54mm-vertical" H 6450 2450 50  0001 C CNN
F 3 "~" H 6450 2450 50  0001 C CNN
	1    6450 2450
	1    0    0    -1  
$EndComp
Wire Wire Line
	6250 2450 6350 2450
Wire Wire Line
	6550 2450 6775 2450
Text HLabel 3950 1750 0    50   Input ~ 0
L
Text HLabel 3950 3050 0    50   Input ~ 0
N
$EndSCHEMATC
