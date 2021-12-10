
[Option01]
Meter=String
X=r
Text="Number of vector layers"
MeterStyle=Set.String:S | Set.OptionName:S
[Set.Div:3123810]
Meter=Shape
MeterStyle=Set.Div:S
[Option02]
Meter=String
X=r
Text="Number of vector bands / points"
MeterStyle=Set.String:S | Set.OptionName:S
[Set.Div:3123811]
Meter=Shape
MeterStyle=Set.Div:S
[Option03]
Meter=String
X=r
Text="Width of vector"
MeterStyle=Set.String:S | Set.OptionName:S
[Set.Div:3123812]
Meter=Shape
MeterStyle=Set.Div:S
[Option04]
Meter=String
X=r
Text="Minimum height of vector"
MeterStyle=Set.String:S | Set.OptionName:S
[Set.Div:3123813]
Meter=Shape
MeterStyle=Set.Div:S
[Option05]
Meter=String
X=r
Text="Height of bottom layer"
MeterStyle=Set.String:S | Set.OptionName:S
[Set.Div:3123814]
Meter=Shape
MeterStyle=Set.Div:S
[Option06]
Meter=String
X=r
Text="Height of second bottom layer"
FontColor=#Set.Text_Color#,(#LayerCount# < 2 ? 150 : 255)
MeterStyle=Set.String:S | Set.OptionName:S
[Set.Div:3123815]
Meter=Shape
MeterStyle=Set.Div:S
[Option07]
Meter=String
X=r
Text="Height of second top layer"
FontColor=#Set.Text_Color#,(#LayerCount# < 3 ? 150 : 255)
MeterStyle=Set.String:S | Set.OptionName:S
[Set.Div:3123816]
Meter=Shape
MeterStyle=Set.Div:S
[Option08]
Meter=String
X=r
Text="Height of top layer"
FontColor=#Set.Text_Color#,(#LayerCount# < 4 ? 150 : 255)
MeterStyle=Set.String:S | Set.OptionName:S
[Set.Div:3123817]
Meter=Shape
MeterStyle=Set.Div:S
[Option09]
Meter=String
X=r
Text="Rotational angle of visualizer"
MeterStyle=Set.String:S | Set.OptionName:S

; ---------------------------------------------------------------------------- ;
;                                     Input                                    ;
; ---------------------------------------------------------------------------- ;

[LayerCount]
Meter=Shape
MeterStyle=Set.Textbox:S
Type=Int|1|4
Y=([Option01:Y]-#Set.P#+(-30/2+8)*[Set.S])
[Value01]
Meter=String
Text=#LayerCount# bars
MeterStyle=Set.String:S | Set.Value:S

[VectorBands]
Meter=Shape
MeterStyle=Set.Textbox:S
Type=Int|1|200
Y=([Option02:Y]-#Set.P#+(-30/2+8)*[Set.S])
[Value02]
Meter=String
Text=#VectorBands# px
MeterStyle=Set.String:S | Set.Value:S

[VectorWidth]
Meter=Shape
MeterStyle=Set.Textbox:S
Type=Int|100|10000
Y=([Option03:Y]-#Set.P#+(-30/2+8)*[Set.S])
[Value03]
Meter=String
Text=#VectorWidth# px
MeterStyle=Set.String:S | Set.Value:S

[MinimumHeight]
Meter=Shape
MeterStyle=Set.Textbox:S
Y=([Option04:Y]-#Set.P#+(-30/2+8)*[Set.S])
[Value04]
Meter=String
Text=#MinimumHeight# px
MeterStyle=Set.String:S | Set.Value:S

[Layer1Height]
Meter=Shape
MeterStyle=Set.Textbox:S
Type=Num|#Layer2Height#|1000
Y=([Option05:Y]-#Set.P#+(-30/2+8)*[Set.S])
[Value05]
Meter=String
Text=#Layer1Height# px
MeterStyle=Set.String:S | Set.Value:S

[Layer2Height]
Meter=Shape
MeterStyle=Set.Textbox:S
Type=Num|#Layer3Height#|#Layer1Height#
Hidden=(#LayerCount# < 2 ? 1 : 0)
Y=([Option06:Y]-#Set.P#+(-30/2+8)*[Set.S])
[Value06]
Meter=String
Text=#Layer2Height# px
Hidden=(#LayerCount# < 2 ? 1 : 0)
MeterStyle=Set.String:S | Set.Value:S

[Layer3Height]
Meter=Shape
MeterStyle=Set.Textbox:S
Type=Int|#Layer4Height#|#Layer2Height#
Hidden=(#LayerCount# < 3 ? 1 : 0)
Y=([Option07:Y]-#Set.P#+(-30/2+8)*[Set.S])
[Value07]
Meter=String
Text=#Layer3Height# px
Hidden=(#LayerCount# < 3 ? 1 : 0)
MeterStyle=Set.String:S | Set.Value:S

[Layer4Height]
Meter=Shape
MeterStyle=Set.Textbox:S
Type=Int|0|#Layer3Height#
Hidden=(#LayerCount# < 4 ? 1 : 0)
Y=([Option08:Y]-#Set.P#+(-30/2+8)*[Set.S])
[Value08]
Meter=String
Text=#Layer4Height# px
Hidden=(#LayerCount# < 4 ? 1 : 0)
MeterStyle=Set.String:S | Set.Value:S

[Angle]
Meter=Shape
MeterStyle=Set.Textbox:S
Type=Int|0|360
Y=([Option09:Y]-#Set.P#+(-30/2+8)*[Set.S])
[Value09]
Meter=String
Text=#Angle# degrees
MeterStyle=Set.String:S | Set.Value:S

; ---------------------------------------------------------------------------- ;
;                                    Anchor                                    ;
; ---------------------------------------------------------------------------- ;

[AnchorSuppli]
Meter=String
Container=ContentContainer
x=r
Y=R