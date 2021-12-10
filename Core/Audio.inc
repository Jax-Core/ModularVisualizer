[Variables]
Sec.SaveLocation=#SKINSPATH##Skin.Name#\@Resources\Vars\AudioAnalyzerSettings.inc
Sec.SaveLocation2=#SKINSPATH##Skin.Name#\@Resources\Vars.inc
Sec.Generate=1
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
IfCondition=#Sec.Generate# = 0
IfTrueAction=[!CommandMeasure PRM ListAudioDevices][!WriteKeyValue Variables Sec.Generate 1 "#SKINSPATH##SKin.Name#\Core\#Skin.Set_Page#.inc"]

[Auto_Refresh:M]
Ifmatchaction=[!CommandMeasure Crafter "[#VisualizerType]"][!Refresh "#Skin.Name#\Main"]

[PRM]
Measure=Plugin
Plugin=PowershellRM
ScriptFile=#SKINSPATH##Skin.Name#\@Resources\Scripts\GetAudioDevices.ps1

; ---------------------------------------------------------------------------- ;
;                                    Styles                                    ;
; ---------------------------------------------------------------------------- ;

[Device:S]
X=(35*[Set.S])
Y=(25*[Set.S])r
OverColor=100,100,100,200
LeaveColor=100,100,100,100
DynamicVariables=1
Shape=Rectangle 0,0,([ContentContainer:W]-35*[Set.S]),(30*[Set.S]),3,3 | StrokeWidth 0 | Extend Fill
Fill=Fill Color [&Func:LocalVar('#CURRENTSECTION#', 'LeaveColor')]
MouseOverAction=[!SetOption #CURRENTSECTION# Fill "Fill Color [&Func:LocalVar('#CURRENTSECTION#', 'OverColor')]"][!UpdateMeter #CURRENTSECTION#][!Redraw]
MouseLeaveAction=[!SetOption #CURRENTSECTION# Fill "Fill Color [&Func:LocalVar('#CURRENTSECTION#', 'LeaveColor')]"][!UpdateMeter #CURRENTSECTION#][!Redraw]
Container=ContentContainer
[DeviceName:S]
X=(([ContentContainer:W]-35*[Set.S])/2*[Set.S])r
Y=(15*[Set.S])r
StringAlign=CenterCenter
FontSize=(10*[Set.S])
Container=ContentContainer
DynamicVariables=1

; ---------------------------------------------------------------------------- ;
;                                    Content                                   ;
; ---------------------------------------------------------------------------- ;

[Option00]
Meter=String
X=(30*[Set.S])
Text="Select a type of device for audio"
MeterStyle=Set.String:S | Set.OptionName:S
[Set.Div:312382109122]
Meter=Shape
MeterStyle=Set.Div:S

@includeAudio=#SKINSPATH##Skin.Name#\Core\audio\DeviceList#AnalyzerPortIsID#.inc

[PrefixTextHeader]
Meter=String
Text="Audio sampling"
MeterStyle=Set.String:S | Set.OptionCat:S
[Option01]
Meter=String
X=r
Text="Maximum Sensititvity"
MeterStyle=Set.String:S | Set.OptionName:S
[Set.Div:3123821092]
Meter=Shape
MeterStyle=Set.Div:S
[Option02]
Meter=String
X=r
Text="Minimum Sensititvity"
MeterStyle=Set.String:S | Set.OptionName:S
[Set.Div:3123821093]
Meter=Shape
MeterStyle=Set.Div:S
[Option03]
Meter=String
X=r
Text="Rising delay (ms)"
MeterStyle=Set.String:S | Set.OptionName:S
[Set.Div:3123821094]
Meter=Shape
MeterStyle=Set.Div:S
[Option04]
Meter=String
X=r
Text="Falling delay (ms)"
MeterStyle=Set.String:S | Set.OptionName:S
[Set.Div:3123821095]
Meter=Shape
MeterStyle=Set.Div:S
[Option05]
Meter=String
X=r
Text="Smoothing level"
MeterStyle=Set.String:S | Set.OptionName:S

; ---------------------------------------------------------------------------- ;
;                                     Stuff                                    ;
; ---------------------------------------------------------------------------- ;

[AnalyzerPort:]
Meter=Shape
MeterStyle=Set.Pick3:S
Shape2=Rectangle (100*[Set.S]*([&Func:returnBool('AnalyzerPort', 'DefaultInput')]+#AnalyzerPortIsID#*2)),0,(300/3*[Set.S]),(30*[Set.S]),(7*[Set.S]) | Fill Color #Set.Text_Color# | StrokeWidth 0
Y=([Option00:Y]-#Set.P#+(-30/2+8)*[Set.S])
[AnalyzerPort:0]
Meter=String
Text="Output"
FontColor=([&Func:returnBool('AnalyzerPort', 'DefaultOutput')] = 1 ? 0 : 255),([&Func:returnBool('AnalyzerPort', 'DefaultOutput')] = 1 ? 0 : 255),([&Func:returnBool('AnalyzerPort', 'DefaultOutput')] = 1 ? 0 : 255)
MeterStyle=Set.String:S | Set.PickOption3_0:S
Leftmouseupaction=[!WriteKeyValue Variables AnalyzerPort "DefaultOutput" "#Sec.SaveLocation2#"][!WriteKeyValue Variables AnalyzerPortIsID "0" "#Sec.SaveLocation2#"][!WriteKeyValue Variables Sec.Generate 1 "#SKINSPATH##SKin.Name#\Core\#Skin.Set_Page#.inc"][!UpdateMeasure "Auto_Refresh:M"][!Refresh]
[AnalyzerPort:1]
Meter=String
Text="Input"
FontColor=([&Func:returnBool('AnalyzerPort', 'DefaultInput')] = 1 ? 0 : 255),([&Func:returnBool('AnalyzerPort', 'DefaultInput')] = 1 ? 0 : 255),([&Func:returnBool('AnalyzerPort', 'DefaultInput')] = 1 ? 0 : 255)
MeterStyle=Set.String:S | Set.PickOption3_1:S
Leftmouseupaction=[!WriteKeyValue Variables AnalyzerPort "DefaultInput" "#Sec.SaveLocation2#"][!WriteKeyValue Variables AnalyzerPortIsID "0" "#Sec.SaveLocation2#"][!WriteKeyValue Variables Sec.Generate 1 "#SKINSPATH##SKin.Name#\Core\#Skin.Set_Page#.inc"][!UpdateMeasure "Auto_Refresh:M"][!Refresh]
[AnalyzerPort:2]
Meter=String
Text="Device"
FontColor=(#AnalyzerPortIsID# = 1 ? 0 : 255),(#AnalyzerPortIsID# = 1 ? 0 : 255),(#AnalyzerPortIsID# = 1 ? 0 : 255)
MeterStyle=Set.String:S | Set.PickOption3_2:S
Leftmouseupaction=[!WriteKeyValue Variables AnalyzerPort "ID: [#*DeviceID*]" "#Sec.SaveLocation2#"][!WriteKeyValue Variables AnalyzerPortIsID "1" "#Sec.SaveLocation2#"][!CommandMeasure PRM ListAudioDevices][!WriteKeyValue Variables Sec.Generate 1 "#SKINSPATH##SKin.Name#\Core\#Skin.Set_Page#.inc"][!UpdateMeasure "Auto_Refresh:M"][!Refresh]

[MaxSensitivity]
Meter=Shape
MeterStyle=Set.Textbox:S
Type=Int|#MinSensitivity#|100
Y=([Option01:Y]-#Set.P#+(-30/2+8)*[Set.S])
[Value01]
Meter=String
Text=#MaxSensitivity#
MeterStyle=Set.String:S | Set.Value:S

[MinSensitivity]
Meter=Shape
MeterStyle=Set.Textbox:S
Type=Int|0|#MaxSensitivity#
Y=([Option02:Y]-#Set.P#+(-30/2+8)*[Set.S])
[Value02]
Meter=String
Text=#MinSensitivity#
MeterStyle=Set.String:S | Set.Value:S

[Attack]
Meter=Shape
MeterStyle=Set.Textbox:S
Type=Int|0|2000
Y=([Option03:Y]-#Set.P#+(-30/2+8)*[Set.S])
[Value03]
Meter=String
Text=#Attack# ms
MeterStyle=Set.String:S | Set.Value:S

[Decay]
Meter=Shape
MeterStyle=Set.Textbox:S
Type=Int|0|2000
Y=([Option04:Y]-#Set.P#+(-30/2+8)*[Set.S])
[Value04]
Meter=String
Text=#Decay# ms
MeterStyle=Set.String:S | Set.Value:S

[BlurRadius]
Meter=Shape
MeterStyle=Set.Textbox:S
Type=Int|1|20
Y=([Option05:Y]-#Set.P#+(-30/2+8)*[Set.S])
[Value05]
Meter=String
Text=#BlurRadius#
MeterStyle=Set.String:S | Set.Value:S
