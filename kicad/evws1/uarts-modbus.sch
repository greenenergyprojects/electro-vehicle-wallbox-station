EESchema Schematic File Version 4
LIBS:evws1-cache
EELAYER 26 0
EELAYER END
$Descr A4 11693 8268
encoding utf-8
Sheet 4 5
Title ""
Date ""
Rev ""
Comp ""
Comment1 ""
Comment2 ""
Comment3 ""
Comment4 ""
$EndDescr
Text HLabel 6525 4200 0    50   Input ~ 0
DE1
Text HLabel 6525 4100 0    50   Input ~ 0
~RE1
Text HLabel 1625 2000 0    50   Input ~ 0
RxD0
Text HLabel 1625 1900 0    50   Output ~ 0
TxD0
Text HLabel 3550 2800 2    50   Output ~ 0
~DTR0
$Comp
L Device:Crystal_Small Y?
U 1 1 5E1D01E4
P 2400 2550
AR Path="/5E0A3961/5E1D01E4" Ref="Y?"  Part="1" 
AR Path="/5E0A3961/5E20BE9A/5E1D01E4" Ref="Y2"  Part="1" 
F 0 "Y2" V 2325 2425 50  0000 C CNN
F 1 "12MHz" V 2400 2350 50  0000 C CNN
F 2 "Project:Oscillator-SMD-M49S" H 2400 2550 50  0001 C CNN
F 3 "~" H 2400 2550 50  0001 C CNN
	1    2400 2550
	0    1    1    0   
$EndComp
$Comp
L _project:ch340g U?
U 1 1 5E1D01F4
P 2600 1900
AR Path="/5E0A3961/5E1D01F4" Ref="U?"  Part="1" 
AR Path="/5E0A3961/5E20BE9A/5E1D01F4" Ref="U5"  Part="1" 
F 0 "U5" H 2725 2225 50  0000 C CNN
F 1 "ch340g" H 3125 800 50  0000 C CNN
F 2 "Project:soic-16_hand-soldering" H 3150 1550 50  0001 C CNN
F 3 "" H 3150 1550 50  0001 C CNN
	1    2600 1900
	1    0    0    -1  
$EndComp
$Comp
L _project:max485esa U?
U 1 1 5E1D01FB
P 7600 4100
AR Path="/5E0A3961/5E1D01FB" Ref="U?"  Part="1" 
AR Path="/5E0A3961/5E20BE9A/5E1D01FB" Ref="U10"  Part="1" 
F 0 "U10" H 7350 4575 50  0000 C CNN
F 1 "max485esa" H 7875 3550 50  0000 C CNN
F 2 "Project:soic-8_hand-soldering" H 7600 3400 50  0001 C CNN
F 3 "" H 7600 4150 50  0001 C CNN
	1    7600 4100
	1    0    0    -1  
$EndComp
$Comp
L _project:usb-mini-socket J?
U 1 1 5E1D0202
P 5600 1900
AR Path="/5E0A3961/5E1D0202" Ref="J?"  Part="1" 
AR Path="/5E0A3961/5E20BE9A/5E1D0202" Ref="J11"  Part="1" 
F 0 "J11" H 5750 2250 50  0000 C CNN
F 1 "USB 2.0 Mini" H 5275 2250 50  0000 C CNN
F 2 "Project:usb-mini-tht" H 5750 1850 50  0001 C CNN
F 3 "" H 5750 1850 50  0001 C CNN
	1    5600 1900
	-1   0    0    -1  
$EndComp
Text HLabel 10375 3650 2    50   Output ~ 0
MODBUS-A
Text HLabel 10375 4550 2    50   Output ~ 0
MODBUS-B
Wire Wire Line
	2600 1900 1625 1900
Wire Wire Line
	1625 2000 2150 2000
NoConn ~ 2600 2200
$Comp
L power:GND #PWR0127
U 1 1 5E29C316
P 2900 3150
F 0 "#PWR0127" H 2900 2900 50  0001 C CNN
F 1 "GND" H 2905 2977 50  0000 C CNN
F 2 "" H 2900 3150 50  0001 C CNN
F 3 "" H 2900 3150 50  0001 C CNN
	1    2900 3150
	1    0    0    -1  
$EndComp
Wire Wire Line
	2900 3150 2900 3100
$Comp
L _project:SS34 D14
U 1 1 5E2A2346
P 4650 1475
F 0 "D14" V 4604 1554 50  0000 L CNN
F 1 "SS34" V 4695 1554 50  0000 L CNN
F 2 "Project:sma_hand-soldering" H 4650 1475 50  0001 C CNN
F 3 "" H 4650 1475 50  0001 C CNN
	1    4650 1475
	0    1    1    0   
$EndComp
$Comp
L power:+5V #PWR?
U 1 1 5E2A2794
P 4650 1175
AR Path="/5E2A2794" Ref="#PWR?"  Part="1" 
AR Path="/5E0A3961/5E2A2794" Ref="#PWR?"  Part="1" 
AR Path="/5E0A3961/5E20BE9A/5E2A2794" Ref="#PWR0210"  Part="1" 
F 0 "#PWR0210" H 4650 1025 50  0001 C CNN
F 1 "+5V" H 4665 1348 50  0000 C CNN
F 2 "" H 4650 1175 50  0001 C CNN
F 3 "" H 4650 1175 50  0001 C CNN
	1    4650 1175
	1    0    0    -1  
$EndComp
$Comp
L Device:C_Small C?
U 1 1 5E2A2D0C
P 4400 1425
AR Path="/5E0A3961/5E2A2D0C" Ref="C?"  Part="1" 
AR Path="/5E0A3961/5E20BE9A/5E2A2D0C" Ref="C37"  Part="1" 
F 0 "C37" H 4500 1350 50  0000 C CNN
F 1 "100n" H 4525 1500 50  0000 C CNN
F 2 "Project:c-1206-hand-soldering" H 4400 1425 50  0001 C CNN
F 3 "~" H 4400 1425 50  0001 C CNN
	1    4400 1425
	-1   0    0    1   
$EndComp
Wire Wire Line
	5300 1700 5200 1700
Wire Wire Line
	4650 1325 4650 1275
Wire Wire Line
	4650 1275 4400 1275
Wire Wire Line
	4400 1275 4400 1325
