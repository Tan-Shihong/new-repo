*version 9.1 1094382040
u 241
C? 5
R? 8
Q? 4
V? 4
? 2
@libraries
@analysis
.AC 1 3 0
+0 200
+1 1
+2 35k
@targets
@attributes
@translators
a 0 u 13 0 0 0 hln 100 PCBOARDS=PCB
a 0 u 13 0 0 0 hln 100 PSPICE=PSPICE
a 0 u 13 0 0 0 hln 100 XILINX=XILINX
@setup
unconnectedPins 0
connectViaLabel 0
connectViaLocalLabels 0
NoStim4ExtIFPortsWarnings 1
AutoGenStim4ExtIFPorts 1
@index
pageloc 1 0 6882 
@status
n 0 122:03:12:15:58:15;1649750295 e 
s 2832 122:03:12:15:58:15;1649750295 e 
*page 1 0 970 720 iA
@ports
port 133 GND_EARTH 510 410 h
@parts
part 12 Q2N2222 380 240 h
a 0 sp 11 0 25 40 hln 100 PART=Q2N2222
a 0 s 0:13 0 0 0 hln 100 PKGTYPE=TO-18
a 0 s 0:13 0 0 0 hln 100 GATE=
a 0 a 0:13 0 0 0 hln 100 PKGREF=Q1
a 0 ap 9 0 5 5 hln 100 REFDES=Q1
part 14 Q2N2222 660 270 h
a 0 sp 11 0 25 40 hln 100 PART=Q2N2222
a 0 s 0:13 0 0 0 hln 100 PKGTYPE=TO-18
a 0 s 0:13 0 0 0 hln 100 GATE=
a 0 a 0:13 0 0 0 hln 100 PKGREF=Q3
a 0 ap 9 0 5 5 hln 100 REFDES=Q3
part 13 Q2N2222 620 170 h
a 0 sp 11 0 25 40 hln 100 PART=Q2N2222
a 0 s 0:13 0 0 0 hln 100 PKGTYPE=TO-18
a 0 s 0:13 0 0 0 hln 100 GATE=
a 0 a 0:13 0 0 0 hln 100 PKGREF=Q2
a 0 ap 9 0 5 5 hln 100 REFDES=Q2
part 6 r 160 230 h
a 0 sp 0 0 0 10 hlb 100 PART=r
a 0 s 0:13 0 0 0 hln 100 PKGTYPE=RC05
a 0 s 0:13 0 0 0 hln 100 GATE=
a 0 a 0:13 0 0 0 hln 100 PKGREF=R1
a 0 ap 9 0 15 0 hln 100 REFDES=R1
a 0 u 13 0 15 25 hln 100 VALUE=1.8k
part 2 c 260 230 h
a 0 sp 0 0 0 10 hlb 100 PART=c
a 0 s 0:13 0 0 0 hln 100 PKGTYPE=CK05
a 0 s 0:13 0 0 0 hln 100 GATE=
a 0 a 0:13 0 0 0 hln 100 PKGREF=C1
a 0 ap 9 0 15 0 hln 100 REFDES=C1
a 0 u 13 0 15 25 hln 100 VALUE=1.2u
part 3 c 530 170 h
a 0 sp 0 0 0 10 hlb 100 PART=c
a 0 s 0:13 0 0 0 hln 100 PKGTYPE=CK05
a 0 s 0:13 0 0 0 hln 100 GATE=
a 0 a 0:13 0 0 0 hln 100 PKGREF=C2
a 0 ap 9 0 15 0 hln 100 REFDES=C2
a 0 u 13 0 15 25 hln 100 VALUE=1.2u
part 4 c 700 320 h
a 0 sp 0 0 0 10 hlb 100 PART=c
a 0 s 0:13 0 0 0 hln 100 PKGTYPE=CK05
a 0 s 0:13 0 0 0 hln 100 GATE=
a 0 a 0:13 0 0 0 hln 100 PKGREF=C3
a 0 ap 9 0 15 0 hln 100 REFDES=C3
a 0 u 13 0 15 25 hln 100 VALUE=1.2u
part 235 VAC 140 290 h
a 0 sp 0 0 0 50 hln 100 PART=VAC
a 0 a 0:13 0 0 0 hln 100 PKGREF=V3
a 1 ap 9 0 20 10 hcn 100 REFDES=V3
a 0 u 13 0 -9 23 hcn 100 ACMAG=12V
part 5 c 470 400 v
a 0 sp 0 0 0 10 hlb 100 PART=c
a 0 s 0:13 0 0 0 hln 100 PKGTYPE=CK05
a 0 s 0:13 0 0 0 hln 100 GATE=
a 0 a 0:13 0 0 0 hln 100 PKGREF=C4
a 0 ap 9 0 15 0 hln 100 REFDES=C4
a 0 u 13 0 15 40 hln 100 VALUE=1.2u
part 131 VDC 470 120 u
a 0 sp 0 0 22 37 hln 100 PART=VDC
a 0 a 0:13 0 0 0 hln 100 PKGREF=V1
a 1 ap 9 0 24 7 hcn 100 REFDES=V1
a 1 u 13 0 -11 18 hcn 100 DC=12V
part 120 r 780 380 v
a 0 sp 0 0 0 10 hlb 100 PART=r
a 0 s 0:13 0 0 0 hln 100 PKGTYPE=RC05
a 0 s 0:13 0 0 0 hln 100 GATE=
a 0 a 0:13 0 0 0 hln 100 PKGREF=R7
a 0 ap 9 0 15 0 hln 100 REFDES=R7
a 0 u 13 0 15 25 hln 100 VALUE=1M
part 11 r 680 390 v
a 0 sp 0 0 0 10 hlb 100 PART=r
a 0 s 0:13 0 0 0 hln 100 PKGTYPE=RC05
a 0 s 0:13 0 0 0 hln 100 GATE=
a 0 a 0:13 0 0 0 hln 100 PKGREF=R6
a 0 ap 9 0 15 0 hln 100 REFDES=R6
a 0 u 13 0 15 35 hln 100 VALUE=12
part 8 r 340 330 v
a 0 sp 0 0 0 10 hlb 100 PART=r
a 0 s 0:13 0 0 0 hln 100 PKGTYPE=RC05
a 0 s 0:13 0 0 0 hln 100 GATE=
a 0 a 0:13 0 0 0 hln 100 PKGREF=R3
a 0 ap 9 0 15 0 hln 100 REFDES=R3
a 0 u 13 0 15 30 hln 100 VALUE=40k
part 10 r 400 190 v
a 0 sp 0 0 0 10 hlb 100 PART=r
a 0 s 0:13 0 0 0 hln 100 PKGTYPE=RC05
a 0 s 0:13 0 0 0 hln 100 GATE=
a 0 a 0:13 0 0 0 hln 100 PKGREF=R5
a 0 ap 9 0 15 0 hln 100 REFDES=R5
a 0 u 13 0 15 35 hln 100 VALUE=50k
part 9 r 400 330 v
a 0 sp 0 0 0 10 hlb 100 PART=r
a 0 s 0:13 0 0 0 hln 100 PKGTYPE=RC05
a 0 s 0:13 0 0 0 hln 100 GATE=
a 0 a 0:13 0 0 0 hln 100 PKGREF=R4
a 0 ap 9 0 15 0 hln 100 REFDES=R4
a 0 u 13 0 10 40 hln 100 VALUE=5k
part 7 r 340 190 v
a 0 sp 0 0 0 10 hlb 100 PART=r
a 0 s 0:13 0 0 0 hln 100 PKGTYPE=RC05
a 0 s 0:13 0 0 0 hln 100 GATE=
a 0 a 0:13 0 0 0 hln 100 PKGREF=R2
a 0 ap 9 0 15 0 hln 100 REFDES=R2
a 0 u 13 0 15 35 hln 100 VALUE=40k
part 1 titleblk 970 720 h
a 1 s 13 0 350 10 hcn 100 PAGESIZE=A
a 1 s 13 0 180 60 hcn 100 PAGETITLE=
a 1 s 13 0 300 95 hrn 100 PAGENO=1
a 1 s 13 0 340 95 hrn 100 PAGECOUNT=1
part 240 nodeMarker 780 320 h
a 0 s 0 0 0 0 hln 100 PROBEVAR=
a 0 a 0 0 4 22 hlb 100 LABEL=1
@conn
w 97
a 0 up 0:33 0 0 0 hln 100 V=
s 640 270 660 270 98
s 640 190 640 270 96
a 0 up 33 0 642 230 hlt 100 V=
w 93
a 0 up 0:33 0 0 0 hln 100 V=
s 560 170 620 170 94
a 0 up 33 0 590 169 hct 100 V=
w 50
a 0 up 0:33 0 0 0 hln 100 V=
s 520 170 530 170 90
s 520 200 520 170 88
s 400 200 520 200 85
a 0 up 33 0 460 199 hct 100 V=
s 400 200 400 220 87
s 400 190 400 200 49
w 75
a 0 up 0:33 0 0 0 hln 100 V=
s 400 260 400 290 51
a 0 up 33 0 402 275 hlt 100 V=
w 20
a 0 up 0:33 0 0 0 hln 100 V=
s 340 230 340 290 32
a 0 up 33 0 342 260 hlt 100 V=
s 340 230 370 230 31
s 340 190 340 230 27
s 370 240 380 240 23
s 370 230 370 240 21
s 290 230 340 230 19
w 18
a 0 up 0:33 0 0 0 hln 100 V=
s 200 230 260 230 17
a 0 up 33 0 230 229 hct 100 V=
w 228
a 0 up 0:33 0 0 0 hln 100 V=
s 680 250 680 120 227
s 640 120 640 150 153
s 640 120 470 120 127
a 0 up 33 0 555 119 hct 100 V=
s 410 150 400 150 42
s 410 120 410 150 40
s 340 120 340 150 44
s 340 120 410 120 38
s 470 120 410 120 224
s 680 120 640 120 229
w 16
a 0 up 0:33 0 0 0 hln 100 V=
s 140 230 140 290 135
a 0 up 33 0 142 260 hlt 100 V=
s 140 230 160 230 15
w 101
a 0 up 0:33 0 0 0 hln 100 V=
s 680 320 700 320 110
s 680 320 680 350 112
s 680 290 680 320 100
a 0 up 33 0 682 305 hlt 100 V=
w 231
s 470 410 510 410 191
s 400 410 470 410 67
s 470 410 470 400 73
s 400 340 400 410 64
s 400 410 340 410 58
s 400 340 470 340 62
s 400 330 400 340 56
s 140 410 340 410 139
s 340 410 340 330 60
s 470 340 470 370 65
s 140 330 140 410 137
s 680 410 510 410 185
s 680 390 680 410 104
s 940 410 780 410 106
s 780 380 780 410 232
s 940 80 940 410 149
s 470 80 940 80 147
s 780 410 680 410 234
w 161
a 0 up 0:33 0 0 0 hln 100 V=
s 780 340 780 320 181
s 730 320 780 320 113
a 0 up 33 0 755 319 hct 100 V=
@junction
j 410 120
+ w 228
+ w 228
j 780 340
+ p 120 2
+ w 161
j 510 410
+ s 133
+ w 231
j 340 330
+ p 8 1
+ w 231
j 400 410
+ w 231
+ w 231
j 340 410
+ w 231
+ w 231
j 470 370
+ p 5 2
+ w 231
j 400 330
+ p 9 1
+ w 231
j 400 340
+ w 231
+ w 231
j 470 400
+ p 5 1
+ w 231
j 470 410
+ w 231
+ w 231
j 160 230
+ p 6 1
+ w 16
j 730 320
+ p 4 2
+ w 161
j 700 320
+ p 4 1
+ w 101
j 680 290
+ p 14 e
+ w 101
j 680 320
+ w 101
+ w 101
j 660 270
+ p 14 b
+ w 97
j 640 190
+ p 13 e
+ w 97
j 560 170
+ p 3 2
+ w 93
j 620 170
+ p 13 b
+ w 93
j 530 170
+ p 3 1
+ w 50
j 400 220
+ p 12 c
+ w 50
j 400 190
+ p 10 1
+ w 50
j 400 200
+ w 50
+ w 50
j 400 260
+ p 12 e
+ w 75
j 400 290
+ p 9 2
+ w 75
j 340 290
+ p 8 2
+ w 20
j 340 190
+ p 7 1
+ w 20
j 340 230
+ w 20
+ w 20
j 380 240
+ p 12 b
+ w 20
j 290 230
+ p 2 2
+ w 20
j 200 230
+ p 6 2
+ w 18
j 260 230
+ p 2 1
+ w 18
j 680 250
+ p 14 c
+ w 228
j 640 150
+ p 13 c
+ w 228
j 400 150
+ p 10 2
+ w 228
j 340 150
+ p 7 2
+ w 228
j 470 120
+ p 131 +
+ w 228
j 640 120
+ w 228
+ w 228
j 140 290
+ p 235 +
+ w 16
j 140 330
+ p 235 -
+ w 231
j 680 350
+ p 11 2
+ w 101
j 680 390
+ p 11 1
+ w 231
j 470 80
+ p 131 -
+ w 231
j 780 380
+ p 120 1
+ w 231
j 680 410
+ w 231
+ w 231
j 780 410
+ w 231
+ w 231
j 780 320
+ p 240 pin1
+ w 161
@attributes
a 0 s 0:13 0 0 0 hln 100 PAGETITLE=
a 0 s 0:13 0 0 0 hln 100 PAGENO=1
a 0 s 0:13 0 0 0 hln 100 PAGESIZE=A
a 0 s 0:13 0 0 0 hln 100 PAGECOUNT=1
@graphics
