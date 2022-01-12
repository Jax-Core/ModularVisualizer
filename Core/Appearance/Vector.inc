[Variables]
Sec.SaveLocation=#SKINSPATH##Skin.Name#\@Resources\Vars\Vector\[#BarType].inc
Sec.SaveLocation2=#SKINSPATH##Skin.Name#\@Resources\Vars\[#VisualizerType].inc

; ---------------------------------------------------------------------------- ;
;                                   Function                                   ;
; ---------------------------------------------------------------------------- ;

[Input:M]
W=(#Set.W#-#Set.L#-#Set.P#*3-10*[Set.S])
StringAlign=Left
[Sec.GradOptionName:S]
X=(30*[Set.S])
Hidden=(#ImageUnderlay# = 1 || [&Func:returnBool('BarType', 'Solid')] = 1 ? 1 : 0)
[Sec.GradBox:S]
X=r
Y=(10*[Set.S])R
Fill=Stroke Color 255,255,255,50
MouseOverAction=[!SetOption #CURRENTSECTION# Fill "Stroke Color 255,255,255,150"][!UpdateMeter #CURRENTSECTION#][!Redraw]
MouseLeaveAction=[!SetOption #CURRENTSECTION# Fill "Stroke Color 255,255,255,50"][!UpdateMeter #CURRENTSECTION#][!Redraw]
Shape=Rectangle 0,0,(#Set.W#-#Set.L#-#Set.P#*3),(30*[Set.S]),3,3 | StrokeWidth 2 | Fill Color 0,0,0,1 | Extend Fill
Hidden=(#ImageUnderlay# = 1 || [&Func:returnBool('BarType', 'Solid')] = 1 ? 1 : 0)
[Sec.GradText:S]
X=(10*[Set.S])r
StringAlign=LeftCenter
Hidden=(#ImageUnderlay# = 1 || [&Func:returnBool('BarType', 'Solid')] = 1 ? 1 : 0)

; ---------------------------------------------------------------------------- ;
;                                    Content                                   ;
; ---------------------------------------------------------------------------- ;

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
Container=ContentContainer

[Layer1]
Meter=Shape
X=r
Y=(20*[Set.S])R
MeterStyle=Box
Hidden=(#LayerCount# < 1 || #ImageUnderlay# = 1 || [&Func:returnBool('BarType', 'Gradient')] = 1 ? 1 : 0)
[Layer2]
Meter=Shape
MeterStyle=Box
Hidden=(#LayerCount# < 2 || #ImageUnderlay# = 1 || [&Func:returnBool('BarType', 'Gradient')] = 1 ? 1 : 0)
[Layer3]
Meter=Shape
MeterStyle=Box
Hidden=(#LayerCount# < 3 || #ImageUnderlay# = 1 || [&Func:returnBool('BarType', 'Gradient')] = 1 ? 1 : 0)
[Layer4]
Meter=Shape
MeterStyle=Box
Hidden=(#LayerCount# < 4 || #ImageUnderlay# = 1 || [&Func:returnBool('BarType', 'Gradient')] = 1 ? 1 : 0)

; ------------------------------ gradient fields ----------------------------- ;


[Gradient]
Meter=String
Y=R
Text="Gradient customization"
Hidden=(#ImageUnderlay# = 1 || [&Func:returnBool('BarType', 'Solid')] = 1 ? 1 : 0)
MeterStyle=Set.String:S | Set.OptionCat:S

[Option21]
Meter=String
X=(30*[Set.S])
Text="Layer 1 gradient"
MeterStyle=Set.String:S | Set.OptionName:S | Sec.GradOptionName:S
[Layer1Gradient]
Meter=Shape
MeterStyle=Set.Textbox:S | Sec.GradBox:S
[Value21]
Meter=String
Text="#Layer1Gradient#"
MeterStyle=Set.String:S | Set.Value:S | Sec.GradText:S

[Option22]
Meter=String
Text="Layer 2 gradient"
MeterStyle=Set.String:S | Set.OptionName:S | Sec.GradOptionName:S
[Layer2Gradient]
Meter=Shape
MeterStyle=Set.Textbox:S | Sec.GradBox:S
[Value22]
Meter=String
Text="#Layer2Gradient#"
MeterStyle=Set.String:S | Set.Value:S | Sec.GradText:S

[Option23]
Meter=String
Text="Layer 3 gradient"
MeterStyle=Set.String:S | Set.OptionName:S | Sec.GradOptionName:S
[Layer3Gradient]
Meter=Shape
MeterStyle=Set.Textbox:S | Sec.GradBox:S
[Value23]
Meter=String
Text="#Layer3Gradient#"
MeterStyle=Set.String:S | Set.Value:S | Sec.GradText:S

[Option24]
Meter=String
Text="Layer 4 gradient"
MeterStyle=Set.String:S | Set.OptionName:S | Sec.GradOptionName:S
[Layer4Gradient]
Meter=Shape
MeterStyle=Set.Textbox:S | Sec.GradBox:S
[Value24]
Meter=String
Text="#Layer4Gradient#"
MeterStyle=Set.String:S | Set.Value:S | Sec.GradText:S

; ---------------------------------------------------------------------------- ;
;                                   Function                                   ;
; ---------------------------------------------------------------------------- ;


[ImageUnderlay]
Meter=Shape
MeterStyle=Set.Bool:S
Y=([Option10:Y]-#Set.P#+(-20/2+8)*[Set.S])
Leftmouseupaction=[!WriteKeyvalue Variables "#CURRENTSECTION#" "([##CURRENTSECTION#] = 1 ? 0 : 1)" "#Sec.SaveLocation3#"][!SetVariable "#CURRENTSECTION#" "([##CURRENTSECTION#] = 1 ? 0 : 1)"][!UpdateMeasure Auto_Refresh:M][!UpdateMeter *][!Redraw]

[BarType:]
Meter=Shape
Shape2=Rectangle ([&Func:returnBool('BarType', 'Gradient')] = 0 ? 0 : (150*[Set.S])),0,(150*[Set.S]),(30*[Set.S]),(7*[Set.S]) | Fill Color #Set.Text_Color# | StrokeWidth 0 |
MeterStyle=Set.Pick:S
Y=([Option01:Y]-#Set.P#+(-30/2+8)*[Set.S])
Hidden=#ImageUnderlay#
[BarType:0]
Meter=String
Text=Solid
FontColor=[&Func:returnBool('BarType', 'Gradient', '#Set.Text_Color#', '#Set.Pri_color#')]
Leftmouseupaction=[!WriteKeyValue Variables BarType "Solid" "#Sec.SaveLocation2#"][!WriteKeyValue Variables Sec.Generate 1 "#SKINSPATH##SKin.Name#\Core\#Skin.Set_Page#.inc"][!Refresh]
MeterStyle=Set.String:S | Set.PickOption_0:S
Hidden=#ImageUnderlay#
[BarType:1]
Meter=String
Text=Gradient
FontColor=[&Func:returnBool('BarType', 'Gradient', '#Set.Pri_color#', '#Set.Text_Color#')]
Leftmouseupaction=[!WriteKeyValue Variables BarType "Gradient" "#Sec.SaveLocation2#"][!WriteKeyValue Variables Sec.Generate 1 "#SKINSPATH##SKin.Name#\Core\#Skin.Set_Page#.inc"][!Refresh]
MeterStyle=Set.String:S | Set.PickOption_1:S
Hidden=#ImageUnderlay#


[Info:Gradient]
Meter=Shape
MeterStyle=Set.RectButton:S
Y=([Gradient:Y]-#Set.P#+(-30/2+8)*[Set.S])
Hidden=(#ImageUnderlay# = 1 || [&Func:returnBool('BarType', 'Solid')] = 1 ? 1 : 0)
[Info02]
Meter=String
MeterStyle=Set.String:S | Set.Icon:S
Hidden=(#ImageUnderlay# = 1 || [&Func:returnBool('BarType', 'Solid')] = 1 ? 1 : 0)

; ---------------------------------------------------------------------------- ;
;                                    Anchor                                    ;
; ---------------------------------------------------------------------------- ;

[AnchorSuppli]
Meter=String
Container=ContentContainer
x=r
Y=R