Connection ~ 4650 1275
Wire Wire Line
	4650 1275 4650 1175
$Comp
L power:GND #PWR0211
U 1 1 5E2A2EB7
P 4400 1575
F 0 "#PWR0211" H 4400 1325 50  0001 C CNN
F 1 "GND" H 4405 1402 50  0000 C CNN
F 2 "" H 4400 1575 50  0001 C CNN
F 3 "" H 4400 1575 50  0001 C CNN
	1    4400 1575
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR0212
U 1 1 5E2A2FB6
P 5600 2425
F 0 "#PWR0212" H 5600 2175 50  0001 C CNN
F 1 "GND" H 5605 2252 50  0000 C CNN
F 2 "" H 5600 2425 50  0001 C CNN
F 3 "" H 5600 2425 50  0001 C CNN
	1    5600 2425
	1    0    0    -1  
$EndComp
Wire Wire Line
	5600 2300 5600 2375
Wire Wire Line
	5700 2300 5700 2375
Wire Wire Line
	5700 2375 5600 2375
Connection ~ 5600 2375
Wire Wire Line
	5600 2375 5600 2425
Wire Wire Line
	4400 1525 4400 1575
Wire Wire Line
	5000 1700 4650 1700
Wire Wire Line
	4650 1625 4650 1700
Wire Wire Line
	5300 1900 3400 1900
Wire Wire Line
	5300 2000 3400 2000
NoConn ~ 3400 2200
NoConn ~ 3400 2300
NoConn ~ 3400 2400
NoConn ~ 3400 2500
NoConn ~ 3400 2600
NoConn ~ 5300 2100
$Comp
L power:+5V #PWR?
U 1 1 5E2A5428
P 2900 1100
AR Path="/5E2A5428" Ref="#PWR?"  Part="1" 
AR Path="/5E0A3961/5E2A5428" Ref="#PWR?"  Part="1" 
AR Path="/5E0A3961/5E20BE9A/5E2A5428" Ref="#PWR0213"  Part="1" 
F 0 "#PWR0213" H 2900 950 50  0001 C CNN
F 1 "+5V" H 2900 1250 50  0000 C CNN
F 2 "" H 2900 1100 50  0001 C CNN
F 3 "" H 2900 1100 50  0001 C CNN
	1    2900 1100
	1    0    0    -1  
$EndComp
$Comp
L Device:C_Small C?
U 1 1 5E2A545B
P 2700 1250
AR Path="/5E0A3961/5E2A545B" Ref="C?"  Part="1" 
AR Path="/5E0A3961/5E20BE9A/5E2A545B" Ref="C33"  Part="1" 
F 0 "C33" V 2825 1250 50  0000 C CNN
F 1 "100n" V 2575 1250 50  0000 C CNN
F 2 "Project:c-1206-hand-soldering" H 2700 1250 50  0001 C CNN
F 3 "~" H 2700 1250 50  0001 C CNN
	1    2700 1250
	0    -1   -1   0   
$EndComp
$Comp
L Device:C_Small C?
U 1 1 5E2A54FC
P 3300 1250
AR Path="/5E0A3961/5E2A54FC" Ref="C?"  Part="1" 
AR Path="/5E0A3961/5E20BE9A/5E2A54FC" Ref="C35"  Part="1" 
F 0 "C35" V 3425 1250 50  0000 C CNN
F 1 "100n" V 3175 1250 50  0000 C CNN
F 2 "Project:c-1206-hand-soldering" H 3300 1250 50  0001 C CNN
F 3 "~" H 3300 1250 50  0001 C CNN
	1    3300 1250
	0    -1   -1   0   
$EndComp
Wire Wire Line
	2900 1500 2900 1250
Wire Wire Line
	2900 1250 2800 1250
Connection ~ 2900 1250
Wire Wire Line
	2900 1250 2900 1100
Wire Wire Line
	3100 1500 3100 1250
Wire Wire Line
	3100 1250 3200 1250
$Comp
L Connector:TestPoint TP?
U 1 1 5E2A603E
P 3100 1150
AR Path="/5E0A3961/5E2A603E" Ref="TP?"  Part="1" 
AR Path="/5E0A3961/5E20BE9A/5E2A603E" Ref="TP5"  Part="1" 
F 0 "TP5" H 3050 1350 50  0000 L CNN
F 1 "TestPoint" H 3158 1179 50  0001 L CNN
F 2 "Wire_Pads:SolderWirePad_single_0-8mmDrill" H 3300 1150 50  0001 C CNN
F 3 "~" H 3300 1150 50  0001 C CNN
	1    3100 1150
	1    0    0    -1  
$EndComp
Wire Wire Line
	3100 1150 3100 1250
Connection ~ 3100 1250
$Comp
L power:GND #PWR0214
U 1 1 5E2A6F71
P 3500 1350
F 0 "#PWR0214" H 3500 1100 50  0001 C CNN
F 1 "GND" H 3505 1177 50  0000 C CNN
F 2 "" H 3500 1350 50  0001 C CNN
F 3 "" H 3500 1350 50  0001 C CNN
	1    3500 1350
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR0215
U 1 1 5E2A6F96
P 2500 1350
F 0 "#PWR0215" H 2500 1100 50  0001 C CNN
F 1 "GND" H 2505 1177 50  0000 C CNN
F 2 "" H 2500 1350 50  0001 C CNN
F 3 "" H 2500 1350 50  0001 C CNN
	1    2500 1350
	1    0    0    -1  
$EndComp
Wire Wire Line
	2600 1250 2500 1250
Wire Wire Line
	2500 1250 2500 1350
Wire Wire Line
	3400 1250 3500 1250
Wire Wire Line
	3500 1250 3500 1350
$Comp
L Device:C_Small C?
U 1 1 5E2A7718
P 2400 2850
AR Path="/5E0A3961/5E2A7718" Ref="C?"  Part="1" 
AR Path="/5E0A3961/5E20BE9A/5E2A7718" Ref="C31"  Part="1" 
F 0 "C31" H 2500 2775 50  0000 C CNN
F 1 "22p" H 2525 2925 50  0000 C CNN
F 2 "Project:c-1206-hand-soldering" H 2400 2850 50  0001 C CNN
F 3 "~" H 2400 2850 50  0001 C CNN
	1    2400 2850
	-1   0    0    1   
