[Variables]
Sec.SaveLocation=#SKINSPATH##Skin.Name#\@Resources\Vars\[#VisualizerType].inc
Sec.SaveLocation2=#SKINSPATH##Skin.Name#\@Resources\Vars.inc
Sec.Generate=0
Sec.AnchorName=AnchorSuppli
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
Ifmatchaction=[!CommandMeasure Crafter "[#VisualizerType]"][!Refresh "#Skin.Name#\Main"]

; ---------------------------------------------------------------------------- ;
;                                    Content                                   ;
; ---------------------------------------------------------------------------- ;

[PrefixTextHeader]
Meter=String
Text="Visualizer type"
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

[VisualizerType:]
Meter=Shape
MeterStyle=Set.Pick3:S
Shape2=Rectangle (100*[Set.S]*([&Func:returnBool('VisualizerType', 'Round')]+[&Func:returnBool('VisualizerType', 'Vector')]*2)),0,(300/3*[Set.S]),(30*[Set.S]),(7*[Set.S]) | Fill Color #Set.Text_Color# | StrokeWidth 0
Y=([Option00:Y]-#Set.P#+(-30/2+8)*[Set.S])
[VisualizerType:0]
Meter=String
Text="Bar"
FontColor=([&Func:returnBool('VisualizerType', 'Bar')] = 1 ? 0 : 255),([&Func:returnBool('VisualizerType', 'Bar')] = 1 ? 0 : 255),([&Func:returnBool('VisualizerType', 'Bar')] = 1 ? 0 : 255)
MeterStyle=Set.String:S | Set.PickOption3_0:S
Leftmouseupaction=[!WriteKeyValue Variables VisualizerType "Bar" "#Sec.SaveLocation2#"][!WriteKeyValue Variables Sec.Generate 1 "#SKINSPATH##SKin.Name#\Core\#Skin.Set_Page#.inc"][!Refresh]
[VisualizerType:1]
Meter=String
Text="Circle"
FontColor=([&Func:returnBool('VisualizerType', 'Round')] = 1 ? 0 : 255),([&Func:returnBool('VisualizerType', 'Round')] = 1 ? 0 : 255),([&Func:returnBool('VisualizerType', 'Round')] = 1 ? 0 : 255)
MeterStyle=Set.String:S | Set.PickOption3_1:S
Leftmouseupaction=[!WriteKeyValue Variables VisualizerType "Round" "#Sec.SaveLocation2#"][!WriteKeyValue Variables Sec.Generate 1 "#SKINSPATH##SKin.Name#\Core\#Skin.Set_Page#.inc"][!Refresh]
[VisualizerType:2]
Meter=String
Text="Vector"
FontColor=([&Func:returnBool('VisualizerType', 'Vector')] = 1 ? 0 : 255),([&Func:returnBool('VisualizerType', 'Vector')] = 1 ? 0 : 255),([&Func:returnBool('VisualizerType', 'Vector')] = 1 ? 0 : 255)
MeterStyle=Set.String:S | Set.PickOption3_2:S
Leftmouseupaction=[!WriteKeyValue Variables VisualizerType "Vector" "#Sec.SaveLocation2#"][!WriteKeyValue Variables Sec.Generate 1 "#SKINSPATH##SKin.Name#\Core\#Skin.Set_Page#.inc"][!Refresh]

[BoostRate]
Meter=Shape
MeterStyle=Set.Bool:S
Y=([Option000:Y]-#Set.P#+(-20/2+8)*[Set.S])
Leftmouseupaction=[!WriteKeyvalue Variables "#CURRENTSECTION#" "([##CURRENTSECTION#] = 1 ? 0 : 1)" "#Sec.SaveLocation2#"][!UpdateMeasure Auto_Refresh:M][!Refresh]

[dimensions]
Meter=String
Text="Visualizer dimensions"
MeterStyle=Set.String:S | Set.OptionCat:S


@includePagePage=#SKINSPATH##Skin.Name#\Core\General\[#VisualizerType]\[#VisualizerType].inc
