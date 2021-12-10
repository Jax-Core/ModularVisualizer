$env:PSModulePath+="$([System.IO.Path]::PathSeparator)$($RmAPI.VariableStr('SKINSPATH') + $RmAPI.VariableStr('Skin.Name'))\@Resources\Addons"

function ListAudioDevices {
    $a=Get-AudioDevice -List
    $device=@"
"@
    $index=0
    $a.GetEnumerator() | ForEach-Object {
        if ($_.Type -eq 'PlayBack') {
            $device+=@"

[DeviceBox$index]
Meter=Shape
MeterStyle=Device:S
LeftMouseUpAction=[!WriteKeyValue Variables DeviceName `"$($_.Name)`" `"#Sec.SaveLocation2#`"][!WriteKeyValue Variables DeviceID `"$($_.ID)`" `"#Sec.SaveLocation2#`"][!UpdateMeasure "Auto_Refresh:M"]
[DeviceName$index]
Meter=String
Text=$($_.Name)
MeterStyle=Set.String:S | DeviceName:S

"@
        }
    $index++
    }
    $index=0
    $a.GetEnumerator() | ForEach-Object {
        if ($_.Type -eq 'Recording') {
            $device+=@"

[DeviceBox$index]
Meter=Shape
MeterStyle=Device:S
LeftMouseUpAction=[!WriteKeyValue Variables DeviceName `"$($_.Name)`" `"#Sec.SaveLocation2#`"][!WriteKeyValue Variables DeviceID `"$($_.ID)`" `"#Sec.SaveLocation2#`"][!UpdateMeasure "Auto_Refresh:M"]
[DeviceName$index]
Meter=String
Text=$($_.Name)
MeterStyle=Set.String:S | DeviceName:S

"@
        }
    $index++
    }
    $device | Out-File -FilePath $($RmAPI.VariableStr('SKINSPATH') + $RmAPI.VariableStr('Skin.Name') + '\Core\audio\DeviceList1.inc')
    $RmAPI.Log('Generated audio devices')
    $RmAPI.Bang('!Refresh')
}