$EndComp
$Comp
L Device:C_Small C?
U 1 1 5E2A77FA
P 1950 2850
AR Path="/5E0A3961/5E2A77FA" Ref="C?"  Part="1" 
AR Path="/5E0A3961/5E20BE9A/5E2A77FA" Ref="C29"  Part="1" 
F 0 "C29" H 2050 2775 50  0000 C CNN
F 1 "22p" H 2075 2925 50  0000 C CNN
F 2 "Project:c-1206-hand-soldering" H 1950 2850 50  0001 C CNN
F 3 "~" H 1950 2850 50  0001 C CNN
	1    1950 2850
	-1   0    0    1   
$EndComp
Wire Wire Line
	2600 2400 2400 2400
Wire Wire Line
	1950 2400 1950 2750
Wire Wire Line
	2400 2400 2400 2450
Connection ~ 2400 2400
Wire Wire Line
	2400 2400 1950 2400
Wire Wire Line
	2400 2750 2400 2700
Wire Wire Line
	2600 2700 2400 2700
Connection ~ 2400 2700
Wire Wire Line
	2400 2700 2400 2650
$Comp
L power:GND #PWR0216
U 1 1 5E2AAA66
P 2150 3100
F 0 "#PWR0216" H 2150 2850 50  0001 C CNN
F 1 "GND" H 2155 2927 50  0000 C CNN
F 2 "" H 2150 3100 50  0001 C CNN
F 3 "" H 2150 3100 50  0001 C CNN
	1    2150 3100
	1    0    0    -1  
$EndComp
Wire Wire Line
	1950 2950 1950 3000
Wire Wire Line
	1950 3000 2150 3000
Wire Wire Line
	2150 3000 2150 3100
Wire Wire Line
	2150 3000 2400 3000
Wire Wire Line
	2400 3000 2400 2950
Connection ~ 2150 3000
Wire Wire Line
	3400 2800 3550 2800
Text HLabel 1125 5825 0    50   Input ~ 0
RxD1
Text HLabel 1100 5400 0    50   Output ~ 0
TxD1
Text HLabel 3800 6625 2    50   Output ~ 0
~DTR1
$Comp
L Device:Crystal_Small Y?
U 1 1 5E2AED8B
P 2650 6375
AR Path="/5E0A3961/5E2AED8B" Ref="Y?"  Part="1" 
AR Path="/5E0A3961/5E20BE9A/5E2AED8B" Ref="Y3"  Part="1" 
F 0 "Y3" V 2575 6250 50  0000 C CNN
F 1 "12MHz" V 2650 6175 50  0000 C CNN
F 2 "Project:Oscillator-SMD-M49S" H 2650 6375 50  0001 C CNN
F 3 "~" H 2650 6375 50  0001 C CNN
	1    2650 6375
	0    1    1    0   
$EndComp
$Comp
L _project:ch340g U?
U 1 1 5E2AED92
P 2850 5725
AR Path="/5E0A3961/5E2AED92" Ref="U?"  Part="1" 
AR Path="/5E0A3961/5E20BE9A/5E2AED92" Ref="U6"  Part="1" 
F 0 "U6" H 2975 6050 50  0000 C CNN
F 1 "ch340g" H 3375 4625 50  0000 C CNN
F 2 "Project:soic-16_hand-soldering" H 3400 5375 50  0001 C CNN
F 3 "" H 3400 5375 50  0001 C CNN
	1    2850 5725
	1    0    0    -1  
$EndComp
$Comp
L _project:usb-mini-socket J?
U 1 1 5E2AED99
P 5850 5725
AR Path="/5E0A3961/5E2AED99" Ref="J?"  Part="1" 
AR Path="/5E0A3961/5E20BE9A/5E2AED99" Ref="J12"  Part="1" 
F 0 "J12" H 6000 6075 50  0000 C CNN
F 1 "USB 2.0 Mini" H 5525 6075 50  0000 C CNN
F 2 "Project:usb-mini-tht" H 6000 5675 50  0001 C CNN
F 3 "" H 6000 5675 50  0001 C CNN
	1    5850 5725
	-1   0    0    -1  
$EndComp
Wire Wire Line
	1125 5825 2500 5825
NoConn ~ 2850 6025
$Comp
L power:GND #PWR0217
U 1 1 5E2AEDA3
P 3150 6975
F 0 "#PWR0217" H 3150 6725 50  0001 C CNN
F 1 "GND" H 3155 6802 50  0000 C CNN
F 2 "" H 3150 6975 50  0001 C CNN
F 3 "" H 3150 6975 50  0001 C CNN
	1    3150 6975
	1    0    0    -1  
$EndComp
Wire Wire Line
	3150 6975 3150 6925
$Comp
L _project:SS34 D15
U 1 1 5E2AEDB2
P 4900 5300
F 0 "D15" V 4854 5379 50  0000 L CNN
F 1 "SS34" V 4945 5379 50  0000 L CNN
F 2 "Project:sma_hand-soldering" H 4900 5300 50  0001 C CNN
F 3 "" H 4900 5300 50  0001 C CNN
	1    4900 5300
	0    1    1    0   
$EndComp
$Comp
L power:+5V #PWR?
U 1 1 5E2AEDB9
P 4900 5000
AR Path="/5E2AEDB9" Ref="#PWR?"  Part="1" 
AR Path="/5E0A3961/5E2AEDB9" Ref="#PWR?"  Part="1" 
AR Path="/5E0A3961/5E20BE9A/5E2AEDB9" Ref="#PWR0218"  Part="1" 
F 0 "#PWR0218" H 4900 4850 50  0001 C CNN
F 1 "+5V" H 4915 5173 50  0000 C CNN
F 2 "" H 4900 5000 50  0001 C CNN
F 3 "" H 4900 5000 50  0001 C CNN
	1    4900 5000
	1    0    0    -1  
$EndComp
$Comp
L Device:C_Small C?
U 1 1 5E2AEDBF
P 4650 5250
AR Path="/5E0A3961/5E2AEDBF" Ref="C?"  Part="1" 
AR Path="/5E0A3961/5E20BE9A/5E2AEDBF" Ref="C38"  Part="1" 
F 0 "C38" H 4750 5175 50  0000 C CNN
F 1 "100n" H 4775 5325 50  0000 C CNN
F 2 "Project:c-1206-hand-soldering" H 4650 5250 50  0001 C CNN
F 3 "~" H 4650 5250 50  0001 C CNN
	1    4650 5250
	-1   0    0    1   
