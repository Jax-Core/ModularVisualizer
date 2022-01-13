[Variables]
Sec.SaveLocation=#SKINSPATH##Skin.Name#\@Resources\Vars\[#VisualizerType].inc
Sec.SaveLocation2=#SKINSPATH##Skin.Name#\@Resources\Vars.inc
Sec.Generate=0
Sec.AnchorName=AnchorSuppli
AutoActivateStatus=0
@includeVariables=#SKINSPATH##Skin.Name#\@Resources\Vars\[#VisualizerType].inc
@includeAnalyzer=#SKINSPATH##Skin.Name#\@Resources\Vars\AudioAnalyzerSettings.inc
@includeColors=#SKINSPATH##Skin.Name#\@Resources\Vars\Colors.inc

; ---------------------------------------------------------------------------- ;
;                                   Functions                                  ;
; ---------------------------------------------------------------------------- ;

[Crafter]
Measure=Plugin
Plugin=PowershellRM
ScriptFile=#SKINSPATH##Skin.Name#\@Resources\Scripts\Crafter.ps1
DynamicVariables=1

[CheckGenerate]
Measure=Calc
IfCondition=#Sec.Generate# = 1
IfTrueAction=[!CommandMeasure Crafter "[#VisualizerType]"]

[Auto_Refresh:M]
OnUpdateAction=[!CommandMeasure Crafter "[#VisualizerType]"][!Refresh "#Skin.Name#\Main"]


[AutoActiveChecker]
Measure=Plugin
Plugin=ConfigActive
ConfigName=#Skin.Name#\Accessories
IfCondition=AutoActiveChecker = 1
IfTrueAction=[!SetVariable AutoActivateStatus 1][!UpdateMeterGroup AutoActivateStatus][!Redraw]
IfFalseAction=[!SetVariable AutoActivateStatus 0][!UpdateMeterGroup AutoActivateStatus][!Redraw]

; ---------------------------------------------------------------------------- ;
;                                    Content                                   ;
; ---------------------------------------------------------------------------- ;

[PrefixTextHeader]
Meter=String
Text="Visualizer behavior"
MeterStyle=Set.String:S | Set.OptionCat:S

[Option00]
Meter=String
X=r
Text="Type of visualizer"
MeterStyle=Set.String:S | Set.OptionName:S
[Set.Div:31238210]
Meter=Shape
MeterStyle=Set.Div:S
[Option000]
Meter=String
X=r
Text="Boost update rate"
MeterStyle=Set.String:S | Set.OptionName:S
[Set.Div:31]
Meter=Shape
MeterStyle=Set.Div:S
[Option0000]
Meter=String
X=r
Text="Automatically toggle visualizer based on media status"
MeterStyle=Set.String:S | Set.OptionName:S

[VisualizerType:]
Meter=Shape
MeterStyle=Set.Pick3:S
Shape2=Rectangle (100*[Set.S]*([&Func:returnBool('VisualizerType', 'Round')]+[&Func:returnBool('VisualizerType', 'Vector')]*2)),0,(300/3*[Set.S]),(30*[Set.S]),(7*[Set.S]) | Fill Color #Set.Text_Color# | StrokeWidth 0
Y=([Option00:Y]-#Set.P#+(-30/2+8)*[Set.S])
[VisualizerType:0]
Meter=String
Text="Bar"
FontColor=[&Func:returnBool('VisualizerType', 'Bar', '#Set.Pri_color#', '#Set.Text_Color#')]
MeterStyle=Set.String:S | Set.PickOption3_0:S
Leftmouseupaction=[!WriteKeyValue Variables VisualizerType "Bar" "#Sec.SaveLocation2#"][!WriteKeyValue Variables Sec.Generate 1 "#SKINSPATH##SKin.Name#\Core\#Skin.Set_Page#.inc"][!Refresh]
[VisualizerType:1]
Meter=String
Text="Circle"
FontColor=[&Func:returnBool('VisualizerType', 'Round', '#Set.Pri_color#', '#Set.Text_Color#')]
MeterStyle=Set.String:S | Set.PickOption3_1:S
Leftmouseupaction=[!WriteKeyValue Variables VisualizerType "Round" "#Sec.SaveLocation2#"][!WriteKeyValue Variables Sec.Generate 1 "#SKINSPATH##SKin.Name#\Core\#Skin.Set_Page#.inc"][!Refresh]
[VisualizerType:2]
Meter=String
Text="Vector"
FontColor=[&Func:returnBool('VisualizerType', 'Vector', '#Set.Pri_color#', '#Set.Text_Color#')]
MeterStyle=Set.String:S | Set.PickOption3_2:S
Leftmouseupaction=[!WriteKeyValue Variables VisualizerType "Vector" "#Sec.SaveLocation2#"][!WriteKeyValue Variables Sec.Generate 1 "#SKINSPATH##SKin.Name#\Core\#Skin.Set_Page#.inc"][!Refresh]

[BoostRate]
Meter=Shape
MeterStyle=Set.Bool:S
Y=([Option000:Y]-#Set.P#+(-20/2+8)*[Set.S])
Leftmouseupaction=[!WriteKeyvalue Variables "#CURRENTSECTION#" "([##CURRENTSECTION#] = 1 ? 0 : 1)" "#Sec.SaveLocation2#"][!UpdateMeasure Auto_Refresh:M][!Refresh]

[AutoActivateStatus]
Meter=Shape
MeterStyle=Set.Bool:S | AutoActivateStatus:#AutoActivateStatus#
Y=([Option0000:Y]-#Set.P#+(-20/2+8)*[Set.S])
Group=AutoActivateStatus
[AutoActivateStatus:0]
Leftmouseupaction=[!ActivateConfig "#Skin.Name#\Accessories"][!UpdateMeasure AutoActiveChecker]
[AutoActivateStatus:1]
Leftmouseupaction=[!DeactivateConfig "#Skin.Name#\Accessories"][!UpdateMeasure AutoActiveChecker]

[dimensions]
Meter=String
Text="Visualizer dimensions"
MeterStyle=Set.String:S | Set.OptionCat:S


@includePagePage=#SKINSPATH##Skin.Name#\Core\General\[#VisualizerType]\[#VisualizerType].inc
