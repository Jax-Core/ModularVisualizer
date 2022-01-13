
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
Text="Gap between consecutive bars"
MeterStyle=Set.String:S | Set.OptionName:S
[Set.Div:3123813]
Meter=Shape
MeterStyle=Set.Div:S
[Option05]
Meter=String
X=r
Text="Stroke width of individual bars"
MeterStyle=Set.String:S | Set.OptionName:S
[Set.Div:3123814]
Meter=Shape
MeterStyle=Set.Div:S
[Option06]
Meter=String
X=r
Text="Corner rounding of individual bars"
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
Text="Rotational angle of visualizer"
MeterStyle=Set.String:S | Set.OptionName:S
[Set.Div:3123817]
Meter=Shape
MeterStyle=Set.Div:S
[Option09]
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

[BarGap]
Meter=Shape
MeterStyle=Set.Textbox:S
Type=Int|0|9000
Y=([Option04:Y]-#Set.P#+(-30/2+8)*[Set.S])
[Value04]
Meter=String
Text=#BarGap# px
MeterStyle=Set.String:S | Set.Value:S

[BarStrokeWidth]
Meter=Shape
MeterStyle=Set.Textbox:S
Type=Int|0|9000
Y=([Option05:Y]-#Set.P#+(-30/2+8)*[Set.S])
[Value05]
Meter=String
Text=#BarStrokeWidth# px
MeterStyle=Set.String:S | Set.Value:S

[CornerRounding]
Meter=Shape
MeterStyle=Set.Textbox:S
Type=Int|0|9000
Y=([Option06:Y]-#Set.P#+(-30/2+8)*[Set.S])
[Value06]
Meter=String
Text=#CornerRounding# px
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

[Angle]
Meter=Shape
MeterStyle=Set.Textbox:S
Type=Int|0|360
Y=([Option08:Y]-#Set.P#+(-30/2+8)*[Set.S])
[Value08]
Meter=String
Text=#Angle# degrees
MeterStyle=Set.String:S | Set.Value:S

[MinimumHeight]
Meter=Shape
MeterStyle=Set.Textbox:S
Type=Int|0|100
Y=([Option09:Y]-#Set.P#+(-30/2+8)*[Set.S])
[Value09]
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