$EndComp
Wire Wire Line
	5550 5525 5450 5525
Wire Wire Line
	4900 5150 4900 5100
Wire Wire Line
	4900 5100 4650 5100
Wire Wire Line
	4650 5100 4650 5150
Connection ~ 4900 5100
Wire Wire Line
	4900 5100 4900 5000
$Comp
L power:GND #PWR0219
U 1 1 5E2AEDCC
P 4650 5400
F 0 "#PWR0219" H 4650 5150 50  0001 C CNN
F 1 "GND" H 4655 5227 50  0000 C CNN
F 2 "" H 4650 5400 50  0001 C CNN
F 3 "" H 4650 5400 50  0001 C CNN
	1    4650 5400
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR0220
U 1 1 5E2AEDD2
P 5850 6250
F 0 "#PWR0220" H 5850 6000 50  0001 C CNN
F 1 "GND" H 5855 6077 50  0000 C CNN
F 2 "" H 5850 6250 50  0001 C CNN
F 3 "" H 5850 6250 50  0001 C CNN
	1    5850 6250
	1    0    0    -1  
$EndComp
Wire Wire Line
	5850 6125 5850 6200
Wire Wire Line
	5950 6125 5950 6200
Wire Wire Line
	5950 6200 5850 6200
Connection ~ 5850 6200
Wire Wire Line
	5850 6200 5850 6250
Wire Wire Line
	4650 5350 4650 5400
Wire Wire Line
	5250 5525 4900 5525
Wire Wire Line
	4900 5450 4900 5525
Wire Wire Line
	5550 5725 3650 5725
Wire Wire Line
	5550 5825 3650 5825
NoConn ~ 3650 6025
NoConn ~ 3650 6125
NoConn ~ 3650 6225
NoConn ~ 3650 6325
NoConn ~ 3650 6425
NoConn ~ 5550 5925
$Comp
L power:+5V #PWR?
U 1 1 5E2AEDE9
P 3150 4925
AR Path="/5E2AEDE9" Ref="#PWR?"  Part="1" 
AR Path="/5E0A3961/5E2AEDE9" Ref="#PWR?"  Part="1" 
AR Path="/5E0A3961/5E20BE9A/5E2AEDE9" Ref="#PWR0221"  Part="1" 
F 0 "#PWR0221" H 3150 4775 50  0001 C CNN
F 1 "+5V" H 3150 5075 50  0000 C CNN
F 2 "" H 3150 4925 50  0001 C CNN
F 3 "" H 3150 4925 50  0001 C CNN
	1    3150 4925
	1    0    0    -1  
$EndComp
$Comp
L Device:C_Small C?
U 1 1 5E2AEDEF
P 2950 5075
AR Path="/5E0A3961/5E2AEDEF" Ref="C?"  Part="1" 
AR Path="/5E0A3961/5E20BE9A/5E2AEDEF" Ref="C34"  Part="1" 
F 0 "C34" V 3075 5075 50  0000 C CNN
F 1 "100n" V 2825 5075 50  0000 C CNN
F 2 "Project:c-1206-hand-soldering" H 2950 5075 50  0001 C CNN
F 3 "~" H 2950 5075 50  0001 C CNN
	1    2950 5075
	0    -1   -1   0   
$EndComp
$Comp
L Device:C_Small C?
U 1 1 5E2AEDF6
P 3550 5075
AR Path="/5E0A3961/5E2AEDF6" Ref="C?"  Part="1" 
AR Path="/5E0A3961/5E20BE9A/5E2AEDF6" Ref="C36"  Part="1" 
F 0 "C36" V 3675 5075 50  0000 C CNN
F 1 "100n" V 3425 5075 50  0000 C CNN
F 2 "Project:c-1206-hand-soldering" H 3550 5075 50  0001 C CNN
F 3 "~" H 3550 5075 50  0001 C CNN
	1    3550 5075
	0    -1   -1   0   
$EndComp
Wire Wire Line
	3150 5325 3150 5075
Wire Wire Line
	3150 5075 3050 5075
Connection ~ 3150 5075
Wire Wire Line
	3150 5075 3150 4925
Wire Wire Line
	3350 5325 3350 5075
Wire Wire Line
	3350 5075 3450 5075
$Comp
L Connector:TestPoint TP?
U 1 1 5E2AEE03
P 3350 4975
AR Path="/5E0A3961/5E2AEE03" Ref="TP?"  Part="1" 
AR Path="/5E0A3961/5E20BE9A/5E2AEE03" Ref="TP6"  Part="1" 
F 0 "TP6" H 3300 5175 50  0000 L CNN
F 1 "TestPoint" H 3408 5004 50  0001 L CNN
F 2 "Wire_Pads:SolderWirePad_single_0-8mmDrill" H 3550 4975 50  0001 C CNN
F 3 "~" H 3550 4975 50  0001 C CNN
	1    3350 4975
	1    0    0    -1  
$EndComp
Wire Wire Line
	3350 4975 3350 5075
Connection ~ 3350 5075
$Comp
L power:GND #PWR0222
U 1 1 5E2AEE0C
P 3750 5175
F 0 "#PWR0222" H 3750 4925 50  0001 C CNN
F 1 "GND" H 3755 5002 50  0000 C CNN
F 2 "" H 3750 5175 50  0001 C CNN
F 3 "" H 3750 5175 50  0001 C CNN
	1    3750 5175
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR0223
U 1 1 5E2AEE12
P 2750 5175
F 0 "#PWR0223" H 2750 4925 50  0001 C CNN
F 1 "GND" H 2755 5002 50  0000 C CNN
F 2 "" H 2750 5175 50  0001 C CNN
F 3 "" H 2750 5175 50  0001 C CNN
	1    2750 5175
	1    0    0    -1  
$EndComp
Wire Wire Line
	2850 5075 2750 5075
Wire Wire Line
	2750 5075 2750 5175
Wire Wire Line
	3650 5075 3750 5075
Wire Wire Line
	3750 5075 3750 5175
