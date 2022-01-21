; ---------------------------------------------------------------------------- ;
;                                   Functions                                  ;
; ---------------------------------------------------------------------------- ;
; ---------------------------------------------------------------------------- ;
;                                    Content                                   ;
; ---------------------------------------------------------------------------- ;
[ImageContainer]
Hidden=1
[Image]
Hidden=1

[Title]
Meter=String
Text="Welcome to mVis"
MeterStyle=Sec.String:S | Style.Title:S

[Description.1]
Meter=String
Text="Start by heading over to the layout page and select a pre-built style! Then customize it with the other setting tabs. A tab called render will show up when you select the bar style, which allows you to further modify the look of it."
MeterStyle=Sec.String:S | Style.Description:S
; [Link.1]
; Meter=String
; Text="https://jax-core.github.io/"
; LeftMouseUpAction=["https://jax-core.github.io/"]
; MeterStyle=Sec.String:S | Style.Link:S

[Title2]
Meter=String
y=(#SEt.P#)R
Text="Change log v1.02"
MeterStyle=Sec.String:S | Style.Title:S

[Description.2]
Meter=String
Text="- Visualizers have the reset. Now everytime the widget updates, visualizer layouts are preserved."
MeterStyle=Sec.String:S | Style.Description:S

[Description.3]
Meter=String
Text="- 3D overlay automatic position has been updated to preserve taskbar space"
MeterStyle=Sec.String:S | Style.Description:S

[Description.4]
Meter=String
Text=">>> Please report visualizer not working issues on the Discord server"
MeterStyle=Sec.String:S | Style.Description:S

; [Description.5]
; Meter=String
; Text="- Added Scrollbar and a few bug fixes"
; MeterStyle=Sec.String:S | Style.Description:S

; [Description.6]
; Meter=String
; Y=(#Sec.P#*2)R
; Text="Happy Holidays everyone! This is the biggest update Core has ever received, if you liked it consider leaving a star on the DeviantArt post!"
; MeterStyle=Sec.String:S | Style.Description:S


[DA:]
Meter=Shape
X=(#Sec.W#/2-(#Sec.BottomWidth#*1+#Sec.P#*0)/2)
Y=(#Sec.H#-#Sec.P#-#SEc.BottomHeight#)
LeftMouseUpAction=[!Deactivateconfig]
meterStyle=BottomBox:S | FalseStyleDesk
[DA:String]
Meter=String
StringAlign=CenterCenter
Text=Got it!
MeterStyle=Sec.String:S | BottomText:S
; [DiscordServer:]
; Meter=Shape
; ColorLeave=88, 101, 242,150
; ColorOver=88, 101, 242
; LeftMouseUpAction=["https://discord.gg/JmgehPSDD6"]
; meterStyle=BottomBox:S | FalseStyleDesk
; [DiscordServer:String]
; Meter=String
; StringAlign=CenterCenter
; Text=Join the Discord
; MeterStyle=Sec.String:S | BottomText:S