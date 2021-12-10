;                                      __ __            
;|\                /|        /\          |   |\        |
;| \              / |       /  \         |   | \       |
;|  \            /  |      /    \        |   |  \      |
;|   \          /   |     /      \       |   |   \     |
;|    \        /    |    /        \      |   |    \    |
;|     \      /     |   /----------\     |   |     \   |
;|      \    /      |  /            \    |   |      \  |
;|       \  /       | /              \   |   |       \ |
;|        \/        |/                \__|__ |        \|

[Variables]
;@About | Name Settings | Description Control how your visualizer is rendered here. | Icon [\xE771]
;@Topic | Name Personalization | Icon [\xE771]
;@ | Name Visualizer | Icon [\xF61F]
;?RadioButton | Name Visualizer Type | Options Bar; Round; Vector
VisualizerType=Bar
;@ | Name Extra | Icon [\xF0B9]
;@ | Name Image Underlay | Description Add an image underlay to your visualizer | Icon [\xE81E]
;@ | Name Colors | Description Define colors of your visualizer | Icon [\xE790]
;@Topic | Name Equalizer Settings | Icon [\xF4C3]
;@ | Name Device | Description Select a specific device(for advanced users) | Icon [\xE95B]
;@ | Name AudioAnalyzer | Icon [\xF0ED]

ImageUnderlay=0
ImageUnderlayName=#SKINSPATH#ModularVisualizer\@Resources\UserImages\Default.jfif
ImageUnderlayFileName=Default

DeviceName=Microphone (2- MAONO AU-BM10)
DeviceID={0.0.1.00000000}.{93cb243a-ea98-4710-825f-c6aaef3a225b}

BoostRate=0

;?RadioButton | Name Audio Source | Options Output,DefaultOutput; Input,DefaultInput; DeviceID,"ID: [#DeviceID]"
AnalyzerPort=DefaultOutput
AnalyzerPortIsID=0