$Comp
L Device:C_Small C?
U 1 1 5E2AEE1C
P 2650 6675
AR Path="/5E0A3961/5E2AEE1C" Ref="C?"  Part="1" 
AR Path="/5E0A3961/5E20BE9A/5E2AEE1C" Ref="C32"  Part="1" 
F 0 "C32" H 2750 6600 50  0000 C CNN
F 1 "22p" H 2775 6750 50  0000 C CNN
F 2 "Project:c-1206-hand-soldering" H 2650 6675 50  0001 C CNN
F 3 "~" H 2650 6675 50  0001 C CNN
	1    2650 6675
	-1   0    0    1   
$EndComp
$Comp
L Device:C_Small C?
U 1 1 5E2AEE23
P 2200 6675
AR Path="/5E0A3961/5E2AEE23" Ref="C?"  Part="1" 
AR Path="/5E0A3961/5E20BE9A/5E2AEE23" Ref="C30"  Part="1" 
F 0 "C30" H 2300 6600 50  0000 C CNN
F 1 "22p" H 2325 6750 50  0000 C CNN
F 2 "Project:c-1206-hand-soldering" H 2200 6675 50  0001 C CNN
F 3 "~" H 2200 6675 50  0001 C CNN
	1    2200 6675
	-1   0    0    1   
$EndComp
Wire Wire Line
	2850 6225 2650 6225
Wire Wire Line
	2200 6225 2200 6575
Wire Wire Line
	2650 6225 2650 6275
Connection ~ 2650 6225
Wire Wire Line
	2650 6225 2200 6225
Wire Wire Line
	2650 6575 2650 6525
Wire Wire Line
	2850 6525 2650 6525
Connection ~ 2650 6525
Wire Wire Line
	2650 6525 2650 6475
$Comp
L power:GND #PWR0224
U 1 1 5E2AEE33
P 2400 6925
F 0 "#PWR0224" H 2400 6675 50  0001 C CNN
F 1 "GND" H 2405 6752 50  0000 C CNN
F 2 "" H 2400 6925 50  0001 C CNN
F 3 "" H 2400 6925 50  0001 C CNN
	1    2400 6925
	1    0    0    -1  
$EndComp
Wire Wire Line
	2200 6775 2200 6825
Wire Wire Line
	2200 6825 2400 6825
Wire Wire Line
	2400 6825 2400 6925
Wire Wire Line
	2400 6825 2650 6825
Wire Wire Line
	2650 6825 2650 6775
Connection ~ 2400 6825
Wire Wire Line
	3650 6625 3800 6625
Wire Wire Line
	7200 4300 2500 4300
Wire Wire Line
	2500 4300 2500 5400
Wire Wire Line
	2500 5825 2850 5825
$Comp
L Connector_Generic:Conn_01x03 J15
U 1 1 5E2CA290
P 1825 5400
F 0 "J15" H 1905 5442 50  0000 L CNN
F 1 "Jumper" H 1905 5351 50  0000 L CNN
F 2 "Project:idc-header-1x03-p2.54mm-vertical" H 1825 5400 50  0001 C CNN
F 3 "~" H 1825 5400 50  0001 C CNN
	1    1825 5400
	1    0    0    -1  
$EndComp
Wire Wire Line
	1625 5400 1100 5400
Wire Wire Line
	2850 5725 1525 5725
Wire Wire Line
	1525 5725 1525 5500
Wire Wire Line
	1525 5500 1625 5500
Wire Wire Line
	1625 5300 1525 5300
Wire Wire Line
	1525 4000 7200 4000
Wire Wire Line
	1525 5300 1525 4000
Connection ~ 2500 5825
$Comp
L Device:R R?
U 1 1 5E2E5D24
P 2350 5150
AR Path="/5E0A3961/5E2E5D24" Ref="R?"  Part="1" 
AR Path="/5E0A3961/5E20BE9A/5E2E5D24" Ref="R73"  Part="1" 
F 0 "R73" H 2225 5200 50  0000 C CNN
F 1 "47K" H 2225 5100 50  0000 C CNN
F 2 "Project:r-0805-hand-soldering" V 2280 5150 50  0001 C CNN
F 3 "~" H 2350 5150 50  0001 C CNN
	1    2350 5150
	1    0    0    -1  
$EndComp
Wire Wire Line
	2350 5300 2350 5400
Wire Wire Line
	2350 5400 2500 5400
Connection ~ 2500 5400
Wire Wire Line
	2500 5400 2500 5825
$Comp
L power:+5V #PWR?
U 1 1 5E2EAA7A
P 2350 4875
AR Path="/5E2EAA7A" Ref="#PWR?"  Part="1" 
AR Path="/5E0A3961/5E2EAA7A" Ref="#PWR?"  Part="1" 
AR Path="/5E0A3961/5E20BE9A/5E2EAA7A" Ref="#PWR0225"  Part="1" 
F 0 "#PWR0225" H 2350 4725 50  0001 C CNN
F 1 "+5V" H 2350 5025 50  0000 C CNN
F 2 "" H 2350 4875 50  0001 C CNN
F 3 "" H 2350 4875 50  0001 C CNN
	1    2350 4875
	1    0    0    -1  
$EndComp
Wire Wire Line
	2350 5000 2350 4875
Wire Wire Line
	6525 4100 6950 4100
Wire Wire Line
	6525 4200 6950 4200
$Comp
L Device:R R?
U 1 1 5E2F550C
P 6950 4550
AR Path="/5E0A3961/5E2F550C" Ref="R?"  Part="1" 
AR Path="/5E0A3961/5E20BE9A/5E2F550C" Ref="R75"  Part="1" 
F 0 "R75" H 6825 4600 50  0000 C CNN
F 1 "47K" H 6825 4500 50  0000 C CNN
F 2 "Project:r-0805-hand-soldering" V 6880 4550 50  0001 C CNN
F 3 "~" H 6950 4550 50  0001 C CNN
	1    6950 4550
	1    0    0    -1  
