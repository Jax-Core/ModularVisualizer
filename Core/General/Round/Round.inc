
[Option01]
Meter=String
X=r
Text="Number of bars"
MeterStyle=Set.String:S | Set.OptionName:S
[Set.Div:3123810]
Meter=Shape
MeterStyle=Set.Div:S
[Option02]
Meter=String
X=r
Text="Height of bars"
MeterStyle=Set.String:S | Set.OptionName:S
[Set.Div:3123811]
Meter=Shape
MeterStyle=Set.Div:S
[Option03]
Meter=String
X=r
Text="Width of individual bars"
MeterStyle=Set.String:S | Set.OptionName:S
[Set.Div:3123812]
Meter=Shape
MeterStyle=Set.Div:S
[Option04]
Meter=String
X=r
Text="Radius of circle"
MeterStyle=Set.String:S | Set.OptionName:S
[Set.Div:3123813]
Meter=Shape
MeterStyle=Set.Div:S
[Option05]
Meter=String
X=r
Text="Starting angle"
MeterStyle=Set.String:S | Set.OptionName:S
[Set.Div:3123814]
Meter=Shape
MeterStyle=Set.Div:S
[Option06]
Meter=String
X=r
Text="Draw angle"
MeterStyle=Set.String:S | Set.OptionName:S
[Set.Div:3123815]
Meter=Shape
MeterStyle=Set.Div:S
[Option07]
Meter=String
X=r
Text="Pixels for bars to go up while visualizing"
MeterStyle=Set.String:S | Set.OptionName:S
[Set.Div:3123816]
Meter=Shape
MeterStyle=Set.Div:S
[Option08]
Meter=String
X=r
Text="Bar inside cap"
MeterStyle=Set.String:S | Set.OptionName:S
[Set.Div:3123817]
Meter=Shape
MeterStyle=Set.Div:S
[Option09]
Meter=String
X=r
Text="Bar outside cap"
MeterStyle=Set.String:S | Set.OptionName:S
[Set.Div:3123818]
Meter=Shape
MeterStyle=Set.Div:S
[Option10]
Meter=String
X=r
Text="Minimum height of individual bars"
MeterStyle=Set.String:S | Set.OptionName:S

; ---------------------------------------------------------------------------- ;
;                                     Input                                    ;
; ---------------------------------------------------------------------------- ;

