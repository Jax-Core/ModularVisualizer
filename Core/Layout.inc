[Variables]
Sec.Generate=0
@includeVariables=#SKINSPATH##Skin.Name#\@Resources\Vars\[#VisualizerType].inc
@includeAnalyzer=#SKINSPATH##Skin.Name#\@Resources\Vars\AudioAnalyzerSettings.inc
@includeColors=#SKINSPATH##Skin.Name#\@Resources\Vars\Colors.inc

[Option01]
Meter=String
X=r
Text=Select a layout, this will change your appearance and general settings.
MeterStyle=Set.String:S | Set.OptionName:S

; ---------------------------------------------------------------------------- ;
;                                    Styles                                    ;
; ---------------------------------------------------------------------------- ;

[Preset:M]
Measure=Script
ScriptFile=#@#Lua\PresetLoad.lua

[Select:S]
X=(20*[Set.S])R
Y=r
W=([ContentContainer:W]/3-20*[Set.S])
ImageName=#SKINSPATH##Skin.Name#\Core\Layout\#CURRENTSECTIOn#.png
DynamicVariables=1
ImageAlpha=200
MouseOverAction=[!SetOption #CURRENTSECTION# ImageAlpha "255"][!UpdateMeter #CURRENTSECTION#][!Redraw]
MouseLeaveAction=[!SetOption #CURRENTSECTION# ImageAlpha "200"][!UpdateMeter #CURRENTSECTION#][!Redraw]
Leftmouseupaction=[!CommandMeasure Preset:M "ChangeToFiles('#CURRENTSECTION#')"][!WriteKeyValue Variables Sec.Generate 1 "#SKINSPATH##SKin.Name#\Core\#Skin.Set_Page#.inc"][!Refresh]
DynamicVariables=1
MaskImageName=#SKINSPATH##Skin.Name#\Core\Layout\Mask.png
Container=ContentContainer
[Selected:S]
ImageAlpha=255
MouseOverAction=
MouseLeaveAction=
LeftMouseUpAction=

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

; ---------------------------------------------------------------------------- ;
;                                    Content                                   ;
; ---------------------------------------------------------------------------- ;


[Gradient]
Meter=Image
X=r
Y=(30*[Set.S])R
MeterStyle=Select:S

[Boxes]
Meter=Image
MeterStyle=Select:S

[Regular]
Meter=Image
MeterStyle=Select:S

[Circ]
Meter=Image
X=(20*[Set.S])
Y=(20*[Set.S])R
MeterStyle=Select:S

[Smooth]
Meter=Image
MeterStyle=Select:S

[Subtle]
Meter=Image
MeterStyle=Select:S

[Tech]
Meter=Image
X=(20*[Set.S])
Y=(20*[Set.S])R
MeterStyle=Select:S

[Screen]
Meter=Image
MeterStyle=Select:S