$EndComp
$Comp
L Device:R R?
U 1 1 5E2F5632
P 6950 3700
AR Path="/5E0A3961/5E2F5632" Ref="R?"  Part="1" 
AR Path="/5E0A3961/5E20BE9A/5E2F5632" Ref="R74"  Part="1" 
F 0 "R74" H 6825 3750 50  0000 C CNN
F 1 "47K" H 6825 3650 50  0000 C CNN
F 2 "Project:r-0805-hand-soldering" V 6880 3700 50  0001 C CNN
F 3 "~" H 6950 3700 50  0001 C CNN
	1    6950 3700
	1    0    0    -1  
$EndComp
Wire Wire Line
	6950 3850 6950 4100
Connection ~ 6950 4100
Wire Wire Line
	6950 4100 7200 4100
Wire Wire Line
	6950 4400 6950 4200
Connection ~ 6950 4200
Wire Wire Line
	6950 4200 7200 4200
$Comp
L power:GND #PWR0226
U 1 1 5E2FADE6
P 6950 4800
F 0 "#PWR0226" H 6950 4550 50  0001 C CNN
F 1 "GND" H 6955 4627 50  0000 C CNN
F 2 "" H 6950 4800 50  0001 C CNN
F 3 "" H 6950 4800 50  0001 C CNN
	1    6950 4800
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR0227
U 1 1 5E2FDC0D
P 7600 4800
F 0 "#PWR0227" H 7600 4550 50  0001 C CNN
F 1 "GND" H 7605 4627 50  0000 C CNN
F 2 "" H 7600 4800 50  0001 C CNN
F 3 "" H 7600 4800 50  0001 C CNN
	1    7600 4800
	1    0    0    -1  
$EndComp
Wire Wire Line
	7600 4800 7600 4700
Wire Wire Line
	6950 4800 6950 4700
$Comp
L power:+5V #PWR?
U 1 1 5E303784
P 6950 3450
AR Path="/5E303784" Ref="#PWR?"  Part="1" 
AR Path="/5E0A3961/5E303784" Ref="#PWR?"  Part="1" 
AR Path="/5E0A3961/5E20BE9A/5E303784" Ref="#PWR0228"  Part="1" 
F 0 "#PWR0228" H 6950 3300 50  0001 C CNN
F 1 "+5V" H 6965 3623 50  0000 C CNN
F 2 "" H 6950 3450 50  0001 C CNN
F 3 "" H 6950 3450 50  0001 C CNN
	1    6950 3450
	1    0    0    -1  
$EndComp
Wire Wire Line
	6950 3550 6950 3450
$Comp
L power:+5V #PWR?
U 1 1 5E306799
P 7600 3200
AR Path="/5E306799" Ref="#PWR?"  Part="1" 
AR Path="/5E0A3961/5E306799" Ref="#PWR?"  Part="1" 
AR Path="/5E0A3961/5E20BE9A/5E306799" Ref="#PWR0229"  Part="1" 
F 0 "#PWR0229" H 7600 3050 50  0001 C CNN
F 1 "+5V" H 7615 3373 50  0000 C CNN
F 2 "" H 7600 3200 50  0001 C CNN
F 3 "" H 7600 3200 50  0001 C CNN
	1    7600 3200
	1    0    0    -1  
$EndComp
$Comp
L Device:C_Small C?
U 1 1 5E306810
P 7800 3325
AR Path="/5E0A3961/5E306810" Ref="C?"  Part="1" 
AR Path="/5E0A3961/5E20BE9A/5E306810" Ref="C39"  Part="1" 
F 0 "C39" V 7925 3325 50  0000 C CNN
F 1 "100n" V 7675 3325 50  0000 C CNN
F 2 "Project:c-1206-hand-soldering" H 7800 3325 50  0001 C CNN
F 3 "~" H 7800 3325 50  0001 C CNN
	1    7800 3325
	0    -1   -1   0   
$EndComp
Wire Wire Line
	7600 3600 7600 3325
Wire Wire Line
	7700 3325 7600 3325
Connection ~ 7600 3325
Wire Wire Line
	7600 3325 7600 3200
$Comp
L power:GND #PWR0230
U 1 1 5E30C889
P 7975 3400
F 0 "#PWR0230" H 7975 3150 50  0001 C CNN
F 1 "GND" H 7980 3227 50  0000 C CNN
F 2 "" H 7975 3400 50  0001 C CNN
F 3 "" H 7975 3400 50  0001 C CNN
	1    7975 3400
	1    0    0    -1  
$EndComp
Wire Wire Line
	7900 3325 7975 3325
Wire Wire Line
	7975 3325 7975 3400
$Comp
L Device:R R?
U 1 1 5E30FDC1
P 2150 1600
AR Path="/5E0A3961/5E30FDC1" Ref="R?"  Part="1" 
AR Path="/5E0A3961/5E20BE9A/5E30FDC1" Ref="R63"  Part="1" 
F 0 "R63" H 2025 1650 50  0000 C CNN
F 1 "47K" H 2025 1550 50  0000 C CNN
F 2 "Project:r-0805-hand-soldering" V 2080 1600 50  0001 C CNN
F 3 "~" H 2150 1600 50  0001 C CNN
	1    2150 1600
	1    0    0    -1  
$EndComp
$Comp
L power:+5V #PWR?
U 1 1 5E30FFED
P 2150 1350
AR Path="/5E30FFED" Ref="#PWR?"  Part="1" 
AR Path="/5E0A3961/5E30FFED" Ref="#PWR?"  Part="1" 
AR Path="/5E0A3961/5E20BE9A/5E30FFED" Ref="#PWR0231"  Part="1" 
F 0 "#PWR0231" H 2150 1200 50  0001 C CNN
F 1 "+5V" H 2150 1500 50  0000 C CNN
F 2 "" H 2150 1350 50  0001 C CNN
F 3 "" H 2150 1350 50  0001 C CNN
	1    2150 1350
	1    0    0    -1  
$EndComp
Wire Wire Line
	2150 2000 2150 1750
Connection ~ 2150 2000
Wire Wire Line
	2150 2000 2600 2000
Wire Wire Line
	2150 1450 2150 1350
Text Label 1675 1900 0    50   ~ 0
UC-RXD0
Text Label 1675 2000 0    50   ~ 0
UC-TXD0
Text Label 1175 5400 0    50   ~ 0
UC-RXD1
Text Label 1175 5825 0    50   ~ 0
UC-TXD1
$Comp
L Connector_Generic:Conn_01x03 J17
U 1 1 5E324F71
P 8250 3050
F 0 "J17" V 8350 3200 50  0000 R CNN
F 1 "header" V 8350 2975 50  0000 R CNN
F 2 "Project:idc-header-1x03-p2.54mm-vertical" H 8250 3050 50  0001 C CNN
F 3 "~" H 8250 3050 50  0001 C CNN
	1    8250 3050
	0    -1   -1   0   
