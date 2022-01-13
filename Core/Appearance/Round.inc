
[PrefixTextHeader]
Meter=String
Text="Visualizer filling"
Y=((180+40*#ImageUnderlay#)*[Set.S]+[HeaderImage:H])
MeterStyle=Set.String:S | Set.OptionCat:S
Hidden=#ImageUnderlay#

[Option01]
Meter=String
X=r
Text="Number of colors in gradient"
Hidden=#ImageUnderlay#
MeterStyle=Set.String:S | Set.OptionName:S
[Set.Div:3123810]
Meter=Shape
MeterStyle=Set.Div:S
Hidden=#ImageUnderlay#

; -------------------------------- color boxes ------------------------------- ;
[CPUI]
Measure=Script
ScriptFile=#SKINSPATH##Skin.Name#\Core\ColorPickerUI\ColorPickerUI.lua
Animations=0
Theme=Core
OnFinishAction=[!WriteKeyValue Variables Sec.Generate 1 "#SKINSPATH##SKin.Name#\Core\#Skin.Set_Page#.inc"][!Refresh]

[Box]
Shape=Rectangle  0,0,(([ContentContainer:W]-25*7*[Set.S])/7),(([ContentContainer:W]-25*7*[Set.S])/7),(#set.R#/2) | Stroke Color #Set.Text_Color# | Fill Color [#Color#CURRENTSECTION#] | Extend Fill
Fill=StrokeWidth 0
X=((([ContentContainer:W]-25*7*[Set.S])/7)+20*[Set.S])r
Y=r
MouseOverAction=[!SetOption #CURRENTSECTION# Fill "StrokeWidth 2"][!UpdateMeter #CURRENTSECTION#][!Redraw]
MouseLeaveAction=[!SetOption #CURRENTSECTION# Fill "StrokeWidth 0"][!UpdateMeter #CURRENTSECTION#][!Redraw]
Leftmouseupaction=[&CPUI:SetColor('Color[#CURRENTSECTION]', 'Variables', 'rgb', '[#Sec.SaveLocation]')]
DynamicVariables=1
Hidden=#ImageUnderlay#
Container=ContentContainer

[A1]
Meter=Shape
X=r
Y=(20*[Set.S])R
MeterStyle=Box
Hidden=(#ColorCount# < 1 || #ImageUnderlay# = 1 ? 1 : 0)
[A2]
Meter=Shape
MeterStyle=Box
Hidden=(#ColorCount# < 2 || #ImageUnderlay# = 1 ? 1 : 0)
[A3]
Meter=Shape
MeterStyle=Box
Hidden=(#ColorCount# < 3 || #ImageUnderlay# = 1 ? 1 : 0)
[A4]
Meter=Shape
MeterStyle=Box
Hidden=(#ColorCount# < 4 || #ImageUnderlay# = 1 ? 1 : 0)
[A5]
Meter=Shape
MeterStyle=Box
Hidden=(#ColorCount# < 5 || #ImageUnderlay# = 1 ? 1 : 0)
[A6]
Meter=Shape
MeterStyle=Box
Hidden=(#ColorCount# < 6 || #ImageUnderlay# = 1 ? 1 : 0)
[A7]
Meter=Shape
MeterStyle=Box
Hidden=(#ColorCount# < 7 || #ImageUnderlay# = 1 ? 1 : 0)

; ---------------------------------- resume ---------------------------------- ;

[LiveAlpha]
Meter=String
Text="Visualizer live alpha"
Y=((([ContentContainer:W]-25*7*[Set.S])/7)+20*[Set.S]-155*#ImageUnderlay#*[Set.S])r
MeterStyle=Set.String:S | Set.OptionCat:S
[Option02]
Meter=String
X=r
Text="Filling live alpha"
MeterStyle=Set.String:S | Set.OptionName:S
[Set.Div:31238110]
Meter=Shape
MeterStyle=Set.Div:S
[Option03]
Meter=String
X=r
Text="Minimum"
MeterStyle=Set.String:S | Set.OptionName:S
[Set.Div:31238210]
Meter=Shape
MeterStyle=Set.Div:S
[Option04]
Meter=String
X=r
Text="Maximum"
MeterStyle=Set.String:S | Set.OptionName:S
[Set.Div:31238310]
Meter=Shape
MeterStyle=Set.Div:S
[Option05]
Meter=String
X=([ContentContainer:W]/2)
Y=([Option02:Y]-#Set.P#)
Text="Stroke live alpha"
MeterStyle=Set.String:S | Set.OptionName:S
Hidden=#ImageUnderlay#
[Set.Div:31238410]
Meter=Shape
MeterStyle=Set.Div:S
Hidden=#ImageUnderlay#
[Option06]
Meter=String
X=r
Text="Minimum"
MeterStyle=Set.String:S | Set.OptionName:S
Hidden=#ImageUnderlay#
[Set.Div:31238510]
Meter=Shape
MeterStyle=Set.Div:S
Hidden=#ImageUnderlay#
[Option07]
Meter=String
X=r
Text="Maximum"
MeterStyle=Set.String:S | Set.OptionName:S
Hidden=#ImageUnderlay#

[Stroke]
Meter=String
Text="Visualizer stroke"
Y=(50*[Set.S])r
MeterStyle=Set.String:S | Set.OptionCat:S
Hidden=#ImageUnderlay#
[Option21]
Meter=String
Text="Visualizer stroke color"
MeterStyle=Set.String:S | Set.OptionName:S
Hidden=#ImageUnderlay#
; ---------------------------------------------------------------------------- ;
;                                     Input                                    ;
; ---------------------------------------------------------------------------- ;


[ImageUnderlay]
Meter=Shape
MeterStyle=Set.Bool:S
Y=([Option10:Y]-#Set.P#+(-20/2+8)*[Set.S])
Leftmouseupaction=[!WriteKeyvalue Variables "#CURRENTSECTION#" "([##CURRENTSECTION#] = 1 ? 0 : 1)" "#Sec.SaveLocation3#"][!SetVariable "#CURRENTSECTION#" "([##CURRENTSECTION#] = 1 ? 0 : 1)"][!UpdateMeasure Auto_Refresh:M][!UpdateMeter *][!Redraw]


[ColorCount]
Meter=Shape
MeterStyle=Set.Textbox:S
Type=Int|1|7
Y=([Option01:Y]-#Set.P#+(-30/2+8)*[Set.S])
Hidden=#ImageUnderlay#
[Value01]
Meter=String
Text="#ColorCount#"
MeterStyle=Set.String:S | Set.Value:S
Hidden=#ImageUnderlay#

[LiveAlphaBool]
Meter=Shape
MeterStyle=Set.Bool:S
X=([ContentContainer:W]/2-60*[Set.S]-#Set.P#/2)
Y=([Option02:Y]-#Set.P#+(-20/2+8)*[Set.S])

[MinAlpha]
Meter=Shape
MeterStyle=Set.Textbox:S
Type=Int
X=([ContentContainer:W]/2-200*[Set.S]-#Set.P#/2)
Y=([Option03:Y]-#Set.P#+(-30/2+8)*[Set.S])
[Value03]
Meter=String
Text="#MinAlpha#"
MeterStyle=Set.String:S | Set.Value:S

[MaxAlpha]
Meter=Shape
MeterStyle=Set.Textbox:S
Type=Int
X=([ContentContainer:W]/2-200*[Set.S]-#Set.P#/2)
Y=([Option04:Y]-#Set.P#+(-30/2+8)*[Set.S])
[Value04]
Meter=String
Text="#MaxAlpha#"
MeterStyle=Set.String:S | Set.Value:S


[StrokeLiveAlpha]
Meter=Shape
MeterStyle=Set.Bool:S
Y=([Option05:Y]-#Set.P#+(-20/2+8)*[Set.S])
Hidden=#ImageUnderlay#

[StrokeMinAlpha]
Meter=Shape
MeterStyle=Set.Textbox:S
Type=Int
Y=([Option06:Y]-#Set.P#+(-30/2+8)*[Set.S])
Hidden=#ImageUnderlay#
[Value06]
Meter=String
Text="#StrokeMinAlpha#"
MeterStyle=Set.String:S | Set.Value:S
Hidden=#ImageUnderlay#

[StrokeMaxAlpha]
Meter=Shape
MeterStyle=Set.Textbox:S
Type=Int
Y=([Option07:Y]-#Set.P#+(-30/2+8)*[Set.S])
Hidden=#ImageUnderlay#
[Value07]
Meter=String
Text="#StrokeMaxAlpha#"
MeterStyle=Set.String:S | Set.Value:S
Hidden=#ImageUnderlay#

[StrokeColor]
Meter=Shape
MeterStyle=Set.Color:S
Y=([Option21:Y]-#Set.P#+(-30/2+8)*[Set.S])
Hidden=#ImageUnderlay#

; ---------------------------------------------------------------------------- ;
;                                    Anchor                                    ;
; ---------------------------------------------------------------------------- ;

[AnchorSuppli]
Meter=String
Container=ContentContainer
x=r
Y=R