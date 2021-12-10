[Variables]
Sec.SaveLocation=#SKINSPATH##Skin.Name#\@Resources\Vars\[#VisualizerType]\[#BarType].inc
Sec.SaveLocation2=#SKINSPATH##Skin.Name#\@Resources\Vars\[#VisualizerType].inc
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
Ifmatchaction=[!CommandMeasure Crafter "[#VisualizerType]"]

; ---------------------------------------------------------------------------- ;
;                                    Content                                   ;
; ---------------------------------------------------------------------------- ;


; --------------------------------- Section 2 -------------------------------- ;

[ModHeader]
Meter=String
Text="Bar modifications"
MeterStyle=Set.String:S | Set.OptionCat:S

[Box]
X=(20*[Set.S])R
Y=r
Shape=Rectangle  0,0,(([ContentContainer:W]-120*[Set.S])/5),(([ContentContainer:W]-120*[Set.S])/5),#set.R# | StrokeWidth 0 | Extend Fill
Fill=Fill Color 255,255,255,10
MouseOverAction=[!SetOption #CURRENTSECTION# Fill "Fill Color 255,255,255,30"][!UpdateMeter #CURRENTSECTION#][!Redraw]
MouseLeaveAction=[!SetOption #CURRENTSECTION# Fill "Fill Color 255,255,255,10"][!UpdateMeter #CURRENTSECTION#][!Redraw]
DynamicVariables=1
Container=ContentContainer
[Box:Selected]
X=(20*[Set.S])R
Y=r
Shape=Rectangle  0,0,(([ContentContainer:W]-120*[Set.S])/5),(([ContentContainer:W]-120*[Set.S])/5),#set.R# | StrokeWidth 0 | Extend Fill
Fill=Fill Color 255,255,255,80
DynamicVariables=1
Container=ContentContainer
[BoxImage]
W=(([ContentContainer:W]-120*[Set.S])/5)
H=(([ContentContainer:W]-120*[Set.S])/5)
X=r
Y=r
DynamicVariables=1
Container=ContentContainer
ImageName=#SKINSPATH##Skin.Name#\Core\Render\#CURRENTSECTION#.png
Container=ContentContainer
MaskImageName=#SKINSPATH##Skin.Name#\Core\Render\Mask.png
Leftmouseupaction=[!WriteKeyValue Variables BarType #CURRENTSECTION# "#Sec.SaveLocation2#"][!SetVariable BarType #CURRENTSECTION#][!WriteKeyValue Variables Sec.Generate 1 "#SKINSPATH##SKin.Name#\Core\#Skin.Set_Page#.inc"][!Refresh]

[NormalBox]
Meter=Shape
X=r
Y=(20*[Set.S])R
MeterStyle=Box
[Normal]
Meter=Image
MeterStyle=BoxImage
[ReflectionBox]
Meter=Shape
MeterStyle=Box
[Reflection]
Meter=Image
MeterStyle=BoxImage
[MirrorXBox]
Meter=Shape
MeterStyle=Box
[MirrorX]
Meter=Image
MeterStyle=BoxImage
[MirrorYBox]
Meter=Shape
MeterStyle=Box
[MirrorY]
Meter=Image
MeterStyle=BoxImage
[MirrorXYBox]
Meter=Shape
MeterStyle=Box
[MirrorXY]
Meter=Image
MeterStyle=BoxImage



@includePagePage2=#SKINSPATH##Skin.Name#\Core\General\[#VisualizerType]\BarType\[#BarType].inc