$EndComp
$Comp
L Connector_Generic:Conn_01x02 J20
U 1 1 5E3251CE
P 9700 3250
F 0 "J20" H 9675 3350 50  0000 L CNN
F 1 "header" H 9650 3050 50  0000 L CNN
F 2 "Project:idc-header-1x02-p2.54mm-vertical" H 9700 3250 50  0001 C CNN
F 3 "~" H 9700 3250 50  0001 C CNN
	1    9700 3250
	1    0    0    -1  
$EndComp
$Comp
L Connector_Generic:Conn_01x02 J19
U 1 1 5E32525A
P 9700 4800
F 0 "J19" H 9650 4900 50  0000 L CNN
F 1 "header" H 9600 4600 50  0000 L CNN
F 2 "Project:idc-header-1x02-p2.54mm-vertical" H 9700 4800 50  0001 C CNN
F 3 "~" H 9700 4800 50  0001 C CNN
	1    9700 4800
	1    0    0    -1  
$EndComp
$Comp
L Connector_Generic:Conn_01x02 J18
U 1 1 5E32530C
P 9350 3900
F 0 "J18" H 9300 4000 50  0000 L CNN
F 1 "header" H 9250 3700 50  0000 L CNN
F 2 "Project:idc-header-1x02-p2.54mm-vertical" H 9350 3900 50  0001 C CNN
F 3 "~" H 9350 3900 50  0001 C CNN
	1    9350 3900
	1    0    0    -1  
$EndComp
$Comp
L Connector_Generic:Conn_01x07 J16
U 1 1 5E32575F
P 8500 1600
F 0 "J16" H 8500 1200 50  0000 C CNN
F 1 "header" H 8525 2025 50  0000 C CNN
F 2 "Project:idc-header-1x07-p2.54mm-vertical" H 8500 1600 50  0001 C CNN
F 3 "~" H 8500 1600 50  0001 C CNN
	1    8500 1600
	1    0    0    1   
$EndComp
$Comp
L power:GND #PWR0232
U 1 1 5E325B32
P 8200 2000
F 0 "#PWR0232" H 8200 1750 50  0001 C CNN
F 1 "GND" H 8205 1827 50  0000 C CNN
F 2 "" H 8200 2000 50  0001 C CNN
F 3 "" H 8200 2000 50  0001 C CNN
	1    8200 2000
	1    0    0    -1  
$EndComp
Wire Wire Line
	8300 1900 8200 1900
Wire Wire Line
	8200 1900 8200 2000
Wire Wire Line
	8300 1800 7800 1800
Wire Wire Line
	8300 1700 7800 1700
Wire Wire Line
	8300 1600 7800 1600
Wire Wire Line
	8300 1500 7800 1500
Wire Wire Line
	8300 1400 7800 1400
Wire Wire Line
	8300 1300 7800 1300
Text Label 6600 4100 0    50   ~ 0
~RE1
Text Label 6600 4200 0    50   ~ 0
DE1
Text Label 7900 1800 0    50   ~ 0
DE1
Text Label 7900 1700 0    50   ~ 0
~RE1
Text Label 7900 1400 0    50   ~ 0
UC-TXD0
Text Label 7900 1300 0    50   ~ 0
UC-RXD0
Text Label 7900 1500 0    50   ~ 0
UC-RXD1
Text Label 7900 1600 0    50   ~ 0
UC-TXD1
$Comp
L _project:SM712 D16
U 1 1 5E31D390
P 9700 4100
F 0 "D16" V 9950 3850 50  0000 L CNN
F 1 "SM712" V 9850 3750 50  0000 L CNN
F 2 "Project:sot-23_hand-soldering" H 9550 4100 50  0001 C CNN
F 3 "" H 9550 4100 50  0001 C CNN
	1    9700 4100
	0    -1   -1   0   
$EndComp
$Comp
L _project:MF-SMDF050-2 F1
U 1 1 5E33820F
P 5000 1700
F 0 "F1" H 5125 1800 50  0000 C CNN
F 1 "MF-SMDF050-2" H 5700 2175 50  0001 C CNN
F 2 "Project:mf-smdf" V 5300 1750 50  0001 L CNN
F 3 "~" V 5100 1700 50  0001 C CNN
F 4 "1.2A/0.55A" H 5075 1600 50  0000 C CNN "Current"
	1    5000 1700
	1    0    0    -1  
$EndComp
$Comp
L _project:MF-SMDF050-2 F2
U 1 1 5E339846
P 5250 5525
F 0 "F2" H 5375 5625 50  0000 C CNN
F 1 "MF-SMDF050-2" H 5950 6000 50  0001 C CNN
F 2 "Project:mf-smdf" V 5550 5575 50  0001 L CNN
F 3 "~" V 5350 5525 50  0001 C CNN
F 4 "1.2A/0.55A" H 5325 5425 50  0000 C CNN "Current"
	1    5250 5525
	1    0    0    -1  
$EndComp
$Comp
L Device:R R?
U 1 1 5E33B244
P 8600 4000
AR Path="/5E0A3961/5E33B244" Ref="R?"  Part="1" 
AR Path="/5E0A3961/5E20BE9A/5E33B244" Ref="R76"  Part="1" 
F 0 "R76" V 8500 3925 50  0000 C CNN
F 1 "10R" V 8500 4100 50  0000 C CNN
F 2 "Project:r-0805-hand-soldering" V 8530 4000 50  0001 C CNN
F 3 "~" H 8600 4000 50  0001 C CNN
	1    8600 4000
	0    1    1    0   
$EndComp
Wire Wire Line
	7975 3325 8150 3325
Wire Wire Line
	8150 3325 8150 3250
Connection ~ 7975 3325
Wire Wire Line
	8000 4000 8250 4000
Wire Wire Line
	8250 3250 8250 4000
Connection ~ 8250 4000
Wire Wire Line
	8250 4000 8450 4000
