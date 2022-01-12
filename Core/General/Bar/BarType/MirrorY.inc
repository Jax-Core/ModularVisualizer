[Option11]
Meter=String
X=(35*[Set.S])
Y=([Normal:YH]-#Set.P#/2)
Text="Visualizer X-Offset"
MeterStyle=Set.String:S | Set.OptionName:S
[Set.Div:3123812217]
Meter=Shape
MeterStyle=Set.Div:S
[Option12]
Meter=String
Text="Mirrored X-Offset"
MeterStyle=Set.String:S | Set.OptionName:S
[Set.Div:3123181217]
Meter=Shape
MeterStyle=Set.Div:S
[Option13]
Meter=String
Text="Visualizer Y-Offset"
MeterStyle=Set.String:S | Set.OptionName:S
[Set.Div:3123381123213217]
Meter=Shape
MeterStyle=Set.Div:S
[Option14]
Meter=String
Text="Mirrored Y-Offset"
MeterStyle=Set.String:S | Set.OptionName:S
[Set.Div:312381121217]
Meter=Shape
MeterStyle=Set.Div:S
[Option15]
Meter=String
Text="Visualizer: Flip horizontally"
MeterStyle=Set.String:S | Set.OptionName:S
[Set.Div:3123812122117]
Meter=Shape
MeterStyle=Set.Div:S
[Option16]
Meter=String
Text="Visualizer: Flip vertically"
MeterStyle=Set.String:S | Set.OptionName:S
[Set.Div:3123811121127]
Meter=Shape
MeterStyle=Set.Div:S
[Option17]
Meter=String
Text="Mirrored: Flip horizontally"
MeterStyle=Set.String:S | Set.OptionName:S
[Set.Div:312213381217]
Meter=Shape
MeterStyle=Set.Div:S
[Option18]
Meter=String
Text="Mirrored: Flip vertically"
MeterStyle=Set.String:S | Set.OptionName:S

; ---------------------------------------------------------------------------- ;
;                                     Input                                    ;
; ---------------------------------------------------------------------------- ;

[Group1XOffset]
Meter=Shape
MeterStyle=Set.Textbox:S
Type=Int|-1920|1920
Y=([Option11:Y]-#Set.P#+(-30/2+8)*[Set.S])
[Value11]
Meter=String
Text=#Group1XOffset# px
MeterStyle=Set.String:S | Set.Value:S

[Group2XOffset]
Meter=Shape
MeterStyle=Set.Textbox:S
Type=Int|-1920|1920
Y=([Option12:Y]-#Set.P#+(-30/2+8)*[Set.S])
[Value12]
Meter=String
Text=#Group2XOffset# px
MeterStyle=Set.String:S | Set.Value:S

[Group1YOffset]
Meter=Shape
MeterStyle=Set.Textbox:S
Type=Int|-1920|1920
Y=([Option13:Y]-#Set.P#+(-30/2+8)*[Set.S])
[Value13]
Meter=String
Text=#Group1YOffset# px
MeterStyle=Set.String:S | Set.Value:S

[Group2YOffset]
Meter=Shape
MeterStyle=Set.Textbox:S
Type=Int|-1920|1920
Y=([Option14:Y]-#Set.P#+(-30/2+8)*[Set.S])
[Value14]
Meter=String
Text=#Group2YOffset# px
MeterStyle=Set.String:S | Set.Value:S

[Group1XFlip]
Meter=Shape
MeterStyle=Set.Bool:S
Y=([Option15:Y]-#Set.P#+(-20/2+8)*[Set.S])

[Group1YFlip]
Meter=Shape
MeterStyle=Set.Bool:S
Y=([Option16:Y]-#Set.P#+(-20/2+8)*[Set.S])

[Group2XFlip]
Meter=Shape
MeterStyle=Set.Bool:S
Y=([Option17:Y]-#Set.P#+(-20/2+8)*[Set.S])

[Group2YFlip]
Meter=Shape
MeterStyle=Set.Bool:S
Y=([Option18:Y]-#Set.P#+(-20/2+8)*[Set.S])

; ---------------------------------------------------------------------------- ;
;                                    Anchor                                    ;
; ---------------------------------------------------------------------------- ;

[AnchorSuppli]
Meter=String
Container=ContentContainer
x=r
Y=R