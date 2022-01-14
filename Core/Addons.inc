[Variables]
Sec.SaveLocation=#SKINSPATH##Skin.Name#\@Resources\LayeringVars.inc
LayeringCheckStatus=0
@includeVars=#SKINSPATH##Skin.Name#\@Resources\LayeringVars.inc
Sec.Generate=1

; ---------------------------------------------------------------------------- ;
;                                   Fucntions                                  ;
; ---------------------------------------------------------------------------- ;


[LayeringActiveChecker]
Measure=Plugin
Plugin=ConfigActive
ConfigName=#Skin.Name#\Main\Layering
IfCondition=LayeringActiveChecker = 1
IfTrueAction=[!SetVariable LayeringCheckStatus 1][!UpdateMeterGroup LayeringCheckStatus][!Redraw]
IfFalseAction=[!SetVariable LayeringCheckStatus 0][!UpdateMeterGroup LayeringCheckStatus][!Redraw]

[Auto_Refresh:M]
OnUpdateAction=[!Delay 100][!Refresh "#Skin.Name#\Main\Layering"]

[Choose:M]
Measure=Plugin
Plugin=FileChoose
UseNewStyle=0
GetTarget=0
AllowNonstorageFolder=1
GetIcon=0
ReturnValue=WholePath
FileInitialDirectory=
DynamicVariables=1
Command1=[!WriteKeyvalue Variables ImagePath "$Path$" "#Sec.SaveLocatioN#"][!WriteKeyvalue Variables ImageName "$Name$" "#Sec.SaveLocatioN#"][!Refresh]

; ---------------------------------------------------------------------------- ;
;                                    Content                                   ;
; ---------------------------------------------------------------------------- ;

[Header]
Text="3D overlay"

; --------------------------------- Section1 --------------------------------- ;

