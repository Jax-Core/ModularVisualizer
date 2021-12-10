[Variables]
Sec.SaveLocation=#SKINSPATH##Skin.Name#\@Resources\Vars\Vector\[#BarType].inc
Sec.SaveLocation2=#SKINSPATH##Skin.Name#\@Resources\Vars\[#VisualizerType].inc

[PrefixTextHeader]
Meter=String
Text="Visualizer filling"
Y=((180+40*#ImageUnderlay#)*[Set.S]+[HeaderImage:H])
FontColor=#Set.Text_Color#,(#ImageUnderlay# = 1 ? 150 : 255)
MeterStyle=Set.String:S | Set.OptionCat:S

[Option01]
Meter=String
X=r
Text="Fill type"
Hidden=#ImageUnderlay#
MeterStyle=Set.String:S | Set.OptionName:S
[Set.Div:3123810]
Meter=Shape
MeterStyle=Set.Div:S
Hidden=#ImageUnderlay#

; -------------------------------- color boxes ------------------------------- ;
[Box]
Shape=Rectangle  0,0,(([ContentContainer:W]-25*5*[Set.S])/5),(([ContentContainer:W]-25*5*[Set.S])/5),(#set.R#/2) | Stroke Color #Set.Text_Color# | Fill Color [##CURRENTSECTION#Color] | Extend Fill
Fill=StrokeWidth 0
X=((([ContentContainer:W]-25*5*[Set.S])/5)+20*[Set.S])r
Y=r
MouseOverAction=[!SetOption #CURRENTSECTION# Fill "StrokeWidth 2"][!UpdateMeter #CURRENTSECTION#][!Redraw]
MouseLeaveAction=[!SetOption #CURRENTSECTION# Fill "StrokeWidth 0"][!UpdateMeter #CURRENTSECTION#][!Redraw]
Leftmouseupaction=["#@#Addons\RainRGB4.exe" "VarName=#CURRENTSECTION#Color" "FileName=#Sec.SaveLocation#" "RefreshConfig=#CURRENTCONFIG#"][!WriteKeyValue Variables Sec.Generate 1 "#SKINSPATH##SKin.Name#\Core\#Skin.Set_Page#.inc"]
DynamicVariables=1
Hidden=#ImageUnderlay#
Container=ContentContainer

[Layer1]
Meter=Shape
X=r
Y=(20*[Set.S])R
MeterStyle=Box
Hidden=(#LayerCount# < 1 || #ImageUnderlay# = 1 ? 1 : 0)
[Layer2]
Meter=Shape
MeterStyle=Box
Hidden=(#LayerCount# < 2 || #ImageUnderlay# = 1 ? 1 : 0)
[Layer3]
Meter=Shape
MeterStyle=Box
Hidden=(#LayerCount# < 3 || #ImageUnderlay# = 1 ? 1 : 0)
[Layer4]
Meter=Shape
MeterStyle=Box
Hidden=(#LayerCount# < 4 || #ImageUnderlay# = 1 ? 1 : 0)
[Layer5]
Meter=Shape
MeterStyle=Box
Hidden=(#LayerCount# < 5 || #ImageUnderlay# = 1 ? 1 : 0)

; ---------------------------------------------------------------------------- ;
;                                   Function                                   ;
; ---------------------------------------------------------------------------- ;

[BarType:]
Meter=Shape
Shape2=Rectangle ([&Func:returnBool('BarType', 'Gradient')] = 0 ? 0 : (150*[Set.S])),0,(150*[Set.S]),(30*[Set.S]),(7*[Set.S]) | Fill Color #Set.Text_Color# | StrokeWidth 0 |
MeterStyle=Set.Pick:S
Y=([Option01:Y]-#Set.P#+(-30/2+8)*[Set.S])
[BarType:0]
Meter=String
Text=Solid
FontColor=[&Func:returnBool('BarType', 'Gradient', '#Set.Text_Color#', '#Set.Pri_color#')]
Leftmouseupaction=[!WriteKeyValue Variables BarType "Solid" "#Sec.SaveLocation2#"][!WriteKeyValue Variables Sec.Generate 1 "#SKINSPATH##SKin.Name#\Core\#Skin.Set_Page#.inc"][!Refresh]
MeterStyle=Set.String:S | Set.PickOption_0:S
[BarType:1]
Meter=String
Text=Gradient
FontColor=[&Func:returnBool('BarType', 'Gradient', '#Set.Pri_color#', '#Set.Text_Color#')]
Leftmouseupaction=[!WriteKeyValue Variables BarType "Gradient" "#Sec.SaveLocation2#"][!WriteKeyValue Variables Sec.Generate 1 "#SKINSPATH##SKin.Name#\Core\#Skin.Set_Page#.inc"][!Refresh]
MeterStyle=Set.String:S | Set.PickOption_1:S

; ---------------------------------------------------------------------------- ;
;                                    Anchor                                    ;
; ---------------------------------------------------------------------------- ;

[AnchorSuppli]
Meter=String
Container=ContentContainer
x=r
Y=R