[Bands]
Meter=Shape
MeterStyle=Set.Textbox:S
Type=Int|1|9000
Y=([Option01:Y]-#Set.P#+(-30/2+8)*[Set.S])
[Value01]
Meter=String
Text=#Bands# bars
MeterStyle=Set.String:S | Set.Value:S

[Height]
Meter=Shape
MeterStyle=Set.Textbox:S
Type=Int|0|9000
Y=([Option02:Y]-#Set.P#+(-30/2+8)*[Set.S])
[Value02]
Meter=String
Text=#Height# px
MeterStyle=Set.String:S | Set.Value:S

[BarWidth]
Meter=Shape
MeterStyle=Set.Textbox:S
Type=Int|1|9000
Y=([Option03:Y]-#Set.P#+(-30/2+8)*[Set.S])
[Value03]
Meter=String
Text=#BarWidth# px
MeterStyle=Set.String:S | Set.Value:S

[Radius]
Meter=Shape
MeterStyle=Set.Textbox:S
Y=([Option04:Y]-#Set.P#+(-30/2+8)*[Set.S])
[Value04]
Meter=String
Text=#Radius# px
MeterStyle=Set.String:S | Set.Value:S

[StartAngle]
Meter=Shape
MeterStyle=Set.Textbox:S
Type=Num|0|360
Y=([Option05:Y]-#Set.P#+(-30/2+8)*[Set.S])
[Value05]
Meter=String
Text=#StartAngle# degrees
MeterStyle=Set.String:S | Set.Value:S

[TotalAngle]
Meter=Shape
MeterStyle=Set.Textbox:S
Type=Num|0|9000
Y=([Option06:Y]-#Set.P#+(-30/2+8)*[Set.S])
[Value06]
Meter=String
Text=#TotalAngle# degrees
MeterStyle=Set.String:S | Set.Value:S

[Levitate]
Meter=Shape
MeterStyle=Set.Textbox:S
Type=Int|0|9000
Y=([Option07:Y]-#Set.P#+(-30/2+8)*[Set.S])
[Value07]
Meter=String
Text=#Levitate# px
MeterStyle=Set.String:S | Set.Value:S

[StartCap:]
Meter=Shape
MeterStyle=Set.Pick3:S
Shape2=Rectangle (100*[Set.S]*([&Func:returnBool('StartCap', 'Round')]+[&Func:returnBool('StartCap', 'Flat')]*2)),0,(300/3*[Set.S]),(30*[Set.S]),(7*[Set.S]) | Fill Color #Set.Text_Color# | StrokeWidth 0
Y=([Option08:Y]-#Set.P#+(-30/2+8)*[Set.S])
[StartCap:0]
Meter=String
Text="Triangle"
FontColor=[&Func:returnBool('StartCap', 'Triangle', '#Set.Pri_color#', '#Set.Text_Color#')]
MeterStyle=Set.String:S | Set.PickOption3_0:S
Leftmouseupaction=[!WriteKeyValue Variables StartCap "Triangle" "#Sec.SaveLocation#"][!WriteKeyValue Variables Sec.Generate 1 "#SKINSPATH##SKin.Name#\Core\#Skin.Set_Page#.inc"][!Refresh]
[StartCap:1]
Meter=String
Text="Round"
FontColor=[&Func:returnBool('StartCap', 'Round', '#Set.Pri_color#', '#Set.Text_Color#')]
MeterStyle=Set.String:S | Set.PickOption3_1:S
Leftmouseupaction=[!WriteKeyValue Variables StartCap "Round" "#Sec.SaveLocation#"][!WriteKeyValue Variables Sec.Generate 1 "#SKINSPATH##SKin.Name#\Core\#Skin.Set_Page#.inc"][!Refresh]
[StartCap:2]
Meter=String
Text="Flat"
FontColor=[&Func:returnBool('StartCap', 'Flat', '#Set.Pri_color#', '#Set.Text_Color#')]
MeterStyle=Set.String:S | Set.PickOption3_2:S
Leftmouseupaction=[!WriteKeyValue Variables StartCap "Flat" "#Sec.SaveLocation#"][!WriteKeyValue Variables Sec.Generate 1 "#SKINSPATH##SKin.Name#\Core\#Skin.Set_Page#.inc"][!Refresh]

[EndCap:]
Meter=Shape
MeterStyle=Set.Pick3:S
Shape2=Rectangle (100*[Set.S]*([&Func:returnBool('EndCap', 'Round')]+[&Func:returnBool('EndCap', 'Flat')]*2)),0,(300/3*[Set.S]),(30*[Set.S]),(7*[Set.S]) | Fill Color #Set.Text_Color# | StrokeWidth 0
Y=([Option09:Y]-#Set.P#+(-30/2+8)*[Set.S])
[EndCap:0]
Meter=String
Text="Triangle"
FontColor=[&Func:returnBool('EndCap', 'Triangle', '#Set.Pri_color#', '#Set.Text_Color#')]
MeterStyle=Set.String:S | Set.PickOption3_0:S
Leftmouseupaction=[!WriteKeyValue Variables EndCap "Triangle" "#Sec.SaveLocation#"][!WriteKeyValue Variables Sec.Generate 1 "#SKINSPATH##SKin.Name#\Core\#Skin.Set_Page#.inc"][!Refresh]
[EndCap:1]
Meter=String
Text="Round"
FontColor=[&Func:returnBool('EndCap', 'Round', '#Set.Pri_color#', '#Set.Text_Color#')]
MeterStyle=Set.String:S | Set.PickOption3_1:S
Leftmouseupaction=[!WriteKeyValue Variables EndCap "Round" "#Sec.SaveLocation#"][!WriteKeyValue Variables Sec.Generate 1 "#SKINSPATH##SKin.Name#\Core\#Skin.Set_Page#.inc"][!Refresh]
[EndCap:2]
Meter=String
Text="Flat"
FontColor=[&Func:returnBool('EndCap', 'Flat', '#Set.Pri_color#', '#Set.Text_Color#')]
MeterStyle=Set.String:S | Set.PickOption3_2:S
Leftmouseupaction=[!WriteKeyValue Variables EndCap "Flat" "#Sec.SaveLocation#"][!WriteKeyValue Variables Sec.Generate 1 "#SKINSPATH##SKin.Name#\Core\#Skin.Set_Page#.inc"][!Refresh]

[MinimumHeight]
Meter=Shape
MeterStyle=Set.Textbox:S
Type=Int|0|100
Y=([Option10:Y]-#Set.P#+(-30/2+8)*[Set.S])
[Value10]
Meter=String
Text=#MinimumHeight# px
MeterStyle=Set.String:S | Set.Value:S

; ---------------------------------------------------------------------------- ;
;                                    Anchor                                    ;
; ---------------------------------------------------------------------------- ;

[AnchorSuppli]
Meter=String
Container=ContentContainer
x=r
Y=R