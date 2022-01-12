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
Text="Visualizer Y-Offset"
MeterStyle=Set.String:S | Set.OptionName:S
[Set.Div:3123181217]
Meter=Shape
MeterStyle=Set.Div:S
[Option13]
Meter=String
Text="X Mirror X-Offset"
MeterStyle=Set.String:S | Set.OptionName:S
[Set.Div:3123381123213217]
Meter=Shape
MeterStyle=Set.Div:S
[Option14]
Meter=String
Text="X Mirror Y-Offset"
MeterStyle=Set.String:S | Set.OptionName:S
[Set.Div:312381121217]
Meter=Shape
MeterStyle=Set.Div:S
[Option15]
Meter=String
Text="Y Mirror X-Offset"
MeterStyle=Set.String:S | Set.OptionName:S
[Set.Div:3123812122117]
Meter=Shape
MeterStyle=Set.Div:S
[Option16]
Meter=String
Text="Y Mirror Y-Offset"
MeterStyle=Set.String:S | Set.OptionName:S
[Set.Div:3123811121127]
Meter=Shape
MeterStyle=Set.Div:S
[Option17]
Meter=String
Text="XY Mirror X-Offset"
MeterStyle=Set.String:S | Set.OptionName:S
[Set.Div:312213381217]
Meter=Shape
MeterStyle=Set.Div:S
[Option18]
Meter=String
Text="XY Mirror X-Offset"
MeterStyle=Set.String:S | Set.OptionName:S
[Set.Div:31238121192117]
Meter=Shape
MeterStyle=Set.Div:S
[Option19]
Meter=String
Text="Flip Visualizer horizontally"
MeterStyle=Set.String:S | Set.OptionName:S
[Set.Div:31238121202117]
Meter=Shape
MeterStyle=Set.Div:S
[Option20]
Meter=String
Text="Flip Visualizer vertically"
MeterStyle=Set.String:S | Set.OptionName:S
[Set.Div:312381112112217]
Meter=Shape
MeterStyle=Set.Div:S
[Option21]
Meter=String
Text="Flip X Mirror horizontally"
MeterStyle=Set.String:S | Set.OptionName:S
[Set.Div:31221322381217]
Meter=Shape
MeterStyle=Set.Div:S
[Option22]
Meter=String
Text="Flip X Mirror vertically"
MeterStyle=Set.String:S | Set.OptionName:S
[Set.Div:31221323381217]
Meter=Shape
MeterStyle=Set.Div:S
[Option23]
Meter=String
Text="Flip Y Mirror horizontally"
MeterStyle=Set.String:S | Set.OptionName:S
[Set.Div:31238121242117]
Meter=Shape
MeterStyle=Set.Div:S
[Option24]
Meter=String
Text="Flip Y Mirror vertically"
MeterStyle=Set.String:S | Set.OptionName:S
[Set.Div:312381112112257]
Meter=Shape
MeterStyle=Set.Div:S
[Option25]
Meter=String
Text="Flip XY Mirror horizontally"
MeterStyle=Set.String:S | Set.OptionName:S
[Set.Div:31221326381217]
Meter=Shape
MeterStyle=Set.Div:S
[Option26]
Meter=String
Text="Flip XY Mirror vertically"
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

[Group1YOffset]
Meter=Shape
MeterStyle=Set.Textbox:S
Type=Int|-1920|1920
Y=([Option12:Y]-#Set.P#+(-30/2+8)*[Set.S])
[Value12]
Meter=String
Text=#Group1YOffset# px
MeterStyle=Set.String:S | Set.Value:S

[Group2XOffset]
Meter=Shape
MeterStyle=Set.Textbox:S
Type=Int|-1920|1920
Y=([Option13:Y]-#Set.P#+(-30/2+8)*[Set.S])
[Value13]
Meter=String
Text=#Group2XOffset# px
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

[Group3XOffset]
Meter=Shape
MeterStyle=Set.Textbox:S
Type=Int|-1920|1920
Y=([Option15:Y]-#Set.P#+(-30/2+8)*[Set.S])
[Value15]
Meter=String
Text=#Group3XOffset# px
MeterStyle=Set.String:S | Set.Value:S

[Group3YOffset]
Meter=Shape
MeterStyle=Set.Textbox:S
Type=Int|-1920|1920
Y=([Option16:Y]-#Set.P#+(-30/2+8)*[Set.S])
[Value16]
Meter=String
Text=#Group3YOffset# px
MeterStyle=Set.String:S | Set.Value:S

[Group4XOffset]
Meter=Shape
MeterStyle=Set.Textbox:S
Type=Int|-1920|1920
Y=([Option17:Y]-#Set.P#+(-30/2+8)*[Set.S])
[Value17]
Meter=String
Text=#Group4XOffset# px
MeterStyle=Set.String:S | Set.Value:S

[Group4YOffset]
Meter=Shape
MeterStyle=Set.Textbox:S
Type=Int|-1920|1920
Y=([Option18:Y]-#Set.P#+(-30/2+8)*[Set.S])
[Value18]
Meter=String
Text=#Group4YOffset# px
MeterStyle=Set.String:S | Set.Value:S

[Group1XFlip]
Meter=Shape
MeterStyle=Set.Bool:S
Y=([Option19:Y]-#Set.P#+(-20/2+8)*[Set.S])

[Group1YFlip]
Meter=Shape
MeterStyle=Set.Bool:S
Y=([Option20:Y]-#Set.P#+(-20/2+8)*[Set.S])

[Group2XFlip]
Meter=Shape
MeterStyle=Set.Bool:S
Y=([Option21:Y]-#Set.P#+(-20/2+8)*[Set.S])

[Group2YFlip]
Meter=Shape
MeterStyle=Set.Bool:S
Y=([Option22:Y]-#Set.P#+(-20/2+8)*[Set.S])

[Group3XFlip]
Meter=Shape
MeterStyle=Set.Bool:S
Y=([Option23:Y]-#Set.P#+(-20/2+8)*[Set.S])

[Group3YFlip]
Meter=Shape
MeterStyle=Set.Bool:S
Y=([Option24:Y]-#Set.P#+(-20/2+8)*[Set.S])

[Group4XFlip]
Meter=Shape
MeterStyle=Set.Bool:S
Y=([Option25:Y]-#Set.P#+(-20/2+8)*[Set.S])

[Group4YFlip]
Meter=Shape
MeterStyle=Set.Bool:S
Y=([Option26:Y]-#Set.P#+(-20/2+8)*[Set.S])

; ---------------------------------------------------------------------------- ;
;                                    Anchor                                    ;
; ---------------------------------------------------------------------------- ;

[AnchorSuppli]
Meter=String
Container=ContentContainer
x=r
Y=R