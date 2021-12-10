[Variables]

;@ | Name Vector

;?Integer | Name LayerCount
LayerCount=4

;?Integer | Name Points
VectorBands=9

;?String | Name Width
VectorWidth=#SCREENAREAWIDTH#

;?String | Name Width
MinimumHeight=30

;?Integer | Name Layer1 Height
Layer1Height=160

;?Integer | Name Layer2 Height
Layer2Height=140

;?Integer | Name Layer3 Height
Layer3Height=110

;?Integer | Name Layer4 Height
Layer4Height=90

;?RadioButton | Name Color Mode | Options Solid; Gradient
BarType=Solid

;?Integer | Name Angle
Angle=0

@includeVectorColors=Vector\[#BarType].inc
