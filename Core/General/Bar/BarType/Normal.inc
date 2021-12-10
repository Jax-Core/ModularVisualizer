
[Option10]
Meter=String
X=(35*[Set.S])
Y=([Normal:YH]-#Set.P#/2)
Text="Flip horizontally"
MeterStyle=Set.String:S | Set.OptionName:S
[Set.Div:312381217]
Meter=Shape
MeterStyle=Set.Div:S
[Option11]
Meter=String
Text="Flip vertically"
MeterStyle=Set.String:S | Set.OptionName:S

; ---------------------------------------------------------------------------- ;
;                                     Input                                    ;
; ---------------------------------------------------------------------------- ;

[flipX]
Meter=Shape
MeterStyle=Set.Bool:S
Y=([Option10:Y]-#Set.P#+(-20/2+8)*[Set.S])

[flipY]
Meter=Shape
MeterStyle=Set.Bool:S
Y=([Option11:Y]-#Set.P#+(-20/2+8)*[Set.S])

; ---------------------------------------------------------------------------- ;
;                                    Anchor                                    ;
; ---------------------------------------------------------------------------- ;

[AnchorSuppli]
Meter=String
Container=ContentContainer
x=r
Y=R