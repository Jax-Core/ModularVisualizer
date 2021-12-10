[AudioAnalyzer]
Measure=Plugin
Plugin=AudioAnalyzer
Type=Parent
Source=[#AnalyzerPort]
ProcessingUnits=Main
Unit-Main=Channels [#Channel] | Handlers MainFFT, MainBR(MainFFT), MainBCT(MainBR), MainTR(MainBCT) ,MainFinalOutput(MainTR)
;, 
; | Filter Custom bqHighPass(Q 0.2, Freq 20, ForcedGain 5.58), bqLowPass(Q 1, Freq 16000, ForcedGain 20)
Handler-MainFFT=Type FFT | BinWidth 8 | OverlapBoost 10 | CascadesCount 2 | WindowFunction [#WindowFunction]
Handler-MainBR=Type BandResampler | Bands Log(Count (#Bands# + 1), FreqMin 20, FreqMax 16000) | CubicInterpolation true
Handler-MainBCT=Type BandCascadeTransformer | MixFunction Average | MinWeight 0.01 | TargetWeight 2 | ZeroLevelMultiplier 1
Handler-MainTR=Type TimeResampler | Attack [#Attack] | Decay [#Decay] | Transform dB, Map(From -[#MaxSensitivity] : -[#MinSensitivity]), Clamp
Handler-MainFinalOutput=Type UniformBlur | Radius [#BlurRadius] | RadiusAdaptation 1
LogUnusedOptions=false