$Comp
L Device:R R?
U 1 1 5E34AD14
P 8600 4300
AR Path="/5E0A3961/5E34AD14" Ref="R?"  Part="1" 
AR Path="/5E0A3961/5E20BE9A/5E34AD14" Ref="R77"  Part="1" 
F 0 "R77" V 8500 4225 50  0000 C CNN
F 1 "10R" V 8500 4400 50  0000 C CNN
F 2 "Project:r-0805-hand-soldering" V 8530 4300 50  0001 C CNN
F 3 "~" H 8600 4300 50  0001 C CNN
	1    8600 4300
	0    1    1    0   
$EndComp
Wire Wire Line
	8000 4300 8350 4300
Wire Wire Line
	8350 3250 8350 4300
Connection ~ 8350 4300
Wire Wire Line
	8350 4300 8450 4300
$Comp
L Device:R R?
U 1 1 5E352CD8
P 9150 4250
AR Path="/5E0A3961/5E352CD8" Ref="R?"  Part="1" 
AR Path="/5E0A3961/5E20BE9A/5E352CD8" Ref="R78"  Part="1" 
F 0 "R78" H 9000 4300 50  0000 C CNN
F 1 "150R" H 9000 4200 50  0000 C CNN
F 2 "Project:r-0805-hand-soldering" V 9080 4250 50  0001 C CNN
F 3 "~" H 9150 4250 50  0001 C CNN
	1    9150 4250
	1    0    0    -1  
$EndComp
Wire Wire Line
	9150 4100 9150 4000
Wire Wire Line
	8850 4000 8850 3650
Wire Wire Line
	9150 3900 9150 3650
Wire Wire Line
	9700 3700 9700 3650
Wire Wire Line
	9700 3650 9450 3650
Connection ~ 9150 3650
Wire Wire Line
	9150 3650 8850 3650
Wire Wire Line
	9700 4500 9700 4550
Wire Wire Line
	9700 4550 9450 4550
Wire Wire Line
	8850 4550 8850 4300
Wire Wire Line
	8850 4300 8750 4300
Wire Wire Line
	9150 4400 9150 4550
Connection ~ 9150 4550
Wire Wire Line
	9150 4550 8850 4550
$Comp
L power:GND #PWR0233
U 1 1 5E37F3F3
P 10000 4200
F 0 "#PWR0233" H 10000 3950 50  0001 C CNN
F 1 "GND" H 10005 4027 50  0000 C CNN
F 2 "" H 10000 4200 50  0001 C CNN
F 3 "" H 10000 4200 50  0001 C CNN
	1    10000 4200
	1    0    0    -1  
$EndComp
Wire Wire Line
	9900 4100 10000 4100
Wire Wire Line
	10000 4100 10000 4200
Wire Wire Line
	9700 3650 10375 3650
Connection ~ 9700 3650
Wire Wire Line
	9700 4550 10375 4550
Connection ~ 9700 4550
Text Label 9750 4550 0    50   ~ 0
MODBUS-B
Text Label 9750 3650 0    50   ~ 0
MODBUS-A
$Comp
L Device:R R?
U 1 1 5E3AB7B3
P 9450 5100
AR Path="/5E0A3961/5E3AB7B3" Ref="R?"  Part="1" 
AR Path="/5E0A3961/5E20BE9A/5E3AB7B3" Ref="R80"  Part="1" 
F 0 "R80" H 9300 5150 50  0000 C CNN
F 1 "330R" H 9300 5050 50  0000 C CNN
F 2 "Project:r-0805-hand-soldering" V 9380 5100 50  0001 C CNN
F 3 "~" H 9450 5100 50  0001 C CNN
	1    9450 5100
	1    0    0    -1  
$EndComp
$Comp
L Device:R R?
U 1 1 5E3AB8B3
P 9450 3050
AR Path="/5E0A3961/5E3AB8B3" Ref="R?"  Part="1" 
AR Path="/5E0A3961/5E20BE9A/5E3AB8B3" Ref="R79"  Part="1" 
F 0 "R79" H 9300 3100 50  0000 C CNN
F 1 "330R" H 9300 3000 50  0000 C CNN
F 2 "Project:r-0805-hand-soldering" V 9380 3050 50  0001 C CNN
F 3 "~" H 9450 3050 50  0001 C CNN
	1    9450 3050
	1    0    0    -1  
$EndComp
Wire Wire Line
	9500 4900 9450 4900
Wire Wire Line
	9450 4900 9450 4950
Wire Wire Line
	9500 4800 9450 4800
Wire Wire Line
	9450 4800 9450 4550
Connection ~ 9450 4550
Wire Wire Line
	9450 4550 9150 4550
Wire Wire Line
	9500 3350 9450 3350
Wire Wire Line
	9450 3350 9450 3650
Connection ~ 9450 3650
Wire Wire Line
	9450 3650 9150 3650
Wire Wire Line
	9500 3250 9450 3250
Wire Wire Line
	9450 3250 9450 3200
$Comp
L power:GND #PWR0234
U 1 1 5E3C0A34
P 9450 5350
F 0 "#PWR0234" H 9450 5100 50  0001 C CNN
F 1 "GND" H 9455 5177 50  0000 C CNN
F 2 "" H 9450 5350 50  0001 C CNN
F 3 "" H 9450 5350 50  0001 C CNN
	1    9450 5350
	1    0    0    -1  
$EndComp
Wire Wire Line
	9450 5250 9450 5350
$Comp
L power:+5V #PWR?
U 1 1 5E3C6360
P 9450 2800
AR Path="/5E3C6360" Ref="#PWR?"  Part="1" 
AR Path="/5E0A3961/5E3C6360" Ref="#PWR?"  Part="1" 
AR Path="/5E0A3961/5E20BE9A/5E3C6360" Ref="#PWR0235"  Part="1" 
F 0 "#PWR0235" H 9450 2650 50  0001 C CNN
F 1 "+5V" H 9465 2973 50  0000 C CNN
F 2 "" H 9450 2800 50  0001 C CNN
F 3 "" H 9450 2800 50  0001 C CNN
	1    9450 2800
	1    0    0    -1  
$EndComp
Wire Wire Line
	9450 2900 9450 2800
Wire Wire Line
	8750 4000 8850 4000
$EndSCHEMATC
