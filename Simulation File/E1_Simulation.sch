*version 9.1 606947062
u 98
R? 7
V? 4
Q? 2
C? 3
? 3
@libraries
@analysis
.AC 1 3 0
+0 200
+1 100
+2 23k
.TRAN 1 0 0 0
+0 0ns
+1 0.005
+3 10u
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
pageloc 1 0 4706 
@status
n 0 122:03:10:14:26:47;1649572007 e 
s 2832 122:03:10:14:27:30;1649572050 e 
*page 1 0 970 720 iA
@ports
port 67 GND_EARTH 430 340 h
@parts
part 2 r 220 240 h
a 0 sp 0 0 0 10 hlb 100 PART=r
a 0 s 0:13 0 0 0 hln 100 PKGTYPE=RC05
a 0 s 0:13 0 0 0 hln 100 GATE=
a 0 a 0:13 0 0 0 hln 100 PKGREF=R1
a 0 ap 9 0 15 0 hln 100 REFDES=R1
part 4 r 480 180 v
a 0 u 13 0 15 40 hln 100 VALUE=220
a 0 sp 0 0 0 10 hlb 100 PART=r
a 0 s 0:13 0 0 0 hln 100 PKGTYPE=RC05
a 0 s 0:13 0 0 0 hln 100 GATE=
a 0 a 0:13 0 0 0 hln 100 PKGREF=R3
a 0 ap 9 0 15 0 hln 100 REFDES=R3
part 6 r 480 310 v
a 0 u 13 0 15 30 hln 100 VALUE=47
a 0 sp 0 0 0 10 hlb 100 PART=r
a 0 s 0:13 0 0 0 hln 100 PKGTYPE=RC05
a 0 s 0:13 0 0 0 hln 100 GATE=
a 0 a 0:13 0 0 0 hln 100 PKGREF=R5
a 0 ap 9 0 15 0 hln 100 REFDES=R5
part 3 r 390 180 v
a 0 sp 0 0 0 10 hlb 100 PART=r
a 0 s 0:13 0 0 0 hln 100 PKGTYPE=RC05
a 0 s 0:13 0 0 0 hln 100 GATE=
a 0 a 0:13 0 0 0 hln 100 PKGREF=R2
a 0 ap 9 0 15 0 hln 100 REFDES=R2
a 0 u 13 0 15 30 hln 100 VALUE=10k
part 5 r 390 300 v
a 0 u 13 0 20 35 hln 100 VALUE=2.2k
a 0 sp 0 0 0 10 hlb 100 PART=r
a 0 s 0:13 0 0 0 hln 100 PKGTYPE=RC05
a 0 s 0:13 0 0 0 hln 100 GATE=
a 0 a 0:13 0 0 0 hln 100 PKGREF=R4
a 0 ap 9 0 15 0 hln 100 REFDES=R4
part 75 c 560 210 h
a 0 u 13 0 15 25 hln 100 VALUE=1u
a 0 sp 0 0 0 10 hlb 100 PART=c
a 0 s 0:13 0 0 0 hln 100 PKGTYPE=CK05
a 0 s 0:13 0 0 0 hln 100 GATE=
a 0 a 0:13 0 0 0 hln 100 PKGREF=C2
a 0 ap 9 0 15 0 hln 100 REFDES=C2
part 7 VDC 440 90 u
a 1 u 13 0 -11 18 hcn 100 DC=12V
a 0 sp 0 0 22 37 hln 100 PART=VDC
a 0 a 0:13 0 0 0 hln 100 PKGREF=V1
a 1 ap 9 0 24 7 hcn 100 REFDES=V1
part 10 Q2N2222 460 240 h
a 0 sp 11 0 25 40 hln 100 PART=Q2N2222
a 0 s 0:13 0 0 0 hln 100 PKGTYPE=TO-18
a 0 s 0:13 0 0 0 hln 100 GATE=
a 0 a 0:13 0 0 0 hln 100 PKGREF=Q1
a 0 ap 9 0 5 5 hln 100 REFDES=Q1
part 72 c 300 240 h
a 0 u 13 0 15 25 hln 100 VALUE=1u
a 0 sp 0 0 0 10 hlb 100 PART=c
a 0 s 0:13 0 0 0 hln 100 PKGTYPE=CK05
a 0 s 0:13 0 0 0 hln 100 GATE=
a 0 a 0:13 0 0 0 hln 100 PKGREF=C1
a 0 ap 9 0 15 0 hln 100 REFDES=C1
part 97 VAC 160 270 h
a 0 sp 0 0 0 50 hln 100 PART=VAC
a 0 a 0:13 0 0 0 hln 100 PKGREF=V3
a 1 ap 9 0 20 10 hcn 100 REFDES=V3
a 0 u 13 0 -9 23 hcn 100 ACMAG=0.5V
part 8 r 640 300 v
a 0 sp 0 0 0 10 hlb 100 PART=r
a 0 s 0:13 0 0 0 hln 100 PKGTYPE=RC05
a 0 s 0:13 0 0 0 hln 100 GATE=
a 0 a 0:13 0 0 0 hln 100 PKGREF=R6
a 0 ap 9 0 15 0 hln 100 REFDES=R6
a 0 u 13 0 15 40 hln 100 VALUE=1M
part 1 titleblk 970 720 h
a 1 s 13 0 350 10 hcn 100 PAGESIZE=A
a 1 s 13 0 180 60 hcn 100 PAGETITLE=
a 1 s 13 0 300 95 hrn 100 PAGENO=1
a 1 s 13 0 340 95 hrn 100 PAGECOUNT=1
part 84 nodeMarker 640 210 h
a 0 s 0 0 0 0 hln 100 PROBEVAR=
a 0 a 0 0 4 22 hlb 100 LABEL=2
@conn
w 28
a 0 up 0:33 0 0 0 hln 100 V=
s 480 260 480 270 27
a 0 up 33 0 482 265 hlt 100 V=
w 78
a 0 up 0:33 0 0 0 hln 100 V=
s 480 210 560 210 47
a 0 up 33 0 520 209 hct 100 V=
s 480 180 480 210 25
s 480 210 480 220 57
w 79
a 0 up 0:33 0 0 0 hln 100 V=
s 260 240 300 240 11
a 0 up 33 0 280 239 hct 100 V=
w 54
a 0 up 0:33 0 0 0 hln 100 V=
s 640 210 640 260 55
s 590 210 640 210 77
a 0 up 33 0 615 209 hct 100 V=
w 20
a 0 up 0:33 0 0 0 hln 100 V=
s 390 140 390 100 19
s 480 100 480 140 23
s 390 100 440 100 60
a 0 up 33 0 415 99 hct 100 V=
s 440 100 480 100 92
s 440 90 440 100 88
w 14
a 0 up 0:33 0 0 0 hln 100 V=
s 390 260 390 240 68
a 0 up 33 0 392 220 hlt 100 V=
s 330 240 390 240 74
a 0 up 33 0 395 239 hct 100 V=
s 390 240 390 180 95
s 390 240 460 240 96
w 62
a 0 up 0:33 0 0 0 hln 100 V=
s 90 340 160 340 31
s 480 340 480 310 33
s 480 340 640 340 43
s 640 340 640 300 45
s 390 340 430 340 70
s 390 300 390 340 29
s 160 340 390 340 82
s 160 310 160 340 39
s 430 340 480 340 86
s 440 50 90 50 61
a 0 up 33 0 265 49 hct 100 V=
s 90 50 90 340 63
w 36
a 0 up 0:33 0 0 0 hln 100 V=
s 220 240 160 240 35
a 0 up 33 0 190 239 hct 100 V=
s 160 240 160 270 37
@junction
j 260 240
+ p 2 2
+ w 79
j 390 140
+ p 3 2
+ w 20
j 480 140
+ p 4 2
+ w 20
j 480 270
+ p 6 2
+ w 28
j 480 260
+ p 10 e
+ w 28
j 220 240
+ p 2 1
+ w 36
j 480 340
+ w 62
+ w 62
j 480 180
+ p 4 1
+ w 78
j 480 220
+ p 10 c
+ w 78
j 480 210
+ w 78
+ w 78
j 640 260
+ p 8 2
+ w 54
j 480 310
+ p 6 1
+ w 62
j 640 300
+ p 8 1
+ w 62
j 390 300
+ p 5 1
+ w 62
j 390 340
+ w 62
+ w 62
j 390 260
+ p 5 2
+ w 14
j 390 180
+ p 3 1
+ w 14
j 300 240
+ p 72 1
+ w 79
j 560 210
+ p 75 1
+ w 78
j 590 210
+ p 75 2
+ w 54
j 160 340
+ w 62
+ w 62
j 640 210
+ p 84 pin1
+ w 54
j 430 340
+ s 67
+ w 62
j 440 50
+ p 7 -
+ w 62
j 440 90
+ p 7 +
+ w 20
j 440 100
+ w 20
+ w 20
j 460 240
+ p 10 b
+ w 14
j 330 240
+ p 72 2
+ w 14
j 390 240
+ w 14
+ w 14
j 160 310
+ p 97 -
+ w 62
j 160 270
+ p 97 +
+ w 36
@attributes
a 0 s 0:13 0 0 0 hln 100 PAGETITLE=
a 0 s 0:13 0 0 0 hln 100 PAGENO=1
a 0 s 0:13 0 0 0 hln 100 PAGESIZE=A
a 0 s 0:13 0 0 0 hln 100 PAGECOUNT=1
@graphics
