
[Description.String]
Text=ModularVisualizer is all yours!
InlinePattern=.*

[Button.1.Shape]
Meter=Shape
X=(#W#/2-300*[S]/2)
Y=(#Set.P#)R
LeftMouseUpAction=[!WriteKeyValue Variables Sec.arg2 "1" "#CURRENTPATH#Main.ini"][!WriteKeyValue Variables "Core.WelcomeCheck" 1 "#SKINSPATH#ModularVisualizer\@Resources\WelcomeVar.inc"][!ActivateConfig "ModularVisualizer\Main"][!Refresh "#JaxCore\Main"][!DeactivateConfig]
MeterStyle=Pos_Button.Shape:S
[Button.1.String]
Meter=String
Text=Complete setup
MeterStyle=Sec.String:S | Button.String:S