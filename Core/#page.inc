[General:Category]
Meter=String
MeterStyle=Set.String:S | Pagecat:S
Text="GENERAL"
Y=(#Set.P#+64*[Set.S])

[Info]
Meter=Shape
Y=(10*[Set.S])R
MeterStyle=PageBox:S
Fill=Fill Color #Set.Accent_Color#,(#BarHandler# = 1 ? 255: 0)
Handle=1
[InfoIcon]
Meter=Image
MeterStyle=PageIcon:S
Greyscale=(#BarHandler# = 1 ? 1 : 0)
[1]
Meter=String
Text="Info"
DynamicVariables-1
MeterStyle=Set.String:S | PageText:S

[General]
Meter=Shape
Y=(10*[Set.S])R
MeterStyle=PageBox:S
Fill=Fill Color #Set.Accent_Color#,(#BarHandler# = 2 ? 255: 0)
Handle=2
[GeneralIcon]
Meter=Image
MeterStyle=PageIcon:S
Greyscale=(#BarHandler# = 2 ? 1 : 0)
[2]
Meter=String
Text="General"
DynamicVariables-1
MeterStyle=Set.String:S | PageText:S

[Appearance]
Meter=Shape
Y=(10*[Set.S])R
MeterStyle=PageBox:S
Fill=Fill Color #Set.Accent_Color#,(#BarHandler# = 3 ? 255: 0)
Handle=3
[AppearanceIcon]
Meter=Image
MeterStyle=PageIcon:S
Greyscale=(#BarHandler# = 3 ? 1 : 0)
[3]
Meter=String
Text="Appearance"
DynamicVariables-1
MeterStyle=Set.String:S | PageText:S

[Layout]
Meter=Shape
Y=(10*[Set.S])R
MeterStyle=PageBox:S
Fill=Fill Color #Set.Accent_Color#,(#BarHandler# = 4 ? 255: 0)
Handle=4
[LayoutIcon]
Meter=Image
MeterStyle=PageIcon:S
Greyscale=(#BarHandler# = 4 ? 1 : 0)
[4]
Meter=String
Text="Layout"
DynamicVariables-1
MeterStyle=Set.String:S | PageText:S

[Audio]
Meter=Shape
Y=(10*[Set.S])R
MeterStyle=PageBox:S
Fill=Fill Color #Set.Accent_Color#,(#BarHandler# = 90 ? 255: 0)
Handle=90
[AudioIcon]
Meter=Image
MeterStyle=PageIcon:S
Greyscale=(#BarHandler# = 90 ? 1 : 0)
[90]
Meter=String
Text="Audio"
DynamicVariables-1
MeterStyle=Set.String:S | PageText:S

[Addons]
Meter=Shape
Y=(10*[Set.S])R
MeterStyle=PageBox:S
Fill=Fill Color #Set.Accent_Color#,(#BarHandler# = 81 ? 255: 0)
Handle=81
[AddonsIcon]
Meter=Image
MeterStyle=PageIcon:S
Greyscale=(#BarHandler# = 81 ? 1 : 0)
[81]
Meter=String
Text="3D overlay"
DynamicVariables-1
MeterStyle=Set.String:S | PageText:S

[Render]
Meter=Shape
Y=(10*[Set.S])R
MeterStyle=PageBox:S
Fill=Fill Color #Set.Accent_Color#,(#BarHandler# = 6 ? 255: 0)
Handle=6
Hidden=[&Func:returnBool('VisualizerType', 'Bar', '0', '1')]
[RenderIcon]
Meter=Image
MeterStyle=PageIcon:S
Greyscale=(#BarHandler# = 6 ? 1 : 0)
Hidden=[&Func:returnBool('VisualizerType', 'Bar', '0', '1')]
[6]
Meter=String
Text="Render"
DynamicVariables-1
MeterStyle=Set.String:S | PageText:S
Hidden=[&Func:returnBool('VisualizerType', 'Bar', '0', '1')]