[Section1]
Meter=Shape
X=(30*[Set.S])
Y=(60*[Set.S])r
Shape=Rectangle 0,0,([ContentContainer:W]-#Set.P#),(100*[Set.S]),(#Set.R#/4) | StrokeWidth 0 | Fill Color #Set.Sec_Color#
Container=ContentContainer
DynamicVariables=1

[Section1.Icon]
Meter=String
Text=[\xe7b3]
X=(#Set.P#)r
Y=(100/2*[Set.S])r
FontSize=(20*[set.s])
MeterStyle=Set.String:S | Set.Icon:S | Section1.Icon:#LayeringCheckStatus#
Group=LayeringCheckStatus
[Section1.Icon:0]
FontColor=#Set.Accent_Color#
InlineSetting=Shadow | 0 | 0 | 2 | #Set.Accent_Color#
[Section1.Icon:1]
FontColor=#Set.Positive_Color#
InlineSetting=Shadow | 0 | 0 | 2 | #Set.Positive_Color#

[Section1.Text]
Meter=String
X=(5*[Set.S])R
Y=r
Text="Layering skin activation status"
W=([ContentContainer:W]-#Set.P#*4-60*[Set.S])
ClipString=2
FontSize=(10*[Set.S])
Container=ContentContainer
StringAlign=LeftCenter
InlinePattern=#CRLF#.*
InlineSetting=Color | #Set.SubText_Color#
MeterStyle=Set.String:S

[LayeringCheckStatus]
Meter=Shape
MeterStyle=Set.Bool:S | LayeringCheckStatus:#LayeringCheckStatus#
Y=(-20/2*[Set.S])r
Group=LayeringCheckStatus
X=([ContentContainer:W]-#Set.P#-60*[Set.S])
[LayeringCheckStatus:0]
Leftmouseupaction=[!ActivateConfig "#Skin.Name#\Main\Layering"][!UpdateMeasure LayeringActiveChecker]
[LayeringCheckStatus:1]
Leftmouseupaction=[!DeactivateConfig "#Skin.Name#\Main\Layering"][!UpdateMeasure LayeringActiveChecker]

; --------------------------------- Section 2 -------------------------------- ;

[Option01]
Meter=String
Text="Layering image"
X=(35*[Set.S])
Y=(60*[Set.S])R
MeterStyle=Set.String:S | Set.OptionName:S
[Set.Div:8]
Meter=Shape
MeterStyle=Set.Div:S
[Option08]
Meter=String
Text="Image fit"
MeterStyle=Set.String:S | Set.OptionName:S
[Set.Div:1]
Meter=Shape
MeterStyle=Set.Div:S
[Option02]
Meter=String
Text="Automated positioning"
MeterStyle=Set.String:S | Set.OptionName:S
[Set.Div:2]
Meter=Shape
MeterStyle=Set.Div:S
[Option03]
Meter=String
Text="Monitor to display on"
FontColor=#Set.Text_Color#,(105+150*#Automated#)
MeterStyle=Set.String:S | Set.OptionName:S
[Set.Div:7]
Meter=Shape
MeterStyle=Set.Div:S
[Option04]
Meter=String
Text="Custom X position"
FontColor=#Set.Text_Color#,(255-105*#Automated#)
MeterStyle=Set.String:S | Set.OptionName:S
[Set.Div:3]
Meter=Shape
MeterStyle=Set.Div:S
[Option05]
Meter=String
Text="Custom Y position"
FontColor=#Set.Text_Color#,(255-105*#Automated#)
MeterStyle=Set.String:S | Set.OptionName:S
[Set.Div:4]
Meter=Shape
MeterStyle=Set.Div:S
[Option06]
Meter=String
Text="Custom W dimension"
FontColor=#Set.Text_Color#,(255-105*#Automated#)
MeterStyle=Set.String:S | Set.OptionName:S
[Set.Div:5]
Meter=Shape
MeterStyle=Set.Div:S
[Option07]
Meter=String
Text="Custom H dimension"
FontColor=#Set.Text_Color#,(255-105*#Automated#)
MeterStyle=Set.String:S | Set.OptionName:S

; ---------------------------------------------------------------------------- ;
;                                   Function                                   ;
; ---------------------------------------------------------------------------- ;

[Button01]
Meter=Shape
MeterStyle=Set.Button:S
Y=([Option01:Y]-#Set.P#+(-30/2+8)*[Set.S])
Act=[!CommandMeasure Choose:M "ChooseFile 1"]
OverColor=#Set.Accent_Color#,150
LeaveColor=#Set.Accent_Color#,50
[Value01]
Meter=String
Text=#ImageName#
MeterStyle=Set.String:S | Set.Value:S

[PreserveAspectRatio:]
Meter=Shape
MeterStyle=Set.Pick3:S
Shape2=Rectangle (100*[Set.S]*([&Func:returnBool('PreserveAspectRatio', '1')]+[&Func:returnBool('PreserveAspectRatio', '2')]*2)),0,(300/3*[Set.S]),(30*[Set.S]),(7*[Set.S]) | Fill Color #Set.Text_Color# | StrokeWidth 0
Y=([Option08:Y]-#Set.P#+(-30/2+8)*[Set.S])
[PreserveAspectRatio:0]
Meter=String
Text="Stretch to fit"
FontColor=[&Func:returnBool('PreserveAspectRatio', '0', '#Set.Pri_color#', '#Set.Text_Color#')]
MeterStyle=Set.String:S | Set.PickOption3_0:S
Leftmouseupaction=[!WriteKeyValue Variables PreserveAspectRatio "0" "#Sec.SaveLocation#"][!WriteKeyValue Variables Sec.Generate 1 "#SKINSPATH##SKin.Name#\Core\#Skin.Set_Page#.inc"][!Refresh]
[PreserveAspectRatio:1]
Meter=String
Text="Fit"
FontColor=[&Func:returnBool('PreserveAspectRatio', '1', '#Set.Pri_color#', '#Set.Text_Color#')]
MeterStyle=Set.String:S | Set.PickOption3_1:S
Leftmouseupaction=[!WriteKeyValue Variables PreserveAspectRatio "1" "#Sec.SaveLocation#"][!WriteKeyValue Variables Sec.Generate 1 "#SKINSPATH##SKin.Name#\Core\#Skin.Set_Page#.inc"][!Refresh]
[PreserveAspectRatio:2]
Meter=String
Text="Fill"
FontColor=[&Func:returnBool('PreserveAspectRatio', '2', '#Set.Pri_color#', '#Set.Text_Color#')]
MeterStyle=Set.String:S | Set.PickOption3_2:S
Leftmouseupaction=[!WriteKeyValue Variables PreserveAspectRatio "2" "#Sec.SaveLocation#"][!WriteKeyValue Variables Sec.Generate 1 "#SKINSPATH##SKin.Name#\Core\#Skin.Set_Page#.inc"][!Refresh]

[Automated]
Meter=Shape
MeterStyle=Set.Bool:S
Y=([Option02:Y]-#Set.P#+(-20/2+8)*[Set.S])

[MonitorIndex]
Meter=Shape
MeterStyle=Set.Textbox:S
Y=([Option03:Y]-#Set.P#+(-30/2+8)*[Set.S])
Hidden=(1-#Automated#)
[Value03]
Meter=String
MeterStyle=Set.String:S | Set.Value:S
Text=#MonitorIndex#
Hidden=(1-#Automated#)

[X]
Meter=Shape
MeterStyle=Set.Textbox:S
Y=([Option04:Y]-#Set.P#+(-30/2+8)*[Set.S])
Hidden=#Automated#
[Value04]
Meter=String
MeterStyle=Set.String:S | Set.Value:S
Text=#X#
Hidden=#Automated#
[Y]
Meter=Shape
MeterStyle=Set.Textbox:S
Y=([Option05:Y]-#Set.P#+(-30/2+8)*[Set.S])
Hidden=#Automated#
[Value05]
Meter=String
MeterStyle=Set.String:S | Set.Value:S
Text=#Y#
Hidden=#Automated#
[W]
Meter=Shape
MeterStyle=Set.Textbox:S
Y=([Option06:Y]-#Set.P#+(-30/2+8)*[Set.S])
Hidden=#Automated#
[Value06]
Meter=String
MeterStyle=Set.String:S | Set.Value:S
Text=#W#
Hidden=#Automated#
[H]
Meter=Shape
MeterStyle=Set.Textbox:S
Y=([Option07:Y]-#Set.P#+(-30/2+8)*[Set.S])
Hidden=#Automated#
[Value07]
Meter=String
MeterStyle=Set.String:S | Set.Value:S
Text=#H#
Hidden=#Automated#
