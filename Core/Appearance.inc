[Variables]
Sec.SaveLocation=#SKINSPATH##Skin.Name#\@Resources\Vars\Colors.inc
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
OnUpdateAction=[!Delay 100][!CommandMeasure Crafter "[#VisualizerType]"][!Refresh "#Skin.Name#\Main"]

[DragNDrop]
Measure=Plugin
Plugin=Drag&Drop
; FilePath=#SKINSPATH#ModularVisualizer\@Resources\UserImages
OnDropAction=[!SetVariable ImageUnderlayName "$Path$"][!WriteKeyValue Variables ImageUnderlayName "$Path$" "#Sec.SaveLocation2#"][!SetVariable ImageUnderlayFileName "$Name$"][!WriteKeyValue Variables ImageUnderlayFileName "$Name$" "#Sec.SaveLocation2#"][!UpdateMeasure Auto_Refresh:M][!UpdateMeter *][!Redraw]
Disabled=(1-#ImageUnderlay#)

[Choose:M]
Measure=Plugin
Plugin=FileChoose
UseNewStyle=0
GetTarget=0
AllowNonstorageFolder=1
GetIcon=0
ReturnValue=WholePath
FileInitialDirectory=#SKINSPATH#ModularVisualizer\@Resources\UserImages
DynamicVariables=1
Command1=[!SetVariable ImageUnderlayName "$Path$"][!WriteKeyValue Variables ImageUnderlayName "$Path$" "#Sec.SaveLocation2#"][!SetVariable ImageUnderlayFileName "$Name$"][!WriteKeyValue Variables ImageUnderlayFileName "$Name$" "#Sec.SaveLocation2#"][!UpdateMeasure Auto_Refresh:M][!UpdateMeter *][!Redraw]
Disabled=(1-#ImageUnderlay#)
; ---------------------------------------------------------------------------- ;
;                                    Content                                   ;
; ---------------------------------------------------------------------------- ;

; -------------------------------- Paper fill -------------------------------- ;

[ImageUnderlayTitle]
Meter=String
Text="ImageUnderlay"
MeterStyle=Set.String:S | Set.OptionCat:S
[Option10]
Meter=String
X=r
Text="Use an image as the fill for the visualizer"
MeterStyle=Set.String:S | Set.OptionName:S
[Option11]
Meter=String
X=r
Text="Click on the image below or drag an image onto it to set a new underlay!"
MeterStyle=Set.String:S | Set.OptionName:S
Hidden=(1-#ImageUnderlay#)

[HeaderImage]
Meter=Image
X=r
Y=(20*[Set.S])R
W=([ContentContainer:W]-30*[Set.S])
H=([ContentContainer:W]/(13/3))
ImageName=#ImageUnderlayName#
DynamicVariables=1
ImageAlpha=255
PreserveAspectRatio=2
DynamicVariables=1
MaskImageName=#@#Images\LayoutMask.png
Container=ContentContainer
LeftMouseUpAction=[!CommandMeasure Choose:M "ChooseFile 1"]
Hidden=(1-#ImageUnderlay#)

[ImageName]
Meter=String
X=([HeaderImage:W]/2)r
Y=([HeaderImage:H]/2)r
Text="#ImageUnderlayFileName#"
MeterStyle=Set.String:S
Container=ContentContainer
StringAlign=CenterCenter
FontSize=(30*[Set.S])
FontFace=Poppins SemiBold
Hidden=(1-#ImageUnderlay#)


; -------------------------------- Color fill -------------------------------- ;

@includePagePage=#SKINSPATH##Skin.Name#\Core\Appearance\[#VisualizerType].inc
